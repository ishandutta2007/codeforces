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

int N, K;
ll dp[100050][205][2];
int sz[100050];
bool dchk[100050];
vector <int> conn[100050];
vector <int> son[100050];

ll val[205][2];
ll tdp[205][3];
ll tdp2[205][3];
void DFS(int n) {
	dchk[n] = true;
	sz[n] = 1;
	for (auto it : conn[n]) {
		if (dchk[it]) continue;
		son[n].push_back(it);
		DFS(it);
		sz[n] += sz[it];
	}

	int mx = 0;
	sort(all(son[n]), [](int a, int b) {
		return sz[a] < sz[b];
	});

	if (n == 1) {
		n = n;
	}
	tdp[0][0] = tdp[0][1] = tdp[0][2] = 0;
	for (auto it : son[n]) {
		int it_mx = min(K, sz[it]);
		for (int i = 0; i <= it_mx; i++) val[i][0] = val[i][1] = 0;
		for (int i = 0; i <= it_mx; i++) {
			val[i][0] += dp[it][i][0];
			val[i][1] += dp[it][i][1];
			val[i + 1][1] += dp[it][i][0];
			val[i + 1][1] += dp[it][i][1];
		}
		for (int i = 0; i <= it_mx; i++) {
			val[i][0] %= MOD;
			val[i][1] %= MOD;
		}

		for (int i = 0; i <= min(K, mx + it_mx); i++) {
			tdp2[i][0] = tdp2[i][1] = tdp2[i][2] = 0;
		}
		for (int i = 0; i <= it_mx; i++) {
			tdp2[i][0] = val[i][0];
			tdp2[i][1] = val[i][1];
		}
		for (int i = 0; i <= mx; i++) {
			tdp2[i][0] = (tdp2[i][0] + tdp[i][0]) % MOD;
			tdp2[i][1] = (tdp2[i][1] + tdp[i][1]) % MOD;
			tdp2[i][2] = (tdp2[i][2] + tdp[i][2]) % MOD;
		}
		for (int i = 0; i <= mx; i++) {
			for(int ii = 0; ii < 3; ii++) {
				for (int j = 0; j <= it_mx && j <= K - i; j++) {
					for (int jj = 0; jj < 2; jj++) {
						tdp2[i + j][2] = (tdp2[i + j][2] + tdp[i][ii] * val[j][jj]) % MOD;
					}
				}
			}
		}
		
		mx = min(K, mx + it_mx);
		for (int i = 0; i <= mx; i++) for (int j = 0; j < 3; j++) tdp[i][j] = tdp2[i][j];
	}
	tdp[0][0]++;

	for (int i = 0; i <= mx; i++) {
		dp[n][i][0] = (tdp[i][0] * 2 + tdp[i][1] + tdp[i][2] * 2) % MOD;
		dp[n][i][1] = tdp[i][1];
	}
	dp[n][0][0] = (dp[n][0][0] + MOD - 1) % MOD;
}

ll cnt[205][205];
ll F[205];
int main() {
	scanf("%d %d", &N, &K);
	for (int i = 1; i < N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}
	DFS(1);

	ll ans = 0;
	cnt[0][0] = 1;
	for (int i = 0; i < 200; i++) {
		for (int j = 0; j <= i; j++) {
			cnt[i + 1][j] = (cnt[i + 1][j] + cnt[i][j] * j) % MOD;
			cnt[i + 1][j + 1] = (cnt[i + 1][j + 1] + cnt[i][j]) % MOD;
		}
	}

	F[0] = 1;
	for (int i = 1; i <= 200; i++) F[i] = F[i - 1] * i % MOD;

	for (int i = 1; i <= K; i++) {
		ll v = cnt[K][i] * F[i] % MOD;
		ans = (ans + v * dp[1][i][0]) % MOD;
	}
	return !printf("%lld\n", ans);
}