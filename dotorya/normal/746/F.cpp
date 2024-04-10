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
const ll MOD = 5000000;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-11;

pii operator + (pii a, pii b) {
	return pii(a.first + b.first, a.second + b.second);
}
pii it[40000];
void update(int p, int v) {
	int op = p;
	p += IT_MAX - 1;
	it[p].first += v * (op / 2);
	it[p].second += v;
	for (p /= 2; p; p /= 2) it[p] = it[2 * p] + it[2 * p + 1];
}
int getval(int w) {
	if (it[1].second <= w) return it[1].first;

	int rv = 0, i;
	for (i = 1; i < IT_MAX;) {
		if (it[2 * i + 1].second > w) {
			i = 2 * i + 1;
		}
		else {
			rv += it[2 * i + 1].first;
			w -= it[2 * i + 1].second;
			i = 2 * i;
		}
	}
	return rv + w * ((i - IT_MAX + 1) / 2);
}
int A[200050];
int T[200050];
int Asum[200050];
int Tsum[200050];
int main() {
	int N, W, K, i;
	scanf("%d %d %d", &N, &W, &K);
	for (i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		Asum[i] = Asum[i - 1] + A[i];
	}
	for (i = 1; i <= N; i++) {
		scanf("%d", &T[i]);
		Tsum[i] = Tsum[i - 1] + T[i];
	}
	
	int ans = 0;
	int st = 1, en = 1;
	update(T[1], 1);
	while (en <= N) {
		int v = Tsum[en] - Tsum[st - 1] - getval(W);
		if (v <= K) {
			ans = max(ans, Asum[en] - Asum[st - 1]);
			update(T[++en], 1);
		}
		else update(T[st++], -1);
	}
	return !printf("%d\n", ans);
}