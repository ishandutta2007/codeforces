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
const db ERR = 1E-11;

int C[22][22];
int dp[1000050];
int rev[1000050][2];
int cnt[25];
int main() {
	int i, j, k;
	for (i = 0; i <= 20; i++) {
		C[i][0] = C[i][i] = 1;
		for (j = 1; j < i; j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	}
	
	dp[0] = 0;
	for (i = 1; i <= 1000000; i++) dp[i] = INF;
	for (i = 10; i <= 20; i++) {
		int v = C[i][i - 10];
		for (j = v; j <= 1000000; j++) {
			if (dp[j] > dp[j - v] + 1) {
				dp[j] = dp[j - v] + 1;
				rev[j][0] = v;
				rev[j][1] = i - 10;
			}
		}
	}
	for (i = 1; i <= 1000000; i++) {
		if (dp[i] >= 90) return !printf("NO %d\n", i);
	}

	int N;
	scanf("%d", &N);
	while (N) {
		cnt[rev[N][1]]++;
		N -= rev[N][0];
	}
	for (i = 0; i <= 10; i++) {
		printf("abcdefghij");
		for (j = 1; j <= cnt[i]; j++) printf("k");
	}
	printf(" abcdefghijk");
	return !printf("\n");
}