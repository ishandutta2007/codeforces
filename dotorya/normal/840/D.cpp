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
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int L[7000000];
int R[7000000];
int sum[7000000];
int nc;
int update(int prv, int st, int en, int p, int v) {
	int nn = ++nc;
	L[nn] = L[prv], R[nn] = R[prv], sum[nn] = sum[prv];
	if (st == en) {
		sum[nn] += v;
		return nn;
	}

	int mi = (st + en) / 2;
	if (p <= mi) L[nn] = update(L[nn], st, mi, p, v);
	else R[nn] = update(R[nn], mi + 1, en, p, v);
	sum[nn] = sum[L[nn]] + sum[R[nn]];
	return nn;
}
int getsum(int st, int en, int S, int E, int n) {
	if (!n) return 0;
	if (en < S || E < st) return 0;
	if (st <= S && E <= en) return sum[n];

	int M = (S + E) / 2;
	return getsum(st, en, S, M, L[n]) + getsum(st, en, M + 1, E, R[n]);
}
int getnxt(int S, int E, int n1, int n2, int x) {
//	printf("S, E, x = %d %d %d\n", S, E, x);
	if (sum[n2] - sum[n1] < x) return INF;
	if (S == E) return S;
	if (sum[L[n2]] - sum[L[n1]] >= x) return getnxt(S, (S + E) / 2, L[n1], L[n2], x);
	else return getnxt((S + E) / 2 + 1, E, R[n1], R[n2], x - (sum[L[n2]] - sum[L[n1]]));
}

int in[300050];
int root[300050];
int main() {
	int N, Q, i, j;
	scanf("%d %d", &N, &Q);
	for (i = 1; i <= N; i++) {
		scanf("%d", &in[i]);
		root[i] = update(root[i - 1], 1, IT_MAX, in[i], 1);
	}
	while (Q--) {
		int L, R, K;
		scanf("%d %d %d", &L, &R, &K);
		K = (R - L + 1) / K + 1;

		int p = 1;
		while (p <= N) {
			int v = getsum(1, p-1, 1, IT_MAX, root[R]) - getsum(1, p-1, 1, IT_MAX, root[L - 1]) + K;
			int tp = getnxt(1, IT_MAX, root[L - 1], root[R], v);

//			printf("p, v, tp = %d %d %d\n", p, v, tp);
			if (p == tp) break;
			p = tp;
		}
		if (p >= N + 1) p = -1;
		printf("%d\n", p);
	}
	return 0;
}