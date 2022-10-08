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
#pragma comment(linker, "/STACK:33554432")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple <int, int, int> t3;

int IT_MAX = 1 << 18;
const ll MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

class Node {
public:
	ll mn, v;
	Node() {
		*this = Node(0, 0);
	}
	Node(ll mn, ll v) : mn(mn), v(v) {}
};
Node indt[600000];
void propagate(int n) {
	ll v = indt[n].v;
	indt[2 * n].mn += v;
	indt[2 * n].v += v;
	indt[2 * n + 1].mn += v;
	indt[2 * n + 1].v += v;
	indt[n].v = 0;
}
void update(int st, int en, int S, int E, int n, ll v) {
	if (st > E || S > en) return;
	if (st <= S && E <= en) {
		indt[n].mn += v;
		indt[n].v += v;
		return;
	}
	propagate(n);

	int M = (S + E) / 2;
	update(st, en, S, M, 2 * n, v);
	update(st, en, M + 1, E, 2 * n + 1, v);
	indt[n].mn = min(indt[2 * n].mn, indt[2 * n + 1].mn);
}
ll getmn(int st, int en, int S, int E, int n) {
	if (st > E || S > en) return LL_INF;
	if (st <= S && E <= en) return indt[n].mn;
	propagate(n);

	int M = (S + E) / 2;
	return min(getmn(st, en, S, M, 2 * n), getmn(st, en, M + 1, E, 2 * n + 1));
}

int in[400050][3];
vector <pll> son[200050];
int par[200050][20];
int dep[200050];
int tus;
int lr[200050][2];
ll T[200050];
ll D[200050];
void DFS(int n) {
	lr[n][0] = ++tus;
	for (auto it : son[n]) {
		D[it.second] = D[n] + it.first;
		dep[it.second] = dep[n] + 1;
		par[it.second][0] = n;
		for (int i = 1; i < 20; i++) par[it.second][i] = par[par[it.second][i - 1]][i - 1];
		DFS(it.second);
	}
	lr[n][1] = tus;
}
bool isValid(int a, int b) {
	if (dep[a] > dep[b]) return false;
	int c = dep[b] - dep[a];
	for (int i = 0; i < 20; i++) if (c & (1 << i)) b = par[b][i];
	return a == b;
}
int main() {
	int N, Q, i;
	scanf("%d %d", &N, &Q);
	for (i = 1; i < N; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		son[t1].emplace_back(t3, t2);
		in[i][0] = t1, in[i][1] = t2, in[i][2] = t3;
	}
	for (i = N; i <= 2 * N - 2; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		T[t1] = t3;
		in[i][0] = t1, in[i][1] = t2, in[i][2] = t3;
	}
	for (i = 0; i < 20; i++) par[1][i] = 1;
	DFS(1);

	for (i = 1; i <= N; i++) update(lr[i][0], lr[i][0], 1, IT_MAX, 1, D[i] + T[i]);

	while (Q--) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		if (t1 == 1) {
			if (t2 < N) {
				int n = in[t2][1];
				update(lr[n][0], lr[n][1], 1, IT_MAX, 1, t3 - in[t2][2]);
				in[t2][2] = t3;
			}
			else {
				int n = in[t2][0];
				update(lr[n][0], lr[n][0], 1, IT_MAX, 1, t3 - in[t2][2]);
				in[t2][2] = t3;
				T[n] = t3;
			}
		}
		else {
			if (isValid(t2, t3)) {
				ll d1 = getmn(lr[t2][0], lr[t2][0], 1, IT_MAX, 1) - T[t2];
				ll d2 = getmn(lr[t3][0], lr[t3][0], 1, IT_MAX, 1) - T[t3];
				printf("%lld\n", d2 - d1);
			}
			else {
				ll d1 = getmn(lr[t2][0], lr[t2][1], 1, IT_MAX, 1);
				ll d2 = getmn(lr[t3][0], lr[t3][0], 1, IT_MAX, 1) - T[t3];
				ll d3 = getmn(lr[t2][0], lr[t2][0], 1, IT_MAX, 1) - T[t2];
				printf("%lld\n", d1 + d2 - d3);
			}
		}
	}
	return 0;
}