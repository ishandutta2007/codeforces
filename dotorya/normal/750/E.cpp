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
#include <cmath>
#include <vector>
#include <deque>
//#include <unordered_set>
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

int IT_MAX = 1 << 14;
const ll MOD = 1000000000;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

struct datax {
public:
	int v[5][5];
	datax() {
		for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) v[i][j] = INF;
	}
	datax(int c) {
		int i, j;
		for (i = 0; i < 5; i++) for (j = 0; j < 5; j++) v[i][j] = INF;
		v[0][0] = (c == 2) ? 1 : 0;
		v[0][1] = (c == 2) ? 0 : INF;
		v[1][1] = (c == 0) ? 1 : 0;
		v[1][2] = (c == 0) ? 0 : INF;
		v[2][2] = (c == 1) ? 1 : 0;
		v[2][3] = (c == 1) ? 0 : INF;
		v[3][3] = (c == 6 || c == 7) ? 1 : 0;
		v[3][4] = (c == 7) ? 0 : INF;
		v[4][4] = (c == 6) ? 1 : 0;
	}
} it[530000];
datax mymerge(datax& a, datax& b) {
	datax rv = datax();
	int i, j, k;
	for (i = 0; i < 5; i++) {
		for (j = i; j < 5; j++) {
			for (k = j; k < 5; k++) {
				rv.v[i][k] = min(rv.v[i][k], a.v[i][j] + b.v[j][k]);
			}
		}
	}
	return rv;
}
void update(int p, char c) {
	p += IT_MAX - 1;
	it[p] = datax(c);
	for (p /= 2; p; p /= 2) it[p] = mymerge(it[2 * p], it[2 * p + 1]);
}
int getans(int p1, int p2) {
	p1 += IT_MAX - 1;
	p2 += IT_MAX - 1;

	vector <int> V1;
	vector <int> V2;

	while (p1 <= p2) {
		if (p1 % 2 == 1) {
			V1.push_back(p1);
			p1++;
		}
		if (p2 % 2 == 0) {
			V2.push_back(p2);
			p2--;
		}
		p1 /= 2, p2 /= 2;
	}
	while (!V2.empty()) {
		V1.push_back(V2.back());
		V2.pop_back();
	}

	int dp[5] = { 0,INF,INF,INF,INF };
	int tdp[5];
	for (auto u : V1) {
		int i, j;
		for (i = 0; i < 5; i++) tdp[i] = INF;
		for (i = 0; i < 5; i++) for (j = i; j < 5; j++) tdp[j] = min(tdp[j], dp[i] + it[u].v[i][j]);
		for (i = 0; i < 5; i++) dp[i] = tdp[i];
	}
	V1.clear();
	return dp[4];
}

char in[200050];
int main() {
	int N, Q, i, t1, t2;
	scanf("%d %d", &N, &Q);
	scanf("%s", in + 1);

	for (IT_MAX = 2; IT_MAX < N; IT_MAX *= 2);
	for (i = 1; i <= N; i++) update(i, in[i] - '0');
	while (Q--) {
		scanf("%d %d", &t1, &t2);
		int rv = getans(t1, t2);
		if (rv > N) rv = -1;
		printf("%d\n", rv);
	}
	return 0;
}