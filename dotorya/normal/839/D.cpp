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

int IT_MAX = 1 << 12;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

ll cnt1[1000050];
ll cnt2[1000050];
ll po2[200050];
ll dp[1000050];
int main() {
	int N, i, j;
	scanf("%d", &N);

	po2[0] = 1;
	for (i = 1; i <= N; i++) po2[i] = po2[i - 1] * 2 % MOD;
	for (i = 1; i <= N; i++) {
		int t;
		scanf("%d", &t);
		cnt1[t]++;
	}
	for (i = 1; i <= 1000000; i++) for (j = i; j <= 1000000; j += i) cnt2[i] += cnt1[j];

	for (i = 1000000; i >= 1; i--) {
		if (cnt2[i] == 0) continue;
		dp[i] = (po2[cnt2[i] - 1] * cnt2[i]) % MOD;
		for (j = 2 * i; j <= 1000000; j += i) dp[i] = (dp[i] + MOD - dp[j]) % MOD;
	}

	ll ans = 0;
	for (i = 2; i <= 1000000; i++) ans = (ans + i * dp[i]) % MOD;
	return !printf("%lld\n", ans);
}