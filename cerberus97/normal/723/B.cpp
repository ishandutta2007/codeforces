#include <iostream>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5, INF = 2147483647;

int countWords(char *s, int i, int j)
{
	while (s[i] == '_' and i <= j)
		++i;

	while (s[j] == '_' and j >= i)
		--j;

	if (j < i)
		return 0;

	int ans = 1;

	for (; i <= j; ++i)
	{
		if (s[i] == '_')
		{
			++ans;

			while (s[i+1] == '_')
				++i;
		}
	}

	return ans;
}

int lengthOfLongestWord(char *s, int i, int j)
{
	while (s[i] == '_' and i <= j)
		++i;

	while (s[j] == '_' and j >= i)
		--j;

	if (j < i)
		return 0;

	int ctr = 0, ans = 1;

	for (int k = i; k <= j; ++k)
	{
		if (s[k] == '_')
		{
			ans = max(ans, ctr);
			ctr = 0;

			while (s[k+1] == '_')
				++k;
		}

		else
			++ctr;
	}

	ans = max(ans, ctr);
	return ans;
}

int main()
{
	int n;
	cin >> n;

	char s[300];
	cin >> s;

	int longestLen = 0, numWords = 0, st = 0;
	bool inParen = false;

	for (int i = 0; i < n; ++i)
	{
		if (s[i] == '(')
		{
			longestLen = max(longestLen, lengthOfLongestWord(s, st, i-1));
			st = i+1;
		}

		else if (s[i] == ')')
		{
			numWords += countWords(s, st, i-1);
			st = i+1;
		}
	}

	longestLen = max(longestLen, lengthOfLongestWord(s, st, n-1));
	cout << longestLen << ' ' << numWords;
}