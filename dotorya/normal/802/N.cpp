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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1E-11;

pll operator + (pll a, pll b) {
	return pll(a.first + b.first, a.second + b.second);
}
ll A[2500];
ll B[2500];

pll dp[2500][2500];
int main() {
	int N, K, i, j;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for (i = 1; i <= N; i++) scanf("%lld", &B[i]);

	ll st = -10ll * INF, en = 10ll * INF, mi;
	
	while (st <= en) {
		mi = (st + en) / 2;

		for (i = 0; i <= N; i++) for (j = 0; j <= N; j++) dp[i][j] = pll(LL_INF, LL_INF);
		dp[0][0] = pll(0, 0);
		for (i = 0; i <= N; i++) {
			for (j = 0; j <= N; j++) {
				if (i) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
				if (j) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
				if (i && j && i <= j) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + pll(A[i] + B[j] + mi, 1));
			}
		}
		ll mn = dp[N][N].second;

		for (i = 0; i <= N; i++) for (j = 0; j <= N; j++) dp[i][j] = pll(LL_INF, LL_INF);
		dp[0][0] = pll(0, 0);
		for (i = 0; i <= N; i++) {
			for (j = 0; j <= N; j++) {
				if (i) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
				if (j) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
				if (i && j && i <= j) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + pll(A[i] + B[j] + mi, -1));
			}
		}
		ll mx = -dp[N][N].second;
		//printf("%lld %lld %lld\n", mi, mn, mx);
		if (mn <= K && K <= mx) return !printf("%lld\n", dp[N][N].first - K*mi);
		if (K < mn) st = mi + 1;
		else en = mi - 1;
	}
	return !printf("ERR\n");
}