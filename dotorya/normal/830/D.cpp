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

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple <int, int, int> t3;

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

ll dp[405][405];
int main() {
	int i, j, k, N;
	scanf("%d", &N);
	N--;
	dp[0][0] = dp[0][1] = 1;

	for (i = 1; i <= N; i++) {
		dp[i][0] = 1;
		for (j = 1; j <= N + 1 - i; j++) {
			for (k = 0; k <= j; k++) dp[i][j] = (dp[i][j] + dp[i - 1][k] * dp[i - 1][j - k]) % MOD;
			for (k = 0; k <= j + 1; k++) {
				ll v = dp[i - 1][k] * dp[i - 1][j + 1 - k] % MOD;
				v = (v * j * (j + 1)) % MOD;
				dp[i][j] = (dp[i][j] + v) % MOD;
			}
			dp[i][j] = (dp[i][j] + 4 * j*dp[i - 1][j]) % MOD;
			for (k = 1; k < j; k++) {
				ll v = dp[i - 1][k] * dp[i - 1][j - k] % MOD;
				v = (v * 2 * j) % MOD;
				dp[i][j] = (dp[i][j] + v) % MOD;
			}
			for (k = 0; k < j; k++) dp[i][j] = (dp[i][j] + dp[i - 1][k] * dp[i - 1][j - 1 - k]) % MOD;
		}
	}
	return !printf("%lld\n", dp[N][1]);
}