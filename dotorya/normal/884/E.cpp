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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int nc = 0;
int ans = 0;

int dp[20000];
int tdp[20000];

char u[20000];
int in[20000];

int ch[18050];

int r[20000];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}
int main() {
	int N, M, i, j, k;
	scanf("%d %d", &N, &M);

	int ans = 0;
	for (i = 1; i <= N; i++) {
		scanf("%s", u + 1);
		for (j = 1; j <= M / 4; j++) {
			int t;
			if (u[j] >= '0' && u[j] <= '9') t = u[j] - '0';
			else t = u[j] - 'A' + 10;
			for (k = 3; k >= 0; k--) in[4 * j - k] = !!(t & (1 << k));
		}

		for (j = 1; j <= 18000; j++) ch[j] = 0;

		int nc = 0;
		for (j = 1; j <= M; j++) nc = max(nc, dp[j]);
		for (j = 1; j <= M; j++) {
			if (!in[j]) {
				tdp[j] = 0;
				continue;
			}
			if (in[j - 1]) tdp[j] = tdp[j - 1];
			else {
				tdp[j] = ++nc;
				ans++;
			}
		}
		for (j = 0; j <= nc; j++) r[j] = j;
		for (j = 1; j <= M; j++) {
			if (dp[j] && tdp[j]);
			else continue;

			if (root(dp[j]) == root(tdp[j])) continue;
			ans--;
			r[root(dp[j])] = root(tdp[j]);
		}

		for (j = 1; j <= M; j++) dp[j] = root(tdp[j]);

		int c = 0;
		for (j = 1; j <= 18000; j++) ch[j] = 0;
		for (j = 1; j <= M; j++) {
			if (!dp[j]) continue;
			if (!ch[dp[j]]) ch[dp[j]] = ++c;
			dp[j] = ch[dp[j]];
		}

		//for (j = 1; j <= M; j++) printf("%d", dp[j]);
		//printf("\n");
	}
	return !printf("%d\n", ans);
}