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
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size()) 
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

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

ll indt[600000];
void update(int p, ll v) {
	p += IT_MAX - 1;
	indt[p] = v;
	for (p /= 2; p; p /= 2) indt[p] = max(indt[2 * p], indt[2 * p + 1]);
}
ll getmx(int p1, int p2) {
	p1 += IT_MAX - 1;
	p2 += IT_MAX - 1;
	ll rv = -LL_INF;
	for (; p1 <= p2; p1 /= 2, p2 /= 2) {
		if (p1 % 2 == 1) rv = max(rv, indt[p1++]);
		if (p2 % 2 == 0) rv = max(rv, indt[p2--]);
	}
	return rv;
}

ll cnt1[200050];
ll cnt2[200050];
ll sum1[200050];
ll sum2[200050];

ll mx[200050];
ll val[200050];
ll vsum[200050];

int main() {
	int N, i;
	ll C;
	scanf("%d %lld", &N, &C);
	for (i = 1; i <= 2 * N - 1; i++) {
		if (i % 2 == 1) scanf("%lld", &cnt1[(i+1)/2]);
		else scanf("%lld", &cnt2[i / 2]);
	}
	if (N == 1) return !printf("%lld\n", min(cnt1[1], C));

	for (i = 1; i <= N; i++) cnt1[i] = min(cnt1[i], C);
	for (i = 1; i < N; i++) cnt2[i] = min(cnt2[i], C);
	for (i = 1; i <= N; i++) sum1[i] = sum1[i - 1] + cnt1[i];
	for (i = 1; i < N; i++) sum2[i] = sum2[i - 1] + cnt2[i];

	val[1] = cnt1[1];
	vsum[1] = val[1];          
	update(1, -sum1[0] - sum2[0] + vsum[0]);
	for (i = 2; i <= N; i++) {
		int st = 1, en = i - 1, mi, rv = i;
		while (st <= en) {
			mi = (st + en) / 2;
			if (sum1[i] + sum2[i - 1] - sum1[mi - 1] - sum2[mi - 1] <= C) {
				rv = mi;
				en = mi - 1;
			}
			else st = mi + 1;
		}

		ll v = 0;
		if (rv != 1) v = max(v, C - vsum[i-1] + vsum[rv - 2]);
		v = max(v, sum1[i] + sum2[i - 1] - vsum[i - 1] + getmx(rv, i - 1));
		v = max(v, cnt1[i]);
		val[i] = v;
		vsum[i] = vsum[i - 1] + val[i];
		update(i, -sum1[i - 1] - sum2[i - 1] + vsum[i - 1]);
	}
	return !printf("%lld\n", vsum[N]);
}