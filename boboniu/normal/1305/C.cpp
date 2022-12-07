#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = 222222;
int n, m, a[maxN];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	if (n > m)
	{
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	i64 ans = 1;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			ans = ans * abs(a[i] - a[j]) % m;
	cout << ans << endl;
}