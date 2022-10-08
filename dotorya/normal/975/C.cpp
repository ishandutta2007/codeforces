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
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 17;
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

ll in[200050];
ll sum[200050];
int main() {
	int N, Q, i, j, k, l;
	scanf("%d %d", &N, &Q);
	for (i = 1; i <= N; i++) scanf("%lld", &in[i]);

	for (i = N; i >= 1; i--) sum[i] = sum[i + 1] + in[i];
	
	ll cur = sum[1];
	while (Q--) {
		ll t;
		scanf("%lld", &t);
		cur -= t;
		if (cur <= 0) cur = sum[1];

		if (N == 1) {
			printf("1\n");
			continue;
		}

		ll st = 1, en = N, mi, rv = N + 1;
		while (st <= en) {
			mi = (st + en) / 2;
			if (cur > sum[mi]) {
				rv = mi;
				en = mi - 1;
			}
			else st = mi + 1;
		}
		printf("%lld\n", N + 2 - rv);
	}
	return 0;
}