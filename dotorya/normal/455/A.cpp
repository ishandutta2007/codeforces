//*
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <time.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef set <int>::iterator siit;
typedef set <ll>::iterator slit;

const int IT_MAX = 32768;
const int MOD = 1000000007;
const int INF = 1234567891;
const ll LL_INF = 1234567890123456789ll;

vector <int> V;
ll cnt[100050];
ll dp[100050];
int main() {
	int N, i, j, t;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &t);
		cnt[t]++;
	}
	
	// DP
	dp[0] = 0;
	dp[1] = cnt[1];
	for (i = 2; i <= 100000; i++) {
		dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * i);
	}
	printf("%lld", dp[100000]);
	return 0;
}

//*/