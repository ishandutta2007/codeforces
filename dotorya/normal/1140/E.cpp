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

int IT_MAX = 1 << 17;
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

ll dp1[300050][3]; // st != 0, num type: 0, 1, 2
ll dp2[300050][2]; // st no restriction, num type: 0, 1
ll getans(vector<int> Vin) {
	vector <int> Vp;
	for (int i = 0; i < Vin.size(); i++) if (Vin[i] != -1) Vp.push_back(i);
	if (Vp.empty()) {
		int N = Vin.size();
		return (dp2[N][0] + dp2[N][1]) % MOD;
	}

	for (int i = 0; i + 1 < Vin.size(); i++) if (Vin[i] != -1 && Vin[i + 1] != -1 && Vin[i] == Vin[i + 1]) return 0;

	ll ans = 1;
	if (Vp[0] != 0) ans = ans * dp2[Vp[0]][1] % MOD;
	if (Vp.back() + 1 != Vin.size()) ans = ans * dp2[Vin.size() - 1 - Vp.back()][1] % MOD;

	for (int i = 0; i + 1 < Vp.size(); i++) {
		int s = Vp[i], e = Vp[i + 1];
		if (s + 1 == e) continue;

		int L = e - s - 1;
		if (Vin[s] == Vin[e]) ans = ans * (dp1[L][1] + dp1[L][2]) % MOD;
		else ans = ans * (dp1[L][0] + dp1[L][2]) % MOD;
	}
	return ans;
}
int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	
	dp1[1][1] = 1;
	dp1[1][2] = K - 2;
	dp2[1][0] = 1;
	dp2[1][1] = K - 1;
	for (int i = 2; i <= N; i++) {
		dp1[i][0] = (dp1[i-1][1] + dp1[i-1][2]) % MOD;
		dp1[i][1] = (dp1[i-1][0] + dp1[i-1][2]) % MOD;
		dp1[i][2] = (dp1[i - 1][0] * (K - 2) + dp1[i - 1][1] * (K - 2) + dp1[i - 1][2] * (K - 3)) % MOD;
		dp2[i][0] = dp2[i - 1][1];
		dp2[i][1] = (dp2[i - 1][0] * (K - 1) + dp2[i - 1][1] * (K - 2)) % MOD;
	}

	vector <int> Vin[2];
	for (int i = 1; i <= N; i++) {
		int t;
		scanf("%d", &t);
		Vin[i % 2].push_back(t);
	}
	
	ll ans = getans(Vin[0]) * getans(Vin[1]) % MOD;
	return !printf("%lld\n", ans);
}