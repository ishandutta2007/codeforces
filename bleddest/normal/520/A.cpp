#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int number_of_characters = 0;
	for (char c = 'a'; c <= 'z'; c++)
	{
		char C = c + 'A' - 'a';
		for (int i = 0; i < n; i++)
			if(s[i] == c || s[i] == C)
			{
				number_of_characters++;
				break;
			}
	}
	if (number_of_characters == 26)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}