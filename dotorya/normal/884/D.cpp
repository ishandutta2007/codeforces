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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

priority_queue <ll, vector<ll>, greater<ll>> Hx;

int main() {
	int N, i;
	scanf("%d", &N);
	for(i = 1; i <= N; i++) {
		ll t;
		scanf("%lld", &t);
		Hx.push(t);
	}

	ll ans = 0;
	if (N % 2 == 0) {
		ll t1 = Hx.top();
		Hx.pop();
		ll t2 = Hx.top();
		Hx.pop();
		ans += t1 + t2;
		Hx.push(t1 + t2);
	}
	
	while (Hx.size() >= 3) {
		ll t1 = Hx.top();
		Hx.pop();
		ll t2 = Hx.top();
		Hx.pop();
		ll t3 = Hx.top();
		Hx.pop();
		ans += t1 + t2 + t3;
		Hx.push(t1 + t2 + t3);
	}
	return !printf("%lld\n", ans);
}