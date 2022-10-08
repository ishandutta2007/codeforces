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
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-9;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

bool pchk[10000050];
int val[10000050];
int mn[10000050];
ll sum[10000050];
int main() {
	int N, i, j;
	scanf("%d", &N);
	if (N <= 2) return !printf("0\n");

	for (i = 1; i <= N; i++) val[i] = 1;
	
	int c1 = 0;
	for (i = 2; i <= N; i++) {
		if (pchk[i]) continue;
		
		if (i * 2 > N) c1++;
		for (j = 2 * i; j <= N; j += i) pchk[j] = true;
		for (j = i; j <= N; j += i) {
			if (!mn[j]) mn[j] = i;
			int c = 0, t = j;
			while (t%i == 0) {
				c++;
				t /= i;
			}
			if (c == 1) val[j] *= -1;
			else val[j] = 0;
		}
	}
	for (i = 2; i <= N; i++) if (mn[i] * 2 <= N) sum[mn[i]]++;
	for (i = 1; i <= N; i++) sum[i] += sum[i - 1];
	ll v1 = 0, v2 = 0;
	for (i = 1; i <= N; i++) v1 += (ll)(N / i)*(N / i)*val[i];
	v2 = (ll)N*N - v1;

	v1 -= 2 * N - 1;
	v2 -= N - 1;
	v1 -= (ll)2 * c1*(N - 2) - (ll)c1*(c1 - 1);
	v1 /= 2, v2 /= 2;

	ll ans = v1 * 2 + v2;
	for (i = 2; i <= N; i++) {
		int t = max(i+1, (N + i) / i);
		ans += (sum[i] - sum[i - 1]) * (sum[N] - sum[t - 1]);
		if (t <= i) ans -= (sum[i] - sum[i - 1]) * (sum[i] - sum[i - 1]);
	}
	return !printf("%lld\n", ans);
}