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
#include <string>
#include <time.h>
#include <cmath>
#include <vector>
#include <deque>
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

int IT_MAX = 1<<19;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-10;

int c[200050];
vector <pii> Ve;
int r[200050];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}

vector <int> conn[200050];
vector <int> V;
int dis[200050];
int main() {
	int N, i, t1, t2;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &c[i]);
	for (i = 1; i <= N; i++) r[i] = i;
	for (i = 1; i < N; i++) {
		scanf("%d %d", &t1, &t2);
		if (c[t1] == c[t2]) r[root(t1)] = root(t2);
		Ve.emplace_back(t1, t2);
	}

	for (auto it : Ve) {
		t1 = root(it.first);
		t2 = root(it.second);
		if (t1 != t2) {
			conn[t1].push_back(t2);
			conn[t2].push_back(t1);
		}
	}

	int s = 0;
	for (i = 1; i <= N; i++) if (root(i) == i) break;
	s = i;

	for (i = 1; i <= N; i++) dis[i] = INF;
	dis[s] = 0;
	V.push_back(s);
	for (i = 0; i < V.size(); i++) {
		for (auto it : conn[V[i]]) {
			if (dis[it] != INF) continue;
			V.push_back(it);
			dis[it] = dis[V[i]] + 1;
		}
	}

	s = V.back();
	V.clear();
	for (i = 1; i <= N; i++) dis[i] = INF;
	dis[s] = 0;
	V.push_back(s);
	for (i = 0; i < V.size(); i++) {
		for (auto it : conn[V[i]]) {
			if (dis[it] != INF) continue;
			V.push_back(it);
			dis[it] = dis[V[i]] + 1;
		}
	}
	return !printf("%d\n", (dis[V.back()] + 1) / 2);
}