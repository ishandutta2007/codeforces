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

int dp[4][1050][1050];
char in[1050][1050];

int del1[1050][1050];
int del2[1050][1050];
int main() {
	int N, M, i, j, k;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) scanf("%s", in[i] + 1);

	for (i = 1; i <= N; i++) for (j = 1; j <= M; j++) dp[0][i][j] = (in[i][j] == '*') ? dp[0][i - 1][j] + 1 : 0;
	for (i = N; i >= 1; i--) for (j = 1; j <= M; j++) dp[1][i][j] = (in[i][j] == '*') ? dp[1][i + 1][j] + 1 : 0;
	for (i = 1; i <= N; i++) for (j = 1; j <= M; j++) dp[2][i][j] = (in[i][j] == '*') ? dp[2][i][j - 1] + 1 : 0;
	for (i = 1; i <= N; i++) for (j = M; j >= 1; j--) dp[3][i][j] = (in[i][j] == '*') ? dp[3][i][j + 1] + 1 : 0;

	vector <pair<pii, int>> Vl;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			int L = INF;
			for (k = 0; k < 4; k++) L = min(L, dp[k][i][j]);
			if (L <= 1) continue;

			L--;
			Vl.emplace_back(pii(i, j), L);
			del1[i][j - L]++;
			del1[i][j + L + 1]--;
			del2[i - L][j]++;
			del2[i + L + 1][j]--;
		}
	}

	for (i = 1; i <= N; i++) for (j = 1; j <= M; j++) del1[i][j] += del1[i][j - 1];
	for (i = 1; i <= N; i++) for (j = 1; j <= M; j++) del2[i][j] += del2[i - 1][j];

	for (i = 1; i <= N; i++) for (j = 1; j <= M; j++) if (in[i][j] == '*' && !del1[i][j] && !del2[i][j]) return !printf("-1\n");

	printf("%d\n", (int)Vl.size());
	for (auto it : Vl) printf("%d %d %d\n", it.first.first, it.first.second, it.second);
	return 0;
}