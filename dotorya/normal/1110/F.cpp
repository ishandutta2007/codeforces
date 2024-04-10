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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

class Node {
public:
	ll mn, v;
	Node() {
		mn = 0, v = 0;
	}
};
Node indt[1100000];
void propagate(int n) {
	ll v = indt[n].v;
	indt[2 * n].mn += v;
	indt[2 * n].v += v;
	indt[2 * n + 1].mn += v;
	indt[2 * n + 1].v += v;
	indt[n].v = 0;
}
void update(int st, int en, int S, int E, int n, ll v) {
	if (en < S || E < st) return;
	if (st <= S && E <= en) {
		indt[n].v += v;
		indt[n].mn += v;
		return;
	}

	propagate(n);
	int M = (S + E) / 2;
	update(st, en, S, M, 2 * n, v);
	update(st, en, M + 1, E, 2 * n + 1, v);
	indt[n].mn = min(indt[2 * n].mn, indt[2 * n + 1].mn);
}
ll getmn(int st, int en, int S, int E, int n) {
	if (en < S || E < st) return LL_INF;
	if (st <= S && E <= en) return indt[n].mn;

	propagate(n);
	int M = (S + E) / 2;
	return min(getmn(st, en, S, M, 2 * n), getmn(st, en, M + 1, E, 2 * n + 1));
}

vector <int> Vq[500050];
ll ans[500050];

vector <pll> son[500050];
ll dep[500050];

int Qu[500050][3];

int lr[500050][2];
int tus;
void DFS1(int n) {
	lr[n][0] = ++tus;
	for (auto it : son[n]) DFS1(it.second);
	lr[n][1] = tus;
}

void DFS2(int n) {
	for (auto it : Vq[n]) {
		int st = Qu[it][1], en = Qu[it][2];
		ans[it] = getmn(st, en, 1, IT_MAX, 1) + dep[n];
	}

	for (auto it : son[n]) {
		update(lr[it.second][0], lr[it.second][1], 1, IT_MAX, 1, -2 * it.first);
		DFS2(it.second);
		update(lr[it.second][0], lr[it.second][1], 1, IT_MAX, 1, 2 * it.first);
	}
}
int main() {
	int N, Q, i, j;
	scanf("%d %d", &N, &Q);
	for (i = 2; i <= N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		dep[i] = dep[t1] + t2;
		son[t1].emplace_back(t2, i);
	}
	
	for (i = 1; i <= Q; i++) {
		scanf("%d %d %d", &Qu[i][0], &Qu[i][1], &Qu[i][2]);
		Vq[Qu[i][0]].push_back(i);
	}
	for (i = 1; i <= N; i++) {
		if (son[i].size()) update(i, i, 1, IT_MAX, 1, LL_INF);
		else update(i, i, 1, IT_MAX, 1, dep[i]);
	}
	DFS1(1);
	DFS2(1);
	for (i = 1; i <= Q; i++) printf("%lld\n", ans[i]);
	return 0;
}