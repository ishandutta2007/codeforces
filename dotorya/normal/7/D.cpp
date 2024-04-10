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
const db ERR = 1e-10;

char in[5000050];
char str[10000050];
int dp[10000050];
int dp2[5000050];
int main() {
	scanf("%s", in);
	int L1 = strlen(in), i, j;
	int L2 = L1 * 2 - 1;
	for (i = 0; i < L1; i++) {
		str[2 * i] = in[i];
		if(i + 1 != L1) str[2 * i + 1] = '#';
	}
	
	int mx = -1, mxp = -1;
	for (i = 0; i < L2; i++) {
		int st = 0;
		if (mx > i) st = min(mx - i, dp[2 * mxp - i]);
		for (j = st; i >= j && i + j < L2; j++) if (str[i - j] != str[i + j]) break;
		dp[i] = j - 1;
		if (mx < i + dp[i]) {
			mx = i + dp[i];
			mxp = i;
		}
	}
//	printf("%s\n", str);
//	for (i = 0; i < L2; i++) printf("%d\n", dp[i]);

	ll ans = 1;
	dp2[0] = 1;
	for (i = 1; i < L1; i++) {
		int t = dp[i];
		if (t >= i) dp2[i] = dp2[(i - 1) / 2] + 1;
		else dp2[i] = 0;
		ans += dp2[i];
	}
	return !printf("%lld\n", ans);
}