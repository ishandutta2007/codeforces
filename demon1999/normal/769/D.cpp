#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define zhfs main
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 1; i <= n; i++)
const int MX = 10001, MAXN = 100 * 1000 + 7;
int bcnt[MAXN];
int cnt[MX];
int zhfs()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	for (int i = 0; i < MAXN; i++)
	{
		int j = i;
		while (j > 0)
		{
			if (j % 2 == 1)
			{
				bcnt[i]++;
			}
			j /= 2;
		}
	}
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	ll res = 0;
	for (int i = 0; i < MX; i++)
	{
		for (int j = i + 1; j < MX; j++)
		{
			if (bcnt[i ^ j] != k) continue;
			res += 1LL * cnt[i] * cnt[j];
		}
	}
	if (k == 0)
	{
		for (int i = 0; i < MX; i++)
		{
			res += 1LL * cnt[i] * (cnt[i] - 1) / 2;
		}
	}
	printf("%lld\n", res);
}