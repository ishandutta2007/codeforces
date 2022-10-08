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

class Matrix {
public:
	ll v[3][3];
	Matrix() {
		memset(v, 0, sizeof(v));
	}
	Matrix operator * (const Matrix &l) const {
		Matrix rv = Matrix();
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					rv.v[i][j] = (rv.v[i][j] + v[i][k] * l.v[k][j]) % MOD;
				}
			}
		}
		return rv;
	}
};

Matrix mul[8][64];
ll val[3];
ll tval[3];
void updateval(ll t, ll x) {
	ll j, k, l;
	for (j = 0; j <= 61; j++) {
		if (t & (1ll << j)) {
			memset(tval, 0, sizeof(tval));
			for (k = 0; k < 3; k++) for (l = 0; l < 3; l++) tval[k] = (tval[k] + val[l] * mul[x][j].v[k][l]) % MOD;
			for (k = 0; k < 3; k++) val[k] = tval[k];
		}
	}
}

int main() {
	ll cur = 1, N, M, i, j, k, l;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 3; k++) {
				if (i & (1 << j)) continue;
				if (abs(j - k) == 2) continue;
				mul[i][0].v[j][k] = 1;
			}
		}
		for (j = 1; j <= 62; j++) mul[i][j] = mul[i][j - 1] * mul[i][j - 1];
	}

	vector <pll> Vu;
	scanf("%lld %lld", &N, &M);
	for (i = 1; i <= N; i++) {
		ll t1, t2, t3;
		scanf("%lld %lld %lld", &t1, &t2, &t3);
		Vu.emplace_back(t2, t1);
		Vu.emplace_back(t3 + 1, -t1);
	}

	sort(all(Vu));
	val[1] = 1;
	ll cnt[4] = { 0,0,0,0 };
	for (i = 0; i < Vu.size(); i++) {
		ll t = Vu[i].first - 1 - cur;
		ll x = !!cnt[1] + !!cnt[2] * 2 + !!cnt[3] * 4;
		updateval(t, x);
		cur = Vu[i].first - 1;

		if (Vu[i].second < 0) cnt[-Vu[i].second]--;
		else cnt[Vu[i].second]++;
	}
	updateval(M - cur, 0);
	return !printf("%lld\n", val[1]);
}