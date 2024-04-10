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

vector <int> son[5050];
int dp[2][5050][5050];
int tdp[2][5050];
int in[5050][2];

int sz[5050];
void DFS(int n) {
	sz[n] = 1;
	for (auto it : son[n]) {
		DFS(it);
		sz[n] += sz[it];
	}

	int c = 1, i, j;
	dp[0][n][0] = in[n][0] - in[n][1], dp[0][n][1] = in[n][0] - in[n][1];
	dp[1][n][0] = 0, dp[1][n][1] = in[n][0];
	for (auto it : son[n]) {
		for (i = 0; i <= c + sz[it]; i++) tdp[0][i] = tdp[1][i] = INF;
		for (i = 0; i <= c; i++) {
			for (j = 0; j <= sz[it]; j++) {
				tdp[0][i + j] = min(tdp[0][i + j], dp[0][n][i] + dp[0][it][j]);
				tdp[1][i + j] = min(tdp[1][i + j], dp[1][n][i] + dp[1][it][j]);
			}
		}
		c += sz[it];
		for (i = 0; i <= c; i++) dp[0][n][i] = tdp[0][i], dp[1][n][i] = tdp[1][i];
	}
	for (i = 0; i <= c; i++) dp[0][n][i] = min(dp[0][n][i], dp[1][n][i]);
}
int main() {
	int N, B, i;
	scanf("%d %d", &N, &B);
	for (i = 1; i <= N; i++) {
		scanf("%d %d", &in[i][0], &in[i][1]);
		if (i >= 2) {
			int t;
			scanf("%d", &t);
			son[t].push_back(i);
		}
	}
	DFS(1);

	for (i = N - 1; i >= 1; i--) dp[0][1][i] = min(dp[0][1][i], dp[0][1][i + 1]);
	for (i = 1; i <= N; i++) if (dp[0][1][i] > B) break;
	return !printf("%d\n", i - 1);
}