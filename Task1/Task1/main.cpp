#include <string>
#include <map>
#include <iostream>

int main(int argc, char* argv[])
{
	constexpr char const* HAS_NO_DUPLICATES = "(";
	constexpr char const* HAS_DUPLICATES = ")";

	std::string in_string, out_string;
	if (argc > 1)
		in_string = std::string(argv[1]);
	else
	{
		std::printf("Please, input a string: \n");
		std::getline(std::cin, in_string);
	}
	std::printf("The input string is \"%s\".\n", in_string.c_str());

	std::map<char, bool> duplicates;
	for (size_t i = 0; i < in_string.length(); ++i)
	{
		char const c = std::tolower(in_string[i]);
		if (duplicates.count(c) < 1)
			duplicates[c] = in_string.find_first_of(c) != in_string.find_last_of(c);
		out_string.append(duplicates[c] ? HAS_DUPLICATES : HAS_NO_DUPLICATES);
	}
	std::printf("The output string is \"%s\".\n", out_string.c_str());

	return 0;
}
