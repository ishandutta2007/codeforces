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

int dp[5003][5003];
int num[5003];
int whr[100005], whr7[7];
int nxt[5003], prv[5003], same[5003], same7[5003];
int n;

int DP(int a, int b) {
	if (a > n && b > n) return 0;
	if (a > b) return DP(b, a);
	int& ret = dp[a][b];
	if (ret != -1) return ret;

	ret = 0;
	if (nxt[a]) {
		if (nxt[a] != b) ret = MAX(ret, 1 + DP(nxt[a], b));
		else if (same[nxt[a]]) ret = MAX(ret, 1 + DP(same[nxt[a]], b));
	}
	if (prv[a]) {
		if (prv[a] != b) ret = MAX(ret, 1 + DP(prv[a], b));
		else if (same[prv[a]]) ret = MAX(ret, 1 + DP(same[prv[a]], b));
	}
	if (same7[a]) {
		int now = same7[a];
		for (int i = 0; i < 7; i++) {
			if (!now) break;
			if (now != b) ret = MAX(ret, 1 + DP(now, b));
			now = same7[now];
		}
	}
	ret = MAX(ret, DP(b, n + 1));
	return ret;
}

void solve(int ks) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
	for (int i = n; i >= 1; i--) {
		if (whr[num[i] + 1]) nxt[i] = whr[num[i] + 1];
		if (whr[num[i] - 1]) prv[i] = whr[num[i] - 1];
		if (whr7[num[i] % 7]) same7[i] = whr7[num[i] % 7];
		if (whr[num[i]]) same[i] = whr[num[i]];
		whr[num[i]] = i;
		whr7[num[i] % 7] = i;
	}
	MEM(dp, -1);
	int ans = 2;
	for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) {
		int now = 2 + DP(i, j);
		ans = MAX(ans, now);
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
		solve(0);
	}

#ifdef LOCAL
	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
#endif

	return 0;
}