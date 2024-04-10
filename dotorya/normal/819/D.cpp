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

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

ll mul_inv(ll a, ll b) {
	ll t1 = a, t2 = b, t3;
	ll v1 = 1, v2 = 0, v3;
	while (t2 != 1) {
		ll x = t1 / t2;
		t3 = t1 - x*t2;
		v3 = v1 - x*v2;
		t1 = t2, t2 = t3;
		v1 = v2, v2 = v3;
	}
	return (v2 + b) % b;
}

ll gcd(ll a, ll b) {
	return (a == 0) ? b : gcd(b%a, a);
}
map <ll, int> Mx;
int ch(ll x) {
	if (Mx.count(x)) return Mx[x];
	int t = Mx.size() + 1;
	Mx[x] = t;
	return t;
}
vector <int> Vu[200050];

ll in[200050];

ll ans[200050];
int main() {
	ll T, N, i, j;
	scanf("%lld %lld", &T, &N);
	scanf("%lld", &in[N]);
	for (i = 1; i < N; i++) scanf("%lld", &in[i]);
	
	for (i = 1; i <= N; i++) in[i] = (in[i - 1] + in[i]) % T;

	if (in[N] == 0) {
		set <ll> Sx;
		for (i = 0; i < N; i++) {
			if (Sx.count(in[i])) printf("0 ");
			else printf("1 ");
			Sx.insert(in[i]);
		}
		return 0;
	}
	
	ll g = gcd(in[N], T);
	for (i = 0; i < N; i++) {
		int t = ch(in[i] % g);
		Vu[t].push_back(i);
		in[i] /= g;
	}
	T /= g;
	in[N] /= g;
	
	for (i = 1; i <= Mx.size(); i++) {
		vector <pll> Vu2;
		for (auto it : Vu[i]) Vu2.emplace_back(in[it] * mul_inv(in[N], T) % T, it);
		sort(all(Vu2), [](pll a, pll b) {
			if (a.first != b.first) return a.first < b.first;
			return a.second > b.second;
		});
		Vu2.push_back(Vu2[0]);
		Vu2.back().first += T;
		for (j = 0; j + 1 < Vu2.size(); j++) ans[Vu2[j].second] = Vu2[j + 1].first - Vu2[j].first;
	}
	for (i = 0; i < N; i++) printf("%lld ", ans[i]);
	return !printf("\n");
}