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
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-16;

unordered_map <int, int> Mx;
int ch(int x) {
	if (Mx.count(x)) return Mx[x];
	int t = Mx.size();
	Mx[x] = t;
	return t;
}
vector <int> it[1000050];
int sz[1000050];
void update(int x, int p, int v) {
	for (p += sz[x]; p; p /= 2) it[x][p] += v;
}
int getsum(int x, int p1, int p2) {
	p1 += sz[x];
	p2 += sz[x];
	int rv = 0;
	while (p1 <= p2) {
		if (p1 % 2 == 1) rv += it[x][p1++];
		if (p2 % 2 == 0) rv += it[x][p2--];
		p1 /= 2, p2 /= 2;
	}
	return rv;
}

vector <int> val[1000050];

int in[1000050][3];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d %d %d", &in[i][0], &in[i][1], &in[i][2]);
		in[i][2] = ch(in[i][2]);
		val[in[i][2]].push_back(in[i][1]);
	}

	for (i = 0; i < Mx.size(); i++) {
		sort(val[i].begin(), val[i].end());
		val[i].erase(unique(val[i].begin(), val[i].end()), val[i].end());
		for (sz[i] = 2; sz[i] < val[i].size(); sz[i] *= 2);
		for (j = 0; j < 2 * sz[i]; j++) it[i].push_back(0);
	}

	for (i = 1; i <= N; i++) {
		int x = in[i][2];
		int st = 0, en = (int)val[x].size() - 1, mi, rv = -1;
		while (st <= en) {
			mi = (st + en) / 2;
			if (val[x][mi] == in[i][1]) {
				rv = mi;
				break;
			}
			if (val[x][mi] > in[i][1]) en = mi - 1;
			else st = mi + 1;
		}
		if (rv == -1) while (1);

		if (in[i][0] == 1) update(x, rv, 1);
		if (in[i][0] == 2) update(x, rv, -1);
		if (in[i][0] == 3) printf("%d\n", getsum(x, 0, rv));
	}
	return 0;
}