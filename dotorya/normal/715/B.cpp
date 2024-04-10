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
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-11;

class edge {
public:
	int s, e;
	ll d;
	edge() {
		*this = edge(0, 0, 0);
	}
	edge(int s, int e, ll d) : s(s), e(e), d(d) {}
};
vector <edge> E;
vector <int> conn[1050];
void epush(int s, int e, int d) {
	conn[s].push_back(E.size());
	conn[e].push_back(E.size());
	E.emplace_back(s, e, d);
}
vector <int> V;

int N;
ll dis[1050];
priority_queue <pll, vector<pll>, greater<pll>> H;
ll getdis(int st, int en) {
	fill(dis, dis + N, LL_INF);
	dis[st] = 0;
	H.emplace(0, st);
	while (!H.empty()) {
		pll u = H.top();
		H.pop();

		if (u.first > dis[u.second]) continue;
		for (auto it : conn[u.second]) {
			pll u2 = pll(u.first + E[it].d, E[it].s + E[it].e - u.second);
			if (dis[u2.second] > u2.first) {
				dis[u2.second] = u2.first;
				H.push(u2);
			}
		}
	}
	return dis[en];
}
int main() {
	int M, L, ST, EN, t1, t2, t3, i, j;
	scanf("%d %d %d %d %d", &N, &M, &L, &ST, &EN);
	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &t1, &t2, &t3);
		epush(t1, t2, t3);
		if (t3 == 0) V.push_back(i);
	}
	if (V.size() == 0) {
		if (getdis(ST, EN) != L) return !printf("NO\n");
		printf("YES\n");
		for (auto it : E) printf("%d %d %lld\n", it.s, it.e, it.d);
		return 0;
	}
	
	ll st = 0, en = (ll)(V.size()) * INF, mi, rv = en;
	while (st <= en) {
		mi = (st + en) / 2;
		for (i = 0; i < V.size(); i++) {
			if (i < mi % (ll)V.size()) E[V[i]].d = mi / (ll)V.size() + 2;
			else E[V[i]].d = mi / (ll)V.size() + 1;
		}
		if (getdis(ST, EN) >= L) {
			rv = mi;
			en = mi - 1;
		}
		else st = mi + 1;
	}
	mi = rv;
	for (i = 0; i < V.size(); i++) {
		if (i < mi % (ll)V.size()) E[V[i]].d = mi / (ll)V.size() + 2;
		else E[V[i]].d = mi / (ll)V.size() + 1;
	}

	if (getdis(ST, EN) != L) return !printf("NO\n");
	printf("YES\n");
	for (auto it : E) printf("%d %d %lld\n", it.s, it.e, it.d);
	return 0;
}