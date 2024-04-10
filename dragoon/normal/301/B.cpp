#pragma warning(disable:4786)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)

typedef pair<int,int> PII;
typedef pair<double, double> PDD;

//typedef int LL;
//typedef __int64 LL;

int n, d, a[105];
int x[105], y[105];
int dist[105], done[105];

int check(int limit)
{
	priority_queue<PII> Q;
	PII u;
	int i, cost;

	memset(done, 0, sizeof(done));
	memset(dist, 0, sizeof(done));

	dist[1] = limit;
	Q.push( PII(dist[1], 1) );
	while(!Q.empty())
	{
		u = Q.top();
		Q.pop();
		done[u.second] = 1;

		for(i = 2; i <= n; i++)
			if(done[i] == 0)
			{
				cost = d*( ABS(x[i] - x[u.second]) + ABS(y[i] - y[u.second]) );
				if(cost > u.first) continue;
				cost = u.first - cost + a[i];

				if(i == n) return 1;

				if(dist[i] < cost)
				{
					dist[i] = cost;
					Q.push( PII(dist[i], i) );
				}
			}
	}

	return 0;
}

int main()
{
	int i;
	int lo, mid, hi;

	scanf("%d %d", &n, &d);
	for(i = 2; i < n; i++)
		scanf("%d", &a[i]);

	for(i = 1; i <= n; i++)
		scanf("%d%d", &x[i], &y[i]);

	lo = 1;
	hi = 1000000000;
	while(lo < hi)
	{
		mid = (lo + hi)/2;
		if(check(mid)) hi = mid;
		else lo = mid + 1;
	}

	printf("%d\n", lo);

	
	return 0;
}