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
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

map <ll, int> Mx;
int ch(ll x) {
	if (Mx.count(x)) return Mx[x];
	int t = Mx.size() + 1;
	return Mx[x] = t;
}

vector <pii> Ve;
int r[200050];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}

int vcnt[200050];
int ecnt[200050];

ll po2[200050];
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		ll t1, t2;
		scanf("%lld %lld", &t1, &t2);
		t2 += LL_INF;
		t1 = ch(t1), t2 = ch(t2);
		Ve.emplace_back(t1, t2);
	}

	int X = Mx.size();
	for (i = 1; i <= X; i++) r[i] = i;
	for (auto it : Ve) r[root(it.first)] = root(it.second);
	for (i = 1; i <= X; i++) vcnt[root(i)]++;
	for (auto it : Ve) ecnt[root(it.first)]++;

	ll ans = 1;
	po2[0] = 1;
	for (i = 1; i <= 200000; i++) po2[i] = po2[i - 1] * 2 % MOD;

	for (i = 1; i <= X; i++) {
		if (ecnt[i] == 0) continue;

		ll v = po2[vcnt[i]];
		if (vcnt[i] - 1 == ecnt[i]) v--;
		ans = (ans*v) % MOD;
	}
	return !printf("%lld\n", ans);
}