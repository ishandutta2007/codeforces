//*
#include <algorithm>
#include <ctype.h>
#include <functional>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <char, int> pci;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;

int uedge[100050];
int dep[100050];
bool echk[100050];
bool chk[100050];
pii in[100050];
vector <pii> conn[100050];
int par[100050][18];
int delta[100050];
int cnt[100050];
int po2[1000050];


void DFS(int n) {
	chk[n] = true;
	for (int i = 0; i < conn[n].size(); i++) {
		int t = conn[n][i].first;
		if (chk[t]) continue;

		dep[t] = dep[n] + 1;
		par[t][0] = n;
		for (int j = 1; j < 18; j++) par[t][j] = par[par[t][j - 1]][j - 1];
		uedge[t] = conn[n][i].second;
		DFS(t);
	}
}

int upe(int x, int y) {
	for (int i = 0; i < 18; i++) if (y & (1 << i)) x = par[x][i];
	return x;
}
int lca(int a, int b) {
	if (dep[a] > dep[b]) swap(a, b);
	b = upe(b, dep[b] - dep[a]);
	if (a == b) return a;
	for (int i = 17; i >= 0; i--) {
		if (par[a][i] != par[b][i]) {
			a = par[a][i];
			b = par[b][i];
		}
	}
	return par[a][0];
}

void DFS2(int n) {
	chk[n] = true;
	for (int i = 0; i < conn[n].size(); i++) {
		int t = conn[n][i].first;
		if (chk[t]) continue;
		DFS2(t);
	}
	cnt[n] = delta[n];
	delta[par[n][0]] += delta[n];
}
int main() {
	int N, K, i, t1, t2, t3;
	scanf("%d", &N);
	for (i = 1; i < N; i++) {
		scanf("%d %d %d", &t1, &t2, &t3);
		conn[t1].push_back(pii(t2, i));
		conn[t2].push_back(pii(t1, i));
		echk[i] = t3;
		in[i] = pii(t1, t2);
	}

	for (i = 0; i < 18; i++) par[1][i] = 1;
	dep[1] = 0;
	DFS(1);

	t1 = 1;
	scanf("%d", &K);
	for (i = 1; i <= K; i++) {
		scanf("%d", &t2);
		t3 = lca(t1, t2);
		if (t1 == t2) continue;

		delta[t3] -= 2;
		delta[t1]++;
		delta[t2]++;
		t1 = t2;
	}

	fill(chk + 1, chk + N + 1, false);
	DFS2(1);

	po2[0] = 1;
	for (i = 1; i <= K+1; i++) po2[i] = (po2[i - 1] * 2) % MOD;
	ll ans = 0;

	for (i = 2; i <= N; i++) {
		t1 = uedge[i];
		if (!echk[t1]) continue;
		t2 = cnt[i] / 2;
		if (cnt[i] % 2 == 1 && in[t1].first == i) t2++;
		ans = ((ans + po2[t2]-1) % MOD + MOD)%MOD;
	}
	printf("%I64d", (ans+MOD)%MOD);
	return 0;
}
//*/