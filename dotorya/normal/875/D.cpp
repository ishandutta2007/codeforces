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
//#include <unordered_map>  
//#include <unordered_set>  
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

//typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple<int, int, int> t3;
#define rep(i, n) for(int i=0;i<n;i++)

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-12;

pii operator + (pii a, pii b) {
	return pii(a.first | b.first, max(a.second, b.second));
}
pii indt[600000];
void update(int p, int v) {
	p += IT_MAX - 1;
	indt[p] = pii(v, v);
	for (p /= 2; p; p /= 2) indt[p] = indt[2 * p] + indt[2 * p + 1];
}
pii getsum(int p1, int p2) {
	pii rv = pii(0, 0);
	for (p1 += IT_MAX - 1, p2 += IT_MAX - 1; p1 <= p2; p1 /= 2, p2 /= 2) {
		if (p1 % 2 == 1) rv = rv + indt[p1++];
		if (p2 % 2 == 0) rv = rv + indt[p2--];
	}
	return rv;
}

int in[200050];
int u[200050];
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &in[i]);
		update(i, in[i]);
	}

	for (i = 1; i <= N; i++) u[i] = i;
	sort(u + 1, u + N + 1, [](int a, int b) {
		if (in[a] != in[b]) return in[a] < in[b];
		return a < b;
	});
	
	ll ans = (ll)N * (N + 1) / 2;
	for (i = 1; i <= N; i++) {
		int p = u[i];
		int st = 1, en = p - 1, mi, rv = p;
		while (st <= en) {
			mi = (st + en) / 2;
			pii u = getsum(mi, p - 1);
			if ((u.first & in[p]) == u.first && u.second <= in[p]) {
				rv = mi;
				en = mi - 1;
			}
			else st = mi + 1;
		}
		st = p + 1, en = N, mi;
		int rv2 = p;
		while (st <= en) {
			mi = (st + en) / 2;
			pii u = getsum(p + 1, mi);
			if ((u.first & in[p]) == u.first && u.second < in[p]) {
				rv2 = mi;
				st = mi + 1;
			}
			else en = mi - 1;
		}
		ans -= (ll)(rv2 - p + 1) * (p - rv + 1);
	}
	return !printf("%lld\n", ans);
}