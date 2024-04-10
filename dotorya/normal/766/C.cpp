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
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const db EPS = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

int val[26];
char in[1050];
ll dp[1050][3];

int main() {
	int N, i, j;
	scanf("%d %s", &N, in + 1);
	for (i = 0; i < 26; i++) scanf("%d", &val[i]);

	dp[0][0] = 1, dp[0][1] = 0, dp[0][2] = 0;
	for (i = 1; i <= N; i++) {
		dp[i][2] = INF;
		
		int len = 0, mx = INF;
		for (j = i; j >= 1; j--) {
			len++, mx = min(mx, val[in[j] - 'a']);
			if (len > mx) break;

			dp[i][0] = (dp[i][0] + dp[j - 1][0]) % MOD;
			dp[i][1] = max(dp[i][1], max((ll)len, dp[j - 1][1]));
			dp[i][2] = min(dp[i][2], dp[j - 1][2] + 1);
		}
	}
	return !printf("%lld\n%lld\n%lld\n", dp[N][0], dp[N][1], dp[N][2]);
}