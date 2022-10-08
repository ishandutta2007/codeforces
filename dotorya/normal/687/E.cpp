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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

vector <int> conn[5050];
vector <int> rconn[5050];
vector <int> V;
int dis[5050][5050];

vector <int> Vs;
bool dchk[5050];
void DFS1(int n) {
	dchk[n] = true;
	for (auto it : conn[n]) if(!dchk[it]) DFS1(it);
	Vs.push_back(n);
}

int gcnt;
vector <int> glist[5050];
int G[5050];
bool outchk[5050];
void DFS2(int n, int g) {
	glist[g].push_back(n);
	G[n] = g;
	for (auto it : rconn[n]) if (G[it] == 0) DFS2(it, g);
}
int main() {
	int N, M, i, j, k, t1, t2;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++) {
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		rconn[t2].push_back(t1);
	}
	for (i = 1; i <= N; i++) {
		fill(dis[i] + 1, dis[i] + N + 1, INF);
		dis[i][i] = 0;
		V.push_back(i);
		for (j = 0; j < V.size(); j++) {
			for (auto it : conn[V[j]]) {
				if (dis[i][it] == INF) {
					dis[i][it] = dis[i][V[j]] + 1;
					V.push_back(it);
				}
			}
		}
		V.clear();
	}

	for (i = 1; i <= N; i++) if (!dchk[i]) DFS1(i);
	while (!Vs.empty()) {
		int u = Vs.back();
		Vs.pop_back();
		if (G[u] == 0) DFS2(u, ++gcnt);
	}
	for (i = 1; i <= N; i++) for (auto it : conn[i]) if (G[i] != G[it]) outchk[G[i]] = true;

	int ans = N;
	for (i = 1; i <= gcnt; i++) {
		if (glist[i].size() == 1 || outchk[i]) continue;
		int t = INF;
		for (j = 0; j < glist[i].size(); j++) {
			for (k = j + 1; k < glist[i].size(); k++) {
				int t1 = glist[i][j];
				int t2 = glist[i][k];
				t = min(t, dis[t1][t2] + dis[t2][t1]);
			}
		}
		ans += 998 * t + 1;
	}

	printf("%d\n", ans);
	return 0;
}