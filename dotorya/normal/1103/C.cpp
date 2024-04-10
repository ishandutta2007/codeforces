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
const db ERR = 1e-10;

vector <int> conn[300050];
vector <int> son[300050];
bool dchk[300050];
int par[300050];
int dep[300050];
void DFS(int n) {
	dchk[n] = true;
	for (auto it : conn[n]) {
		if (dchk[it]) continue;
		son[n].push_back(it);
		par[it] = n;
		dep[it] = dep[n] + 1;
		DFS(it);
	}
}

vector <pii> Ve;

vector <int> conn2[300050];
int main() {
	int N, M, K, i, j;
	scanf("%d %d %d", &N, &M, &K);
	for (i = 1; i <= M; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		Ve.emplace_back(t1, t2);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}

	DFS(1);

	int p = 1;
	for (i = 2; i <= N; i++) if (dep[i] > dep[p]) p = i;
	if ((ll)(dep[p] + 1) * K >= N) {
		printf("PATH\n");

		printf("%d\n", dep[p] + 1);
		printf("%d ", p);
		while (p != 1) {
			p = par[p];
			printf("%d ", p);
		}
		return !printf("\n");
	}

	for (auto it : Ve) {
		int t1 = it.first, t2 = it.second;
		if (dep[t1] < dep[t2]) swap(t1, t2);
		if (par[t1] == t2) continue;

		conn2[t1].push_back(t2);
	}

	vector <vector<int>> Va;
	for (i = 1; i <= N; i++) {
		if (!son[i].empty()) continue;

		if (conn2[i].size() < 2) while (1);

		int v1 = conn2[i][0], v2 = conn2[i][1];

		vector <int> Vu;
		if ((dep[i] - dep[v2] + 1) % 3 != 0) swap(v1, v2);
		if ((dep[i] - dep[v1] + 1) % 3 != 0) {
			Vu.push_back(i);
			int t = i;
			while (t != v1) {
				t = par[t];
				Vu.push_back(t);
			}
		}
		else {
			if (dep[v1] < dep[v2]) swap(v1, v2);
			Vu.push_back(i);
			Vu.push_back(v1);

			while (v1 != v2) {
				v1 = par[v1];
				Vu.push_back(v1);
			}
		}
		Va.push_back(Vu);
		if (Va.size() == K) break;
	}

	printf("CYCLES\n");
	for (auto it : Va) {
		printf("%d\n", it.size());
		for (auto it2 : it) printf("%d ", it2);
		printf("\n");
	}
	return 0;
}