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

int IT_MAX = 1 << 21;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-12;

int it[2100000];
void update(int p, int v) {
	p += IT_MAX - 1;
	for (; p; p /= 2) it[p] ^= v;
}
int getsum(int p1, int p2) {
	p1 += IT_MAX - 1;
	p2 += IT_MAX - 1;
	int rv = 0;
	while (p1 <= p2) {
		if (p1 % 2 == 1) rv ^= it[p1++];
		if (p2 % 2 == 0) rv ^= it[p2--];
		p1 /= 2, p2 /= 2;
	}
	return rv;
}

map <int, int> Mx;
int in[1000050];
int sum[1000050];
int nxt[1000050];

pair<pii, int> Q[1000050];
int ans[1000050];
int main() {
	int N, i, t, M;
	scanf("%d", &N);
	for (IT_MAX = 2; IT_MAX < N; IT_MAX *= 2);
	for (i = 1; i <= N; i++) {
		scanf("%d", &in[i]);
		if (Mx.count(in[i])) nxt[Mx[in[i]]] = i;
		else update(i, in[i]);
		Mx[in[i]] = i;

		sum[i] = sum[i - 1] ^ in[i];
	}

	scanf("%d", &M);
	for (i = 1; i <= M; i++) {
		Q[i].second = i;
		scanf("%d %d", &Q[i].first.first, &Q[i].first.second);
	}
	sort(Q + 1, Q + M + 1);

	int p = 1;
	for (i = 1; i <= N; i++) {
		while (p <= M) {
			if (Q[p].first.first != i) break;
			ans[Q[p].second] = getsum(Q[p].first.first, Q[p].first.second) ^ sum[Q[p].first.second] ^ sum[Q[p].first.first - 1];
			p++;
		}
		update(i, in[i]);
		if (nxt[i] != 0) update(nxt[i], in[i]);
	}
	for (i = 1; i <= M; i++) printf("%d\n", ans[i]);
	return 0;
}