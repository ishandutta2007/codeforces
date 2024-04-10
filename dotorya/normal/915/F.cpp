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

int IT_MAX = 1 << 20;
ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int r[1000050];
int sz[1000050];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}
int in[1000050];
bool chk[1000050];
vector <int> conn[1000050];

int u[1000050];
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);
	for (i = 1; i < N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}
	for (i = 1; i <= N; i++) u[i] = i;
	sort(u + 1, u + N + 1, [](int a, int b) {
		return in[a] < in[b];
	});

	ll ans = 0;

	memset(chk, 0, sizeof(chk));
	for (i = 1; i <= N; i++) r[i] = i, sz[i] = 1;
	for (i = 1; i <= N; i++) {
		int t = u[i];
		chk[t] = true;
		for (auto it : conn[t]) {
			if (!chk[it]) continue;

			int r1 = root(t), r2 = root(it);
			if (r1 == r2) continue;
			ans += (ll)sz[r1] * sz[r2] * in[t];
			sz[r2] += sz[r1];
			r[r1] = r2;
		}
	}
	memset(chk, 0, sizeof(chk));
	for (i = 1; i <= N; i++) r[i] = i, sz[i] = 1;
	for (i = N; i >= 1; i--) {
		int t = u[i];
		chk[t] = true;
		for (auto it : conn[t]) {
			if (!chk[it]) continue;

			int r1 = root(t), r2 = root(it);
			if (r1 == r2) continue;
			ans -= (ll)sz[r1] * sz[r2] * in[t];
			sz[r2] += sz[r1];
			r[r1] = r2;
		}
	}
	return !printf("%lld\n", ans);
}
//*/