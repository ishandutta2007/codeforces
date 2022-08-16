#include <iostream>
#include <cstring>

using namespace std;

const int N = 105;

int p[N];
char l[N][N];

bool isVowel(char c)
{
	return (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'y');
}

int countSyllables(char *word, int len)
{
	int ans = 0;

	for (int i = 0; i < len; ++i)
		if (isVowel(word[i]))
			++ans;

	return ans;
}

int totalSyllables(char *line)
{
	int len = strlen(line), j = 0, ans = 0;
	char word[N];

	for (int i = 0; i <= len; ++i)
	{
		if (i == len or line[i] == ' ')
		{
			word[j] = 0;
			ans += countSyllables(word, j);
			j = 0;
		}

		else
			word[j++] = line[i];
	}

	return ans;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> p[i];

	char c;
	cin.get(c);

	for (int i = 0; i < n; ++i)
	{
		cin.getline(l[i], N);
		//cout << l[i] << endl;
	}

	for (int i = 0; i < n; ++i)
	{
		//cout << l[i] << ' ' << totalSyllables(l[i]) << endl;

		if (totalSyllables(l[i]) != p[i])
		{
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";
}