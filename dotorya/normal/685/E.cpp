//*
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
#include <unordered_set>
#include <unordered_map>

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

int IT_MAX = 1024;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

int in[200050][2];
int dis[1050][1050];
vector <pair<pair<pii, pii>, int>> V;
bool ans[200050];
int main() {
	int N, M, Q, i, j, t1, t2, t3, t4;
	scanf("%d %d %d", &N, &M, &Q);
	for (i = 1; i <= M; i++) scanf("%d %d", &in[i][0], &in[i][1]);

	for (i = 1; i <= Q; i++) {
		scanf("%d %d %d %d", &t1, &t2, &t3, &t4);
		V.emplace_back(mp(pii(t1, t2), pii(t3, t4)), i);
	}
	sort(V.begin(), V.end());
	
	for (i = 1; i <= N; i++) for(j = 1; j <= N; j++) if(i != j) dis[i][j] = M + 1;
	for (i = M; i >= 1; i--) {
		int s = in[i][0], e = in[i][1];
		for (j = 1; j <= N; j++) dis[s][j] = min(dis[s][j], max(dis[e][j], i));
		swap(s, e);
		for (j = 1; j <= N; j++) dis[s][j] = min(dis[s][j], max(dis[e][j], i));
		
		while (!V.empty()) {
			auto u = V.back();
			if (u.first.first.first != i) break;
			if (dis[u.first.second.first][u.first.second.second] <= u.first.first.second) ans[u.second] = true;
			V.pop_back();
		}
	}

	for (i = 1; i <= Q; i++) {
		if (ans[i]) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}