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

int IT_MAX = 1 << 15;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

ll dp[10050];
ll tdp[10050];

ll in[105];
int main() {
	int N, K, M, i, j, k;
	scanf("%d %d %d", &N, &K, &M);
	for (i = 1; i <= K; i++) scanf("%d", &in[i]);
	sort(in + 1, in + K + 1);

	for (i = 1; i <= 10000; i++) dp[i] = LL_INF;
	dp[0] = 0;
	for (i = 1; i <= N; i++) {
		for (j = 0; j <= 10000; j++) tdp[j] = LL_INF;
		int s = 0;
		for (j = 0; j < K; j++) {
			for (k = 0; j + k <= 10000; k++) tdp[j + k] = min(tdp[j + k], dp[k] + s);
			s += in[j + 1];
		}
		for (j = 0; j + K + 1 <= 10000; j++) tdp[j + K + 1] = min(tdp[j + K + 1], dp[j] + s);
		for (j = 0; j <= 10000; j++) dp[j] = tdp[j];
	}

	for (i = 10000; i >= 0; i--) if (dp[i] <= M) return !printf("%d\n", i);
	return 0;
}