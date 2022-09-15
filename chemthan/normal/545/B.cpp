#include <iostream>
#include <bitset>

char s[100001];
char t[100001];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	std::cin>>s>>t;
	char result[100001];
	memset(result, 0, 100001 * sizeof(char));
	bool state = true;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] != t[i])
		{
			if (state)
				result[i] = s[i];
			else
				result[i] = t[i];
			state = !state;
		}
		else
			result[i] = '0';
	}
	if (!state)
		std::cout<<"impossible";
	else
		std::cout<<result;
	return 0;
}