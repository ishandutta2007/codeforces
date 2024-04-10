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

pii sz[600050];
int r[600050];
int root(int x) {
	return (x == r[x]) ? x : root(r[x]);
}

vector <pii> Vl[2000050];
void init(int st, int en, int S, int E, int n, pii v) {
	if (en < S || E < st) return;
	if (st <= S && E <= en) {
		Vl[n].push_back(v);
		return;
	}

	int M = (S + E) / 2;
	init(st, en, S, M, 2 * n, v);
	init(st, en, M + 1, E, 2 * n + 1, v);
}

void printans(int S, int E, int n, ll cur) {
	vector <pii> Vr;
	vector<pair<int, pii>> Vsz;
	for (auto it : Vl[n]) {
		int a = it.first, b = it.second;
		a = root(a), b = root(b);
		if (a == b) continue;

		if (sz[a].first + sz[a].second > sz[b].first + sz[b].second) swap(a, b);

		cur -= (ll)sz[a].first * sz[a].second;
		cur -= (ll)sz[b].first * sz[b].second;
		Vr.emplace_back(a, r[a]);
		Vsz.emplace_back(b, sz[b]);
		sz[b] = pii(sz[a].first + sz[b].first, sz[a].second + sz[b].second);
		r[a] = b;
		cur += (ll)sz[b].first * sz[b].second;
	}

	if (S == E) printf("%lld ", cur);
	else {
		int M = (S + E) / 2;
		printans(S, M, 2 * n, cur);
		printans(M + 1, E, 2 * n + 1, cur);
	}
	
	reverse(all(Vr));
	reverse(all(Vsz));
	for (auto it : Vr) r[it.first] = it.second;
	for (auto it : Vsz) sz[it.first] = it.second;
}

int main() {
	int N, i, j;
	scanf("%d", &N);

	map <pii, int> Mx;
	for (i = 1; i <= N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		t2 += 300000;
		if (Mx.count(pii(t1, t2))) {
			init(Mx[pii(t1, t2)], i - 1, 1, N, 1, pii(t1, t2));
			Mx.erase(pii(t1, t2));
		}
		else Mx[pii(t1, t2)] = i;
	}
	for (auto it : Mx) init(it.second, N, 1, N, 1, it.first);

	for (i = 1; i <= 600000; i++) {
		r[i] = i;
		if (i <= 300000) sz[i] = pii(1, 0);
		else sz[i] = pii(0, 1);
	}
	printans(1, N, 1, 0);
	return !printf("\n");
}