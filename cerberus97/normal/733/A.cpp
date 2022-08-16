#include <iostream>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5, INF = 2147483647;

bool isVowel(char c)
{
	return (c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U' or c == 'Y');
}

int main()
{
	string s;
	cin >> s;

	s = "A" + s + "A";

	int cur = 0, ans = 1;

	for (int i = 1; i < s.length(); ++i)
	{
		++cur;

		if (isVowel(s[i]))
		{
			ans = max(ans, cur);
			cur = 0;
		}
	}

	cout << ans;
}