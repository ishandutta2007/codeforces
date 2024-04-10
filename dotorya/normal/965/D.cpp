#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")

using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18; // segment tree size
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f; // memset(dp, 0x3f, sizeof(dp)), 2*INF < INT_MAX
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10; // double EPS

ll in[100050];

ll sum[100050];
int main() {
	ll N, K, i, j, k;
	sum[0] = INF + 2;
	scanf("%lld %lld", &N, &K);
	for (i = 1; i < N; i++) {
		scanf("%lld", &in[i]);
		sum[i] = sum[i - 1] + in[i];
	}
	sum[N] = sum[N - 1] + INF + 2;
	
	ll st = 1, en = INF, mi, rv = 0;
	while (st <= en) {
		mi = (st + en) / 2;
		for (i = 0; i < N; i++) {
			int p = lower_bound(sum, sum + N + 1, sum[i] + mi) - sum;
			if (p - i > K) break;
		}
		if (i >= N) {
			rv = mi;
			st = mi + 1;
		}
		else en = mi - 1;
	}
	return !printf("%lld\n", rv);
}