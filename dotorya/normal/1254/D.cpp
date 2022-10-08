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
int IT_MAX = 1 << 12;
const ll MOD = 998244353;
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

vector <int> conn[200050];
vector <int> son[200050];
int lr[150050][2];
int tus;
bool dchk[150050];

ll sz[150050];
void DFS1(int n) {
	lr[n][0] = ++tus;
	dchk[n] = true;
	sz[n] = 1;
	for (auto it : conn[n]) {
		if (dchk[it]) continue;

		son[n].push_back(it);
		DFS1(it);
		sz[n] += sz[it];
	}
	lr[n][1] = tus;
}

ll ans[150050];

ll u[150050];
ll sum[150050];
void DFS2(int n) {
	for (auto it : son[n]) {
		sum[it] += sum[n];
		DFS2(it);
	}
}

#define DEBUG 0
int main() {
	int N, Q, i, j;
	if(!DEBUG) scanf("%d %d", &N, &Q);
	else N = 150000, Q = 150000;
	for (i = 1; i < N; i++) {
		int t1, t2;
		if(!DEBUG) scanf("%d %d", &t1, &t2);
		else {
			if (i <= 75000) t1 = i, t2 = i + 1;
			else t1 = 75001, t2 = i + 1;
		}
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}
	DFS1(1);

	srand(15353);

	vector <pll> Vq;
	while (Q--) {
		int t1, t2, t3;
		if(!DEBUG) scanf("%d", &t1);
		else t1 = rand() % 2 + 1;

		if (t1 == 1) {
			if(!DEBUG) scanf("%d %d", &t2, &t3);
			else t2 = 75001, t3 = rand();
			Vq.emplace_back(t2, t3);
		}
		else {
			if(!DEBUG) scanf("%d", &t2);
			else t2 = rand() % N + 1;
			ll R = ans[t2];
			for (auto it : Vq) {
				int p = it.first;
				if (p == t2) R = (R + it.second * N) % MOD;
				else if (lr[p][0] <= lr[t2][0] && lr[t2][0] <= lr[p][1]) {
					int st = 0, en = (int)son[p].size() - 1, mi, rv = -1;
					while (st <= en) {
						mi = (st + en) / 2;
						int nn = son[p][mi];
						if (lr[nn][0] <= lr[t2][0]) {
							rv = mi;
							st = mi + 1;
						}
						else en = mi - 1;
					}
					R = (R + it.second * (N - sz[son[p][rv]])) % MOD;
				}
				else R = (R + it.second * sz[p]) % MOD;
			}
			if(!DEBUG) printf("%lld\n", R * mul_inv(N) % MOD);
		}

		if (Q % 1000 != 0) continue;

		ll tot = 0;
		memset(u, 0, sizeof(u));
		for (auto it : Vq) {
			u[it.first] = (u[it.first] + it.second) % MOD;
			tot = (tot + it.second) % MOD;
		}

		memset(sum, 0, sizeof(sum));
		for (i = 1; i <= N; i++) {
			ans[i] = (ans[i] + u[i] * N) % MOD;
			for (auto it : son[i]) sum[it] = (sum[it] + u[i] * (N - sz[it])) % MOD;
			sum[1] = (sum[1] + u[i] * sz[i]) % MOD;
			sum[i] = (sum[i] - u[i] * sz[i]) % MOD;
			sum[i] = (sum[i] + MOD) % MOD;
		}

		DFS2(1);
		for (i = 1; i <= N; i++) ans[i] = (ans[i] + sum[i]) % MOD;

		Vq.clear();
	}

	if (DEBUG) printf("%d\n", (int)clock());
	return 0;
}