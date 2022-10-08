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
const int INF = 2034567891;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

queue <ll> Q;

ll ans[200050];
int main() {
	ll N, B, i, t1, t2, t3;
	scanf("%lld %lld", &N, &B);
	fill(ans + 1, ans + N + 1, -1);
	for (i = 1; i <= N; i++) {
		scanf("%lld %lld", &t1, &t2);
		while (!Q.empty() && Q.front() <= t1) Q.pop();

		if (Q.size() > B) continue;
		if (Q.empty()) t3 = t1 + t2;
		else t3 = Q.back() + t2;
		Q.push(t3);
		ans[i] = t3;
	}
	for (i = 1; i <= N; i++) printf("%lld ", ans[i]);
	return 0;
}