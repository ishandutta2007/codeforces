#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 5e4 + 5;

char s[N];

bool check(int st)
{
	bool seen[26]={0};

	for (int i = st; i <= st+25; ++i)
	{
		if (s[i] == '?')
			continue;

		if (seen[s[i]-'A'])
			return false;

		seen[s[i]-'A']=true;
	}

	vector <char> left;

	for (int i = 0; i < 26; ++i)
		if (!seen[i])
			left.push_back(i+'A');

	vector <char>::iterator j = left.begin();

	for (int i = st; i <= st+25; ++i)
	{
		if (s[i] == '?')
		{
			s[i] = *j;
			++j;
		}
	}

	return true;
}

void fill(int len)
{
	for (int i = 0; i < len; ++i)
	{
		if (s[i] == '?')
			s[i] = 'A';
	}
}

int main()
{
	cin >> s;
	int len = strlen(s);

	for (int i = 0; i + 25 < len; ++i)
	{
		if (check(i))
		{
			fill(len);
			cout << s;
			return 0;
		}
	}

	cout << -1;
}