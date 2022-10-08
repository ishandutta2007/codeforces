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
//#include <unordered_map>
//#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")

using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()

//typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18; // segment tree size
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f; // memset(dp, 0x3f, sizeof(dp)), 2*INF < INT_MAX
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10; // double EPS

int in[500050];

vector <pii> Vmx;
vector <pii> Vmn;
int mxp = 0, mnp = 0;
void addval(int p) {
	while (Vmx.size() > mxp) {
		if (Vmx.back().first <= in[p]) Vmx.pop_back();
		else break;
	}
	Vmx.emplace_back(in[p], p);

	while (Vmn.size() > mnp) {
		if (Vmn.back().first >= in[p]) Vmn.pop_back();
		else break;
	}
	Vmn.emplace_back(in[p], p);
}
void removeval(int p) {
	if (Vmx[mxp].second == p) mxp++;
	if (Vmn[mnp].second == p) mnp++;
}

int bit[500050];
int prv[500050];
void update(int p, int v) {
	for (; p <= 500000; p += p & (-p)) bit[p] += v;
}
int getsum(int p) {
	if (p <= 0) return 0;
	int rv = 0;
	for (; p; p -= p & (-p)) rv += bit[p];
	return rv;
}

int dp[500050];
int main() {
	int N, K, D, i, j;
	scanf("%d %d %d", &N, &K, &D);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);

	sort(in + 1, in + N + 1);

	int st = 1;
	for (i = 1; i <= N; i++) {
		addval(i);
		while (Vmx[mxp].first - Vmn[mnp].first > D) {
			removeval(st);
			st++;
		}
		prv[i] = st;
	}

	for (i = K; i <= N; i++) {
		if (prv[i] == 1) dp[i] = 1;
		else {
			int st = prv[i], en = i - K + 1;
			if (st > en) dp[i] = 0;
			else dp[i] = !!(getsum(en - 1) - getsum(st - 2));
		}
		update(i, dp[i]);
	}
	if (dp[N] == 1) printf("YES\n");
	else printf("NO\n");
	return 0;
}