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

int IT_MAX = 1 << 20;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1E-11;

char in[20][105];
int dp[20][2];
int main() {
	int N, M, i, j, k;
	scanf("%d %d", &N, &M);
	for (i = N; i >= 1; i--) scanf("%s", in[i] + 1);

	while (N) {
		for (i = 1; i <= M + 2; i++) if (in[N][i] == '1') break;
		if (i <= M + 2) break;
		N--;
	}
	if (!N) return !printf("0\n");

	dp[1][0] = 0, dp[1][1] = INF;
	for (i = 1; i < N; i++) {
		int L = M + 2, R = 1;
		for (j = 2; j <= M + 1; j++) {
			if (in[i][j] == '0') continue;
			L = min(L, j);
			R = max(R, j);
		}
		dp[i + 1][0] = min(dp[i][0] + 2 * (R - 1), dp[i][1] + M + 1) + 1;
		dp[i + 1][1] = min(dp[i][1] + 2 * (M + 2 - L), dp[i][0] + M + 1) + 1;
	}
	int L = M + 2, R = 1;
	for (j = 2; j <= M + 1; j++) {
		if (in[N][j] == '0') continue;
		L = min(L, j);
		R = max(R, j);
	}

	return !printf("%d\n", min(dp[i][0] + R - 1, dp[i][1] + M + 2 - L));
}