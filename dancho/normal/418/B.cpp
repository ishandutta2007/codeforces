#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct fr
{
	long long k, x;
	int m;
	vector<int> p;
	bool operator<(const fr &f) const
	{
		return k < f.k;
	}
};

fr f[128];
long long dp[1<<20];
int n, m;
long long b;

int main()
{
	scanf("%d %d %lld", &n, &m, &b);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld %lld %d", &f[i].x, &f[i].k, &f[i].m);
		f[i].p.resize(f[i].m);
		for (int j = 0; j < f[i].m; ++j)
		{
			scanf("%d", &f[i].p[j]);
			--f[i].p[j];
		}
	}
	sort(f, f + n);
	
	memset(dp, 63, sizeof(dp));
	//~ printf("%lld\n", dp[0]);
	
	long long ans = dp[0];
	long long sans = ans;
	dp[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		int ma = 0;
		for (int j = 0; j < f[i].m; ++j)
			ma |= (1 << f[i].p[j]);
		for (int j = 0; j < (1<<m); ++j)
		{
			if (dp[j | ma] > dp[j] + f[i].x)
				dp[j | ma] = dp[j] + f[i].x;
		}
		ans = min(ans, dp[(1<<m) - 1] + f[i].k * b);
	}
	if (ans >= sans)
		ans = -1;
	printf("%lld\n", ans);
	
	return 0;
}