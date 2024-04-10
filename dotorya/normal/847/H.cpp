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

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

ll in[100050];
ll mx1[100050];
ll mx2[100050];
ll sum1[100050];
ll sum2[100050];
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%lld", &in[i]);

	for (i = 1; i <= N; i++) {
		mx1[i] = max(mx1[i - 1] + 1, in[i]);
		sum1[i] = sum1[i - 1] + mx1[i];
	}
	
	for (i = N; i >= 1; i--) {
		mx2[i] = max(mx2[i + 1] + 1, in[i]);
		sum2[i] = sum2[i + 1] + mx2[i];
	}

	ll ans = LL_INF;
	for (i = 1; i <= N; i++) {
		ll x = max(mx1[i], mx2[i]) + sum1[i - 1] + sum2[i + 1];
		ans = min(ans, x);
	}
	for (i = 1; i <= N; i++) ans -= in[i];
	return !printf("%lld\n", ans);
}