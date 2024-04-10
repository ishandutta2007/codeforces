#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <vector>
//#include <unordered_set>
//#include <unordered_map>

#pragma warning(disable:4996)
using namespace std;

#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;

int IT_MAX = 262144;
const int MOD = 1000003;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-11;

class edge {
public:
	ll s, e, f, c;
	edge() {
		*this = edge(0, 0, 0, 0);
	}
	edge(ll s, ll e, ll f, ll c) : s(s), e(e), f(f), c(c) {}
};
vector <edge> E;
vector <int> conn[100050];
void epush(ll s, ll e, ll f, ll c) {
	if (f == 0) return;
	conn[s].push_back(E.size());
	conn[e].push_back(E.size() + 1);
	E.emplace_back(s, e, f, c);
	E.emplace_back(e, s, 0, -c);
}

ll dis[305];
int rev[305];
bool cchk[305];
bool ctchk[305];

int cnt[305];
bool chk[305];

int uchk[305];
vector <int> V;
ll BellmanFord(int N) {
	int i, j;
	fill(dis + 1, dis + N + 1, LL_INF);
	fill(rev + 1, rev + N + 1, -1);
	fill(cchk + 1, cchk + N + 1, false);

	for (i = 1; i <= N; i++) {
		if (cchk[i]) continue;
		fill(ctchk + 1, ctchk + N + 1, false);
		fill(chk + 1, chk + N + 1, false);
		fill(cnt + 1, cnt + N + 1, 0);

		int n = -1;
		V.clear();
		V.push_back(i);
		dis[i] = 0;
		chk[i] = true;
		for (j = 0; j < V.size(); j++) {
			ctchk[V[j]] = true;
			chk[V[j]] = false;
			cnt[V[j]]++;
			if (cnt[V[j]] >= 2 * N) {
				n = V[j];
				break;
			}
			for (auto it : conn[V[j]]) {
				if (cchk[E[it].e] || E[it].f == 0 || dis[E[it].e] <= dis[V[j]] + E[it].c) continue;
				dis[E[it].e] = dis[V[j]] + E[it].c;
				rev[E[it].e] = it;
				if (!chk[E[it].e]) {
					V.push_back(E[it].e);
					chk[E[it].e] = true;
				}
			}
		}
		for (j = 1; j <= N; j++) if (ctchk[j]) cchk[j] = true;
		if (n == -1) continue;

		ll rv = 0;
		ll mxf = INF;
		ll tn = n;
		
		V.clear();
		fill(uchk + 1, uchk + N + 1, 0);
		do {
			uchk[tn] = 1;
			
			tn = E[rev[tn]].s;
		} while (!uchk[tn]);
		
		n = tn;
		do {
			mxf = min(mxf, E[rev[tn]].f);
			rv += E[rev[tn]].c;
			tn = E[rev[tn]].s;
		} while (tn != n);
		rv *= mxf;

		tn = n;
		do {
			E[rev[tn]].f -= mxf;
			E[rev[tn]^1].f += mxf;
			tn = E[rev[tn]].s;
		} while (tn != n);
		return rv;
	}
	return 1;
}
int main() {
	int N, M, i, j, t1, t2, t3, t4;

	ll ans = 0;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++) {
		scanf("%d %d %d %d", &t1, &t2, &t3, &t4);

		if (t4 >= t3) {
			epush(t1, t2, t3, -1);
			epush(t1, t2, t4 - t3, 0);
			epush(t1, t2, INF, 2);
		}
		else {
			epush(t1, t2, t4, -1);
			epush(t1, t2, t3 - t4, 1);
			epush(t1, t2, INF, 2);
		}
		ans += t4;
	}
	epush(N, 1, (ll)INF * 10000, 0);

	ll t = 0;
	while ((t = BellmanFord(N)) < 0) ans += t;
	return !printf("%lld\n", ans);
}