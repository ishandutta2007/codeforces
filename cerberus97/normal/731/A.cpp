#include <iostream>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

int diff(char a, char b)
{
	if (a > b)
		swap(a,b);

	return min(b-a, 26-b+a);
}

int main()
{
	string s;
	cin >> s;

	int ans = 0;
	char cur = 'a';

	for (auto &i : s)
	{
		ans += diff(cur, i);
		cur = i;
	}

	cout << ans;
}