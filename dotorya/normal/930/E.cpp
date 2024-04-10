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
#define Se second
#define Fi first

ll mypow(ll a, ll b) {
	ll rv = 1;
	while (b) {
		if (b % 2) rv = rv*a%MOD;
		a = a*a%MOD;
		b /= 2;
	}
	return rv;
}
ll mul_inv(ll a) {
	return mypow(a, MOD - 2);
}

vector <pii> readinput(int N) {
	vector <pii> Vu;
	while (N--) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		Vu.emplace_back(t1, t2);
	}
	sort(all(Vu));
	reverse(all(Vu));

	vector <pii> Vr;
	int mn = INF;
	for (auto it : Vu) {
		if (it.second >= mn) continue;
		Vr.push_back(it);
		mn = min(mn, it.second);
	}
	reverse(all(Vr));
	return Vr;
}

ll dp[2][200050];
ll sum1[2][200050];
ll sum2[2][200050];

vector <pair<pii, int>> Vt;

pair<pii, int> in[200050];
int getpos(int a) {
	int st = 1, en = Vt.size(), mi, rv = 0;
	while (st <= en) {
		mi = (st + en) / 2;
		if (in[mi].first.second <= a) {
			rv = mi;
			st = mi + 1;
		}
		else en = mi - 1;
	}
	return rv;
}
int main() {
	int K, N, M, i, j;
	scanf("%d %d %d", &K, &N, &M);
	vector <pii> Vin[2];
	Vin[0] = readinput(N);
	Vin[1] = readinput(M);
	N = Vin[0].size(), M = Vin[1].size();
	for (auto it : Vin[0]) Vt.emplace_back(it, 0);
	for (auto it : Vin[1]) Vt.emplace_back(it, 1);
	sort(all(Vt), [](auto a, auto b) {
		return a.first.second < b.first.second;
	});

	N = Vt.size();
	for (i = 0; i < N; i++) in[i + 1] = Vt[i];

	for (i = 1; i <= N; i++) {
		int st = in[i].first.first, en = in[i].first.second, x = in[i].second;
		int p = getpos(in[i].first.first - 1);

		dp[x][i] = -mypow(2, K - (en - st + 1));
		dp[x][i] -= (sum1[0][p] + sum1[1][p]) * mypow(mul_inv(2), en - st + 1) % MOD;
		dp[x][i] -= (sum2[x][i - 1] - sum2[x][p]) * mypow(mul_inv(2), en) % MOD;
		dp[x][i] = (dp[x][i] % MOD + MOD) % MOD;

		for (j = 0; j < 2; j++) {
			sum1[j][i] = (sum1[j][i - 1] + dp[j][i]) % MOD;
			sum2[j][i] = (sum2[j][i - 1] + dp[j][i] * mypow(2, en)) % MOD;
		}
	}

	ll ans = mypow(2, K);
	for (int i = 1; i <= N; i++) ans = (ans + dp[0][i] + dp[1][i]) % MOD;
	return !printf("%lld\n", ans);
}