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
const ll MOD = 987654321;
const int INF = 1034567891;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

vector <pii> E;
int r[300050];

int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}

int cnt[300050];
bool chk[300050];

ll chk2[2050][2050];

int gcnt[300050];
int gsz[2050];

unordered_map <int, int> Mx;
int Mv[300050];
int ch(int x) {
	if (Mx.count(x)) return Mx[x];
	int t = Mx.size() + 1;
	Mv[t] = x;
	Mx[x] = t;
	return t;
}

int get_gcnt(int N) {
	int i, j;
	if (N <= 2000) {
		for (i = 1; i <= N; i++) for (j = 1; j <= N; j++) chk2[i][j] = 1;
		for (auto it : E) chk2[it.first][it.second] = chk2[it.second][it.first] = 0;

		int rv = N;
		for (i = 1; i <= N; i++) r[i] = i;
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				if (!chk2[i][j]) continue;
				if (root(i) != root(j)) {
					rv--;
					r[root(i)] = root(j);
				}
			}
		}
		return rv;
	}
	for (i = 1; i <= N; i++) r[i] = i;

	fill(cnt + 1, cnt + N + 1, N - 1);
	for (auto it : E) {
		cnt[it.first]--;
		cnt[it.second]--;
	}

	int mx = 1;
	for (i = 2; i <= N; i++) if (cnt[mx] < cnt[i]) mx = i;

	fill(chk + 1, chk + N + 1, true);
	for (auto it : E) {
		if (it.first == mx) chk[it.second] = false;
		if (it.second == mx) chk[it.first] = false;
	}

	for (i = 1; i <= N; i++) {
		if (!chk[i]) continue;
		if (root(i) != root(mx)) {
			r[root(i)] = root(mx);
		}
	}

	Mx.clear();
	fill(gcnt + 1, gcnt + N + 1, 0);
	for (i = 1; i <= N; i++) gcnt[root(i)]++;
	for (i = 1; i <= N; i++) {
		if (gcnt[i] == 0) continue;
		int t = ch(i);
	}

	fill(gsz + 1, gsz + N + 1, 0);
	for (i = 1; i <= N; i++) gsz[ch(root(i))]++;

	for (i = 1; i <= Mx.size(); i++) for (j = 1; j <= Mx.size(); j++) chk2[i][j] = (ll)gsz[i] * gsz[j];

	int gcnt = Mx.size();
	for (auto it : E) {
		int t1 = ch(root(it.first));
		int t2 = ch(root(it.second));
		chk2[t1][t2]--;
		chk2[t2][t1]--;
	}

	for (i = 1; i <= gcnt; i++) r[i] = i;
	for (i = 1; i <= Mx.size(); i++) {
		for (j = 1; j <= Mx.size(); j++) {
			if (chk2[i][j] == 0) continue;
			if (root(i) != root(j)) {
				gcnt--;
				r[root(i)] = root(j);
			}
		}
	}
	return gcnt;
}
int main() {
	int N, M, K, i, j, t1, t2;
	scanf("%d %d %d", &N, &M, &K);

	int c = N - 1;
	for (i = 1; i <= M; i++) {
		scanf("%d %d", &t1, &t2);
		if (t1 > t2) swap(t1, t2);
		if (t1 == 1) c--;
		E.push_back(pii(t1, t2));
	}

	if (c < K || get_gcnt(N) != 1) return !printf("impossible\n");

	for (i = 2; i <= N; i++) E.push_back(pii(1, i));
	sort(E.begin(), E.end());
	E.erase(unique(E.begin(), E.end()), E.end());

	if (get_gcnt(N) > K + 1) return !printf("impossible\n");
	return !printf("possible\n");
}
//*/