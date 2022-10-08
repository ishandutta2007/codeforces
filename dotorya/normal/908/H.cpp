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

char in[50][50];

int r[50];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}

int sz[50];
map <int, int> ch;
vector <int> Vl;
int conn2[50][50];

int col[50];
int u[50];
bool tchk[50];
int main() {
	

	int N, i, j, k, l;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%s", in[i]);

	int st = clock();
	for (i = 0; i < N; i++) r[i] = i;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (in[i][j] == 'A') r[root(i)] = root(j);
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (in[i][j] != 'X') continue;
			if (root(i) == root(j)) return !printf("-1\n");
		}
	}

	for (i = 0; i < N; i++) sz[root(i)]++;
	for (i = 0; i < N; i++) if (sz[i] >= 2) Vl.push_back(i);

	int X = Vl.size();
	for (i = 0; i < X; i++) ch[Vl[i]] = i;

	for (i = 0; i < N; i++) {
		int t1 = root(i);
		if (!ch.count(t1)) continue;
		t1 = ch[t1];
		for (j = 0; j < N; j++) {
			int t2 = root(j);
			if (!ch.count(t2)) continue;
			t2 = ch[t2];
			if (in[i][j] == 'X') conn2[t1][t2] = conn2[t2][t1] = true;
		}
	}

	if (Vl.empty()) return !printf("%d\n", N - 1);

	int mn = INF;

	for (i = 0; i < X; i++) u[i] = i;
	while (clock() - st <= CLOCKS_PER_SEC * 4.5) {
		random_shuffle(u, u + X);
		int mx = 0;
		for (i = 0; i < X; i++) col[i] = 0;
		for (i = 0; i < X; i++) {
			int t = u[i];
			for (j = 1; j <= X; j++) tchk[j] = false;
			for (j = 0; j < X; j++) if (conn2[t][j]) tchk[col[j]] = true;
			for (j = 1;; j++) if (!tchk[j]) break;
			col[t] = j;
			mx = max(mx, j);
		}
		mn = min(mn, mx);
	}
	return !printf("%d\n", N - 1 + mn);
}