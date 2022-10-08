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
#define rep(i, n) for(int i=0;i<n;i++)  
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

int IT_MAX = 1 << 15;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

map <int, int> Mx;
int in[1000050];
int prv[1000050];
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &in[i]);
		if (Mx.count(in[i])) prv[i] = Mx[in[i]];
		Mx[in[i]] = i;
	}

	ll ans = 0;
	for (i = 1; i <= N; i++) {
		int s = prv[i] + 1, e = i;
		ll cnt = (ll)(e - s + 1) * (N + 1 - e) * 2 - 1;
		ans += cnt;
	}

	db A = 1.0 * ans / N / N;
	return !printf("%.20lf\n", A);
}