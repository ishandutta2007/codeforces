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
const int MOD = 1000;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

char in[500050];
int sa[20][500050];
int rsa[500050];

int u[500050];
int u2[500050];
int cnt[500050];
int pos[500050];
int mn[500050];
vector <int> V[1000050];
inline int sa_val(int i, int j, int N) {
	if ((j + (1 << i)) > N) return 0;
	return sa[i][j + (1 << i)];
}
void getSA(int N) {
	int i, j, k;
	for (i = 1; i <= N; i++) u[i] = i;
	sort(u + 1, u + N + 1, [](int a, int b) {
		if (in[a] != in[b]) return in[a] < in[b];
		else return a < b;
	});
	for (i = 1, j = 0; i <= N; i++) {
		if (i == 1 || in[u[i]] != in[u[i-1]]) j++;
		sa[0][u[i]] = j;
	}

	for (i = 1; i <= 19; i++) {
		fill(cnt, cnt + N + 1, 0);
		for (j = 1; j <= N; j++) cnt[sa_val(i-1, j, N)]++;
		pos[0] = 1;
		for (j = 1; j <= N; j++) pos[j] = pos[j - 1] + cnt[j - 1];
		for (j = 1; j <= N; j++) u[pos[sa_val(i - 1, j, N)]++] = j;

		fill(cnt, cnt + N + 1, 0);
		for (j = 1; j <= N; j++) cnt[sa[i - 1][j]]++;
		pos[1] = 1;
		for (j = 2; j <= N; j++) pos[j] = pos[j - 1] + cnt[j - 1];
		for (j = 1; j <= N; j++) u2[pos[sa[i - 1][u[j]]]++] = u[j];

		for (j = 1, k = 0; j <= N; j++) {
			if (j == 1 || sa[i - 1][u2[j]] != sa[i - 1][u2[j - 1]] || sa_val(i - 1, u2[j], N) != sa_val(i - 1, u2[j - 1], N)) k++;
			sa[i][u2[j]] = k;
		}
	}
	
	for (i = 1; i <= N; i++) rsa[sa[19][i]] = i;
	rsa[0] = 0;
}
int lcp(int a, int b) {
	if (a == 0 || b == 0) return 0;
	int rv = 0, i;
	for (i = 19; i >= 0; i--) {
		if (sa[i][a] == sa[i][b]) {
			rv += (1 << i);
			a += (1 << i);
			b += (1 << i);
		}
	}
	return rv;
}

int it[1100000];
void update(int p, int v) {
	p += IT_MAX - 1;
	it[p] = v;
	for (p /= 2; p; p /= 2) it[p] = min(it[2 * p], it[2 * p + 1]);
}
int getmn(int p1, int p2) {
	p1 += IT_MAX - 1;
	p2 += IT_MAX - 1;
	int rv = INF;
	while (p1 <= p2) {
		if (p1 % 2 == 1) rv = min(rv, it[p1++]);
		if (p2 % 2 == 0) rv = min(rv, it[p2--]);
		p1 /= 2, p2 /= 2;
	}
	return rv;
}

int getv(int x, int y) {
	int st = 0, en = (int)V[x].size() - 1, mi, rv = -1;
	while (st <= en) {
		mi = (st + en) / 2;
		if (V[x][mi] <= y) {
			rv = mi;
			st = mi + 1;
		}
		else en = mi - 1;
	}
	return rv + 1;
}

int main() {
	int N, i;
	scanf("%d %s", &N, in + 1);

	getSA(N);

	for (IT_MAX = 2; IT_MAX <= N; IT_MAX *= 2);
	fill(it + 1, it + IT_MAX * 2, INF);
	int p = 500000;
	V[p].push_back(0);
	pos[0] = p;
	for (i = 1; i <= N; i++) {
		if (in[i] == '(') p++;
		else p--;
		V[p].push_back(i);
		pos[i] = p;
		update(i, pos[i]);
	}
	ll ans = 0;
	for (i = 1; i <= N; i++) {
		int mn = lcp(rsa[i], rsa[i - 1]);
		mn += rsa[i];

		int st = mn, en = N, mi, rv = st - 1;
		while (st <= en) {
			mi = (st + en) / 2;
			if (getmn(rsa[i], mi) >= pos[rsa[i] - 1]) {
				rv = mi;
				st = mi + 1;
			}
			else en = mi - 1;
		}

		ans += getv(pos[rsa[i] - 1], rv) - getv(pos[rsa[i] - 1], mn - 1);
	}
	printf("%lld\n", ans);
	return 0;
}
//*/