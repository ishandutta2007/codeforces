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
ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

bool pchk[1000050];
vector <int> Vp;

vector <int> Vl[1000050];

vector <pll> Vu;
ll getcnt(ll t) {
	ll rv = 0;
	for (auto it : Vu) rv += (t / it.first) * it.second;
	return rv;
}
int main() {
	int i, j;
	for (i = 2; i <= 1000000; i++) {
		if (pchk[i]) continue;
		Vp.push_back(i);
		for (j = 2 * i; j <= 1000000; j += i) pchk[j] = true;
		for (j = i; j <= 1000000; j += i) Vl[j].push_back(i);
	}

	int T;
	scanf("%d", &T);
	while (T--) {
		ll X, P, K;
		scanf("%lld %lld %lld", &X, &P, &K);

		Vu.clear();
		int n = Vl[P].size();
		for (i = 0; i < (1 << n); i++) {
			ll v = 1, c = 0;
			for (j = 0; j < n; j++) {
				if (i & (1 << j)) {
					v *= Vl[P][j];
					c++;
				}
			}
			if (c % 2 == 0) Vu.emplace_back(v, 1);
			else Vu.emplace_back(v, -1);
		}
		ll c = getcnt(X);
		ll st = X + 1, en = 1e11, mi, rv = en + 1;
		while (st <= en) {
			mi = (st + en) / 2;
			ll c2 = getcnt(mi) - c;
			if (c2 >= K) {
				rv = mi;
				en = mi - 1;
			}
			else st = mi + 1;
		}
		printf("%lld\n", rv);
	}
	return 0;
}
//*/