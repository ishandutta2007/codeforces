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
ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int dp[1050];

char u[1050];
int in[1050];
ll C[1050][1050];
int main() {
	int i, j, k;

	dp[0] = INF;
	dp[1] = 0;
	for (i = 2; i <= 1002; i++) {
		int c = 0, t = i;
		while (t) {
			c += t % 2;
			t /= 2;
		}
		dp[i] = dp[c] + 1;
	}
	
	int K;
	scanf("%s %d", u, &K);
	int L = strlen(u);
	for (i = 0; i < L; i++) in[L - 1 - i] = u[i] - '0';

	if (K == 0) return !printf("1\n");

	for (i = 0; i <= 1000; i++) {
		C[i][0] = C[i][i] = 1;
		for (j = 1; j < i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
	}

	ll ans = 0;
	int c1 = 0;
	in[0]++;
	for (i = L - 1; i >= 0; i--) {
		for (j = 0; j < in[i]; j++) {
			int tc1 = c1 + (int)(j == 1);
			for (k = 0; k <= i; k++) {
				int c = 1 + dp[tc1 + k];
				if (c == K) ans = (ans + C[i][k]) % MOD;
			}
		}
		if (in[i] == 1) c1++;
	}
	if (K == 1) ans = (ans + MOD - 1) % MOD;
	return !printf("%lld\n", ans);
}
//*/