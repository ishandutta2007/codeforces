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

int IT_MAX = 1 << 18;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

ll mul_inv(ll a, ll b = MOD) {
	ll t1 = a, t2 = b, t3;
	ll v1 = 1, v2 = 0, v3;
	while (t2 != 1) {
		ll x = t1 / t2;
		t3 = t1 - x*t2;
		v3 = v1 - x*v2;
		t1 = t2, t2 = t3;
		v1 = v2, v2 = v3;
	}
	return (v2 + b) % b;
}
int in1[100050];
int in2[100050];
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) scanf("%d", &in1[i]);
	for (i = 1; i <= N; i++) scanf("%d", &in2[i]);

	ll ans = 0, curp = 1;
	for (i = 1; i <= N; i++) {
		if (in1[i] && in2[i]) {
			if (in1[i] == in2[i]) continue;
			if (in1[i] < in2[i]) break;
			if (in1[i] > in2[i]) {
				ans = (ans + curp) % MOD;
				break;
			}
		}
		else if (!in1[i] && in2[i]) {
			curp = curp * mul_inv(M) % MOD;
			ans = (ans + curp * (M - in2[i])) % MOD;
		}
		else if (in1[i] && !in2[i]) {
			curp = curp * mul_inv(M) % MOD;
			ans = (ans + curp * (in1[i] - 1)) % MOD;
		}
		else {
			ll p = curp;
			p = p * (M - 1) % MOD;
			p = p * mul_inv(2 * M) % MOD;
			curp = curp * mul_inv(M) % MOD;
			ans = (ans + p) % MOD;
		}
	}
	return !printf("%lld\n", ans);
}