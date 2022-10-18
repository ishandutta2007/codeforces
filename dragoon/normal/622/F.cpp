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
//typedef __int64 LL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;

LL inv[1000006];
LL MOD = 1000000007;
LL pre[1000006], suf[1000006], term[1000006];

LL bigmod(LL a, LL b) {
	if (b == 0) return 1;
	LL x = bigmod(a, b / 2);
	x = (x * x) % MOD;
	if (b & 1) x = (x * a) % MOD;
	return x;
}
LL n, k;

void solve() {
	if (k == 0) {
		printf("%I64d\n", n);
		return;
	}

	for (int i = 1; i <= k + 2; i++) {
		term[i] = n - i;
		if (term[i] < 0) term[i] += MOD;
	}
	pre[0] = 1;
	suf[k + 3] = 1;
	for (int i = 1; i <= k + 2; i++) pre[i] = (pre[i - 1] * term[i]) % MOD;
	for (int i = k + 2; i >= 1; i--) suf[i] = (suf[i + 1] * term[i]) % MOD;

	LL hor;
	LL y = 0;
	LL ans = 0;
	for (int i = 1; i <= k + 2; i++) {
		y = (y + bigmod(i, k)) % MOD;
		LL lob = (pre[i - 1] * suf[i + 1]) % MOD;
		if (i == 1) {
			hor = 1;
			for (int j = 1; j <= k + 1; j++) hor = (hor * j) % MOD;
			if ((k+1) & 1) hor = (MOD - hor) % MOD;
		}
		else {
			hor = (hor * (i - 1)) % MOD;
			hor = (hor * inv[k - i + 3]) % MOD;
			hor = (MOD - hor) % MOD;
		}
		ans += (y * ((lob * bigmod(hor, MOD - 2)) % MOD)) % MOD;
		ans %= MOD;
	}
	printf("%I64d\n", ans);
}

int main() {
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
#endif

	// All inverses
	inv[1] = 1;
	for (int i = 2; i < 1000006; ++i) {
		inv[i] = (MOD - (MOD / i) * inv[MOD%i] % MOD) % MOD;
	}

	while (scanf("%I64d %I64d", &n, &k) != EOF) {
		solve();
	}


	return 0;
}