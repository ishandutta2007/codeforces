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

int IT_MAX = 1 << 17;
const ll MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

class edge {
public:
	int s, e;
	int f;
	edge() {
		*this = edge(0, 0, 0);
	}
	edge(int s, int e, int f) : s(s), e(e), f(f) {}
};
vector <edge> Ve;
vector <int> conn[100050];
void epush(int s, int e, int f) {
	conn[s].push_back(Ve.size());
	conn[e].push_back(Ve.size() + 1);
	Ve.emplace_back(s, e, f);
	Ve.emplace_back(e, s, 0);
}

int pos[100050];
int dis[100050];
int dchk[100050];
bool DFS(int n, int snk, int C) {
	if (n == snk) return true;
	dchk[n] = C;
	for (; pos[n] < conn[n].size(); pos[n]++) {
		int it = conn[n][pos[n]];
		edge &ed = Ve[it];
		if (ed.f == 0 || dchk[ed.e] == C || dis[ed.e] != dis[ed.s] + 1) continue;
		if (DFS(ed.e, snk, C)) {
			ed.f--;
			Ve[it ^ 1].f++;
			return true;
		}
	}
	return false;
}

int getFlow(int src, int snk) {
	for (int i = 0; i <= snk; i++) pos[i] = 0, dchk[i] = 0, dis[i] = INF;

	dis[src] = 0;
	vector <int> Vu;
	Vu.push_back(src);
	for (int i = 0; i < Vu.size(); i++) {
		for (auto it : conn[Vu[i]]) {
			edge &ed = Ve[it];
			if (ed.f == 0 || dis[ed.e] != INF) continue;
			dis[ed.e] = dis[Vu[i]] + 1;
			Vu.push_back(ed.e);
		}
	}
	if (dis[snk] == INF) return 0;

	int f = 0;
	while (DFS(src, snk, f + 1)) f++;
	return f;
}

int N;
pii in[1050];
int myFind(pii u) {
	int it = lower_bound(in + 1, in + N + 1, u) - in;
	if (it == N + 1 || in[it] != u) return -1;
	else return it;
}

vector <pair<pii, pii>> Vl1;
vector <pair<pii, pii>> Vl2;
bool echk[1050][1050];

int u[1050];

bool tdchk[3050];

bool chk3[1050];
bool chk4[1050];
int main() {
	int i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d %d", &in[i].first, &in[i].second);
	sort(in + 1, in + N + 1);

	for (i = 1; i < N; i++) {
		if (in[i].first != in[i + 1].first) continue;
		Vl2.emplace_back(in[i], in[i + 1]);
	}

	for (i = 1; i <= N; i++) u[i] = i;
	sort(u + 1, u + N + 1, [](int a, int b) {
		return pii(in[a].second, in[a].first) < pii(in[b].second, in[b].first);
	});
	for (i = 1; i < N; i++) {
		if (in[u[i]].second != in[u[i + 1]].second) continue;
		Vl1.emplace_back(in[u[i]], in[u[i + 1]]);
	}
	
	int X = Vl1.size(), Y = Vl2.size();
	int src = X + Y, snk = X + Y + 1;
	for (i = 0; i < X; i++) epush(src, i, 1);
	for (i = 0; i < Y; i++) epush(X + i, snk, 1);
	for (i = 0; i < X; i++) {
		for (j = 0; j < Y; j++) {
			if (Vl2[j].first.second > Vl1[i].first.second || Vl2[j].second.second < Vl1[i].first.second) continue;
			if (Vl1[i].first.first > Vl2[j].first.first || Vl1[i].second.first < Vl2[j].first.first) continue;

			pii u = pii(Vl2[j].first.first, Vl1[i].first.second);
			int t = myFind(u);
			if (t == -1) {
				echk[i][j] = true;
				epush(i, j + X, 1);
			}
		}
	}

	int f = 0, t;
	while (t = getFlow(src, snk)) f += t;

	vector <int> Vu;
	Vu.push_back(src);
	tdchk[src] = true;
	for (i = 0; i < Vu.size(); i++) {
		for (auto it : conn[Vu[i]]) {
			edge &ed = Ve[it];
			if (ed.f == 0 || tdchk[ed.e]) continue;
			tdchk[ed.e] = true;
			Vu.push_back(ed.e);
		}
	}
	for (i = 0; i < X; i++) if (!tdchk[i]) chk3[i] = true;
	for (i = 0; i < Y; i++) if (tdchk[i + X]) chk4[i] = true;

	vector <pii> Va1;
	vector <pii> Va2;
	int st = 1, idx = 0;
	for (i = 1; i <= N; i++) {
		bool chk = false;
		int x = u[i], y = u[i + 1];
		if (i == N || in[x].second != in[y].second) chk = true;
		else {
			if (chk3[idx++]) chk = true;
		}
		if (chk) {
			Va1.emplace_back(u[st], u[i]);
			st = i + 1;
		}
	}

	st = 1, idx = 0;
	for (i = 1; i <= N; i++) {
		bool chk = false;
		if (i == N || in[i].first != in[i + 1].first) chk = true;
		else {
			if (chk4[idx++]) chk = true;
		}
		if (chk) {
			Va2.emplace_back(st, i);
			st = i + 1;
		}
	}

	printf("%d\n", (int)Va1.size());
	for (auto it : Va1) printf("%d %d %d %d\n", in[it.first].first, in[it.first].second, in[it.second].first, in[it.second].second);
	printf("%d\n", (int)Va2.size());
	for (auto it : Va2) printf("%d %d %d %d\n", in[it.first].first, in[it.first].second, in[it.second].first, in[it.second].second);
	return 0;
}