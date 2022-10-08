//*
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
#include <time.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>

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

int IT_MAX = 1024;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

vector <int> son[300050];
int par[300050];
int stot[300050];
pii smx[300050];
int dep[300050];

int par2[300050][20];
void DFS(int n) {
	stot[n] = 1;
	for (auto it : son[n]) {
		dep[it] = dep[n] + 1;
		par2[it][0] = n;
		for (int i = 1; i <= 19; i++) par2[it][i] = par2[par2[it][i - 1]][i - 1];
		DFS(it);
		stot[n] += stot[it];
	
		smx[n] = max(smx[n], pii(stot[it], it));
	}
}

int ans[300050];
bool isValid(int x, int y) {
	if (dep[x] > dep[y]) return false;

	int t = dep[y] - dep[x];
	for (int i = 19; i >= 0; i--) if (t & (1 << i)) y = par2[y][i];
	return x == y;
}
void DFS2(int n) {
	if (n == 1) ans[n] = 1;
	else ans[n] = (!isValid(n, ans[par[n]]))? n : ans[par[n]];

	while (1) {
		if (smx[ans[n]].first * 2 <= stot[n]) break;
		else ans[n] = smx[ans[n]].second;
	}
	for (auto it : son[n]) DFS2(it);
}
int main() {
	srand(time(0));
	int N, Q, i, t;
	scanf("%d %d", &N, &Q);
	for (i = 2; i <= N; i++) {
		scanf("%d", &par[i]);
		son[par[i]].push_back(i);
	}
	for (i = 0; i < 20; i++) par2[1][i] = 1;
	DFS(1);

	DFS2(1);

	while (Q--) {
		scanf("%d", &t);
		printf("%d\n", ans[t]);
	}
	return 0;
}