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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

ll in[105];
bool isValid(ll N, ll K, ll d) {
	ll v = 0;
	for (int i = 1; i <= N; i++) v += (in[i] - 1) % d;
	if (v >= (d - 1) * N - K) return true;
	return false;
}
int main() {
	int N, i, j;
	ll K;
	scanf("%d %lld", &N, &K);
//	N = 100, K = 1215752192ll;
	for (i = 1; i <= N; i++) {
		scanf("%lld", &in[i]);
//		in[i] = 1000000000ll;
	}
	ll ans = 0;
	for (i = 1; i <= 500000; i++) if (isValid(N, K, i)) ans = i;

	vector <ll> Vu;
	for (i = 1; i <= N; i++) {
		for (j = 0; j <= 2000; j++) {
			ll v = (in[i] - 1) / (j + 1) + 1;
			Vu.push_back(v);
		}
	}
	Vu.push_back((ll)INF * 1000);
	sort(all(Vu));
	Vu.erase(unique(all(Vu)), Vu.end());
	for (i = 0; i + 1 < Vu.size(); i++) {
		ll v1 = Vu[i], v2 = Vu[i + 1] - 1;
		ll st = v1, en = v2, mi, rv = v1 - 1;
		while (st <= en) {
			mi = (st + en) / 2;
			if (isValid(N, K, mi)) {
				rv = mi;
				st = mi + 1;
			}
			else en = mi - 1;
		}
		if (rv != v1 - 1) ans = max(ans, rv);
	}
	return !printf("%lld\n", ans);
}