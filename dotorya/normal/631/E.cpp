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
const ldb ERR = 1E-12;

const int NMX = 200000 + 50;

pll operator - (pll a, pll b) {
	return pll(a.first - b.first, a.second - b.second);
}
ll A[NMX];
ll sum[NMX];

pll tmp[NMX];

vector <pll> ch;
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
		sum[i] = sum[i - 1] + A[i];
		tmp[i] = pll(i, -sum[i]);
	}

	for (i = 0; i <= N; i++) {
		pll u = tmp[i];

		while (ch.size() >= 2) {
			pll u1 = ch.back() - ch[ch.size() - 2];
			pll u2 = u - ch[ch.size() - 2];

			if (u1.first * u2.second < u2.first * u1.second) break;
			ch.pop_back();
		}
		ch.push_back(tmp[i]);
	}

	ll ans = 0;
	for (i = 1; i <= N; i++) {
		int st = 0, en = (int)ch.size() - 2, mi, rv = ch.size() - 1;
		while (st <= en) {
			mi = (st + en) / 2;
			ll t1 = ch[mi].first * A[i] + ch[mi].second;
			ll t2 = ch[mi + 1].first * A[i] + ch[mi + 1].second;
			if (t1 > t2) {
				rv = mi;
				en = mi - 1;
			}
			else st = mi + 1;
		}
		ans = max(ans, ch[rv].first * A[i] + ch[rv].second + sum[i] - i * A[i]);
	}
	
	for (i = 1; i <= N; i++) ans += i * A[i];
	printf("%lld\n", ans);
	return 0;
}
//*/