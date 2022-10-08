#include <algorithm>
#include <assert.h>
#include <bitset>
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
#include <cmath>
#include <vector>
#include <deque>
//#include <unordered_set>
#include <unordered_map>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
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

int IT_MAX = 1 << 20;
const ll MOD = 98765431;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-6;

set <int> Sx;
vector <pii> Vu;
map <pii, int> Mx;

vector <int> Vp[100050];
vector <int> Ve[100050];
set <int> conn[100050];
int u[100050];
int ans[100050];

vector <int> Vaa[1000050];
int aacnt = 0;

vector <int> son[100050];
int sz[100050];
bool dchk[100050];
vector <int> Vv;
void DFS(int n) {
	dchk[n] = true;
	Vv.push_back(n);
	sz[n] = 1;
	for (auto it : conn[n]) {
		if (dchk[it]) continue;
		son[n].push_back(it);
		DFS(it);
		sz[n] += sz[it];
	}
}
int aa(int c, int n, int lvl) {
	aacnt++;
	DFS(n);

	int S = Vv.size();
	int cv = n;
	while (!son[cv].empty()) {
		int mx = 0;
		for (int i = 1; i < son[cv].size(); i++) if (sz[son[cv][i]] > sz[son[cv][mx]]) mx = i;
		if (sz[son[cv][mx]] * 2 <= S) break;
		cv = son[cv][mx];
	}
	ans[cv] = lvl;
	for (auto it : conn[cv]) {
		conn[it].erase(cv);
		Vaa[aacnt].push_back(it);
	}
	conn[cv].clear();
	for (auto it : Vv) {
		son[it].clear();
		dchk[it] = false;
		sz[it] = 0;
	}
	Vv.clear();

	int tu = aacnt;
	for (auto it : Vaa[tu]) aa(c, it, lvl + 1);
}
int main() {
	int N, M, i, j, t1, t2;
	scanf("%d %d", &N, &M);
	for(i = 1; i <= M; i++) {
		scanf("%d %d", &t1, &t2);
		if (t1 > t2) swap(t1, t2);
		Vu.emplace_back(t1, t2);
		Mx[pii(t1, t2)] = i;
	}
	sort(Vu.begin(), Vu.end(), [](pii a, pii b) {
		if (a.second != b.second) return a.second < b.second;
		return a.first > b.first;
	});
	Vu.emplace_back(1, N);
	for (i = 1; i <= N; i++) Sx.insert(i);
	int c = 0;
	for (auto it : Vu) {
		t1 = it.first, t2 = it.second;
		c++;
		Vp[c].push_back(t1);
		while (1) {
			auto it = Sx.lower_bound(t1 + 1);
			if (*it == t2) break;
			Vp[c].push_back(*it);
			Sx.erase(it);
		}
		Vp[c].push_back(t2);
	}
	
	for (i = 1; i <= c; i++) {
		for (j = 0; j + 1 < Vp[i].size(); j++) {
			t1 = Vp[i][j], t2 = Vp[i][j + 1];
			if (Mx.count(pii(t1, t2))) Ve[Mx[pii(t1, t2)]].push_back(i);
		}
		t1 = Vp[i][0], t2 = Vp[i].back();
		if (Mx.count(pii(t1, t2))) Ve[Mx[pii(t1, t2)]].push_back(i);
		reverse(Vp[i].begin(), Vp[i].end());
	}
	for (i = 1; i <= M; i++) {
		t1 = Ve[i][0], t2 = Ve[i][1];
		conn[t1].insert(t2);
		conn[t2].insert(t1);
	}
	
	aa(c, 1, 1);

	for (i = 1; i <= c; i++) u[i] = i;
	sort(u + 1, u + c + 1, [](int a, int b) {
		for (int i = 0; i < Vp[a].size() && i < Vp[b].size(); i++) {
			if (Vp[a][i] != Vp[b][i]) return Vp[a][i] < Vp[b][i];
		}
		return false;
	});

	for (i = 1; i <= c; i++) printf("%d ", ans[u[i]]);
	return 0;
}