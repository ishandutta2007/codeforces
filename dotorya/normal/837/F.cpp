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
#pragma comment(linker, "/STACK:1048576")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple <int, int, int> t3;

int IT_MAX = 1 << 18;
const ll MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const db EPS = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

ll mymul(ll a, ll b) {
	if (a == 0 || b == 0) return 0;
	if (LL_INF / b < a) return LL_INF;
	return min(LL_INF, a*b);
}

ll C1[1050][1050];
ll C2[2200050][11];
ll C(ll a, ll b) {
	if (a <= 1000) return C1[a][b];
	
	if (b >= a / 2) b = a - b;

	if (b == 0) return 1;
	if (b == 1) return a;
	if (b == 2) return mymul(a, a - 1) / 2;
	if (a >= 2200000) return LL_INF;
	if (b <= 10) return C2[a][b];
	else return LL_INF;
}

ll in[200050];
int main() {
	int i, j;
	for (i = 0; i <= 1000; i++) {
		C1[i][0] = C1[i][i] = 1;
		for (j = 1; j < i; j++) C1[i][j] = min(C1[i - 1][j] + C1[i - 1][j - 1], LL_INF);
	}
	for (i = 0; i <= 2200000; i++) {
		C2[i][0] = 1;
		if (i <= 10) C2[i][i] = 1;
		for (j = 1; j < i && j <= 10; j++) C2[i][j] = min(C2[i - 1][j] + C2[i - 1][j - 1], LL_INF);
	}

	int N;
	ll K;
	scanf("%d %lld", &N, &K);
	int st = N;
	for (i = 1; i <= N; i++) {
		scanf("%lld", &in[i]);
		if (in[i] >= K) return !printf("0\n");
		if (in[i]) st = min(st, i);
	}
	
	ll s = 1, e = LL_INF, m, r = LL_INF + 1;
	if (st < N - 2) e = 2000000;

	while (s <= e) {
		m = (s + e) / 2;

		ll v = 0;
		for (i = 1; i <= N; i++) v = min(LL_INF, v + mymul(C(N - i + m - 1, m - 1), in[i]));
		if (v >= K) {
			r = m;
			e = m - 1;
		}
		else s = m + 1;
	}
	return !printf("%lld\n", r);
}