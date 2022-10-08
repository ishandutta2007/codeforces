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
#pragma comment(linker, "/STACK:1048576")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

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
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

vector <int> conn[100050];
vector <int> son[100050];
int par[100050][20];
int dep[100050];
bool dchk[100050];
void DFS(int n) {
	dchk[n] = true;
	for (auto it : conn[n]) {
		if (dchk[it]) continue;
		par[it][0] = n;
		for (int i = 1; i < 20; i++) par[it][i] = par[par[it][i - 1]][i - 1];
		dep[it] = dep[n] + 1;
		son[n].push_back(it);
		DFS(it);
	}
}
int upnode(int a, int x) {
	for (int i = 19; i >= 0; i--) if (x & (1 << i)) a = par[a][i];
	return a;
}
int lca(int a, int b) {
	if (dep[a] > dep[b]) swap(a, b);
	int c = dep[b] - dep[a];
	for (int i = 19; i >= 0; i--) if (c & (1 << i)) b = par[b][i];
	if (a == b) return a;

	for (int i = 19; i >= 0; i--) {
		if (par[a][i] != par[b][i]) {
			a = par[a][i];
			b = par[b][i];
		}
	}
	return par[a][0];
}
int getdis(int s, int f) {
	return dep[s] + dep[f] - 2*dep[lca(s, f)];
}
int gonode(int a, int b, int x) {
	int c = lca(a, b);
	if (dep[a] - dep[c] >= x) return upnode(a, x);
	x -= dep[a] - dep[c];
	return upnode(b, dep[b] - dep[c] - x);
}
int getans(int s, int f, int t) {
	int st = 1, en = 100000, mi, rv = 0;
	en = min(en, getdis(s, f));
	en = min(en, getdis(t, f));
	while (st <= en) {
		mi = (st + en) / 2;
		if (gonode(f, s, mi) == gonode(f, t, mi)) {
			rv = mi;
			st = mi + 1;
		}
		else en = mi - 1;
	}
	return rv + 1;
}
int main() {
	int N, Q, i, j;
	scanf("%d %d", &N, &Q);
	for (i = 2; i <= N; i++) {
		scanf("%d", &j);
		conn[j].push_back(i);
		conn[i].push_back(j);
	}
	for (i = 0; i < 20; i++) par[1][i] = 1;
	DFS(1);

	while (Q--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		int ans = 0;
		ans = max(ans, getans(a, b, c));
		ans = max(ans, getans(a, c, b));
		ans = max(ans, getans(b, a, c));
		printf("%d\n", ans);
	}
	return 0;
}