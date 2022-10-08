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
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

ll in[20];
ll po10[20];
int main() {
	ll N, i, j;
	scanf("%lld", &N);
	for (i = 0; i <= 18; i++, N /= 10) in[i] = N % 10;

	po10[0] = 1;
	for (i = 1; i <= 18; i++) po10[i] = po10[i - 1] * 10;
	
	ll mn = -INF, ans = 0;
	ll s = 0, v = 0;
	for (i = 18; i >= 0; i--) {
		if (in[i] == 0) continue;
		ll t = s + (in[i] - 1) + 9 * i;
		if (mn <= t) {
			ans = v + in[i] * po10[i] - 1;
			mn = t;
		}

		s += in[i];
		v += in[i] * po10[i];
	}
	if (mn <= s) {
		mn = s;
		ans = v;
	}
	return !printf("%lld\n", ans);
}