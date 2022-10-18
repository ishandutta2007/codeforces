#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include <ctime>
#include<list>
#include <numeric>
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
//#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FORAB(i, a, b) for(int i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;
typedef vector<double> VD;
typedef vector<LL> VL;

int A[203];
LL dp[2][102][1003];
const LL MOD = 1000000007;

int main()
{
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	double start_time = clock();
#endif

	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
	sort(A + 1, A + 1 + n);
	int u = 0, v = 1;
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		int lim = MIN(i, n - i);
		for (int j = 0; j <= lim; j++) {
			for (int kk = 0; kk <= k; kk++) {
				dp[v][j][kk] = 0;
			}
		}

		lim = MIN(i - 1, n - i + 1);
		for (int j = 0; j <= lim; j++) {
			for (int kk = 0; kk <= k; kk++) {
				if (dp[u][j][kk] == 0) continue;
				int newk = kk + j * (A[i] - A[i - 1]);
				LL temp = (j * dp[u][j][kk]) % MOD;
				if (newk <= k) {
					dp[v][j + 1][newk] += dp[u][j][kk];
					dp[v][j][newk] += temp;
					dp[v][j][newk] += dp[u][j][kk];
					if (j) {
						dp[v][j - 1][newk] += temp;
					}
				}

			}
		}

		lim = MIN(i, n - i);
		for (int j = 0; j <= lim; j++) {
			for (int kk = 0; kk <= k; kk++) {
				dp[v][j][kk] %= MOD;
			}
		}
		swap(u, v);
	}
	int ans = 0;
	for (int i = 0; i <= k; i++) {
		ans += dp[u][0][i];
		if (ans >= MOD) ans -= MOD;
	}
	printf("%d\n", ans);

#ifdef LOCAL
	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
#endif

	return 0;
}