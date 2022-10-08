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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

vector <int> conn[500050];
char col[500050];
int dis[500050];

int solve(int N) {
	if (N <= 2) return !printf("Draw\n");

	int i, j, c = 0;
	for (i = 1; i <= N; i++) if (col[i] == 'W') c++;

	if (c >= 3) return !printf("White\n");

	if (c == 2) {
		for (i = 1; i <= N; i++) if (conn[i].size() >= 3) return !printf("White\n");
		for (i = 1; i <= N; i++) if (col[i] == 'W' && conn[i].size() == 2) return !printf("White\n");

		if (N % 2 == 1) printf("White\n");
		else printf("Draw\n");
		return 0;
	}

	if(c == 1) {
		for (i = 1; i <= N; i++) if (conn[i].size() >= 4) return !printf("White\n");

		int p = 0;
		for (i = 1; i <= N; i++) if (col[i] == 'W') p = i;

		if (conn[p].size() == 3) return !printf("White\n");
		if (conn[p].size() == 2) {
			if (N >= 4) return !printf("White\n");
			else return !printf("Draw\n");
		}

		for (i = 1; i <= N; i++) if (conn[i].size() >= 3) break;
		if (i > N) return !printf("Draw\n");

		vector <int> Vl;
		Vl.push_back(p);
		Vl.push_back(conn[p][0]);
		while (1) {
			int t = Vl.back();
			if (conn[t].size() == 3) break;

			int nx = Vl[Vl.size() - 2] ^ conn[t][0] ^ conn[t][1];
			Vl.push_back(nx);
		}

		if (Vl.size() % 2 == 0) return !printf("White\n");

		int c2 = 0;
		for (auto it : conn[Vl.back()]) if (conn[it].size() == 1) c2++;
		if (c2 == 2) return !printf("Draw\n");
		return !printf("White\n");
	}

	for (i = 1; i <= N; i++) if (conn[i].size() >= 4) return !printf("White\n"); 

	for (i = 1; i <= N; i++) {
		if (conn[i].size() != 3) continue;

		int c[4] = { 0,0,0,0 };
		for (auto it : conn[i]) c[conn[it].size()]++;

		if (c[1] < 2) return !printf("White\n");
	}

	c = 0;
	for (i = 1; i <= N; i++) if (conn[i].size() == 3) c++;
	if (c >= 3) return !printf("White\n");
	if (c <= 1) return !printf("Draw\n");

	int p1 = -1, p2 = -1;
	for (i = 1; i <= N; i++) {
		if (conn[i].size() != 3) continue;
		if (p1 == -1) p1 = i;
		else p2 = i;
	}

	vector <int> Vu;
	for (i = 1; i <= N; i++) dis[i] = INF;
	dis[p1] = 0;
	Vu.push_back(p1);
	for (i = 0; i < Vu.size(); i++) {
		for (auto it : conn[Vu[i]]) {
			if (dis[it] != INF) continue;
			dis[it] = dis[Vu[i]] + 1;
			Vu.push_back(it);
		}
	}

	if (dis[p2] % 2 == 0) return !printf("White\n");
	return !printf("Draw\n");
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, i, j;
		scanf("%d", &N);
		for (i = 1; i < N; i++) {
			int t1, t2;
			scanf("%d %d", &t1, &t2);
			conn[t1].push_back(t2);
			conn[t2].push_back(t1);
		}
		scanf("%s", col + 1);
		solve(N);

		for (i = 1; i <= N; i++) col[i] = 0, conn[i].clear();
	}
	return 0;
}