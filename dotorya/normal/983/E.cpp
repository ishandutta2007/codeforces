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
//#include <unordered_map>
//#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")

using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()

//typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18; // segment tree size
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f; // memset(dp, 0x3f, sizeof(dp)), 2*INF < INT_MAX
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10; // double EPS

vector <int> son[200050];
int par[200050][20];
int dp[200050][20];
int dep[200050];

int lr[200050][2];
int tus = 0;
void DFS1(int n) {
	lr[n][0] = ++tus;
	for (auto it : son[n]) {
		dep[it] = dep[n] + 1;
		par[it][0] = n;
		for (int i = 1; i <= 19; i++) par[it][i] = par[par[it][i - 1]][i - 1];
		DFS1(it);
	}
	lr[n][1] = tus;
}
int upnode(int a, int b) {
	for (int i = 19; i >= 0; i--) if (b & (1 << i)) a = par[a][i];
	return a;
}
int lca(int a, int b) {
	if (dep[a] > dep[b]) swap(a, b);
	b = upnode(b, dep[b] - dep[a]);
	if (a == b) return a;

	for (int i = 19; i >= 0; i--) {
		if (par[a][i] != par[b][i]) {
			a = par[a][i];
			b = par[b][i];
		}
	}
	return par[a][0];
}

vector <int> indt[600000];
void update(int p, int v) {
	p += IT_MAX - 1;
	for (; p; p /= 2) indt[p].push_back(v);
}
bool isExists(int p1, int p2, int p3, int p4) {
	p1 += IT_MAX - 1;
	p2 += IT_MAX - 1;
	for (; p1 <= p2; p1 /= 2, p2 /= 2) {
		if (p1 % 2 == 1) {
			auto it = lower_bound(all(indt[p1]), p3);
			if (it != indt[p1].end() && *it <= p4) return true;
			p1++;
		}
		if (p2 % 2 == 0) {
			auto it = lower_bound(all(indt[p2]), p3);
			if (it != indt[p2].end() && *it <= p4) return true;
			p2--;
		}
	}
	return false;
}

int getupdis(int t1, int t2) {
	if (dep[dp[t2][19]] > dep[t1]) return INF;

	int ans = 0;
	for (int i = 19; i >= 0; i--) {
		if (dep[dp[t2][i]] > dep[t1]) {
			ans += 1 << i;
			t2 = dp[t2][i];
		}
	}
	return ans + 1;
}
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 2; i <= N; i++) {
		int t;
		scanf("%d", &t);
		son[t].push_back(i);
	}
	for (i = 0; i < 20; i++) par[1][i] = 1;
	DFS1(1);

	int M;
	scanf("%d", &M);

	for (i = 1; i <= N; i++) dp[i][0] = dep[i];
	while (M--) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		if (dep[t1] > dep[t2]) swap(t1, t2);

		if (upnode(t2, dep[t2] - dep[t1]) == t1) {
			dp[t2][0] = min(dp[t2][0], dep[t1]);
			continue;
		}

		int L = lca(t1, t2);
		dp[t1][0] = min(dp[t1][0], dep[L]);
		dp[t2][0] = min(dp[t2][0], dep[L]);

		update(min(lr[t1][0], lr[t2][0]), max(lr[t1][0], lr[t2][0]));
	}
	for (i = 1; i < 2 * IT_MAX; i++) sort(all(indt[i]));
	for (i = N; i >= 1; i--) for (auto it : son[i]) dp[i][0] = min(dp[i][0], dp[it][0]);
	for (i = 1; i <= N; i++) dp[i][0] = upnode(i, dep[i] - dp[i][0]);
	for (i = 1; i <= 19; i++) for (j = 1; j <= N; j++) dp[j][i] = dp[dp[j][i - 1]][i - 1];

	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		if (dep[t1] > dep[t2]) swap(t1, t2);

		if (lca(t1, t2) == t1) {
			int D = getupdis(t1, t2);
			if (D == INF) printf("-1\n");
			else printf("%d\n", D);
		}
		else {
			int L = lca(t1, t2);
			int D1 = getupdis(L, t1);
			int D2 = getupdis(L, t2);
			if (D1 == INF || D2 == INF) {
				printf("-1\n");
				continue;
			}

			int ans = D1 + D2;
			D1--, D2--;

			for (i = 19; i >= 0; i--) if (D1 & (1 << i)) t1 = dp[t1][i];
			for (i = 19; i >= 0; i--) if (D2 & (1 << i)) t2 = dp[t2][i];

			int l1 = lr[t1][0], r1 = lr[t1][1], l2 = lr[t2][0], r2 = lr[t2][1];
			if (l1 > l2) {
				swap(l1, l2);
				swap(r1, r2);
			}
			if (isExists(l1, r1, l2, r2)) ans--;
			printf("%d\n", ans);
		}
	}
	return 0;
}