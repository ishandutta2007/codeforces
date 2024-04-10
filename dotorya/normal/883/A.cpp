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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-12;

ll in[100050];
int main() {
	ll N, M, A, D, i, j;
	scanf("%lld %lld %lld %lld", &N, &M, &A, &D);
	for (i = 1; i <= M; i++) scanf("%lld", &in[i]);

	ll c = D / A + 1;

	ll ans = 0, p1 = 0, p2 = 0;
	while (p1 != N || p2 != M) {
		if (p1 != N && (p2 == M || (p1+1) * A < in[p2+1])) {
			ll x = min(N + 1, (in[p2+1] + A - 1) / A) - (p1 + 1);
			if (p2 == M) x = N - p1;
			ll c2 = (x + c - 1) / c;

			ll s = (p1 + 1)*A, e = s + c*(c2 - 1)*A + D;
			p2 = lower_bound(in + 1, in + M + 1, e + 1) - (in + 1);
			p1 = min(N, e / A);
			ans += c2;
		}
		else {
			ans++;
			ll s = in[p2+1], e = s + D;
			p2 = lower_bound(in + 1, in + M + 1, e + 1) - (in + 1);
			p1 = min(N, e / A);
		}
	}
	return !printf("%lld\n", ans);
}