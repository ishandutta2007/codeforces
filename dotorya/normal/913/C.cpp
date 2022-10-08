#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 16;
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

ll in[35];
int main() {
	int N, L, i, j;
	scanf("%d %d", &N, &L);
	for (i = 0; i < N; i++) {
		scanf("%lld", &in[i]);
		if (i) in[i] = min(in[i], 2 * in[i - 1]);
	}
	for (i = N; i <= 31; i++) in[i] = in[i - 1] * 2;

	ll ans = LL_INF;
	for (ll x = L; x <= (1ll << 31ll); x += x & (-x)) {
		ll s = 0;
		for (i = 0; i <= 31; i++) if (x & (1ll << (ll)i)) s += in[i];
		ans = min(ans, s);
	}
	return !printf("%lld\n", ans);
}