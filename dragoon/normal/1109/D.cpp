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
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII > VP;
typedef vector<PLL > VPL;
typedef vector<double> VD;
typedef long double ld;

int n, m, a, b;
LL fact[1000006], ifact[1000006];
const LL MOD = 1000000000 + 7;
LL bigmod(LL a, LL n) {
	if (n == 0) return 1;
	LL x = bigmod(a, n / 2);
	x = (x * x) % MOD;
	if (n & 1) x = (x * a) % MOD;
	return x;
}

void solve(int ks) {
	scanf("%d %d %d %d", &n, &m, &a, &b);

	fact[0] = 1;
	for (int i = 1; i <= 1000002; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	ifact[1000002] = bigmod(fact[1000002], MOD - 2);
	for (int i = 1000001; i >= 0; i--) {
		ifact[i] = (ifact[i + 1] * (i + 1)) % MOD;
	}

	LL ans = 0;
	for (int e = 1; e <= MIN(n - 1, m); e++) {
		// a...e edges...b
		LL now = (fact[m - 1] * ifact[m - e]) % MOD;
		now = (now * fact[n - 2]) % MOD;
		now = (now * ifact[e - 1]) % MOD;
		now = (now * ifact[n - 2 - e + 1]) % MOD;
		int v = e - 1 + 2;
		int rem = n - v;
		LL x = bigmod(m, rem) % MOD;
		LL zz = 0;
		if (rem == 0) zz = 1;
		else if (rem == 1) zz = (n - 1LL);
		else {
			LL z = bigmod(n, rem - 1);
			zz = (z * v) % MOD;
		}
		//printf("%lld %lld\n", now, zz);
		zz = (zz * x) % MOD;
		ans += now * zz;
		ans %= MOD;
	}
	printf("%lld\n", ans);
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