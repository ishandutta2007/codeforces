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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)

ll in[100050];
ll dp[100050];
int main() {
	int N, i;
	ll ts, tf, t;
	scanf("%lld %lld %lld", &ts, &tf, &t);
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%lld", &in[i]);
	sort(in + 1, in + N + 1);
	if (N == 0) return !printf("%lld\n", ts);
	if (in[1] > ts) return !printf("%lld\n", ts);

	in[N + 1] = LL_INF;

	ll ans = ts - (in[1] - 1), ap = in[1] - 1;
	for (i = 1; i <= N; i++) {
		in[i] = max(in[i], ts);
		dp[i] = max(dp[i - 1], in[i]) + t;
		if (dp[i] > tf - t) break;
		if (in[i] == in[i + 1]) continue;
		
		ll tx = min(in[i + 1] - 1, tf - t);
		if (ans > max(0ll, dp[i] - tx)) {
			ans = max(0ll, dp[i] - tx);
			ap = tx;
		}
	}
	return !printf("%lld\n", ap);
}