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
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()  
#define ldb ldouble  

//typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple<int, int, int> t3;
#define rep(i, n) for(int i=0;i<n;i++)

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-12;

ll X[200050];
ll val[200050];
pll indt[600050];

set <pll> Sx[600050];
void update(int p, int v, int o, ll curt) {
	p += IT_MAX - 1;
	if (o == 1) {
		X[v] = p - IT_MAX + 1;
		val[v] = curt;
		Sx[p].emplace(curt, v);
		for (; p; p /= 2) indt[p] = min(indt[p], pll(curt, v));
	}
	else {
		pll u = pll(val[v], v);
		Sx[p].erase(u);

		indt[p] = pll(LL_INF, LL_INF);
		if (!Sx[p].empty()) indt[p] = *Sx[p].begin();
		for (p /= 2; p; p /= 2) indt[p] = min(indt[2 * p], indt[2 * p + 1]);
	}
}
pair<int,pll> getlower(int n) {
	int p = IT_MAX + n - 1;
	while (1) {
		if (indt[p] != pll(LL_INF, LL_INF)) break;
		if (p & (p - 1));
		else return mp(-INF, pll(LL_INF, LL_INF));
		p = (p - 1) / 2;
	}
	while (p < IT_MAX) {
		if (indt[2 * p + 1] != pll(LL_INF, LL_INF)) p = 2 * p + 1;
		else p = 2 * p;
	}
	return mp(p - IT_MAX + 1, indt[p]);
}
pair<int, pll> getupper(int n) {
	int p = IT_MAX + n - 1;
	while (1) {
		if (indt[p] != pll(LL_INF, LL_INF)) break;
		if (p & (p + 1));
		else return mp(INF, pll(LL_INF, LL_INF));
		p = (p + 1) / 2;
	}
	while (p < IT_MAX) {
		if (indt[2 * p] != pll(LL_INF, LL_INF)) p = 2 * p;
		else p = 2 * p + 1;
	}
	return  mp(p - IT_MAX + 1, indt[p]);
}

priority_queue <pair<ll, pll>, vector<pair<ll,pll>>, greater<pair<ll,pll>>> Hx1;
priority_queue <int, vector<int>, greater<int>> Hx2;

ll in[200050][3];
int main() {
	int N, K, M, i, j;
	scanf("%d %d %d", &N, &K, &M);
	for (i = 1; i <= K; i++) scanf("%lld", &X[i]);
	for (i = 1; i <= M; i++) {
		scanf("%lld %lld %lld", &in[i][0], &in[i][1], &in[i][2]);
		Hx1.emplace(in[i][0], pll(i, i));
	}
	for (i = 1; i < 2 * IT_MAX; i++) indt[i] = pll(LL_INF, LL_INF);
	for (i = 1; i <= K; i++) update(X[i], i, 1, 0);

	ll curt = 0;
	while (!Hx1.empty() || !Hx2.empty()) {
		curt = Hx1.top().first;
		while (!Hx1.empty()) {
			if (Hx1.top().first != curt) break;
			
			pll t = Hx1.top().second;
			Hx1.pop();
			if (t.first > 0) Hx2.push(t.first);
			else update(t.second, -t.first, 1, curt);
		}

		while (!Hx2.empty()) {
			int t = Hx2.top();

			auto u1 = getlower(in[t][1]);
			auto u2 = getupper(in[t][1]);
			u1.first = in[t][1] - u1.first;
			u2.first = u2.first - in[t][1];
			if (u1 > u2) u1 = u2;
			if (u1.second.second >= 1 && u1.second.second <= K) {
				printf("%lld %lld\n", u1.second.second, curt - in[t][0] + u1.first);
				update(X[u1.second.second], u1.second.second, -1, curt);
				Hx1.emplace(curt + u1.first + abs(in[t][1] - in[t][2]), pll(-u1.second.second, in[t][2]));
				Hx2.pop();
			}
			else break;
		}
	}
	return 0;
}