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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

ll in[100050];
ll sum[100050];
int main() {
	ll N, K, M, i, j;
	scanf("%lld %lld %lld", &N, &K, &M);
	for (i = 1; i <= N; i++) scanf("%lld", &in[i]);

	sort(in + 1, in + N + 1);
	for (i = 1; i <= N; i++) sum[i] = sum[i - 1] + in[i];

	db mx = -1;
	for (i = 0; i < N && i <= M; i++) {
		ll x = min(M - i, (N - i)*K);
		
		db v = (sum[N] - sum[i] + x) / (db)(N - i);
		mx = max(mx, v);
	}
	return !printf("%.20lf\n", mx);
}