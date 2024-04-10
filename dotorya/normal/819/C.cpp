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

inline ll mymul(ll a, ll b) {
	if (LL_INF / b < a) return LL_INF;
	return min(LL_INF, a*b);
}
ll mypow(ll a, ll b) {
	ll rv = 1;
	while (b) {
		if (b % 2) rv = mymul(rv, a);
		a = mymul(a, a);
		b /= 2;
	}
	return rv;
}

bool pchk[1050];
vector <int> plist;

void getp(map<ll, int>& Mu, int x) {
	int i;
	for (auto it : plist) {
		if (it*it > x) break;
		if (x % it) continue;

		int c = 0;
		while (x % it == 0) {
			x /= it;
			c++;
		}
		Mu[it] += c;
	}
	if (x != 1) Mu[x] += 1;
}

map <ll, int> Mn;
map <ll, int> Mm;
map <ll, int> Ms;
vector <pll> Vs;
ll a2 = 0;
void aa(ll N, ll v, ll x) {
	if (x == Vs.size()) {
		if (v <= N) a2++;
		return;
	}

	for (int i = 0; i <= Vs[x].second; i++) {
		aa(N, v, x+1);
		v = mymul(v, Vs[x].first);
	}
	return;
}

int main() {
	int i, j;
	for (i = 2; i <= 1000; i++) {
		if (pchk[i]) continue;
		plist.push_back(i);
		for (j = 2 * i; j <= 1000; j += i) pchk[j] = true;
	}
	
	int T;
	scanf("%d", &T);
	while (T--) {
		int n1, n2, n3, m1, m2, m3, s1, s2, s3;
		scanf("%d %d %d %d %d %d %d %d %d", &n1, &n2, &n3, &m1, &m2, &m3, &s1, &s2, &s3);
		s3 *= 2;
		getp(Mn, n1);
		getp(Mn, n2);
		getp(Mn, n3);
		getp(Mm, m1);
		getp(Mm, m2);
		getp(Mm, m3);
		getp(Ms, s1);
		getp(Ms, s2);
		getp(Ms, s3);
		ll N = (ll)n1 * (ll)n2 * n3;
		ll M = (ll)m1 * (ll)m2 * m3;
		ll S = (ll)s1 * (ll)s2 * s3;

		vector <ll> Vu;
		for (auto it : Mn) {
			ll t1 = it.first;
			int t2 = it.second, t3 = 0;
			if (Ms.count(t1)) t3 = Ms[t1];

			if (t2 > t3) Vu.push_back(mypow(t1, t3 + 1));
		}

		ll a1 = 0;
		for (i = 0; i < (1 << Vu.size()); i++) {
			int c = 0;
			ll x = 1;
			for (j = 0; j < Vu.size(); j++) {
				if (i & (1 << j)) {
					c++;
					x = mymul(x, Vu[j]);
				}
			}
			if (c % 2) a1 -= M / x;
			else a1 += M / x;
		}
		Vu.clear();
		
		for (auto it : Ms) Vs.emplace_back(it.first, it.second);
		a2 = 0;
		aa(N, 1, 0);

		Mn.clear();
		Mm.clear();
		Ms.clear();
		Vs.clear();
		printf("%lld\n", a1 + a2);
	}
	return 0;
}