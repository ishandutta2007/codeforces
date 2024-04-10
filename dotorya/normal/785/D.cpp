#include <stdio.h>
#include <algorithm>
#include <assert.h>
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
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

ll mul_inv(ll a, ll b = MOD)
{
	ll b0 = b, t, q;
	ll x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

char in[200050];

ll c1[200050];
ll c2[200050];

ll F[200050];
ll Finv[200050];
ll C(ll a, ll b) {
	if (b < 0 || b > a) return 0;
	ll rv = F[a];
	rv = (rv * Finv[b]) % MOD;
	rv = (rv * Finv[a - b]) % MOD;
	return rv;
}
int main() {
	int N, i;
	scanf("%s", in + 1);
	N = strlen(in + 1);

	for (i = 1; i <= N; i++) c1[i] = c1[i - 1] + (in[i] == '(');
	for (i = N; i >= 1; i--) c2[i] = c2[i + 1] + (in[i] == ')');

	F[0] = 1;
	for (i = 1; i <= N; i++) F[i] = F[i - 1] * i % MOD;
	for (i = 0; i <= N; i++) Finv[i] = mul_inv(F[i]);
	ll ans = 0;
	for (i = 1; i <= N; i++) {
		if (in[i] != ')') continue;
		if (c1[i - 1] == 0) continue;

		ll a = c1[i - 1], b = c2[i + 1];
		if (a > b) ans = (ans + C(a + b, b + 1)) % MOD;
		else ans = (ans + C(a + b, a - 1)) % MOD;
	}
	return !printf("%lld\n", ans);
}