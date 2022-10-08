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

int dp[1050][1050][21];
char in1[1050];
char in2[1050];
int main() {
	int N, M, K, i, j, k;
	scanf("%d %d %d", &N, &M, &K);
	scanf("%s %s", in1 + 1, in2 + 1);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			for (k = 0; k <= 2 * K; k++) {
				if (k) dp[i][j][k] = max(dp[i][j][k - 1], dp[i][j][k]);
				if (k % 2 && in1[i] == in2[j]) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + 1);
				if (k % 2 == 0) {
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
					dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
				}
			}
		}
	}
	return !printf("%d\n", dp[N][M][K * 2]);
}