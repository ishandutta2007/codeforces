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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

int r[1050][2];
int root(int x) {
	if (r[x][0] == x) return r[x][0];

	int t = r[x][0];
	r[x][0] = root(r[x][0]);
	r[x][1] ^= r[t][1];
	return r[x][0];
}

pair <pii, pii> in[500050];
int main() {
	int N, Q, M, i, j, t1, t2, t3, S, E;

	scanf("%d %d %d", &N, &M, &Q);
	for (i = 1; i <= M; i++) {
		scanf("%d %d %d", &t1, &t2, &t3);
		in[i] = mp(pii(t3, i), pii(t1, t2));
	}
	sort(in + 1, in + M + 1);
	
	while (Q--) {
		scanf("%d %d", &S, &E);
		for (i = 1; i <= N; i++) r[i][0] = i, r[i][1] = 0;
		
		for (i = M; i >= 1; i--) {
			if (in[i].first.second < S || in[i].first.second > E) continue;
			t1 = in[i].second.first;
			t2 = in[i].second.second;
			int u1 = root(t1);
			int u2 = root(t2);
			int u3 = r[t1][1] ^ r[t2][1] ^ 1;
			if (u1 == u2 && u3 == 1) break;

			r[u1][0] = u2;
			r[u1][1] = u3;
		}
		if (i == 0) printf("-1\n");
		else printf("%d\n", in[i].first.first);
	}
	return 0;
}