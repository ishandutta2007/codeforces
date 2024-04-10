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

ll mul_inv(ll a, ll b = MOD) {
	ll t1 = a, t2 = b, t3;
	ll v1 = 1, v2 = 0, v3;
	while (t2 != 1) {
		ll x = t1 / t2;
		t3 = t1 - x * t2;
		v3 = v1 - x * v2;
		t1 = t2, t2 = t3;
		v1 = v2, v2 = v3;
	}
	return (v2 + b) % b;
}

bool dchk[105];
ll P[105][105];
ll dp[105];
ll tdp[105];

ll minv[105];

vector <pll> Vl;
ll ans = 0;
void aa(int lvl, ll Pr, ll v) {
	if (lvl == Vl.size()) {
		ans = (ans + v * Pr) % MOD;
		return;
	}

	for (int i = 0; i <= Vl[lvl].second; i++) {
		aa(lvl + 1, Pr * P[Vl[lvl].second][i] % MOD, v);
		v = v * Vl[lvl].first % MOD;
	}
}
int main() {
	ll N, K, i, j, k;
	scanf("%lld %lld", &N, &K);
	
	for (i = 2; i * i <= N; i++) {
		if (N%i) continue;
		
		int c = 0;
		while (N%i == 0) {
			N /= i;
			c++;
		}
		Vl.emplace_back(i, c);
	}
	if (N != 1) Vl.emplace_back(N, 1);

	for (i = 1; i <= 90; i++) minv[i] = mul_inv(i);
	for (auto it : Vl) {
		ll t = it.second;
		if (dchk[t]) continue;

		dchk[t] = true;

		for (i = 0; i <= t; i++) dp[i] = 0;
		dp[t] = 1;

		for (i = 1; i <= K; i++) {
			for (j = 0; j <= t; j++) tdp[j] = 0;
			for (j = 0; j <= t; j++) {
				ll v = minv[j + 1] * dp[j] % MOD;
				for (k = 0; k <= j; k++) tdp[k] += v;
			}
			for (j = 0; j <= t; j++) dp[j] = tdp[j] % MOD;
		}
		for (i = 0; i <= t; i++) P[t][i] = dp[i];
	}

	aa(0, 1, 1);
	return !printf("%lld\n", ans);
}