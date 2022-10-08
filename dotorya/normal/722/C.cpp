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
#include <string>
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

int IT_MAX = 262144;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-11;

multiset <pii> Sx1;
multiset <ll> Sx2;

ll sum[100050];
void mpush(pii u) {
	Sx1.insert(u);
	Sx2.insert(sum[u.second] - sum[u.first - 1]);
}
void merase(pii u) {
	ll s = sum[u.second] - sum[u.first - 1];
	Sx1.erase(u);
	auto it = Sx2.lower_bound(s);
	Sx2.erase(it);
}
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		ll t;
		scanf("%lld", &t);
		sum[i] = sum[i - 1] + t;
	}
	
	mpush(pii(1, N));
	for (i = 1; i < N; i++) {
		int p;
		scanf("%d", &p);

		auto it = Sx1.lower_bound(pii(p + 1, 0));
		it--;
		
		pii u = *it;
		merase(u);
		if (u.first != p) mpush(pii(u.first, p - 1));
		if (u.second != p) mpush(pii(p + 1, u.second));

		auto it2 = Sx2.end();
		it2--;
		printf("%lld\n", *it2);
	}
	return !printf("0\n");
}