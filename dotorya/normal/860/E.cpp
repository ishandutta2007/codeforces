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

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int dep[500050];
int par[500050][20];
vector <int> son[500050];
vector <int> Vd[500050];
void DFS1(int n) {
	Vd[dep[n]].push_back(n);
	for (auto it : son[n]) {
		dep[it] = dep[n] + 1;
		par[it][0] = n;
		for (int i = 1; i <= 19; i++) par[it][i] = par[par[it][i - 1]][i - 1];
		DFS1(it);
	}
}
int lca(int a, int b) {
	if (dep[a] > dep[b]) swap(a, b);
	int c = dep[b] - dep[a];
	for (int i = 0; i <= 19; i++) if (c & (1 << i)) b = par[b][i];
	if (a == b) return a;

	for (int i = 19; i >= 0; i--) {
		if (par[a][i] != par[b][i]) {
			a = par[a][i];
			b = par[b][i];
		}
	}
	return par[a][0];
}

ll ans[500050];

void dodo(int i) {
	int j;
	vector <pll> Vu;
	ll sum = 0;
	for (j = 1; j < Vd[i].size(); j++) {
		ll prv = j - 1;
		ll v = dep[lca(Vd[i][j - 1], Vd[i][j])];
		while (!Vu.empty()) {
			pll u = Vu.back();
			if (u.first >= v) {
				sum -= (prv - u.second) * u.first;
				prv = u.second;
				Vu.pop_back();
			}
			else break;
		}
		sum += (j - prv) * v;
		Vu.emplace_back(v, prv);
		ans[Vd[i][j]] += sum;
	}
}
int main() {
	int N, i, j, r = 0;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		int t;
		scanf("%d", &t);
		if (!t) r = i;
		else son[t].push_back(i);
	}
	dep[r] = 1;
	DFS1(r);

	int mxd = 0;
	for (i = 1; i <= N; i++) mxd = max(mxd, dep[i]);
	for (i = 2; i <= mxd; i++) {
		for (auto it : Vd[i]) {
			ans[it] = ans[par[it][0]];
			ans[it] += dep[it] - 1;
		}

		if (Vd[i].size() < 2) continue;
		dodo(i);
		reverse(all(Vd[i]));
		dodo(i);
	}
	for (i = 1; i <= N; i++) printf("%lld ", ans[i]);
	return !printf("\n");
}