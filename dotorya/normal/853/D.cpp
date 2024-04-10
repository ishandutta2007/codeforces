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

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

ll dp[305];
ll tdp[305];

int in[300050];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &in[i]);
		in[i] /= 100;
	}

	for (i = 1; i <= 300; i++) dp[i] = LL_INF;
	for (i = 1; i <= N; i++) {
		for (j = 0; j <= 300; j++) tdp[j] = LL_INF;
		for (j = 0; j <= 300; j++) {
			tdp[min(j + in[i] / 10, 300)] = min(tdp[min(j + in[i] / 10, 300)], dp[j] + in[i]);

			int c = min(in[i], j);
			tdp[j - c] = min(tdp[j - c], dp[j] + in[i] - c);
		}
		for (j = 0; j <= 300; j++) dp[j] = tdp[j];
	}

	ll ans = LL_INF;
	for (i = 0; i <= 300; i++) ans = min(ans, dp[i]);
	return !printf("%lld\n", ans * 100);
}