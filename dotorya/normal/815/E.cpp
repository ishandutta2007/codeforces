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

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

// based on http://codeforces.com/contest/815/submission/27862681

map <ll, ll> Mx;

void getmap(ll x) {
	map <ll, ll> Mu;
	Mx.clear();
	Mu[x] = 1;
	while (!Mu.empty()) {
		auto it = Mu.end();
		it--;
		if (it->first == 0) break;
		pll u = *it;
		Mu.erase(it);

		Mx[(u.first - 1) / 2] += u.second;
		Mu[(u.first - 1) / 2] += u.second;
		Mu[u.first / 2] += u.second;
	}
}
int main() {
	ll N, K, i, j;
	scanf("%lld %lld", &N, &K);
	if (K == 1) return !printf("1\n");
	if (K == 2) return !printf("%lld\n", N);
	K -= 2;

	getmap(N - 2);
	ll v = 0;
	for (auto it = Mx.end();;) {
		it--;
		if (K <= it->second) {
			v = it->first;
			break;
		}
		K -= it->second;
	}

	ll st = 1, en = N;
	while (st <= en) {
		ll mi = (st + en) / 2;
		ll L = en - st - 1;
		if ((L - 1) / 2 == v) {
			if (--K == 0) return !printf("%lld\n", mi);
		}

		getmap(mi - st - 1);
		if (Mx[v] >= K) en = mi;
		else {
			st = mi;
			K -= Mx[v];
		}
	}
	return 0;
}