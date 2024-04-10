/*













 
*/
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
const ll MOD = 1000 * 1000 * 1000 + 7;
const int MAXN = 1000 * 1000 + 7;
ll cnt[MAXN];
ll pw[11];
ll pw2[MAXN];
ll masks[67];
ll bitCnt[67];
ll cntMore[MAXN][3];
ll g[MAXN], s[MAXN], k[MAXN];
ll mask9[MAXN];
int zhfs()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	pw[0] = 1;
	pw2[0] = 1;
	for (int i = 1; i < MAXN; i++)
	{
		pw2[i] = (pw2[i - 1] * 2) % MOD;
	}
	for (int i = 0; i < MAXN; i++)
	{
		int x = i;
		for (int j = 0; j < 7; j++)
		{
			if (x % 10 == 9)
			{
				mask9[i] |= (1 << j);
			}
			x /= 10;
		}
	}
	for (int i = 1; i < 7; i++)
	{
		pw[i] = pw[i - 1] * 10;
	}
	for (int i = 0; i < 64; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (i & (1 << j))
			{
				masks[i] += pw[j];
				bitCnt[i]++;
			}
		}
	}
	for (int i = 999999; i >= 0; i--)
	{
		cntMore[i][0] = cnt[i];
		cntMore[i][1] = 1LL * i * cnt[i];
		cntMore[i][2] = 1LL * i * i * cnt[i] % MOD;
		for (int j = 1; j < 64; j++)
		{
			if (i + masks[j] < MAXN && (mask9[i] & j) == 0)
			{
				ll mul = 1;
				if (bitCnt[j] % 2 == 0) mul = -1;
				for (int k = 0; k < 3; k++)
				{
					cntMore[i][k] += mul * cntMore[i + masks[j]][k];
				}
			}
		}
		for (int k= 0;k < 3;k++)
		cntMore[i][k] = (cntMore[i][k] + MOD * MOD) % MOD;
		for (int k = 0; k < 3; k++)
		{
			cntMore[i][k] %= MOD;
		}
		if (cntMore[i][0] > 0)
		{
	//		cerr << "CNT: " << i << " " << cntMore[i][0] << endl;
		}
	}
	ll res = 0;
	for (int i = 999999; i >= 0; i--)
	{
		if (cntMore[i][0] == 0)
		{
			g[i] = 0;
		}
		else if (cntMore[i][0] == 1)
		{
			g[i] = cntMore[i][2];
		}
		else
		{
			g[i] = pw2[cntMore[i][0] - 2] * ((cntMore[i][1] * cntMore[i][1]) % MOD + cntMore[i][2]) % MOD;
		}
		if (i < 4)
		{
	//		cerr << "BEF: " << i << " " << g[i] <<  " " << cntMore[i][1] << " " << cntMore[i][2] << endl;
		}
		g[i] %= MOD;
	}
	for (int i = 0; i <= 999999; i++)
	{
		for (int j = 1; j < 64; j++)
		{
			if (i + masks[j] < MAXN && (mask9[i] & j) == 0)
			{
				ll mul = 1;
				if (bitCnt[j] % 2 == 1) mul = -1;
				g[i] += mul * g[i + masks[j]];
			}
		}
		g[i] = (g[i] + MOD * MOD) % MOD;
		if (g[i] > 0)
		{
	//		cerr << "G: " << i << " " << g[i] << " " <<  1LL * i * g[i] << endl;
		}
		res ^= 1LL * i * g[i];
	}
	printf("%lld\n", res);
}