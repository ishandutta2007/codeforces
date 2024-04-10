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

int IT_MAX = 1 << 19;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

vector <int> conn[200050];
int dis[2][200050];
int rev[2][200050];
vector <int> Vu;
void BFS(int N, int st, int* dis, int* rev) {
	Vu.clear();
	int i, j;
	for (i = 1; i <= N; i++) dis[i] = INF, rev[i] = -1;
	dis[st] = 0;
	Vu.push_back(st);
	for (i = 0; i < Vu.size(); i++) {
		for (auto it : conn[Vu[i]]) {
			if (dis[it] != INF) continue;
			dis[it] = dis[Vu[i]] + 1;
			rev[it] = Vu[i];
			Vu.push_back(it);
		}
	}
}


bool dchk[200050];

int deg[200050];
vector <pair<pii, int>> Va;
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i < N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}
	BFS(N, 1, dis[0], rev[0]);

	int mx = 1;
	for (i = 1; i <= N; i++) if (dis[0][mx] < dis[0][i]) mx = i;
	BFS(N, mx, dis[0], rev[0]);

	int p1 = mx, p2 = 1;
	for (i = 1; i <= N; i++) if (dis[0][p2] < dis[0][i]) p2 = i;

	BFS(N, p1, dis[0], rev[0]);
	BFS(N, p2, dis[1], rev[1]);

	int v = p2;
	vector <int> Vl;
	while (v != p1) {
		dchk[v] = true;
		Vl.push_back(v);
		v = rev[0][v];
	}
	dchk[p1] = true;
	Vl.push_back(p1);

	for (i = 1; i <= N; i++) deg[i] = conn[i].size();

	ll ans = 0;
	Vu.clear();
	for (i = 1; i <= N; i++) if (deg[i] == 1 && !dchk[i]) Vu.push_back(i);
	for (i = 0; i < Vu.size(); i++) {
		deg[Vu[i]] = 0;

		int t = p1;
		if (dis[0][Vu[i]] < dis[1][Vu[i]]) t = p2;
		ans += max(dis[0][Vu[i]], dis[1][Vu[i]]);
		Va.emplace_back(pii(Vu[i], t), Vu[i]);
		for (auto it : conn[Vu[i]]) {
			deg[it]--;
			if (deg[it] == 1 && !dchk[it]) Vu.push_back(it);
		}
	}
	ans += (ll)dis[0][p2] * (dis[0][p2] + 1) / 2;
	for (auto it : Vl) {
		if (it == Vl.back()) continue;
		Va.emplace_back(pii(it, Vl.back()), it);
	}

	printf("%lld\n", ans);
	for (auto it : Va) printf("%d %d %d\n", it.first.first, it.first.second, it.second);
	return 0;
}