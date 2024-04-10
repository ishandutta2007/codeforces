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
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-9;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

ll getv(ll x) {
	ll st = 1, en = 30000, mi, rv = 0;
	while (st <= en) {
		mi = (st + en) / 2;
		if (mi*(mi + 1) / 2 <= x) {
			rv = mi;
			st = mi + 1;
		}
		else en = mi - 1;
	}
	return (rv + 1)*x - rv*(rv + 1)*(rv + 2) / 6;
}

vector <pair<int, pii>> Ve;

vector <int> conn[1000050];
vector <int> rconn[1000050];
bool dchk[1000050];
int G[1000050];
vector <int> Vstk;
void DFS1(int n) {
	dchk[n] = true;
	for (auto it : conn[n]) if (!dchk[it]) DFS1(it);
	Vstk.push_back(n);
}
void DFS2(int n, int g) {
	G[n] = g;
	for (auto it : rconn[n]) if (!G[it]) DFS2(it, g);
}

ll gval[1000050];
vector <pll> gconn[1000050];
int inc[1000050];
ll dp[1000050];
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		Ve.emplace_back(t3, pii(t1, t2));
		conn[t1].push_back(t2);
		rconn[t2].push_back(t1);
	}
	for (i = 1; i <= N; i++) if (!dchk[i]) DFS1(i);
	reverse(all(Vstk));
	
	int gc = 0;
	for (auto it : Vstk) if (!G[it]) DFS2(it, ++gc);

	for (auto it : Ve) {
		int t1 = it.first, t2 = it.second.first, t3 = it.second.second;
		if (G[t2] == G[t3]) gval[G[t2]] += getv(t1);
		else {
			gconn[G[t2]].emplace_back(t1, G[t3]);
			inc[G[t3]]++;
		}
	}

	int s;
	scanf("%d", &s);
	s = G[s];
	for (i = 1; i <= N; i++) dp[i] = -LL_INF;
	dp[s] = gval[s];

	ll ans = dp[s];
	vector <int> Vu;
	for (i = 1; i <= gc; i++) if (inc[i] == 0) Vu.push_back(i);
	for (i = 0; i < Vu.size(); i++) {
		for (auto it : gconn[Vu[i]]) {
			dp[it.second] = max(dp[it.second], it.first + dp[Vu[i]] + gval[it.second]);
			if (--inc[it.second] == 0) Vu.push_back(it.second);
		}
		ans = max(ans, dp[Vu[i]]);
	}
	return !printf("%lld\n", ans);
}