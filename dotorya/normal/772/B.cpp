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
const ll MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)

pll operator - (pll a, pll b) {
	return pll(a.first - b.first, a.second - b.second);
}

pll in[2050];
vector <pll> Vu;
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%lld %lld", &in[i].first, &in[i].second);
	for (i = 0; i < N; i++) in[i + N] = in[i];

	for (i = 0; i < N; i++) {
		Vu.push_back(in[i + 1] - in[i]);
		Vu.push_back(in[i + 2] - in[i]);
	}

	db ans = INF;
	for (auto it : Vu) {
		vector <ll> Vv;
		for (i = 0; i < N; i++) Vv.push_back(in[i].second * it.first - in[i].first * it.second);

		sort(all(Vv));

		for (i = 0; i + 2 < N; i++) {
			db t = 1.0 * (Vv[i + 2] - Vv[i]) / 2 / sqrt(it.first*it.first + it.second*it.second);
			ans = min(ans, t);
		}
	}
	return !printf("%.20lf\n", ans);
}