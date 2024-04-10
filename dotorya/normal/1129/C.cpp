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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int in[3050];
int dp[3050][3050];

bool isValid(int st, int en) {
	if (en - st != 3) return true;

	if (in[st] == 0 && in[st + 1] == 0 && in[st + 2] == 1 && in[st + 3] == 1) return false;
	if (in[st] == 0 && in[st + 1] == 1 && in[st + 2] == 0 && in[st + 3] == 1) return false;
	if (in[st] == 1 && in[st + 1] == 1 && in[st + 2] == 1 && in[st + 3] == 0) return false;
	if (in[st] == 1 && in[st + 1] == 1 && in[st + 2] == 1 && in[st + 3] == 1) return false;
	return true;
}

int rin[3050];
int u[3050];
int val[3050];

int getlcp(int x, int y, int N) {
	int i;
	for (i = 0; x + i <= N && y + i <= N; i++) if (rin[x + i] != rin[y + i]) break;
	return i;
}

int main() {
	int N, M, i, j;
	scanf("%d", &N);

	for (i = 1; i <= N; i++) scanf("%d", &in[i]);

	for (i = N; i >= 1; i--) {
		dp[i][i] = 1;
		if (i + 1 <= N) dp[i][i + 1] = 2;
		if (i + 2 <= N) dp[i][i + 2] = 4;
		if (i + 3 <= N) {
			dp[i][i + 3] = 8;
			if (!isValid(i, i + 3)) dp[i][i + 3]--;
		}
		for (j = i + 4; j <= N; j++) {
			dp[i][j] = 0;
			
			dp[i][j] = dp[i][j - 1];
			dp[i][j] += dp[i][j - 2];
			dp[i][j] %= MOD;
			dp[i][j] += dp[i][j - 3];
			dp[i][j] %= MOD;
			if (isValid(j - 3, j)) dp[i][j] += dp[i][j - 4];
			dp[i][j] %= MOD;
		}
	}

	
	for (i = 1; i <= N; i++) rin[i] = in[N + 1 - i];

	for (i = 1; i <= N; i++) u[i] = i;
	sort(u + 1, u + N + 1, [&](int a, int b) {
		for (int i = 0; a + i <= N && b + i <= N; i++) if (rin[a + i] != rin[b + i]) return rin[a + i] < rin[b + i];
		return a > b;
	});

	for (i = 1; i <= N; i++) {
		val[u[i]] = 0;
		for (j = i - 1; j >= 1; j--) if (u[j] > u[i]) break;
		if(j >= 1) val[u[i]] = max(val[u[i]], getlcp(u[j], u[i], N));
		for (j = i + 1; j <= N; j++) if (u[j] > u[i]) break;
		if (j <= N) val[u[i]] = max(val[u[i]], getlcp(u[j], u[i], N));
	}
	
	ll ans = 0;
	for (i = 1; i <= N; i++) {
		for (j = val[N+1-i] + 1; j <= i; j++) ans += dp[i - j + 1][i];
		ans %= MOD;
		printf("%lld\n", ans);
	}
	return 0;
}