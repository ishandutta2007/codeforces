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

int IT_MAX = 1 << 20;
ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
//#define Se second
#define Fi first

ll ans = 0;
ll dp[200050][2][2];
ll V[200050];
vector <int> conn[200050];
vector <int> son[200050];
bool dchk[200050];
void DFS(int n) {
	dchk[n] = true;
	for (auto it : conn[n]) {
		if (dchk[it]) continue;
		DFS(it);
		son[n].push_back(it);
	}

	

	ll sum[2][2];
	sum[0][0] = sum[0][1] = sum[1][0] = sum[1][1] = 0;
	for (auto it : son[n]) {
		for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) sum[i][j] = (sum[i][j] + dp[it][i][j]) % MOD;
	}

	ans = (ans + V[n]) % MOD;
	ans = (ans + sum[0][0] * V[n] - sum[1][0] * V[n] + sum[0][1] + sum[1][1]) % MOD;
	ans = (ans + sum[0][0] * V[n] + sum[1][0] * V[n] + sum[0][1] - sum[1][1]) % MOD;
	for (auto it : son[n]) {
		ll ts[2][2];
		for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) ts[i][j] = (sum[i][j] - dp[it][i][j]) % MOD;

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				ans = (ans + ts[j][0] * dp[it][i][1]) % MOD;

				ll v = dp[it][i][0] * ts[j][0] % MOD;
				v = v * V[n] % MOD;
				if (i == 0) ans = (ans + v) % MOD;
				else ans = (ans - v) % MOD;

				if ((i + j + 1) % 2 == 1) ans = (ans + ts[j][1] * dp[it][i][0]) % MOD;
				else ans = (ans - ts[j][1] * dp[it][i][0]) % MOD;
			}
		}
	}

	dp[n][0][0] = sum[1][0];
	dp[n][0][1] = (-sum[1][0] * V[n] + sum[1][1]) % MOD;
	dp[n][1][0] = sum[0][0];
	dp[n][1][1] = (sum[0][0] * V[n] + sum[0][1]) % MOD;
	dp[n][1][0] = (dp[n][1][0] + 1) % MOD;
	dp[n][1][1] = (dp[n][1][1] + V[n]) % MOD;
}
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%lld", &V[i]);
	for (i = 1; i < N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}

	DFS(1);
	ans = (ans % MOD + MOD) % MOD;
	return !printf("%lld\n", ans);
}