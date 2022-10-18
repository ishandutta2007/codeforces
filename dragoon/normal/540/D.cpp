#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<list>
#include<bitset>
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
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FORAB(i, a, b) for(int i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;

typedef pair<int,int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;
typedef vector<double> VD;
typedef vector<LL> VL;

VD dp[102][102][102];

VD DP(int r, int s, int p) {
	VD& V = dp[r][s][p];
	if (SZ(V)) return V;
	V = { 0, 0, 0 };
	if (!r && !s && !p) return V;
	if (r && !s && !p) return V = { 1, 0, 0 };
	if (!r && s && !p) return V = { 0, 1, 0 };
	if (!r && !s && p) return V = { 0, 0, 1 };
	double total = r * s + s * p + p * r;
	
	if (r && s) {
		double pp = (r * s) / total;
		auto W = DP(r, s - 1, p);
		FORN(i, 3) V[i] += pp * W[i];
	}
	if (p && s) {
		double pp = (p * s) / total;
		auto W = DP(r, s, p - 1);
		FORN(i, 3) V[i] += pp * W[i];
	}
	if (r && p) {
		double pp = (r * p) / total;
		auto W = DP(r - 1, s, p);
		FORN(i, 3) V[i] += pp * W[i];
	}
	return V;
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif
	int r, s, p;
	scanf("%d %d %d", &r, &s, &p);
	VD V = DP(r, s, p);
	printf("%.15lf %.15lf %.15lf\n", V[0], V[1], V[2]);
	return 0;
}