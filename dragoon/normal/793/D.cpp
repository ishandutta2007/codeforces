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
typedef long long int LL;
//typedef __int64 LL;

int dp[81][81][81][81];
int n, k;
VP V[81];

int DP(int at, int l, int r, int rem) {
	int& ret = dp[at][l][r][rem];
	if (ret != -1) return ret;
	if (rem == 0) return ret = 0;
	ret = 100000000;

	for (auto& p : V[at]) {
		if (!IN(p.first, l, r)) continue;
		if (p.first < at) {
			int now = DP(p.first, l, at - 1, rem - 1) + p.second;
			ret = MIN(ret, now);
		}
		if (p.first > at) {
			int now = DP(p.first, at + 1, r, rem - 1) + p.second;
			ret = MIN(ret, now);
		}
	}
	return ret;
}

int main()
{
	MEM(dp, -1);
	scanf("%d %d", &n, &k);
	int m;
	scanf("%d", &m);
	while (m--) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		V[u].push_back(PII(v, w));
	}

	int ans = 100000000;
	for (int i = 1; i <= n; i++) {
		int temp = DP(i, 1, n, k - 1);
		ans = MIN(ans, temp);
	}

	if (ans == 100000000) ans = -1;
	printf("%d\n", ans);
	return 0;
}