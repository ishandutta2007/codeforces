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

int IT_MAX = 1 << 20;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
//#define Se second
#define Fi first

ll in[1050];
int main() {
	int N, k1, k2, i, j, k;
	scanf("%d %d %d", &N, &k1, &k2);
	int K = k1 + k2;
	for (i = 1; i <= N; i++) {
		ll t;
		scanf("%lld", &t);
		in[i] += t;
	}
	for (i = 1; i <= N; i++) {
		ll t;
		scanf("%lld", &t);
		in[i] -= t;
	}

	while (K--) {
		int mxp = 1;
		for (i = 2; i <= N; i++) if (abs(in[mxp]) < abs(in[i])) mxp = i;

		if (in[mxp] >= 0) in[mxp]--;
		else in[mxp]++;
	}

	ll ans = 0;
	for (i = 1; i <= N; i++) ans += in[i] * in[i];
	return !printf("%lld\n", ans);
}