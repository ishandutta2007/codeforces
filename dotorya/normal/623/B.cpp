#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#pragma warning(disable:4996)
using namespace std;

#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;

int IT_MAX = 131072;
const ll MOD = 1000;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-10;

vector <int> V;
vector <int> plist;
bool pchk[40050];
int in[1000050];
ll chk[1000050];
ll lsum[1000050];
ll rsum[1000050];

void getPrime(int x) {
	for (auto it : plist) {
		if (x % it != 0) continue;
		while (x % it == 0) x /= it;
		V.push_back(it);
	}
	if (x != 1) V.push_back(x);
}

int main() {
	int N, i, j;
	ll A, B;
	for (i = 2; i <= 40000; i++) {
		if (pchk[i]) continue;
		plist.push_back(i);
		for (j = 2 * i; j <= 40000; j += i) pchk[j] = true;
	}

	scanf("%d %lld %lld", &N, &A, &B);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);
	getPrime(in[1] - 1);
	getPrime(in[1]);
	getPrime(in[1] + 1);
	getPrime(in[N] - 1);
	getPrime(in[N]);
	getPrime(in[N] + 1);

	sort(V.begin(), V.end());
	V.erase(unique(V.begin(), V.end()), V.end());

	ll ans = LL_INF;
	for (auto it : V) {
		for (i = 1; i <= N; i++) {
			if (in[i] % it == 0) chk[i] = 0;
			else if (in[i] % it == 1 || in[i] % it == it - 1) chk[i] = B;
			else chk[i] = LL_INF;
		}
		lsum[0] = 0;
		for (i = 1; i <= N; i++) {
			lsum[i] = lsum[i - 1] + chk[i];
			if (lsum[i] >= 2*LL_INF) lsum[i] = 2*LL_INF;
		}
		rsum[N + 1] = 0;
		for (i = N; i >= 1; i--) {
			rsum[i] = rsum[i + 1] + chk[i];
			if (rsum[i] >= 2*LL_INF) rsum[i] = 2*LL_INF;
		}

		ll mn = 0;
		for (i = 1; i <= N; i++) {
			ans = min(ans, mn + rsum[i] + A * (i - 1));
			mn = min(mn, lsum[i] - i * A);
		}
		for (i = 1; i <= N; i++) ans = min(ans, lsum[i] + (N - i)*A);
		for (i = 1; i <= N; i++) ans = min(ans, rsum[i] + (i - 1)*A);
	}
	assert(ans >= 0);
	printf("%lld\n", ans);
	return 0;
}