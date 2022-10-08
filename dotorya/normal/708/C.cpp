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

int ans[400050];

vector <int> conn[400050];

vector <int> son[400050];
int sz[400050];
int par[400050];
int gpar[400050];
void DFS(int n) {
	for (auto it : conn[n]) {
		if (it == par[n]) continue;
		par[it] = n;
		son[n].push_back(it);
		DFS(it);
		sz[n] += sz[it];
	}
	sz[n]++;
}

vector <int> V;
int main() {
	int N, i, t1, t2;
	scanf("%d", &N);
	for (i = 1; i < N; i++) {
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}
	DFS(1);

	int n = 1;
	while (1) {
		t1 = 0, t2 = -1;
		for (auto it : son[n]) {
			if (t1 < sz[it]) {
				t1 = sz[it];
				t2 = it;
			}
		}
		if (t1 <= N / 2) break;
		n = t2;
	}
	ans[n] = 1;

	for (i = 1; i <= N; i++) {
		son[i].clear();
		par[i] = 0;
		sz[i] = 0;
	}
	DFS(n);

	V.push_back(n);
	for (i = 0; i < V.size(); i++) {
		if (V[i] != n && par[V[i]] != n) gpar[V[i]] = gpar[par[V[i]]];
		else gpar[V[i]] = V[i];
		for (auto it : son[V[i]]) V.push_back(it);
	}
	V.clear();

	int mx1 = 0, mx2 = 0;
	for (auto it : son[n]) {
		if (sz[it] > sz[mx2]) mx2 = it;
		if (sz[mx1] < sz[mx2]) swap(mx1, mx2);
	}
	for (i = 1; i <= N; i++) {
		if (i == n) continue;

		t1 = gpar[i];
		ans[i] = 0;
		if (N - sz[t1] <= N / 2) ans[i] = 1;

		if (mx1 != 0 && mx1 != t1 && N - sz[i] - sz[mx1] <= N / 2) ans[i] = 1;
		if (mx2 != 0 && mx2 != t1 && N - sz[i] - sz[mx2] <= N / 2) ans[i] = 1;
	}
	for (i = 1; i <= N; i++) printf("%d ", ans[i]);
	return !printf("\n");
}