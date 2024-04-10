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

vector <ll> Vb;
class Node {
public:
	ll cnt[5];
	int v = 0;
	Node() {
		memset(cnt, 0, sizeof(cnt));
	}
	Node operator + (const Node &l) const {
		Node rv;
		for (int i = 0; i <= 4; i++) rv.cnt[i] = cnt[i] + l.cnt[i];
		rv.v = 0;
		return rv;
	}
	void update(int x) {
		ll u[5] = { 0,0,0,0,0 };
		for (int i = 0; i < 5; i++) if (i + x >= 0 && i + x < 5) u[i + x] = cnt[i];
		for (int i = 0; i < 5; i++) cnt[i] = u[i];
	}
};
Node indt[600000];

ll u[5];
void propagate(int n) {
	int v = indt[n].v;
	indt[2 * n].v += v;
	indt[2 * n].update(v);
	indt[2 * n + 1].v += v;
	indt[2 * n + 1].update(v);
	indt[n].v = 0;
}
void update(ll st, ll en, int S, int E, int n, int v) {
	if (S == 1 && E == IT_MAX) {
		st = lower_bound(all(Vb), st) - Vb.begin() + 1;
		en = lower_bound(all(Vb), en) - Vb.begin();
	}
	if (en < S || E < st) return;
	if (st <= S && E <= en) {
		indt[n].update(v);
		indt[n].v += v;
		return;
	}
	propagate(n);

	int M = (S + E) / 2;
	update(st, en, S, M, 2 * n, v);
	update(st, en, M + 1, E, 2 * n + 1, v);
	indt[n] = indt[2 * n] + indt[2 * n + 1];
}
ll getcnt(ll st, ll en, int S, int E, int n, int v) {
	if (S == 1 && E == IT_MAX) {
		st = lower_bound(all(Vb), st) - Vb.begin() + 1;
		en = lower_bound(all(Vb), en) - Vb.begin();
	}
	if (en < S || E < st) return 0;
	if (st <= S && E <= en) return indt[n].cnt[v];
	propagate(n);

	int M = (S + E) / 2;
	return getcnt(st, en, S, M, 2 * n, v) + getcnt(st, en, M + 1, E, 2 * n + 1, v);
}

ll getcnt(ll a, ll b) {
	if (a % 2 == 0) a++;
	if (b % 2 == 0) b--;
	return (b + 1) / 2 - (a + 1) / 2 + 1;
}
vector <pii> Vq;

pii in[100050];
int mn[2][100050];
int mx[2][100050];
ll getans(vector <pii> Vin) {
	if (Vin.empty()) return 0;
	int N = Vin.size(), i, j;
	for (i = 0; i < N; i++) in[i] = pii(Vin[i].first + Vin[i].second, Vin[i].first - Vin[i].second);
	sort(in, in + N);

	Vb.push_back(-LL_INF);
	for (i = 0; i < N; i++) {
		Vb.push_back(in[i].second);
		Vb.push_back(in[i].second + 1);
	}
	Vb.push_back(LL_INF);
	sort(all(Vb));
	Vb.erase(unique(all(Vb)), Vb.end());

	mn[0][0] = in[0].second;
	mx[0][0] = in[0].second;
	for (i = 1; i < N; i++) {
		mn[0][i] = min(mn[0][i - 1], in[i].second);
		mx[0][i] = max(mx[0][i - 1], in[i].second);
	}
	mn[1][N - 1] = in[N - 1].second;
	mx[1][N - 1] = in[N - 1].second;
	for (i = N - 2; i >= 0; i--) {
		mn[1][i] = min(mn[1][i + 1], in[i].second);
		mx[1][i] = max(mx[1][i + 1], in[i].second);
	}

	memset(indt, 0, sizeof(indt));
	for (i = 0; i + 1 < Vb.size(); i++) {
		ll t1 = Vb[i], t2 = Vb[i + 1] - 1;
		indt[IT_MAX + i].cnt[0] = getcnt(t1, t2);
	}
	for (i = IT_MAX - 1; i >= 1; i--) indt[i] = indt[2 * i] + indt[2 * i + 1];

	ll rv = 0;
	ll prv = -LL_INF;
	update(-LL_INF, mx[1][0], 1, IT_MAX, 1, 1);
	update(mn[1][0] + 1, LL_INF, 1, IT_MAX, 1, 1);
	for (i = 0; i < N; i++) {
		ll nxt = in[i].first;

		rv += getcnt(prv, nxt - 1) * indt[1].cnt[4];
		prv = nxt;
		if (i + 1 == N) break;

		update(mx[1][i + 1], mx[1][i], 1, IT_MAX, 1, -1);
		update(mn[1][i] + 1, mn[1][i + 1] + 1, 1, IT_MAX, 1, -1);
		
		if (i == 0) {
			update(-LL_INF, mx[0][i], 1, IT_MAX, 1, 1);
			update(mn[0][i] + 1, LL_INF, 1, IT_MAX, 1, 1);
		}
		else {
			update(mx[0][i - 1], mx[0][i], 1, IT_MAX, 1, 1);
			update(mn[0][i] + 1, mn[0][i - 1] + 1, 1, IT_MAX, 1, 1);
		}
	}
	return rv;
}
int main() {
	vector <pii> Vl[2];
	int N, i;
	scanf("%d", &N);
	while (N--) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		if ((t1 + t2) % 2) Vl[1].emplace_back(t1, t2);
		else Vl[0].emplace_back(t1, t2);
	}
	for (auto &it : Vl[1]) it.second--;
	
	ll ans = getans(Vl[0]) + getans(Vl[1]);
	return !printf("%lld\n", ans);
}