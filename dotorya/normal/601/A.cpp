//*
#include <algorithm>
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

#define pow10 pasiodfiopsdjviozjxciovjxcviozj
#define pow2 qpowdskopjkcoizxnzoicn

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <char, int> pci;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef pair <ldb, int> pdi;
typedef pair <ldb, ll> pdl;

int IT_MAX;
const int MOD = 500500507;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;

bool conn[405][405];

int dis[405];
vector <int> V;
int main() {
	int N, M, i, j, t1, t2;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++) {
		scanf("%d %d", &t1, &t2);
		conn[t1][t2] = conn[t2][t1] = true;
	}

	if (conn[1][N]) {
		for (i = 1; i <= N; i++) for (j = 1; j <= N; j++) if (i != j) conn[i][j] = !conn[i][j];
	}

	fill(dis + 1, dis + N + 1, INF);
	V.push_back(1);
	dis[1] = 0;
	for (i = 0; i < V.size(); i++) {
		int t = V[i];
		for (j = 1; j <= N; j++) {
			if (conn[t][j] && dis[j] == INF) {
				dis[j] = dis[t] + 1;
				V.push_back(j);
			}
		}
	}

	if (dis[N] == INF) printf("-1");
	else printf("%d\n", dis[N]);
	return 0;
}