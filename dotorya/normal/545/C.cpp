//*
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
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

typedef pair <int, ll> pil;
typedef pair <ll, int> pli;

const int IT_MAX = 32768;
const int MOD = 1000000007;
const int INF = 1234567891;
const ll LL_INF = 1234567890123456789ll;

pii D[100050];
pii dp[100050];
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d %d", &D[i].first, &D[i].second);

	sort(D + 1, D + N + 1);

	// DP
	dp[1].first = 1;
	dp[1].second = (D[1].first + D[1].second <= D[2].first) ? 1 : -INF;

	for (i = 2; i <= N; i++) {
		if (i == N || D[i].first + D[i].second < D[i + 1].first) dp[i].second = max(dp[i - 1].first, dp[i - 1].second) + 1;
		else dp[i].second = -INF;

		if (D[i].first - D[i - 1].first > D[i].second + D[i - 1].second) dp[i].first = max(dp[i - 1].first, dp[i - 1].second) + 1;
		else if (D[i].first - D[i - 1].first > D[i].second) dp[i].first = max(dp[i - 1].second, dp[i - 1].first + 1);
		else dp[i].first = max(dp[i - 1].first, dp[i - 1].second);
	}
	printf("%d", max(dp[N].first, dp[N].second));
	return 0;
}
//*/