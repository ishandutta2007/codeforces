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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-8;

vector <pii> conn[300050];

vector <pair<pii, int>> Ex;
vector <pair<pii, int>> Eb;
int dep[300050];
int low[300050];
int par[300050];
bool dchk[300050];

int r[300050];
int root(int x) {
	return (r[x] == x) ? x : (r[x] = root(r[x]));
}
void DFS(int n) {
	low[n] = dep[n];
	dchk[n] = true;

	for (auto it : conn[n]) {
		if (it.first == par[n]) continue;
		if (dchk[it.first]) {
			low[n] = min(low[n], dep[it.first]);
			Ex.push_back(mp(pii(it.first, n), it.second));
		}
		else {
			dep[it.first] = dep[n] + 1;
			par[it.first] = n;
			DFS(it.first);
			if (low[it.first] > dep[n]) Eb.push_back(mp(pii(it.first, n), it.second));
			else Ex.push_back(mp(pii(it.first, n), it.second));
			low[n] = min(low[n], low[it.first]);
		}
	}
}
int glist[300050];
int gchk[300050];
vector <pii> gconn[300050];

bool gdchk[300050];
bool achk[300050];
int rev[300050];
vector <int> V;
int main() {
	int N, M, i, t1, t2, t3, st, en;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++) {
		scanf("%d %d %d", &t1, &t2, &t3);
		conn[t1].push_back(pii(t2, t3));
		conn[t2].push_back(pii(t1, t3));
	}
	scanf("%d %d", &st, &en);

	for (i = 1; i <= N; i++) r[i] = i;
	for (i = 1; i <= N; i++) if (!dchk[i]) DFS(i);

	for (auto it : Ex) {
		t1 = root(it.first.first);
		t2 = root(it.first.second);
		if (t1 != t2) r[t1] = t2;
	}
	for (auto it : Ex) if (it.second == 1) gchk[root(it.first.first)] = true;

	for (auto it : Eb) {
		it.first.first = root(it.first.first);
		it.first.second = root(it.first.second);
		gconn[it.first.first].push_back(pii(it.first.second, it.second));
		gconn[it.first.second].push_back(pii(it.first.first, it.second));
	}

	st = root(st), en = root(en);
	
	gdchk[st] = true;
	if (gchk[st]) achk[st] = true;
	V.push_back(st);
	for (i = 0; i < V.size(); i++) {
		for (auto it : gconn[V[i]]) {
			if (!gdchk[it.first]) {
				gdchk[it.first] = true;
				if (achk[V[i]] || gchk[it.first] || it.second) achk[it.first] = true;
				V.push_back(it.first);
			}
		}
	}

	if (achk[en]) printf("YES\n");
	else printf("NO\n");
	return 0;
}