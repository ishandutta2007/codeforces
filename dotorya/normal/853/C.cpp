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

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int nc;
int L[5000000];
int R[5000000];
int sum[5000000];
int update(int n, int S, int E, int p, int v) {
	int nn = ++nc;
	L[nn] = L[n], R[nn] = R[n], sum[nn] = sum[n];
	if (S == E) {
		sum[nn]++;
		return nn;
	}

	int M = (S + E) / 2;
	if (p <= M) L[nn] = update(L[nn], S, M, p, v);
	else R[nn] = update(R[nn], M + 1, E, p, v);
	sum[nn] = sum[L[nn]] + sum[R[nn]];
	return nn;
}
int getsum(int st, int en, int S, int E, int n) {
	if (!n) return 0;
	if (S > en || st > E) return 0;
	if (st <= S && E <= en) return sum[n];
	int M = (S + E) / 2;
	return getsum(st, en, S, M, L[n]) + getsum(st, en, M + 1, E, R[n]);
}

ll aa(ll a) {
	return a * (a - 1) / 2;
}
int in[200050];
int root[200050];
int main() {
	int N, Q, i;
	scanf("%d %d", &N, &Q);
	for (i = 1; i <= N; i++) {
		scanf("%d", &in[i]);
		root[i] = update(root[i - 1], 1, IT_MAX, in[i], 1);
	}
	while (Q--) {
		ll sx, ex, sy, ey;
		scanf("%lld %lld %lld %lld", &sy, &sx, &ey, &ex);

		ll ans = aa(N);
		ans -= aa(sx - 1);
		ans -= aa(sy - 1);
		ans -= aa(N - ex);
		ans -= aa(N - ey);
		
		ans += aa(getsum(1, sx - 1, 1, IT_MAX, root[sy - 1]));
		ans += aa(getsum(1, sx - 1, 1, IT_MAX, root[N]) - getsum(1, sx - 1, 1, IT_MAX, root[ey]));
		ans += aa(getsum(ex + 1, N, 1, IT_MAX, root[sy - 1]));
		ans += aa(getsum(ex + 1, N, 1, IT_MAX, root[N]) - getsum(ex + 1, N, 1, IT_MAX, root[ey]));
		printf("%lld\n", ans);
	}
	return 0;
}