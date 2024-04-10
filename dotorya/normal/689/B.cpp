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
//#include <unordered_set>
//#include <unordered_map>

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
const ll MOD = 97654321;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-13;

vector <int> conn[200050];
vector <int> V;

int dis[200050];
int main() {
	int N, i, t;
	scanf("%d", &N);
	for (i = 1; i < N; i++) {
		conn[i].push_back(i + 1);
		conn[i + 1].push_back(i);
		scanf("%d", &t);
		conn[i].push_back(t);
	}
	scanf("%d", &t);
	conn[N].push_back(t);

	fill(dis + 1, dis + N + 1, INF);
	dis[1] = 0;
	V.push_back(1);
	for (i = 0; i < V.size(); i++) {
		for (auto it : conn[V[i]]) {
			if (dis[it] == INF) {
				dis[it] = dis[V[i]] + 1;
				V.push_back(it);
			}
		}
	}
	for (i = 1; i <= N; i++) printf("%d ", dis[i]);
	return !printf("\n");
}