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
const ll MOD = 1000000007;
const int INF = 534567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-16;

vector <int> conn[3050];
int dis[3050][3050];
int rdis[3050][3050];
pii mx1[3050][4];
pii mx2[3050][4];
vector <int> V;
int main() {
	int N, M, i, j, k, l, t1, t2;
	scanf("%d %d", &N, &M);
	while (M--) {
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
	}

	for (i = 1; i <= N; i++) {
		fill(dis[i] + 1, dis[i] + N + 1, -INF);
		dis[i][i] = 0;
		V.push_back(i);
		for (j = 0; j < V.size(); j++) {
			for (auto it : conn[V[j]]) {
				if (dis[i][it] == -INF) {
					dis[i][it] = dis[i][V[j]] + 1;
					V.push_back(it);
				}
			}
		}
		V.clear();
		dis[i][i] = -INF;
	}
	for (i = 1; i <= N; i++) for (j = 1; j <= N; j++) rdis[i][j] = dis[j][i];

	for (i = 1; i <= N; i++) {
		mx1[i][0] = mx1[i][1] = mx1[i][2] = mx1[i][3] = pii(-INF, -INF);
		for (j = 1; j <= N; j++) {
			mx1[i][3] = max(mx1[i][3], pii(dis[i][j], j));
			for (k = 3; k >= 1; k--) {
				if (mx1[i][k] > mx1[i][k - 1]) swap(mx1[i][k], mx1[i][k - 1]);
				else break;
			}
		}
	}

	for (i = 1; i <= N; i++) {
		mx2[i][0] = mx2[i][1] = mx2[i][2] = mx2[i][3] = pii(-INF, -INF);
		for (j = 1; j <= N; j++) {
			mx2[i][3] = max(mx2[i][3], pii(rdis[i][j], j));
			for (k = 3; k >= 1; k--) {
				if (mx2[i][k] > mx2[i][k - 1]) swap(mx2[i][k], mx2[i][k - 1]);
				else break;
			}
		}
	}

	int ans = -1, a1 = -1, a2 = -1, a3 = -1, a4 = -1;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (i == j) continue;
			for (k = 0; k <= 3; k++) {
				if (mx2[i][k].second == j || mx2[i][k].second == i) continue;
				for (l = 0; l <= 3; l++) {
					if (mx1[j][l].second == i || mx1[j][l].second == j || mx1[j][l].second == mx2[i][k].second) continue;
					
					int t = mx2[i][k].first + mx1[j][l].first + dis[i][j];
					if (ans < t) {
						ans = t;
						a1 = mx2[i][k].second;
						a2 = i;
						a3 = j;
						a4 = mx1[j][l].second;
					}
				}
			}
		}
	}

	printf("%d %d %d %d\n", a1, a2, a3, a4);
	return 0;
}