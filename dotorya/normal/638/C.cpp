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

int IT_MAX = 1 << 17;
const ll MOD = 987654321;
const int INF = 1034567891;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

vector <int> ans[200050];
vector <pii> conn[200050];
int par[200050][2];
bool dchk[200050];

void DFS(int n) {
	int i;
	dchk[n] = true;

	int p = 0;
	for (i = 0; i < conn[n].size(); i++) {
		if (dchk[conn[n][i].first]) continue;
		p++;
		if (p == par[n][1]) p++;

		par[conn[n][i].first][0] = n;
		par[conn[n][i].first][1] = p;
		ans[p].push_back(conn[n][i].second);
		DFS(conn[n][i].first);
	}
	return;
}
int main() {
	int N, i, t1, t2;
	scanf("%d", &N);
	for (i = 1; i < N; i++) {
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(pii(t2, i));
		conn[t2].push_back(pii(t1, i));
	}

	int r = 1;
	for (i = 2; i <= N; i++) if (conn[i].size() > conn[r].size()) r = i;

	DFS(r);

	printf("%d\n", (int)conn[r].size());
	for (i = 1; i <= conn[r].size(); i++) {
		printf("%d ", ans[i].size());
		for (auto it : ans[i]) printf("%d ", it);
		printf("\n");
	}
	return 0;
}
//*/