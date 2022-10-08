#include <algorithm>
#include <assert.h>
#include <bitset>
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
#include <string>
#include <time.h>
#include <cmath>
#include <vector>
#include <deque>
//#include <unordered_set>
#include <unordered_map>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
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

int IT_MAX = 1 << 20;
const ll MOD = 98765431;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-6;

ll in[100050];
ll sum[100050];
ll getans(ll N, vector <ll> Vx) {
	ll rv = 0;
	map <ll, ll> Mx;
	Mx[0] = 1;
	for (int i = 1; i <= N; i++) {
		for (auto it : Vx) {
			ll v = sum[i] - it;
			if (Mx.count(v)) rv += Mx[v];
		}
		Mx[sum[i]]++;
	}
	return rv;
}
int main() {
	ll N, K, i;
	scanf("%lld %lld", &N, &K);
	for (i = 1; i <= N; i++) {
		scanf("%lld", &in[i]);
		sum[i] = sum[i - 1] + in[i];
	}

	vector <ll> Vx;
	if (K == 1) Vx.push_back(1);
	else if (K == -1) {
		Vx.push_back(1);
		Vx.push_back(-1);
	}
	else {
		for (i = 1; abs(i) < 1e15; i *= K) Vx.push_back(i);
	}
	return !printf("%lld\n", getans(N, Vx));
}