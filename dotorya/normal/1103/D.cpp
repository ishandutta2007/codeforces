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

int IT_MAX = 1 << 20;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

ll gcd(ll a, ll b) {
	return (a == 0) ? b : gcd(b%a, a);
}

pll in[1000050];

vector <ll> Vl;
map <ll, vector<ll>> Mx;

bool tchk[2048];
ll dp[12][2048];
int main() {
	ll N, K, i, j;
	scanf("%lld %lld", &N, &K);
	for (i = 1; i <= N; i++) scanf("%lld", &in[i].second);
	for (i = 1; i <= N; i++) scanf("%lld", &in[i].first);
	sort(in + 1, in + N + 1);

	ll g = 0;
	for (i = 1; i <= N; i++) g = gcd(g, in[i].second);
	if (g == 1) return !printf("0\n");

	for (i = 2; i * i <= g; i++) {
		if (g%i) continue;

		Vl.push_back(i);
		while (g%i == 0) g /= i;
	}
	if (g != 1) Vl.push_back(g);

	for (i = 1; i <= N; i++) {
		ll v = 1;
		for (auto it : Vl) {
			while (in[i].second % it == 0) {
				v *= it;
				in[i].second /= it;
			}
		}
		if (Mx[v].size() >= 11) continue;
		Mx[v].push_back(in[i].first);
	}

	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	int X = Vl.size();
	vector <pll> Vin;

	vector <int> Vp;
	for (auto it : Mx) {
		ll v = it.first;

		ll u[13] = { 1, };
		for (i = 0; i < X; i++) {
			u[i] = 1;
			while (v % Vl[i] == 0) {
				u[i] *= Vl[i];
				v /= Vl[i];
			}
		}

		Vp.clear();

		memset(tchk, false, sizeof(tchk));
		for (i = (1 << X) - 1; i >= 1; i--) {
			if (tchk[i]) continue;
			ll tu = 1;
			for (j = 0; j < X; j++) if (i & (1 << j)) tu *= u[j];
			if (tu > K) continue;

			for (j = i; j; j = (j - 1)&i) tchk[j] = true;
			Vp.push_back(i);
		}

		for (auto val : it.second) {
			for (i = 10; i >= 0; i--) {
				for (j = 0; j < (1 << X); j++) {
					if (dp[i][j] == LL_INF) continue;
					for (auto it2 : Vp) dp[i + 1][j | it2] = min(dp[i + 1][j | it2], dp[i][j] + val);
				}
			}
		}
	}

	ll ans = LL_INF;
	for (i = 1; i <= 11; i++) {
		if (dp[i][(1 << X) - 1] > LL_INF / 2) continue;
		ans = min(ans, dp[i][(1 << X) - 1] * i);
	}
	if (ans == LL_INF) return !printf("-1\n");
	return !printf("%lld\n", ans);
}