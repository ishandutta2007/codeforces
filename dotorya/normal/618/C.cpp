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

int IT_MAX = 131072;
const ll MOD = 1000000007;
const int INF = 2034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-10;

pair<pll, int> in[100050];
int main() {
	int N, i, t1, t2;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d %d", &t1, &t2);
		in[i] = make_pair(pii(t1, t2), i);
	}
	sort(in + 1, in + N + 1);

	for (i = 1; i <= N - 2; i++) {
		ll x1 = in[i + 1].first.first - in[i].first.first;
		ll y1 = in[i + 1].first.second - in[i].first.second;
		ll x2 = in[i + 2].first.first - in[i].first.first;
		ll y2 = in[i + 2].first.second - in[i].first.second;

		if (x1 * y2 != x2*y1) return !printf("%d %d %d\n", in[i].second, in[i + 1].second, in[i + 2].second);
	}
	while (1);
	return 0;
}