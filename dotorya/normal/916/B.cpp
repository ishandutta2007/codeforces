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

int IT_MAX = 1 << 20;
ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int getcnt(ll t) {
	int c = 0;
	while (t) {
		if (t % 2) c++;
		t /= 2;
	}
	return c;
}
int main() {
	ll N, K, i, j;
	scanf("%lld %lld", &N, &K);

	int c = 0;
	ll t = N;
	while (t) {
		if (t % 2) c++;
		t /= 2;
	}
	if (c > K) return !printf("No\n");

	printf("Yes\n");
	
	vector <int> Va;

	for (i = 62;; i--) {
		if (i >= 0 && (N < (1ll << i))) continue;

		ll v;
		if(i >= 0) v = (N / (1ll << i)) + getcnt(N % (1ll << i));
		else v = N << (-i);
		if (v > K) break;
	}
	int mx = i + 1;
	if (mx >= 0) {
		for (i = 1; i <= N / (1ll << mx); i++) Va.push_back(mx);
		N %= 1ll << mx;
	}
	else {
		for (i = 1; i <= (N << (-mx)); i++) Va.push_back(mx);
		N = 0;
	}
	for (i = 62; i >= 0; i--) if (N & (1ll << i)) Va.push_back(i);
	while (Va.size() < K) {
		ll t = Va.back();
		Va.pop_back();
		Va.push_back(t - 1);
		Va.push_back(t - 1);
	}
	for (auto it : Va) printf("%d ", it);
	return !printf("\n");
}
//*/