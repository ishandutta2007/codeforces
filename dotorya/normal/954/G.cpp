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

int IT_MAX = 1 << 17;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define Se second
#define Fi first

ll in[500050];
ll del[500050];

ll rm[500050];
int main() {
	ll N, R, K, i, j;
	scanf("%lld %lld %lld", &N, &R, &K);
	for (i = 1; i <= N; i++) scanf("%lld", &in[i]);
	for (i = 1; i <= N; i++) {
		ll st = max(1ll, i - R);
		ll en = min(N, i + R);
		del[st] += in[i];
		del[en + 1] -= in[i];
	}
	for (i = 1; i <= N; i++) del[i] += del[i - 1];
	
	if (2 * R + 1 >= N) {
		ll mn = LL_INF;
		for (i = 1; i <= N; i++) mn = min(mn, del[i]);
		return !printf("%lld\n", mn + K);
	}

	ll st = 1, en = LL_INF, mi, rv = 0;
	while (st <= en) {
		mi = (st + en) / 2;

		ll cnt = 0;
		for (i = 1; i <= N; i++) rm[i] = 0;
		ll cur = 0;
		for (i = 1; i <= N; i++) {
			cur -= rm[i];
			ll t = del[i] + cur;
			if (t < mi) {
				cnt += mi - t;
				if (cnt > K) break;
				cur += mi - t;
				rm[min(N + 1, i + 2 * R + 1)] += mi - t;
			}
		}
		if (i > N) {
			rv = mi;
			st = mi + 1;
		}
		else en = mi - 1;
	}
	return !printf("%lld\n", rv);
}