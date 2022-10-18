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

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;

double dp[1003][1003][2];
double DP(int w, int b, int who) {
	double& ret = dp[w][b][who];
	if (ret >= -0.5) return ret;
	ret = 0;
	if (w + b == 0) {
		if (who == 0) return ret = 0;
		else return ret = 1;
	}
	double total = w + b;
	if (!who) {
		ret = w / total;
		if (b) ret += b / total * (1 - DP(w, b - 1, 1));
	}
	else {
		if (b + w <= 2) return ret = 1.;
		if (w) ret += w / total;
		if (b) {
			ret += b / total * (
				(b > 1 ? (b - 1) / (total - 1) * (1 - DP(w, b - 2, 0)) : 0) +
				(w > 0 ? (w) / (total - 1) * (1 - DP(w - 1, b - 1, 0)) : 0)
				);
		}
	}
	return ret;
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif
	int w, b;
	FORN(i, 1002) FORN(j, 1002) dp[i][j][0] = dp[i][j][1] = -1.;
	scanf("%d %d", &w, &b);
	double ans = DP(w, b, 0);
	printf("%.10lf\n", ans);
	return 0;
}