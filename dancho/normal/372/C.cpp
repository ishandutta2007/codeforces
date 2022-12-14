#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct sta
{
	int stop;
	long long val[1<<20], mx[1<<20];
	
	inline int sz() { return stop; }

	inline void st_init()
	{
		stop = 0;
		mx[0] = -(1LL<<62);
	}

	inline void st_push(long long x)
	{
		++stop;
		val[stop] = x;
		mx[stop] = std::max(val[stop], mx[stop-1]);
	}

	inline long long st_pop() { --stop; return val[stop+1]; }

	inline long long get_mx()
	{
		return mx[stop];
	}
};

struct que
{
	sta s1, s2;
	
	inline void init()
	{
		s1.st_init(); s2.st_init();
	}
	
	inline void q_push(long long val)
	{
		s2.st_push(val);
	}
	inline void q_pop()
	{
		if (s1.sz() == 0)
		{
			while (s2.sz())
			{
				s1.st_push(s2.st_pop());
			}
		}
		s1.st_pop();
	}
	
	inline long long get_mx()
	{
		return max(s1.get_mx(), s2.get_mx());
	}
};

inline long long ia(long long x)
{
	if (x < 0) return -x;
	return x;
}

int n, m, d;
int a[512], b[512], t[512];

inline long long eval(int i, int pos)
{
	return b[i] - ia(a[i]-pos);
}

long long dp[150020][2];

que q;

int main()
{
	scanf("%d %d %d", &n, &m, &d);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &a[i], &b[i], &t[i]);
	}
	
	for (int i = 1; i <= n; ++i)
	{
		dp[i][m&1] = eval(m, i);
	}
	
	long long be = -(1LL<<62);
	for (int j = m-1; j > 0; --j)
	{
		long long ple = 1, pri = 0;
		q.init();
		for (int i = 1; i <= n; ++i)
		{
			long long le = (long long) i - (long long) d * (t[j+1]-t[j]);
			long long ri = (long long) i + (long long) d * (t[j+1]-t[j]);
			
			if (le < 1) le = 1;
			if (ri > n) ri = n;
			while (pri < ri)
			{
				++pri;
				q.q_push(dp[pri][(j+1)&1]);
			}
			while (ple < le)
			{
				q.q_pop();
				++ple;
			}
			dp[i][j&1] = q.get_mx() + eval(j, i);
			if (j == 1)
			{
				be = std::max(be, dp[i][j&1]);
			}
		}
	}
	std::cout << be << std::endl;
	return 0;
}