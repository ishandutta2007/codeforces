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
//#include <unordered_map>  
//#include <unordered_set>  
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

//typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple<int, int, int> t3;
#define rep(i, n) for(int i=0;i<n;i++)

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-12;

int dis[105][105];
int dp[105][3];
int main() {
	int N, A, B, C, i, j, k;
	scanf("%d %d %d %d", &N, &A, &B, &C);
	dis[0][1] = dis[1][0] = A;
	dis[0][2] = dis[2][0] = B;
	dis[1][2] = dis[2][1] = C;

	dp[1][0] = 0;
	dp[1][1] = dp[1][2] = INF;
	for (i = 2; i <= N; i++) {
		for (j = 0; j < 3; j++) {
			dp[i][j] = INF;
			for (k = 0; k < 3; k++) {
				if (j == k) continue;
				dp[i][j] = min(dp[i][j], dp[i - 1][k] + dis[j][k]);
			}
		}
	}
	return !printf("%d\n", min(dp[N][0], min(dp[N][1], dp[N][2])));
}