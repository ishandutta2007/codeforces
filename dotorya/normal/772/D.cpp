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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)

class Node {
public:
	ll n, x, y;
	Node() {
		*this = Node(0, 0, 0);
	}
	Node(int x) {
		*this = Node(1, x, 0);
	}
	Node(ll n, ll x, ll y) : n(n), x(x), y(y) {}
	Node operator + (const Node &l) const {
		Node rv = Node(n + l.n, x + l.x, y + l.y + x*l.x);
		rv.n %= MOD;
		rv.x %= MOD;
		rv.y %= MOD;
		return rv;
	}
	Node operator - (const Node &l) const {
		Node rv = Node(n - l.n, x - l.x, y - l.y - (x - l.x) * l.x);
		rv.n = (rv.n % MOD + MOD) % MOD;
		rv.x = (rv.x % MOD + MOD) % MOD;
		rv.y = (rv.y % MOD + MOD) % MOD;
		return rv;
	}
};

Node dp[1000000];
ll po2[1000050];
ll po10[1000050];
ll val[64];
int cnt1[64];

ll X[1000050];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		ll t;
		scanf("%lld", &t);
		dp[t] = dp[t] + Node(t);
	}
	po2[0] = po10[0] = 1;
	for (i = 1; i <= 1000000; i++) {
		po2[i] = (po2[i - 1] * 2) % MOD;
		po10[i] = (po10[i - 1] * 10) % MOD;
	}

	for (i = 0; i < 64; i++) {
		for (j = 0; j < 6; j++) {
			if (i & (1 << j)) {
				cnt1[i]++;
				val[i] += po10[j];
			}
		}
	}
	for (i = 999999; i >= 0; i--) {
		int v9 = 0, t = i;
		for (j = 0; j < 6; j++) {
			if (t % 10 == 9) v9 |= 1 << j;
			t /= 10;
		}

		for (j = 1; j < 64; j++) {
			if (v9 & j) continue;
			if (cnt1[j] % 2) dp[i] = dp[i] + dp[i + val[j]];
			else dp[i] = dp[i] - dp[i + val[j]];
		}
	}
	for (i = 0; i < 1000000; i++) {
		X[i] = dp[i].x * dp[i].x - dp[i].y;
		X[i] %= MOD;
		X[i] = (X[i] + MOD) % MOD;
		if(dp[i].n) X[i] = (X[i] * po2[dp[i].n - 1]) % MOD;
	}
	
	ll ans = 0;
	for (i = 0; i < 1000000; i++) {
		int v9 = 0, t = i;
		for (j = 0; j < 6; j++) {
			if (t % 10 == 9) v9 |= 1 << j;
			t /= 10;
		}

		ll g = 0;
		for (j = 0; j < 64; j++) {
			if (v9 & j) continue;
			if (cnt1[j] % 2 == 0) g = (g + X[i + val[j]]) % MOD;
			else g = (g - X[i+val[j]] + MOD) % MOD;
		}
		g *= i;
		ans ^= g;
	}
	return !printf("%lld\n", ans);
}