//*
#include <algorithm>
#include <ctype.h>
#include <functional>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;

const int IT_MAX = 131072;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;

vector <int> conn[100050];
int G[100050];
bool c[100050];

pii DFS(int node) {
	pii rv;
	if (G[node] == 1) rv = pii(1, 0);
	else rv = pii(0, 1);

	for (int i = 0; i < conn[node].size(); i++) {
		int t = conn[node][i];
		if (G[t] == G[node]) return pii(-1, -1);
		if (G[t] == 0) {
			G[t] = 3 - G[node];
			pii t2 = DFS(t);
			if (t2 == pii(-1, -1)) return pii(-1, -1);
			rv.first += t2.first;
			rv.second += t2.second;
		}
	}
	return rv;
}
int main() {
	int N, M, i, j, t1, t2;
	scanf("%d %d", &N, &M);
	if (M == 0) {
		printf("%d %I64d", 3, (ll)N*(N - 1)*(N - 2) / 6);
		return 0;
	}
	bool ch = true;
	for (i = 1; i <= M; i++) {
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
		if (c[t1] || c[t2]) ch = false;
		c[t1] = c[t2] = true;
	}
	if (ch) {
		printf("%d %I64d", 2, (ll)M*(N - 2));
		return 0;
	}

	ll ans = 0;
	for (i = 1; i <= N; i++) {
		if (G[i] != 0) continue;
		G[i] = 1;
		pii tmp = DFS(i);
		if (tmp == pii(-1, -1)) break;
		ans += (ll)(tmp.first)*(tmp.first - 1)/2;
		ans += (ll)(tmp.second)*(tmp.second - 1)/2;

	}
	if (i <= N) printf("0 1");
	else printf("1 %I64d", ans);
	return 0;
}