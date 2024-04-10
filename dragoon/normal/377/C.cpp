#pragma warning(disable:4786)
#include<list>
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
#include<assert.h>
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
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;


#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
//typedef long long int LL;
//typedef __int64 LL;

int n, m;
int s[200];
char op[30][30];
int opd[30];

int dp[1<<20];
char vis[1<<20];

int DP(int pos, int mask)
{
	if(pos == m) return 0;
	int &ret = dp[mask];
	if(vis[mask] == 1) return ret;
	vis[mask] = 1;

	int i, now;

	if(opd[pos] == 1)
	{
		ret = -1000000000;
		if(op[pos][0] == 'p')
		{
			for(i = 0; i < m; i++) if(mask & (1<<i));
			else
			{
				now = s[i] + DP(pos + 1, mask | (1<<i));
				ret = MAX(ret, now);
			}

			return ret;
		}
		else
		{
			for(i = 0; i < m; i++) if(mask & (1<<i));
			else
			{
				now = DP(pos + 1, mask | (1<<i));
				ret = MAX(ret, now);
			}

			return ret;
		}
	}
	else
	{
		ret = 1000000000;
		if(op[pos][0] == 'p')
		{
			for(i = 0; i < m; i++) if(mask & (1<<i));
			else
			{
				now = -s[i] + DP(pos + 1, mask | (1<<i));
				ret = MIN(ret, now);
			}

			return ret;
		}
		else
		{
			for(i = 0; i < m; i++) if(mask & (1<<i));
			else
			{
				now = DP(pos + 1, mask | (1<<i));
				ret = MIN(ret, now);
			}

			return ret;
		}
	}

	return ret;
}

int main()
{
	int i;

	scanf("%d", &n);
	FORN(i, n) scanf("%d", &s[i]);
	sort(s, s + n, greater<int>());

	scanf("%d", &m);
	FORN(i, m)
	{
		scanf("%s %d", op[i], &opd[i]);
	}

	printf("%d\n", DP(0, 0));

	return 0;
}