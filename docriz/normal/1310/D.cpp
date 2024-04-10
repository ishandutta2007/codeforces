#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = (int)1e9 + 99;
const int N = 88;
const int K = 14;
int dp[K][N];
int g[N][N];
int a[N];
int ANS = INF;
int n, k;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &g[i][j]);
	while((double)clock() / CLOCKS_PER_SEC < 1.5) {
		for (int i = 0; i < n; i++)
			a[i] = rng() & 1;
		for (int i = 0; i <= k; i++)
			for (int j = 0; j < n; j++)
				dp[i][j] = INF;
		dp[0][0] = 0;
		for (int t = 0; t < k; t++) {
			for (int v = 0; v < n; v++)
				for (int u = 0; u < n; u++) {
					if (a[v] == a[u]) continue;
					dp[t + 1][u] = min(dp[t + 1][u], dp[t][v] + g[v][u]);
				}
		}
		ANS = min(ANS, dp[k][0]);
	}
	printf("%d\n", ANS);

	return 0;
}