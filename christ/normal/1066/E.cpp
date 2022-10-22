#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353, MAXN = 200005;

vector<int> pre(MAXN);
char s[MAXN], t[MAXN];

int main()
{
	int n, m;
	scanf("%i%i%s%s", &n, &m, s, t);
	for (int x = 0; x < m; x++)
		pre[x] = t[x] - '0';
	for (int x = 1; x < m; x++)
		pre[x] += pre[x - 1];
	int ans = 0;
	for (int x = n - 1, b = 1; x >= 0; x--)
	{
		if (s[x] == '1')
		{
			int t = m - (n - x);
			ans = (ans + (long long)(t >= 0 ? pre[t] : 0) * b) % MOD;
		}
		b = (long long)b * 2 % MOD;
	}
	printf("%i\n", ans);
}