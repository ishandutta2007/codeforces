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

class edge {
public:
	int s, e, f;
	int of;
	edge() {
		*this = edge(0, 0, 0);
	}
	edge(int s, int e, int f) : s(s), e(e), f(f) {}
};
vector <edge> E;
vector <int> fconn[100050];
void epush(int s, int e, int f) {
	fconn[s].push_back(E.size());
	fconn[e].push_back(E.size() + 1);
	E.emplace_back(s, e, f);
	E.emplace_back(e, s, 0);
}
int dchk[100050];
int DFS(int n, int snk, int C, int F) {
	if (n == snk) return F;
	dchk[n] = C;
	for (auto it : fconn[n]) {
		edge& ed = E[it];
		if (ed.f == 0 || dchk[ed.e] == C) continue;
		int t;
		if (t = DFS(ed.e, snk, C, min(F, ed.f))) {
			ed.f -= t;
			E[it ^ 1].f += t;
			return t;
		}
	}
	return 0;
}
void init(int snk) {
	int i;
	for (i = 0; i <= snk; i++) {
		fconn[i].clear();
		dchk[i] = false;
	}
	E.clear();
}

int in[5050][2];
int ans[5050][2];
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++) scanf("%d %d", &in[i][0], &in[i][1]);

	int st = 0, en = N - 1, mi, rv = N;
	while (st <= en) {
		mi = (st + en) / 2;
		int src = 0, snk = N + M + 1;
		for (i = 1; i <= M; i++) epush(src, i, 1);
		for (i = 1; i <= N; i++) epush(i + M, snk, mi);
		for (i = 1; i <= M; i++) {
			epush(i, M+in[i][0], 1);
			epush(i, M+in[i][1], 1);
		}

		int f = 0;
		while (DFS(src, snk, f + 1, INF)) f++;
		if (f == M) {
			rv = mi;
			en = mi - 1;

			for (auto it : E) {
				if (it.s >= 1 && it.s <= M && it.e >= M + 1 && it.e <= M + N && !it.f) {
					int x = it.s, y = it.e - M;
					ans[x][0] = y;
					ans[x][1] = in[x][0] + in[x][1] - y;
				}
			}
		}
		else st = mi + 1;
		init(snk);
	}
	printf("%d\n", rv);
	for (i = 1; i <= M; i++) printf("%d %d\n", ans[i][0], ans[i][1]);
}