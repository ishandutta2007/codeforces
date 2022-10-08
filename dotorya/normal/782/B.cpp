#include <stdio.h>
#include <algorithm>
#include <assert.h>
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
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
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
const ll MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

ll in1[60050];
ll in2[60050];
ll mymul(ll a, ll b) {
	if ((2 * LL_INF) / b < a) return 2 * LL_INF;
	else return a*b;
}
int main() {

	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%lld", &in1[i]);
	for (i = 1; i <= N; i++) scanf("%lld", &in2[i]);

	ldb st = 0, en = INF;
	for (j = 1; j <= 100; j++) {
		ldb t1 = (st + en) / 2;
		ldb mn = -LL_INF, mx = LL_INF;

		ldb T = t1;
		for (i = 1; i <= N; i++) {
			mn = max(mn, in1[i] - in2[i] * T);
			mx = min(mx, in1[i] + in2[i] * T);
		}
		if (mn < mx) en = t1;
		else st = t1;
	}
	return !printf("%.20lf\n", (db)en);
}