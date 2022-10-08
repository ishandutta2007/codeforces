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
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size()) 
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

int IT_MAX = 1 << 19;
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int in[105][105];

db dp[10][105];

db dp2[10][105];
int main() {
	int N, i, j, k, l;
	scanf("%d", &N);
	for (i = 0; i < (1 << N); i++) for (j = 0; j < (1 << N); j++) scanf("%d", &in[i][j]);

	for (i = 0; i < (1 << N); i++) dp[0][i] = 1;
	for (i = 1; i <= N; i++) {
		int sz = 1 << (i - 1);
		for (j = 0; j < (1 << (N - i)); j++) {
			int st = j * 2 * sz;
			for (k = st; k < st + sz; k++) {
				for (l = st + sz; l < st + sz * 2; l++) {
					dp[i][k] += dp[i - 1][k] * dp[i - 1][l] * in[k][l] / 100;
					dp[i][l] += dp[i - 1][k] * dp[i - 1][l] * in[l][k] / 100;
				}
			}
		}
	}
	for (i = 1; i <= N; i++) {
		int sz = 1 << (i - 1);
		for (j = 0; j < (1 << (N - i)); j++) {
			int st = j * 2 * sz;
			for (k = st; k < st + sz; k++) {
				for (l = st + sz; l < st + sz * 2; l++) {
					dp2[i][k] = max(dp2[i][k], dp2[i - 1][k] + dp2[i - 1][l] + (1<<(i-1)) * dp[i][k]);
				}
			}
			for (k = st + sz; k < st + 2 * sz; k++) {
				for (l = st; l < st + sz; l++) {
					dp2[i][k] = max(dp2[i][k], dp2[i - 1][k] + dp2[i - 1][l] + (1<<(i-1)) * dp[i][k]);
				}
			}
		}
	}

	db ans = 0;
	for (i = 0; i < (1 << N); i++) ans = max(ans, dp2[N][i]);
	return !printf("%.20lf\n", ans);
}