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

map<int, int> M;
int L[305], C[305];
int n;

int gcd(int a, int b)
{
	if(a % b == 0) return b;
	return gcd(b, a % b);
}

int DP(int g, int at)
{
	if(M.find(g) != M.end())
		return M[g];

	if(g == 1)
	{
		return M[g] = 0;
	}

	int ret = 100000000;
	for(int i = at + 1; i < n; i++)
	{
		int ng = gcd(g, L[i]);
		if(g == ng) continue;
		int now = DP(ng, i) + C[i];
		ret = MIN(ret, now);
	}

	return M[g] = ret;
}

int main()
{
	int i;

	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%d", &L[i]);
	for(i = 0; i < n; i++) scanf("%d", &C[i]);
	//for(i = 0; i < n; i++) C[i] = L[i] = rand() % 1000000000 + 1;
	int ans = 100000000;
	for(i = 0; i < n; i++)
	{
		int now = C[i] + DP(L[i], i);
		ans = MIN(ans, now);
	}

	if(ans >= 100000000) printf("-1\n");
	else printf("%d\n", ans);

	return 0;
}