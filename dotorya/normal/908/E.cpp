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

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int r[1050];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}
char in[55][1050];

int sz[1050];
ll dp[1050];
ll C[1050][1050];
int main() {
	int M, N, i, j, k;
	scanf("%d %d", &M, &N);
	for (i = 0; i <= 1000; i++) {
		C[i][0] = C[i][i] = 1;
		for (j = 1; j < i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
	}
	dp[0] = dp[1] = 1;
	for (i = 2; i <= 1000; i++) {
		dp[i] = 0;
		for (j = 0; j <= i - 1; j++) dp[i] = (dp[i] + dp[i - 1 - j] * C[i - 1][j]) % MOD;
	}

	for (i = 0; i < N; i++) scanf("%s", in[i]);

	for (i = 0; i < M; i++) r[i] = i;
	for (i = 0; i < M; i++) {
		for (j = 0; j < i; j++) {
			for (k = 0; k < N; k++) if (in[k][i] != in[k][j]) break;
			if (k >= N) r[root(i)] = root(j);
		}
	}

	int c = 0;
	for (i = 0; i < M; i++) sz[root(i)]++;


	ll ans = 1;
	for (i = 0; i < M; i++) ans = ans * dp[sz[i]] % MOD;
	return !printf("%lld\n", ans);
}