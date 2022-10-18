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

struct State {
	// st = 1, if loose.
	LL l, r, st;
	State(LL _l, LL _r, LL _st) {
		l = _l;
		r = _r;
		st = _st;
	}
};
vector<State> V;

int dp[1000];

void gen() {
	//dp[1] = dp[2] = dp[3] = 0;
	//for (int i = 4; i <= 100; i++) {
	//	set<int> S;
	//	for (int j = 1; j < i; j++) {
	//		if (sqrt(sqrt(i)) <= j && j <= sqrt(i)) {
	//			S.insert(dp[j]);
	//		}
	//	}
	//	for (int j = 0; ; j++) {
	//		if (S.find(j) == S.end()) {
	//			dp[i] = j;
	//			break;
	//		}
	//	}
	//}

	//for (int i = 1; i <= 100; i++) {
	//	printf("%d: %d\n", i, dp[i]);
	//}

	//V.emplace_back( 2, 3, 1 );
	//while (V.back().r < 1000000000000LL) {
	//	if (V.back().st == 0) {
	//		// if prev winning
	//		LL x = V.back().r + 1;
	//		LL y = S(x) - 1; double dy = S(x * 1.) - 1;
	//		if (dy > 1e12) y = 1000000000000LL;
	//		V.emplace_back(x, y, 1);
	//	}
	//	else {
	//		// if prev loosing
	//		LL x = S(V.back().l); double dx = S(1. * V.back().l);
	//		LL y = S(S(V.back().r)); double dy = S(S(1. * V.back().r));
	//		if (dx > 1e12) assert(0);
	//		if (dy > 1e12) y = 1000000000000LL;
	//		V.emplace_back(x, y, 0);
	//	}
	//}
	//V[0].l = 1;

	//for (auto& s : V) {
	//	printf("%lld %lld %d\n", s.l, s.r, s.st);
	//}
	//  1- 3   loosing: 0
	//  4-15   winning: 1
	// 16-81   winning: 2
	// 82-6723 loosing: 0
	// 6724-45212175: winning 1
	// 45212176-1e12: winning 2
	V.emplace_back(1, 3, 0);
	V.emplace_back(4, 15, 1);
	V.emplace_back(16, 81, 2);
	V.emplace_back(82, 6723, 0);
	V.emplace_back(6724, 50625, 3);
	V.emplace_back(50626, 2562991875LL, 1);
	V.emplace_back(2562991876LL, 1000000000000LL, 2);
}

int calc(LL a) {
	for (auto& s : V) {
		if (s.l <= a && a <= s.r) {
			return s.st;
		}
	}
	assert(0);
}

void solve(int ks) {
	gen();
	int n;
	scanf("%d", &n);
	int xr = 0;
	for (int i = 1; i <= n; i++) {
		LL a;
		scanf("%lld", &a);
		xr ^= calc(a);
	}
	printf("%s\n", xr ? "Furlo" : "Rublo");
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