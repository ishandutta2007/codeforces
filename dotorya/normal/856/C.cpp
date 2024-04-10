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
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

ll C[4050][4050];
ll F[4050];
vector <int> Vin[2];

ll dp1[2050][12];
ll dp2[2050][12];
ll tdp[2050][12];

void dodp(vector<int> Vin, ll dp[2050][12]) {
	int i, j, N = Vin.size();
	for (i = 0; i <= N; i++) for (j = 0; j < 11; j++) dp[i][j] = 0;
	dp[0][0] = 1;
	for (auto it : Vin) {
		for (i = 0; i <= N; i++) for (j = 0; j < 11; j++) tdp[i][j] = 0;
		for (i = 0; i <= N; i++) {
			for (j = 0; j < 11; j++) {
				tdp[i][(j + it) % 11] += dp[i][j];
				tdp[i + 1][(j - it + 11) % 11] += dp[i][j];
			}
		}
		for (i = 0; i <= N; i++) for (j = 0; j < 11; j++) dp[i][j] = tdp[i][j] % MOD;
	}
}
int main() {
	int T, i, j;
	for (i = 0; i <= 4000; i++) {
		C[i][0] = C[i][i] = 1;
		for (j = 1; j < i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
	}
	F[0] = 1;
	for (i = 1; i <= 4000; i++) F[i] = (F[i - 1] * i) % MOD;
	scanf("%d", &T);
	while (T--) {
		int N;
		scanf("%d", &N);
		for (i = 1; i <= N; i++) {
			int t;
			scanf("%d", &t);
			int c = 0, x = t;
			while (x) {
				c++;
				x /= 10;
			}
			Vin[c % 2].push_back(t % 11);
		}

		dodp(Vin[0], dp1);
		dodp(Vin[1], dp2);

		int c1 = Vin[1].size() / 2, c0 = Vin[1].size() - c1;
	
		ll ans = 0;
		if (c0 == 0 && c1 == 0) ans = dp1[0][0] * F[Vin[0].size()] % MOD;
		else {
			for (i = 0; i < 11; i++) {
				for (j = 0; j <= Vin[0].size(); j++) {
					ll cnt = dp2[c1][i] * dp1[j][(11 - i) % 11] % MOD;

					int d1 = j, d0 = Vin[0].size() - j;
					ll v0 = F[c0 + d0];
					if (c0 != c1) v0 = F[c0 + d0 - 1] * c0 % MOD;

					ll v1 = F[c1 + d1];
					if (c0 == c1) v1 = c1 * F[c1 + d1 - 1] % MOD;
					cnt = (cnt * v0) % MOD;
					cnt = (cnt * v1) % MOD;
					ans = (ans + cnt) % MOD;
				}
			}
		}
		printf("%lld\n", ans);

		Vin[0].clear();
		Vin[1].clear();
	}
	return 0;
}