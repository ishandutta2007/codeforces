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
const ldb ERR = 1E-8;

int in[100050];
vector <int> rin[100050];

pii IT[300050];
void update(int p, pii v) {
	p += IT_MAX - 1;
	IT[p] = v;
	for (p /= 2; p; p /= 2) IT[p] = max(IT[2 * p], IT[2 * p + 1]);
}
pii getmx(int p1, int p2) {
	p1 += IT_MAX - 1;
	p2 += IT_MAX - 1;
	pii rv = pii(-1, -1);
	while (p1 <= p2) {
		if (p1 % 2 == 1) rv = max(rv, IT[p1++]);
		if (p2 % 2 == 0) rv = max(rv, IT[p2--]);
		p1 /= 2, p2 /= 2;
	}
	return rv;
}

int cnt[100050];
int main() {
	int N, i;
	scanf("%d", &N);
	for (IT_MAX = 2; IT_MAX < N; IT_MAX *= 2);
	for (i = 1; i < N; i++) {
		scanf("%d", &in[i]);
		rin[in[i]].push_back(i);
		update(i, pii(in[i], i));
	}

	ll ans = 0, v = 0;
	for (i = 2; i <= N; i++) {
		cnt[i-1]++;
		v++;
		for (auto it : rin[i - 1]) {
			v += cnt[it];
			pii u = getmx(it + 1, in[it]);
			cnt[u.second] += cnt[it];
			cnt[it] = 0;
		}
		ans += v;
	}
	return !printf("%lld\n", ans);
}