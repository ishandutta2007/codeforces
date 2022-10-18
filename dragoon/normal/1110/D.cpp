//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
#include<unordered_map>
#include<unordered_set>
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
//typedef __int128 LLL;
//typedef __int64 LL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<long double, long double> PDD;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII > VP;
typedef vector<double> VD;
typedef long double ld;

int dp[6][6];
int ndp[6][6];
int cnt[1000006];
int n, m;

void solve(int ks) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}

	MEM(dp, -1);
	dp[0][0] = 0;
	for (int i = 1; i <= m; i++) {
		//if (cnt[i]) printf("%d %d\n", i, cnt[i]);
		MEM(ndp, -1);
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 6; k++) {
				if (dp[j][k] == -1) continue;
				int taken = MIN(j, k);
				for (int me = 0; me <= taken; me++) {
					if (me > cnt[i]) continue;
					for (int carry = 0; carry < 6; carry++) {
						if (me + carry > cnt[i]) continue;
						int now = me + dp[j][k] + (cnt[i] - me - carry) / 3;
						if (now > ndp[k - me][carry]) {
							ndp[k - me][carry] = now;
						}
					}
				}
			}
		}
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 6; k++) {
				dp[j][k] = ndp[j][k];
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			ans = MAX(ans, ndp[i][j]);
		}
	}
	printf("%d\n", ans);
}

int main()
{
#ifdef LOCAL
	double start_time = clock();
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif

	if (0) {
		int T;
		scanf("%d", &T);
		for (int ks = 1; ks <= T; ks++) solve(ks);
	}
	else {
		/*
		n = 30, m = 1000;
		for (int i = 1; i <= n/3; i++) {
			int x = rand() % 7 + 1;
			if (rand() % 2) cnt[x]+=3;
			else cnt[x]++, cnt[x + 1]++, cnt[x + 2]++;
		}
		cnt[1] = 0;
		*/
		solve(0);
	}

#ifdef LOCAL
	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
#endif

	return 0;
}