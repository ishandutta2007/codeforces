#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <unordered_map>

inline long long gcd(long long a, long long b)
{
	while (b)
	{
		long long t = a % b;
		a = b;
		b = t;
	}
	return a;
}

long long ans = 1;
int n;
long long a[1<<20];
int ld;
long long dels[1<<20];
int p;
long long pd[1<<20];
int cnt[7000];

std::set<long long> vis;

std::unordered_map<long long, int> ps;

int kk;

int dp[7000][13];

int rec(int i, int q)
{
	if (q >= p)
		return cnt[i];
	if (dp[i][q] != -1)
		return dp[i][q];
	int c = 0;
	long long x = dels[i];
	while (a[kk] % x == 0)
	{
		c += rec((int) (std::lower_bound(dels, dels+ld, x) - dels), q+1);
		x *= pd[q];
	}
	return (dp[i][q]=c);
}

int main()
{
	srand(1002);
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%I64d", &a[i]);
	}
	std::random_shuffle(a, a + n);
	for (int iter = 0; vis.size() < 14 && iter < n; ++iter)
	{
		//~ int k = ((rand()<<15) + rand()) % n;
		//~ int k = ((rand()<<16) + rand())%n;
		int k = iter;
		kk = k;
		//~ if (a[k] != 963761198400LL)
			//~ continue;
		if (a[k] <= ans)
		{
			continue;
		}
		if (vis.find(a[k]) != vis.end())
		{
			continue;
		}
		//~ printf("TRY %I64d\n", a[k]);
		vis.insert(a[k]);
		ld = 0;
		for (long long i = 1; i*i <= a[k]; ++i)
		{
			if (a[k] % i == 0)
			{
				dels[ld++] = i;
				if (a[k] / i != i)
					dels[ld++] = a[k]/i;
			}
		}
		std::sort(dels, dels + ld);
		ps.clear();
		for (int i = 0; i < ld; ++i)
		{
			ps[dels[i]] = i;
			//~ printf("DEL %I64d\n", dels[i]);
		}
		long long x = a[k];
		p = 0;
		for (long long i = 2; i*i <= x; ++i)
		{
			if (x%i == 0)
			{
				pd[p++] = i;
				while (x%i == 0)
					x /= i;
			}
		}
		if (x > 1)
		{
			pd[p++] = x;
		}
		
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++)
		{
			long long d = gcd(a[i], a[k]);
			//~ int pos = (int) (std::lower_bound(dels, dels+ld, d) - dels);
			++cnt[ps[d]];
			//~ printf("CNT %I64d %d\n", d, cnt[ps[d]]);
		}
		
		for (int i = 0; i < ld; ++i)
			dp[i][p] = cnt[i];
		for (int q = p-1; q >= 0; --q)
		{
			for (int i = ld - 1; i >= 0; --i)
			{
				dp[i][q] = dp[i][q + 1];
				long long x = dels[i] * pd[q];
				if (a[k] % x == 0)
				{
					//~ dp[i][q] += dp[ (int) (std::lower_bound(dels, dels+ld, x) - dels) ][q+1];
					dp[i][q] += dp[ ps[x] ][q];
				}
			}
		}

		for (int i = 0; i < ld; ++i)
		{
			if (dp[i][0])
			{
				//~ printf("%I64d %d\n", dels[i], dp[i][0]);
			}
			if (dels[i] > ans)
			{
				if (dp[i][0] >= (n+1)/2)
				{
					ans = dels[i];
				}
			}
		}
	}
	
	printf("%I64d\n", ans);

	return 0;
}