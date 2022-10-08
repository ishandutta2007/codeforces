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

int main() {
	ll N, A, B, i, j;
	scanf("%lld %lld %lld", &N, &A, &B);
	for (i = 1; i <= N; i++) scanf("%lld %lld", &in[i].first, &in[i].second);
	B = min(B, N);

	sort(in + 1, in + N + 1, [](pll a, pll b) {
		return a.first - a.second > b.first - b.second;
	});

	ll ans = 0;
	for (i = 1; i <= N; i++) ans += in[i].second;

	if (B == 0) return !printf("%lld\n", ans);
	for (i = 1; i <= B; i++) if (in[i].first > in[i].second) ans += in[i].first - in[i].second;

	ll ANS = ans;
	for (i = 1; i <= N; i++) {
		ll tans = ans;
		if (i <= B) {
			tans += max(in[i].first << A, in[i].second) - in[i].second;
			tans -= max(0ll, in[i].first - in[i].second);
		}
		else {
			tans += max(in[i].first << A, in[i].second) - in[i].second;
			tans -= max(0ll, in[B].first - in[B].second);
		}
		ANS = max(ANS, tans);
	}
	return !printf("%lld\n", ANS);
}