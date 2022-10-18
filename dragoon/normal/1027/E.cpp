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

const LL MOD = 998244353;
LL dp[502][502];

LL semiDp[502];

int main()
{
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif
	int n, k;
	scanf("%d %d", &n, &k);

	for (int mx = 1; mx <= n; mx++) {
		CLR(semiDp);
		semiDp[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= mx && j <= i; j++) {
				semiDp[i] += semiDp[i - j];
			}
			semiDp[i] %= MOD;
		}
		for (int i = 1; i <= n; i++) {
			dp[i][mx] = semiDp[i];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = n; j > 1; j--) {
			dp[i][j] = (dp[i][j] - dp[i][j - 1] + MOD) % MOD;
		}
	}

	LL ans = 0;
 	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i * j >= k) continue;
			ans += dp[n][i] * dp[n][j];
			ans %= MOD;
		}
	}
	ans = (ans * 2) % MOD;
	printf("%lld\n", ans);
	return 0;
}