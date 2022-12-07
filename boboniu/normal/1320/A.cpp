#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int n;
map<int, i64> val;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		val[a - i] += a;
	}
	i64 ans = 0;
	for (auto kv : val)
		ans = max(ans, kv.second);
	cout << ans << endl;
}