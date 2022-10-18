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
typedef __int64 LL;

map<VI, int > hashing;
LL dp[1000][5];
int vis[10000][5];

LL DP(VI V, int remaining)
{
	int id = hashing[V];
	if(vis[id][remaining]) return dp[id][remaining];
	vis[id][remaining] = 1;
	LL &ret = dp[id][remaining];
	ret = 0;

	if(remaining == 0)
	{
		int n = SZ(V);
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				ret += (V[i] > V[j]);
		return ret;
	}

	int n = SZ(V);
	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++)
		{
			VI Z = V;
			for(int a = i, b = j; a < b; a++, b--) swap(Z[a], Z[b]);
			ret += DP(Z, remaining - 1);
		}

	return ret;
}

int main()
{
	int n, k;
	int i;

	scanf("%d %d", &n, &k);
	VI V;
	for(i = 1; i <= n; i++)
		V.push_back(i);
	int cnt = 1;
	do
	{
		hashing[V] = cnt++;
	} while(next_permutation(V.begin(), V.end()));

	V.clear();
	for(i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		V.push_back(a);
	}

	LL ans = DP(V, k);
	double hor = ((n + 1) * n) / 2;
	double dAns = ans / (pow(hor, k));
	printf("%.20lf\n", dAns);
		
	return 0;
}