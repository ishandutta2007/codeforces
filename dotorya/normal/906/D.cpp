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
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

ll mul_inv(ll a, ll b) {
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
int mypow(int a, int b) {
	int rv = 1;
	while (b) {
		if (b % 2) rv = rv * a;
		a = a*a;
		b /= 2;
	}
	return rv;
}
ll mypow(ll a, ll b, ll m) {
	ll rv = 1;
	while (b) {
		if (b % 2) rv = (rv*a) % m;
		a = a*a%m;
		b /= 2;
	}
	return rv;
}

map <int, int> My;
map <int, map<int, int>> Mx;
vector <int> Vu;

bool pchk[40050];
vector <int> pl;

int in[100050];
int getv(int s, int e) {
	int i;
	for (i = s; i <= e && i <= s+4; i++) if (in[i] == 1) break;
	
	e = i - 1;
	if (s > e) return 1;
	if (s + 3 <= e) return INF;

	int v = in[e];
	for (i = e - 1; i >= s; i--) {
		if (pow(100, 1.0 / v) < in[i]) return INF;
		v = mypow(in[i], v);
		if (v >= 32) return INF;
	}
	return v;
}
ll aa(int s, int e, int m) {
	if (s == e) return in[s] % m;
	if (m == 1) return 0;
	if (in[s] == 1) return 1;

	int v = getv(s + 1, e);
	if (v < 32) return mypow(in[s], v, m);

	int mu = 1;
	int x = in[s];
	Vu.clear();
	for (auto it : My) Vu.push_back(it.first);
	for (auto it : Vu) {
		if (x % it) continue;
		m /= mypow(it, My[it]);
		mu *= mypow(it, My[it]);
		My.erase(it);
	}
	Vu.clear();
	if (m == 1) return 0;

	int om = m;
	for (auto it : My) Vu.push_back(it.first);
	for (auto it : Vu) {
		My[it]--;
		if (My[it] == 0) My.erase(it);
		for (auto it2 : Mx[it - 1]) My[it2.first] += it2.second;
		m /= it;
		m *= it - 1;
	}
	Vu.clear();

	ll a = mypow(x, aa(s + 1, e, m), om);
	ll t = a * mul_inv(mu, om) % om;
	return mu*t;
}
int main() {
	int N, M, i, j;

	for (i = 2; i <= 40000; i++) {
		if (pchk[i]) continue;
		pl.push_back(i);
		for (j = 2 * i; j <= 40000; j += i) pchk[j] = true;
	}

	scanf("%d %d", &N, &M);
	//N = 100000, M = 1000000000;
	Vu.push_back(M);
	Mx[M] = {};
	for (i = 0; i < Vu.size(); i++) {
		int x = Vu[i];
		for (auto it : pl) {
			if (it*it > x) break;
			if (x%it) continue;

			if (!Mx.count(it-1)) {
				Mx[it-1] = {};
				Vu.push_back(it-1);
			}
			int c = 0;
			while (x%it == 0) {
				c++;
				x /= it;
			}
			Mx[Vu[i]][it] = c;
		}
		if (x > 1) {
			if (!Mx.count(x-1)) {
				Mx[x-1] = {};
				Vu.push_back(x-1);
			}
			Mx[Vu[i]][x] = 1;
		}
	}
	//printf("clock = %d\n", clock());

	Vu.clear();
	for (i = 1; i <= N; i++) {
		scanf("%d", &in[i]);
	//	in[i] = 2;
	}
	int Q;
	scanf("%d", &Q);
	//Q = 100000;
	while (Q--) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		//t1 = 1, t2 = 100000;
		My = Mx[M];
		ll rv = aa(t1, t2, M);
		printf("%lld\n", rv);
	}
	//printf("clock = %d\n", clock());
	return 0;
}