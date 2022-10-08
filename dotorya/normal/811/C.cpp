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

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int lr[5050][2];

int in[5050];
int dp[5050];

bool chk[5050];
int main() {
	int N, i, j;
	for (i = 0; i <= 5000; i++) lr[i][0] = INF, lr[i][1] = -INF;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &in[i]);
		lr[in[i]][0] = min(lr[in[i]][0], i);
		lr[in[i]][1] = max(lr[in[i]][1], i);
	}

	dp[0] = 0;
	for (i = 1; i <= N; i++) {
		dp[i] = dp[i - 1];
		for (j = 0; j <= 5000; j++) chk[j] = false;

		int st = INF, en = -INF, v = 0;
		for (j = i; j >= 1; j--) {
			if (!chk[in[j]]) v ^= in[j];
			chk[in[j]] = true;
			st = min(st, lr[in[j]][0]);
			en = max(en, lr[in[j]][1]);
			if (st == j && en == i) dp[i] = max(dp[i], dp[j - 1] + v);
		}
	}
	return !printf("%d\n", dp[N]);
}