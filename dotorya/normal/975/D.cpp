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
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

pll in[200050];

map <ll, ll> Mx;
int main() {
	ll N, A, B, i, j;
	scanf("%lld %lld %lld", &N, &A, &B);
	for (i = 1; i <= N; i++) {
		ll t1, t2, t3;
		scanf("%lld %lld %lld", &t1, &t2, &t3);

		ll v1 = t2 * A - t3;
		ll v2 = t2 + t3 * A;
		in[i] = pll(v1, v2);
	}
	sort(in + 1, in + N + 1);

	ll ans = 0;
	int st = 1;
	for (i = 1; i <= N; i++) {
		if (i == N || in[i].first != in[i + 1].first) {
			int en = i;
			Mx.clear();
			for (j = st; j <= en; j++) Mx[in[j].second]++;
			for (j = st; j <= en; j++) ans += (en - st + 1) - Mx[in[j].second];
			st = en + 1;
		}
	}
	return !printf("%lld\n", ans);
}