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

int IT_MAX = 1 << 16;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

ll DB[16] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53 };

ll mymul(ll a, ll b) {
	if (a > LL_INF / b) return LL_INF;
	return min(LL_INF, a * b);
}

set <ll> Sx;
ll in[20];

vector <ll> Vu[2];
void aa(vector <ll>& Vu, int s, int e) {
	Sx.clear();
	Sx.insert(1);
	int i, j;
	for (i = 1;; i++) {
		ll u = *(Sx.begin());
		Sx.erase(u);
		if (u > 1.5e18) break;

		Sx.insert(mymul(u,in[s]));
		for (j = s; j < e; j++) if (u%in[j] == 0) Sx.insert(mymul(u / in[j], in[j + 1]));
		Vu.push_back(u);
	}
}
int main() {
	int N;
	ll i, j, K;
	scanf("%d", &N);
	//N = 16;
	for (i = 1; i <= N; i++) {
		scanf("%lld", &in[i]);
		//in[i] = DB[i-1];
	}
	scanf("%lld", &K);
	//K = 0;

	if (N <= 6) {
		aa(Vu[0], 1, N);
		return !printf("%lld\n", Vu[0][K - 1]);
	}

	int n1 = min(6, N / 2);
	aa(Vu[0], 1, n1);
	aa(Vu[1], n1 + 1, N);

	ll st = 1, en = LL_INF, mi, rv = en + 1;
	while (st <= en) {
		mi = (st + en) / 2;
		
		ll c = 0;
		for (auto it : Vu[1]) {
			ll x = mi / it;
			int p = lower_bound(all(Vu[0]), x + 1) - Vu[0].begin();
			c += p;
		}
		if (c >= K) {
			rv = mi;
			en = mi - 1;
		}
		else st = mi + 1;
	}
	
	return !printf("%lld\n", rv);
}