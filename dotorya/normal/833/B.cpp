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
#pragma comment(linker, "/STACK:1048576")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple <int, int, int> t3;

int IT_MAX = 1 << 16;
const ll MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db EPS = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

class Node {
public:
	int mx, v;
	Node() {
		mx = v = 0;
	}
};

Node indt[150000];
void propagate(int n) {
	int v = indt[n].v;
	indt[2 * n].mx += v;
	indt[2 * n].v += v;
	indt[2 * n + 1].mx += v;
	indt[2 * n + 1].v += v;
	indt[n].v = 0;
}
void update(int st, int en, int S, int E, int n, int v) {
	if (st > en) return;
	if (st == S && en == E) {
		indt[n].mx += v;
		indt[n].v += v;
		return;
	}
	propagate(n);

	int M = (S + E) / 2;
	update(st, min(M, en), S, M, 2 * n, v);
	update(max(M + 1, st), en, M + 1, E, 2 * n + 1, v);
	indt[n].mx = max(indt[2 * n].mx, indt[2 * n + 1].mx);
}

int in[40050];
int pos[40050];
int prv[40050];
int dp[55][40050];
int main() {
	int N, K, i, j;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);
	for (i = 1; i <= N; i++) {
		prv[i] = pos[in[i]];
		pos[in[i]] = i;
	}

	for (i = 1; i <= N; i++) {
		dp[1][i] = dp[1][i - 1];
		if (!prv[i]) dp[1][i]++;
	}
	for (i = 2; i <= K; i++) {
		memset(indt, 0, sizeof(indt));
		update(i-1, i-1, 0, IT_MAX - 1, 1, i);
		dp[i][i] = i;
		for (j = i + 1; j <= N; j++) {
			update(prv[j], j - 2, 0, IT_MAX - 1, 1, 1);
			update(j-1, j-1, 0, IT_MAX - 1, 1, dp[i - 1][j - 1] + 1);
			dp[i][j] = indt[1].mx;
		}
	}
	return !printf("%d\n", dp[K][N]);
}