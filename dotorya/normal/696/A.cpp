#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
//#include <unordered_set>
//#include <unordered_map>

#pragma warning(disable:4996)
using namespace std;

#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;

int IT_MAX = 1 << 17;
const ll MOD = 1000000009;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-13;

map <ll, ll> Mx;

vector <ll> V1;
vector <ll> V2;
int main() {
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int c;
		ll t1, t2, t3;
		scanf("%d %lld %lld", &c, &t1, &t2);
		while (t1) {
			V1.push_back(t1);
			t1 /= 2;
		}
		while (t2) {
			V2.push_back(t2);
			t2 /= 2;
		}
		ll mx = 0;
		while (!V1.empty() && !V2.empty()) {
			if (V1.back() != V2.back()) break;
			mx = V1.back();
			V1.pop_back();
			V2.pop_back();
		}
		if (c == 1) {
			scanf("%lld", &t3);	
			for (auto it : V1) Mx[it] += t3;
			for (auto it : V2) Mx[it] += t3;
		}
		else {
			ll ans = 0;
			for (auto it : V1) if (Mx.count(it)) ans += Mx[it];
			for (auto it : V2) if (Mx.count(it)) ans += Mx[it];
			printf("%lld\n", ans);
		}
		V1.clear();
		V2.clear();
	}
	return 0;
}