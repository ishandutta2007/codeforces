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

int IT_MAX = 1 << 20;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-9;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

ll seed, vmax;
ll rnd() {
	ll rv = seed;
	seed = (seed * 7 + 13) % 1000000007;
	return rv;
}

set <pll> Sx;
ll getv(ll x) {
	auto it = Sx.lower_bound(pll(x + 1, -1));
	it--;
	return it->second;
}

ll mypow(ll a, ll b, ll m) {
	a %= m;
	ll rv = 1 % m;
	while (b) {
		if (b % 2) rv = (rv * a) % m;
		a = (a*a) % m;
		b /= 2;
	}
	return rv;
}
int main() {
	ll N, M, i;
	scanf("%lld %lld %lld %lld", &N, &M, &seed, &vmax);
	for (i = 1; i <= N; i++) {
		ll t = rnd() % vmax + 1;
		Sx.emplace(i, t);
	}

	vector <pll> Vu;
	vector <pll> Vu2;
	for (i = 1; i <= M; i++) {
		ll op = rnd() % 4 + 1;
		ll L = rnd() % N + 1;
		ll R = rnd() % N + 1;
		if (L > R) swap(L, R);

		ll X, Y;
		if (op == 3) X = rnd() % (R - L + 1) + 1;
		else X = rnd() % vmax + 1;

		if (op == 4) Y = rnd() % vmax + 1;

		//printf("%lld %lld %lld %lld ", op, L, R, X);
		//if (op == 4) printf("%lld\n", Y);
		//else printf("\n");

		Vu.clear();
		ll v1 = getv(L), v2 = getv(R + 1);
		Sx.emplace(L, v1);
		if (R != N) Sx.emplace(R + 1, v2);
		while (1) {
			auto it = Sx.lower_bound(pll(L, 0));
			if (it == Sx.end() || it->first > R) break;
			Vu.push_back(*it);
			Sx.erase(it);
		}
		if (op == 1) {
			for (auto it : Vu) Sx.emplace(it.first, it.second + X);
		}
		else if (op == 2) {
			Sx.emplace(L, X);
		}
		else if (op == 3) {
			for (auto it : Vu) Sx.insert(it);

			Vu.emplace_back(R + 1, 0);
			Vu2.clear();
			for (int i = 0; i + 1 < Vu.size(); i++) Vu2.emplace_back(Vu[i].second, Vu[i + 1].first - Vu[i].first);
			sort(all(Vu2));

			for (auto it : Vu2) {
				if (it.second >= X) {
					printf("%lld\n", it.first);
					break;
				}
				else X -= it.second;
			}
		}
		else if (op == 4) {
			for (auto it : Vu) Sx.insert(it);

			Vu.emplace_back(R + 1, 0);
			Vu2.clear();
			for (int i = 0; i + 1 < Vu.size(); i++) Vu2.emplace_back(Vu[i].second, Vu[i + 1].first - Vu[i].first);

			ll ans = 0;
			for (auto it : Vu2) ans = (ans + mypow(it.first, X, Y) * it.second) % Y;
			printf("%lld\n", ans);
		}
	}
	return 0;
}