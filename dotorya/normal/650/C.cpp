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
const ll MOD = 1000000009;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

vector <int> in[1000050];

vector <pii> out[1000050];
int ind[1000050];

vector <pii> V;
vector <pair<int, pii>> conn;

int dp[1000050];
vector <int> U;

int r[1000050];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}
int main() {
	int N, M, i, j, t;

	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%d", &t);
			in[i].push_back(t);
		}
	}

	for (i = 0; i < N*M; i++) r[i] = i;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) V.push_back(pii(in[i][j], j));
		sort(V.begin(), V.end());
		for (j = 1; j < M; j++) {
			if (V[j].first == V[j - 1].first) {
				int r1 = root(i*M + V[j - 1].second);
				int r2 = root(i*M + V[j].second);
				if (r1 != r2) r[r1] = r2;
			}
			else conn.push_back(mp(i*M + V[j - 1].second, pii(1, i*M + V[j].second)));
		}
		V.clear();
	}
	for (j = 0; j < M; j++) {
		for (i = 0; i < N; i++) V.push_back(pii(in[i][j], i));
		sort(V.begin(), V.end());
		for (i = 1; i < N; i++) {
			if (V[i].first == V[i - 1].first) {
				int r1 = root(V[i - 1].second * M + j);
				int r2 = root(V[i].second * M + j);
				if (r1 != r2) r[r1] = r2;
			}
			else conn.push_back(mp(V[i - 1].second * M + j, pii(1, V[i].second * M + j)));
		}
		V.clear();
	}

	for (auto it : conn) {
		int t1 = root(it.first);
		int t2 = it.second.first;
		int t3 = root(it.second.second);

		out[t1].push_back(pii(t2, t3));
		ind[t3]++;
	}

	for (i = 0; i < N*M; i++) {
		if (ind[i] == 0) {
			U.push_back(i);
			dp[i] = 1;
		}
	}

	for (i = 0; i < U.size(); i++) {
		for (auto it : out[U[i]]) {
			dp[it.second] = max(dp[it.second], dp[U[i]] + it.first);
			ind[it.second]--;
			if (ind[it.second] == 0) U.push_back(it.second);
		}
	}
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) printf("%d ", dp[root(i*M + j)]);
		printf("\n");
	}
	return 0;
}