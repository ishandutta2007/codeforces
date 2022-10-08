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

int IT_MAX = 1 << 20;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1E-11;

int in[100050][2];
int par[100050][20];
int dep[100050];
vector <int> son[100050];
int sz[100050];
void DFS(int n) {
	sz[n] = 1;
	for (auto it : son[n]) {
		par[it][0] = n;
		dep[it] = dep[n] + 1;
		for (int i = 1; i < 20; i++) par[it][i] = par[par[it][i - 1]][i - 1];
		DFS(it);
		sz[n] += sz[it];
	}
}
int lca(int a, int b) {
	if (dep[a] > dep[b]) swap(a, b);
	int c = dep[b] - dep[a];
	for (int i = 0; i < 20; i++) if (c & (1 << i)) b = par[b][i];

	if (a == b) return a;
	for (int i = 19; i >= 0; i--) {
		if (par[a][i] != par[b][i]) {
			a = par[a][i];
			b = par[b][i];
		}
	}
	return par[a][0];
}

int u[100050];
int main() {
	int N, M, K, Q, i;
	scanf("%d %d %d %d", &N, &M, &K, &Q);
	for (i = 1; i <= K; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		par[t1][0] = u[t2];
		u[t2] = t1;

		in[i][0] = t1, in[i][1] = t2;
	}

	for (i = 1; i <= M; i++) u[i] = 0;
	for (i = K; i >= 1; i--) if (!u[in[i][1]]) u[in[i][1]] = in[i][0];
	for (i = 1; i <= N; i++) son[par[i][0]].push_back(i);
	DFS(0);

	while (Q--) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		t2 = u[t2];
		if (lca(t1, t2) == t1) printf("%d\n", sz[t1]);
		else printf("0\n");
	}
	return 0;
}