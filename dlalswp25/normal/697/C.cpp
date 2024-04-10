#include <stdio.h>
#include <map>

using namespace std;

map<long long, long long> M;

long long lca(long long a, long long b)
{
	if(a < b)	return lca(b, a);
	long long da = 0, ta = a, db = 0, tb = b;
	while(ta > 0)
	{
		da++;	ta /= 2;
	}
	while(tb > 0)
	{
		db++;	tb /= 2;
	}

	while(da > db)
	{
		da--;	a /= 2;
	}
	if(a == b)	return a;

	while(a != b)
	{
		a /= 2;	b /= 2;
	}

	return a;
}

int main()
{
	int Q;	scanf("%d", &Q);
	for(int i = 0; i < Q; i++)
	{
		long long u, v, w;
		int x;	scanf("%d", &x);
		if(x == 1)
		{
			scanf("%lld %lld %lld", &u, &v, &w);
			long long l = lca(u, v);
			while(u != l)
			{
				M[u] += w;	u /= 2;
			}
			while(v != l)
			{
				M[v] += w;	v /= 2;
			}
		}
		else
		{
			scanf("%lld %lld", &u, &v);
			long long l = lca(u, v);	long long ret = 0;
			while(u != l)
			{
				ret += M[u];	u /= 2;
			}
			while(v != l)
			{
				ret += M[v];	v /= 2;
			}
			printf("%lld\n", ret);
		}
	}
	return 0;
}