#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	int n;
	cin >> n;
	cin >> s;
	int ans = 0, sum = 0;
	for (int i = 0; i < n; i++)
	{
		int cs = sum;
		if (s[i] == '(')
			cs += 1;
		else
			cs -= 1;
		if (min(cs, sum) < 0)
			ans += 1;
		sum = cs;
	}
	if (sum != 0)
		ans = -1;
	cout << ans << "\n";
}