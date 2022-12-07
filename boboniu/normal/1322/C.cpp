#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

mt19937_64 rnd(random_device{}());

const int maxN = 555555;
int n, m;
u64 key[maxN], val[maxN];
i64 weight[maxN];

i64 gcd(i64 a, i64 b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

void solve()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> weight[i];
		key[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		val[i] = rnd();
	}
	for (int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		--l;
		--r;
		key[r] += val[l];
	}
	map<u64, i64> s;
	for (int i = 0; i < n; i++)
	{
		if (key[i] != 0)
		{
			s[key[i]] += weight[i];
		}
	}
	i64 a = 0;
	for (auto p : s)
	{
		a = gcd(a, p.second);
	}
	cout << a << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		solve();
	}
}