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

ll A[100050];
ll B[100050];
int main() {
	ll N, P, i, j;
	scanf("%lld %lld", &N, &P);
	for (i = 1; i <= N; i++) scanf("%lld %lld", &A[i], &B[i]);

	ll s = 0;
	for (i = 1; i <= N; i++) s += A[i];
	if (s <= P) return !printf("-1\n");

	db st = 0, en = LL_INF;
	for (i = 1; i <= 150; i++) {
		db mi = (st + en) / 2;

		db s = 0;
		for (j = 1; j <= N; j++) {
			db t = B[j] - mi * A[j];
			if (t < 0) s += t;
		}
		if (s >= -mi*P) st = mi;
		else en = mi;
	}
	return !printf("%.20lf\n", st);
}