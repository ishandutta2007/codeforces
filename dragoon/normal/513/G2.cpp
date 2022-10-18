#pragma warning(disable:4786)
#pragma warning(disable:4996)
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

int f(int L, int R, int at)
{
	if(at < L || at > R) return at;
	return L + (R - at);
}

int vis[32][32][204];
double dp[32][32][204];
int n;
int p[32];
double P[32][32][32][32];

double DP(int i, int j, int k)
{
	double &ret = dp[i][j][k];
	if(vis[i][j][k]) return ret;
	vis[i][j][k] = 1;
	ret = 0;

	if(k == 0)
	{
		return ret = 1. * (i > j);
	}

	for(int ni = 0; ni < n; ni++)
		for(int nj = 0; nj < n; nj++)
		{
			if(P[i][j][ni][nj] < 1e-9) continue;
			ret += P[i][j][ni][nj] * DP(ni, nj, k - 1);
		}

	return ret;
}

int main()
{
	int k, i, j, a, b;

	scanf("%d %d", &n, &k);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &p[i]);
	}

	double prob = 1. / ( ((n + 1) * n) / 2. );
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++) if(i != j)
		{
			for(a = 0; a < n; a++)
				for(b = a; b < n; b++)
				{
					int newi = f(a, b, i);
					int newj = f(a, b, j);
					P[i][j][newi][newj] += prob;
				}
		}

	double ans = 0.0;
	for(i = 0; i < n; i++)
		for(j = i + 1; j < n; j++)
		{
			double now = 0.0;
			if(p[i] < p[j]) now = DP(i, j, k);
			else now = DP(j, i, k);
			ans += now;
		}

	printf("%.20lf\n", ans);
	return 0;
}