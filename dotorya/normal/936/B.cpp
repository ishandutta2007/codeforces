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

int IT_MAX = 1 << 18;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

vector <int> conn[100050];
vector <int> rconn[100050];
bool dc[100050];
int G[100050];
int gcnt[100050];
vector <int> Vstk;
void DFS1(int n) {
	dc[n] = true;
	for (auto it : conn[n]) if (!dc[it]) DFS1(it);
	Vstk.push_back(n);
}
void DFS2(int n, int g) {
	G[n] = g;
	gcnt[g]++;
	for (auto it : rconn[n]) if (!G[it]) DFS2(it, g);
}


bool dchk[100050][2];
int prv[100050][2][2];
int main() {
	int N, M, i, j, S;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		int t1, t2;
		scanf("%d", &t1);
		while (t1--) {
			scanf("%d", &t2);
			conn[i].push_back(t2);
			rconn[t2].push_back(i);
		}
	}
	scanf("%d", &S);

	dchk[S][0] = true;
	vector <pii> Vu;
	Vu.emplace_back(S, 0);
	for (i = 0; i < Vu.size(); i++) {
		for (auto it : conn[Vu[i].first]) {
			int t1 = it, t2 = Vu[i].second ^ 1;
			if (dchk[t1][t2]) continue;
			dchk[t1][t2] = true;
			prv[t1][t2][0] = Vu[i].first, prv[t1][t2][1] = Vu[i].second;
			Vu.emplace_back(t1, t2);
		}
	}

	for (i = 1; i <= N; i++) {
		if (conn[i].size()) continue;
		if (!dchk[i][1]) continue;

		vector <int> Va;
		int t1 = i, t2 = 1;
		while (t1 != S || t2 != 0) {
			int t3 = prv[t1][t2][0], t4 = prv[t1][t2][1];
			Va.push_back(t1);
			t1 = t3, t2 = t4;
		}
		Va.push_back(S);

		printf("Win\n");
		reverse(all(Va));
		for (auto it : Va) printf("%d ", it);
		printf("\n");
		return 0;
	}

	for (i = 1; i <= N; i++) if (!dc[i]) DFS1(i);
	reverse(all(Vstk));

	int gc = 0;
	for (auto it : Vstk) if (!G[it]) DFS2(it, ++gc);

	for (i = 1; i <= N; i++) {
		if (!dchk[i][0] && !dchk[i][1]) continue;
		if (gcnt[G[i]] >= 2) return !printf("Draw\n");
	}
	return !printf("Lose\n");
}