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

int in[400050];

vector <pii> V;
int it1[1100000];
void update(int p, int v, int* it) {
	p += IT_MAX - 1;
	it[p] = v;
	for (p /= 2; p > 0; p /= 2) it[p] = max(it[2 * p], it[2 * p + 1]);
}
int getmx(int p1, int p2, int* it) {
	p1 += IT_MAX - 1;
	p2 += IT_MAX - 1;
	int rv = 0;
	while (p1 <= p2) {
		if (p1 % 2 == 1) rv = max(rv, it[p1++]);
		if (p2 % 2 == 0) rv = max(rv, it[p2--]);
		p1 /= 2, p2 /= 2;
	}
	return rv;
}

int ldp[400050];
int rdp[400050];
int cnt[400050];
bool chk[400050];
int ans[400050];
int lv[400050];
int rv[400050];

vector <pair<pii, int>> Q;
int main() {
	int N, M, i, j, t1, t2;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);

	for (IT_MAX = 2; IT_MAX < N; IT_MAX *= 2);

	for (i = 1; i <= N; i++) V.push_back(pii(in[i], -i));
	sort(V.begin(), V.end());
	for (auto it : V) {
		ldp[-it.second] = getmx(1, -it.second - 1, it1) + 1;
		update(-it.second, ldp[-it.second], it1);
	}

	for (i = 1; i < 2 * IT_MAX; i++) it1[i] = 0;
	for (i = V.size() - 1; i >= 0; i--) {
		auto it = V[i];
		rdp[-it.second] = getmx(-it.second + 1, N, it1) + 1;
		update(-it.second, rdp[-it.second], it1);
	}

	int lmx = 0;
	for (i = 1; i <= N; i++) lmx = max(lmx, ldp[i]);
	for (i = 1; i <= N; i++) if (ldp[i] + rdp[i] - 1 == lmx) cnt[ldp[i]]++;
	for (i = 1; i <= N; i++) if (ldp[i] + rdp[i] - 1 == lmx && cnt[ldp[i]] == 1) chk[i] = true;

	for (i = 0; i < M; i++) {
		scanf("%d %d", &t1, &t2);
		Q.push_back(mp(pii(t2, t1), i));
	}
	sort(Q.begin(), Q.end());

	V.clear();
	for (i = 1; i <= N; i++) V.push_back(pii(in[i], i));
	sort(V.begin(), V.end());

	int p = 0;
	for (i = 1; i < 2 * IT_MAX; i++) it1[i] = 0;
	for (i = 0; i < M; i++) {
		while (p != V.size() && V[p].first < Q[i].first.first) {
			update(V[p].second, ldp[V[p].second], it1);
			p++;
		}
		lv[Q[i].second] = getmx(1, Q[i].first.second - 1, it1) + 1;
	}

	for (i = 1; i < 2 * IT_MAX; i++) it1[i] = 0;
	p = (int)V.size() - 1;
	for (i = M - 1; i >= 0; i--) {
		while (p != -1 && V[p].first > Q[i].first.first) {
			update(V[p].second, rdp[V[p].second], it1);
			p--;
		}
		rv[Q[i].second] = getmx(Q[i].first.second + 1, N, it1) + 1;
	}

	for (i = 0; i < M; i++) {
		int ux = lmx;
		if (chk[Q[i].first.second]) ux = lmx - 1;
		ux = max(ux, lv[Q[i].second] + rv[Q[i].second] - 1);
		ans[Q[i].second] = ux;
	}

	for (i = 0; i < M; i++) printf("%d\n", ans[i]);
	return 0;
}