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
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int in1[100050];
int in2[100050];
ll sum1[100050];
ll sum2[100050];
int main() {
	int N, K, i, j;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) scanf("%d", &in1[i]);
	for (i = 1; i <= N; i++) scanf("%d", &in2[i]);
	for (i = 1; i <= N; i++) {
		sum1[i] = sum1[i - 1] + in1[i] * in2[i];
		sum2[i] = sum2[i - 1] + in1[i];
	}

	ll mx = 0;
	for (i = 1; i <= N - K + 1; i++) {
		ll v = sum1[i - 1] + (sum2[i + K - 1] - sum2[i - 1]) + (sum1[N] - sum1[i + K - 1]);
		mx = max(mx, v);
	}
	return !printf("%lld\n", mx);
}