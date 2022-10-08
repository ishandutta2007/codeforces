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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

ll A[1050];
ll B[1050];
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) scanf("%lld", &A[i]);
	for (i = 0; i < N; i++) scanf("%lld", &B[i]);

	db st = 1e-10, en = 1e10, mi;
	for (int q = 1; q <= 200; q++) {
		mi = (st + en) / 2;
		db cur = mi;
		for (i = 0; i < N; i++) {
			db v = (M + cur) / A[i];
			if (cur < v) break;
			cur -= v;

			v = (M + cur) / B[(i + 1) % N];
			if (cur < v) break;
			cur -= v;
		}
		if (i >= N) en = mi;
		else st = mi;
	}
	if (mi > 2e9) return !printf("-1\n");
	return !printf("%.20lf\n", mi);
}