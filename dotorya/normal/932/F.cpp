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

int IT_MAX = 1 << 19;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

pll operator - (pll a, pll b) {
	return pll(a.first - b.first, a.second - b.second);
}

// a.first*b.second-a.second*b.first
ll ccw(pll a, pll b) {
	if (a.first == 0 || b.second == 0) {
		if (a.second == 0 || b.first == 0) return 0;
		if ((a.second > 0) == (b.first > 0)) return -1;
		return 1;
	}
	if (a.second == 0 || b.first == 0) {
		if ((a.first > 0) == (b.second > 0)) return 1;
		return -1;
	}

	ll v = 1;
	ll t1 = 1, t2 = 1;
	if ((a.first > 0) == (b.second > 0)) t1 = 1;
	else t1 = -1;

	if ((a.second > 0) == (b.first > 0)) t2 = 1;
	else t2 = -1;
	if (t1 != t2) return t1;

	a.first = abs(a.first);
	a.second = abs(a.second);
	b.first = abs(b.first);
	b.second = abs(b.second);

	ll v2 = 0;
	ll t3 = b.second / b.first, t4 = a.second / a.first;
	if (t3 != t4) {
		if (t3 > t4) v2 = 1;
		else v2 = -1;
	}
	else {
		b.second %= b.first;
		a.second %= a.first;
		v2 = a.first*b.second - a.second*b.first;
	}
	v2 *= t1;
	return v2;
}

set <pll> Sx[200050];
int ch[200050];
int sc = 0;

void addval(set <pll> &Sx, pll u) {
	auto it = Sx.lower_bound(pll(u.first, u.second+1));
	if (it != Sx.begin()) {
		it--;
		if (it->first == u.first) return;
	}

	auto it1 = Sx.lower_bound(u);
	auto it2 = it1;
	if (it1 != Sx.begin() && it1 != Sx.end()) {
		it2--;
		if (ccw(u - *it2, *it1 - *it2) > 0);
		else return;
	}
	
	while (1) {
		auto it = Sx.lower_bound(u);
		if (it == Sx.end() || it->first != u.first) break;
		Sx.erase(it);
	}
	while (1) {
		auto it1 = Sx.lower_bound(u);
		if (it1 == Sx.end()) break;
		auto it2 = it1;
		it2++;
		if (it2 == Sx.end()) break;
		if (ccw(*it1 - u, *it2 - u) > 0) break;
		Sx.erase(it1);
	}
	while (1) {
		auto it1 = Sx.lower_bound(u);
		if (it1 == Sx.begin()) break;
		it1--;
		if (it1 == Sx.begin()) break;
		auto it2 = it1;
		it2--;

		if (ccw(*it1 - *it2, u - *it2) > 0) break;
		Sx.erase(it1);
	}
	Sx.insert(u);
}
ll getmn(set <pll> &Sx, ll x) {
	ll st = -INF, en = INF, mi, rv = en+1;
	while (st <= en) {
		mi = (st + en) / 2;
		auto it = Sx.lower_bound(pll(mi, -LL_INF));
		if (it == Sx.end()) {
			rv = mi;
			en = mi - 1;
			continue;
		}
		auto it2 = it;
		it2++;
		if (it2 == Sx.end()) {
			rv = mi;
			en = mi - 1;
			continue;
		}
		if (it->first * x + it->second <= it2->first * x + it2->second) {
			rv = mi;
			en = mi - 1;
		}
		else st = mi + 1;
	}
	auto it = Sx.lower_bound(pll(rv, -LL_INF));
	return it->first*x + it->second;
}

ll A[100050];
ll B[100050];
ll dp[100050];
vector <int> conn[100050];
vector <int> son[100050];
bool dchk[100050];
void DFS(int n) {
	dchk[n] = true;
	for (auto it : conn[n]) {
		if (dchk[it]) continue;
		son[n].push_back(it);
		DFS(it);
	}

	if (son[n].empty()) {
		dp[n] = 0;
		ch[n] = ++sc;
		addval(Sx[sc], pll(B[n], 0));
		return;
	}

	dp[n] = LL_INF;
	for (auto it : son[n]) dp[n] = min(dp[n], getmn(Sx[ch[it]], A[n]));
	sort(all(son[n]), [](int a, int b) {
		return Sx[ch[a]].size() > Sx[ch[b]].size();
	});
	ch[n] = ch[son[n][0]];
	for (int i = 1; i < son[n].size(); i++) {
		int t = son[n][i];
		for (auto it : Sx[ch[t]]) addval(Sx[ch[n]], it);
	}
	addval(Sx[ch[n]], pll(B[n], dp[n]));
}
int DEBUG = 0;
int main() {
	int N, i;
	if (!DEBUG) {
		scanf("%d", &N);
		for (i = 1; i <= N; i++) scanf("%lld", &A[i]);
		for (i = 1; i <= N; i++) scanf("%lld", &B[i]);
	}
	else {
		N = 100000;
		for (i = 1; i <= N; i++) A[i] = 100000;
		for (i = 1; i <= N; i++) B[i] = 100000;
	}
	for (i = 1; i < N; i++) {
		int t1, t2;
		if(!DEBUG) scanf("%d %d", &t1, &t2);
		else t1 = i, t2 = i + 1;
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}
	DFS(1);

	for (i = 1; i <= (DEBUG?100:N); i++) printf("%lld ", dp[i]);
	return !printf("\n");
}