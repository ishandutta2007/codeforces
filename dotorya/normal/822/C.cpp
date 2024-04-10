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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

vector <pii> Vin[200050];
int main() {
	int N, X, i;
	scanf("%d %d", &N, &X);
	for (i = 1; i <= N; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		Vin[t2 - t1 + 1].emplace_back(t1, t3);
	}
	for (i = 1; i < X; i++) sort(all(Vin[i]));

	ll ans = INF * 2;
	for (i = 1; i < X; i++) {
		ll mn = 2 * INF;
		int p = 0;
		for (auto it : Vin[i]) {
			while (p < Vin[X - i].size()) {
				if (Vin[X - i][p].first + (X - i - 1) >= it.first) break;
				mn = min(mn, (ll)Vin[X - i][p++].second);
			}
			ans = min(ans, mn + it.second);
		}
	}
	if (ans == INF * 2) ans = -1;
	return !printf("%lld\n", ans);
}