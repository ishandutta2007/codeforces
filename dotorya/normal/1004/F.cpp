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
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

class Node {
public:
	ll sum;
	ll v;
	Node() {
		*this = Node(0, 0);
	}
	Node(ll sum, ll v) : sum(sum), v(v) {}
};
Node indt[300000];
void propagate(int n, ll sz) {
	if (indt[n].v == 0) return;

	indt[2 * n].sum = (sz / 2) * indt[n].v;
	indt[2 * n].v = indt[n].v;
	indt[2 * n + 1].sum = (sz / 2) * indt[n].v;
	indt[2 * n + 1].v = indt[n].v;
	indt[n].v = 0;
}
void update(int st, int en, int S, int E, int n, ll v) {
	if (en < S || E < st) return;
	if (st <= S && E <= en) {
		indt[n].v = v;
		indt[n].sum = (E - S + 1) * v;
		return;
	}
	propagate(n, E - S + 1);

	int M = (S + E) / 2;
	update(st, en, S, M, 2 * n, v);
	update(st, en, M + 1, E, 2 * n + 1, v);
	indt[n].sum = indt[2 * n].sum + indt[2 * n + 1].sum;
}
ll getsum(int st, int en, int S, int E, int n) {
	if (en < S || E < st) return 0;
	if (st <= S && E <= en) return indt[n].sum;
	propagate(n, E - S + 1);

	int M = (S + E) / 2;
	return getsum(st, en, S, M, 2 * n) + getsum(st, en, M + 1, E, 2 * n + 1);
}

int N, M, X;
ll ans = 0;
set <int> Sp[20];
int in[100050];
void myupdate(int p, int v) {
	vector <pii> Vl1;
	vector <pii> Vl2;

	int i;
	for (i = 0; i < 20; i++) if (in[p] & (1 << i)) Sp[i].erase(p);
	in[p] = v;
	for (i = 0; i < 20; i++) if (in[p] & (1 << i)) Sp[i].insert(p);

	int s = 1, e = p - 1, m, r = p;
	while (s <= e) {
		m = (s + e) / 2;
		if (getsum(m, m, 1, IT_MAX, 1) >= p) {
			r = m;
			e = m - 1;
		}
		else s = m + 1;
	}

	int cur1 = 0, cur2 = 0;
	for (i = 0; i < 20; i++) {
		auto it = Sp[i].lower_bound(p + 1);
		if (it == Sp[i].begin()) continue;
		it--;
		if (*it < r) continue;
		Vl1.emplace_back(*it, i);
		cur1 ^= 1 << i;
	}
	for (i = 0; i < 20; i++) {
		auto it = Sp[i].lower_bound(p);
		if (it == Sp[i].end()) continue;
		Vl2.emplace_back(*it, i);
	}
	Vl1.emplace_back(r-1, -1);
	sort(all(Vl1));
	sort(all(Vl2));

	int ans = p, p2 = 0;
	for (i = 0; i < Vl1.size(); i++) {
		int st = Vl1[i].first + 1;
		int en = (i+1 == Vl1.size())? p : Vl1[i + 1].first;
		while ((cur1 | cur2) < X) {
			if (p2 == Vl2.size()) {
				update(st, p, 1, IT_MAX, 1, N + 1);
				return;
			}
			ans = Vl2[p2].first;
			cur2 |= 1 << Vl2[p2].second;
			p2++;
		}
		update(st, en, 1, IT_MAX, 1, ans);
		if(i + 1 != Vl1.size()) cur1 ^= 1 << Vl1[i + 1].second;
	}
}
int main() {
	int i, j, k;
	scanf("%d %d %d", &N, &M, &X);
	if (X == 0) {
		for (i = 1; i <= N; i++) scanf("%d", &j);
		while (M--) {
			int t1, t2, t3;
			scanf("%d %d %d", &t1, &t2, &t3);
			if (t1 == 2) printf("%lld\n", (ll)N*(N + 1) / 2);
		}
		return 0;
	}

	update(1, N, 1, IT_MAX, 1, N + 1);
	for (i = 1; i <= N; i++) {
		int t;
		scanf("%d", &t);
		myupdate(i, t);
	}
	while (M--) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		if (t1 == 1) myupdate(t2, t3);
		else {
			int st = t2, en = t3, mi, rv = t2 - 1;
			while (st <= en) {
				mi = (st + en) / 2;
				if (getsum(mi, mi, 1, IT_MAX, 1) <= t3) {
					rv = mi;
					st = mi + 1;
				}
				else en = mi - 1;
			}

			ll ans = 0;
			if (rv != t2 - 1) ans = (ll)(rv - t2 + 1) * (t3 + 1) - getsum(t2, rv, 1, IT_MAX, 1);
			printf("%lld\n", ans);
		}
	}
	return 0;
}