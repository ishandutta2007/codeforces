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

char in[5050];
int sum[5050];
int main() {
	scanf("%s", in + 1);
	int N = strlen(in + 1), i, j;
	for (i = 1; i <= N; i++) {
		sum[i] = sum[i - 1];
		if (in[i] == 'a') sum[i]++;
	}

	int ans = 0;
	for (i = 0; i <= N; i++) {
		for (j = 0; i + j <= N; j++) {
			int c = sum[i] + (sum[N] - sum[N - j]) + (N - i - j - (sum[N - j] - sum[i]));
			ans = max(ans, c);
		}
	}
	return !printf("%d\n", ans);
}