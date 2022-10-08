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

int main() {
	int mn1 = INF, mx1 = -INF, mn2 = INF, mx2 = -INF;

	int N, M, i, j;
	scanf("%d", &N);
	while (N--) {
		scanf("%d %d", &i, &j);
		mx1 = max(mx1, i);
		mn1 = min(mn1, j);
	}
	scanf("%d", &M);
	while (M--) {
		scanf("%d %d", &i, &j);
		mx2 = max(mx2, i);
		mn2 = min(mn2, j);
	}

	int ans = 0;
	ans = max(ans, mx2 - mn1);
	ans = max(ans, mx1 - mn2);
	return !printf("%d\n", ans);
}