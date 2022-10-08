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

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

vector <int> conn[300050];
int par[300050];
int dep[300050];
int low[300050];
bool dchk[300050];

vector <pii> Ve;
void DFS(int n) {
	dchk[n] = true;
	low[n] = dep[n];
	for (auto it : conn[n]) {
		if (par[n] == it) continue;
		if (dchk[it]) {
			low[n] = min(low[n], dep[it]);
			Ve.emplace_back(n, it);
			continue;
		}
		par[it] = n;
		dep[it] = dep[n] + 1;
		DFS(it);

		if (low[it] <= dep[n]) Ve.emplace_back(it, n);
		low[n] = min(low[n], low[it]);
	}
}

int r[300050];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}
vector <int> Vl[300050];

vector <pii> Vu;
int mx[300050];
ll sum[300050];
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}
	for (i = 1; i <= N; i++) if (!dchk[i]) DFS(i);
	for (i = 1; i <= N; i++) r[i] = i;
	for (auto it : Ve) r[root(it.first)] = root(it.second);

	for (i = 1; i <= N; i++) Vl[root(i)].push_back(i);

	for (i = 1; i <= N; i++) mx[i] = N;
	for (i = 1; i <= N; i++) {
		if (Vl[i].size() <= 1) continue;
		mx[Vl[i][0]] = min(mx[Vl[i][0]], Vl[i].back() - 1);
	}
	for (i = N - 1; i >= 1; i--) mx[i] = min(mx[i], mx[i + 1]);
	for (i = 1; i <= N; i++) sum[i] = sum[i - 1] + mx[i];

	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);

		int st = t1, en = t2, mi, rv = t1 - 1;
		while (st <= en) {
			mi = (st + en) / 2;
			if (mx[mi] <= t2) {
				rv = mi;
				st = mi + 1;
			}
			else en = mi - 1;
		}

		ll s1 = sum[rv] - sum[t1 - 1] + (ll)t2 * (t2 - rv);
		ll s2 = (ll)(t1 + t2) * (t2 - t1 + 1) / 2 - (t2 - t1 + 1);
		printf("%lld\n", s1 - s2);
	}
	return 0;
}