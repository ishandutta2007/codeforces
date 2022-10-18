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
//typedef __int128 LL;
//typedef __int64 LL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<long double, long double> PDD;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII > VP;
typedef vector<double> VD;
typedef vector<LL> VL;
typedef long double ld;

LL dp[102][102][2][102];
int score[102];
LL dpF[102][102];
char S[102];
int n;

LL DPF(int i, int j);

LL DP(int i, int j, int prev, int cnt) {
	if (i > j) {
		return score[cnt];
	}
	LL& ret = dp[i][j][prev][cnt];
	if (ret != -1) return ret;

	ret = 0;
	if (S[i] - '0' == prev) {
		ret = DP(i + 1, j, prev, cnt + 1);
	}
	for (int k = i; k <= j; k++) {
		LL now = DPF(i, k) + DP(k + 1, j, prev, cnt);
		ret = MAX(ret, now);
	}
	return ret;
}

LL DPF(int i, int j) {
	LL& ret = dpF[i][j];
	if (ret != -1) return ret;
	for (int k = i; k < j; k++) {
		LL now = DPF(i, k) + DPF(k + 1, j);
		ret = MAX(ret,  now);
	}
	ret = MAX(ret, DP(i, j, S[i] - '0', 0));
	return ret;
}

void solve(int ks) {
	scanf("%d", &n);
	scanf("%s", S);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &score[i]);
	}
	MEM(dpF, -1);
	MEM(dp, -1);
	printf("%lld\n", DPF(0, n - 1));
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
		solve(0);
	}

#ifdef LOCAL
	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
#endif

	return 0;
}