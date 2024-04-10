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

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple <int, int, int> t3;

int IT_MAX = 1 << 20;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

ll in1[1050];
ll in2[2050];
int main() {
	int N, K, P, i, j;
	scanf("%d %d %d", &N, &K, &P);
	for (i = 1; i <= N; i++) scanf("%lld", &in1[i]);
	for (i = 1; i <= K; i++) scanf("%lld", &in2[i]);
	sort(in2 + 1, in2 + K + 1);

	ll st = 0, en = (ll)INF * 10, mi, rv = en + 1;
	while (st <= en) {
		mi = (st + en) / 2;
		
		vector <pll> Vu;
		for (i = 1; i <= N; i++) {
			ll d = abs(P - in1[i]);
			ll st = min(in1[i], (ll)P), en = max(in1[i], (ll)P);
			d = mi - d;
			if (d < 0) break;
			st -= d / 2, en += d / 2;
			Vu.emplace_back(st, en);
		}
		if (i <= N) {
			st = mi + 1;
			continue;
		}
		sort(all(Vu), [](pll a, pll b) {
			return a.second < b.second;
		});

		multiset <ll> Sx;
		int p = 1;
		for (i = 0; i < Vu.size(); i++) {
			while (p <= K) {
				if (in2[p] > Vu[i].second) break;
				Sx.insert(in2[p++]);
			}
			auto it = Sx.lower_bound(Vu[i].first);
			if (it == Sx.end()) break;
			Sx.erase(it);
		}
		if (i >= Vu.size()) {
			rv = mi;
			en = mi - 1;
		}
		else st = mi + 1;
	}
	return !printf("%lld\n", rv);
}