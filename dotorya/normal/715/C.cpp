#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <vector>
//#include <unordered_set>
//#include <unordered_map>

#pragma warning(disable:4996)
using namespace std;

#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;

int IT_MAX = 262144;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-11;

int M;
ll po10[100050];

set <pii> conn[100050];

vector <int> V;
vector <pii> son[100050];
int sz[100050];
int dchk1[100050];

int gpar[100050];
pll val1[100050];
ll val2[100050];
map <ll, int> Mx[100050];
int dc1 = 0;
int DFS1(int n, int C) {
	dchk1[n] = C;
	V.push_back(n);

	int rv = 1;
	for (auto it : conn[n]) {
		if (dchk1[it.second] == C) continue;
		rv += DFS1(it.second, C);
		son[n].push_back(it);
	}
	return sz[n] = rv;
}
void DFS2(int n, int gp) {
	gpar[n] = gp;
	for (auto it : son[n]) {
		int x = it.second;
		val1[x].first = (it.first + val1[n].first * 10) % M;
		val1[x].second = val1[n].second + 1;
		val2[x] = (val2[n] + it.first * po10[val1[n].second]) % M;
		DFS2(x, gp);
	}
}

ll mul_inv(ll a, ll b = MOD)
{
	ll b0 = b, t, q;
	ll x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

ll gogo(int n) {
	int N = DFS1(n, ++dc1), i, j;
	if (N == 1) return 0;

	while (1) {
		int x = son[n][0].second;
		for (auto it : son[n]) if (sz[x] < sz[it.second]) x = it.second;
		if (sz[x] * 2 <= N) break;
		n = x;
	}
	for (auto it : V) son[it].clear();
	V.clear();
	N = DFS1(n, ++dc1);

	vector <int> V2;
	for (auto it : conn[n]) {
		V2.push_back(it.second);
		val1[it.second] = pll(it.first % M, 1);
		val2[it.second] = it.first % M;
		DFS2(it.second, it.second);

		pii u = it;
		conn[u.second].erase(pii(u.first, n));
	}
	conn[n].clear();

	for (auto it : V) {
		if (it != n) {
			Mx[gpar[it]][val2[it]]++;
			Mx[0][val2[it]]++;
		}
	}

	ll rv = 0;
	for (auto it : V) {
		if (it == n) continue;
		if (val1[it].first == 0) rv++;
		if (val2[it] == 0) rv++;
		
		ll x = mul_inv(po10[val1[it].second], M) * (M - val1[it].first);
		x %= M;
		rv += Mx[0][x];
		rv -= Mx[gpar[it]][x];
	}
	for (auto it : V) son[it].clear();
	Mx[0].clear();
	for (auto it : V2) Mx[it].clear();
	V.clear();

	for (auto it : V2) rv += gogo(it);
	return rv;
}
int main() {
	int N, i, t1, t2, t3;
	scanf("%d %d", &N, &M);

	po10[0] = 1 % M;
	for (i = 1; i <= N; i++) po10[i] = (po10[i - 1] * 10) % M;
	for (i = 1; i < N; i++) {
		scanf("%d %d %d", &t1, &t2, &t3);
		t1++, t2++;
		conn[t1].emplace(t3, t2);
		conn[t2].emplace(t3, t1);
	}
	
	printf("%lld\n", gogo(1));
	return 0;
}