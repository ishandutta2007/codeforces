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

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple <int, int, int> t3;

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

int minv[5] = { 0,1,3,2,4 };
int A[505][505];
int piv[505];

int qu[505];
int ans[505];
char u[505];
int main() {
	int N, M, Q, i, j, k, l, p;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		scanf("%s", u + 1);
		for (j = 1; j <= M; j++) A[i][j] = u[j] - 'a';
	}

	for (i = 1, j = 1; i <= N && j <= M; j++) {
		for (p = i; p <= N; p++) if (A[p][j]) break;
		if (p > N) continue;
		for (k = j; k <= M; k++) swap(A[i][k], A[p][k]);
		piv[i] = j;
		for (k = i + 1; k <= N; k++) {
			int t = A[k][j] * minv[A[i][j]] % 5;
			for (l = j; l <= M; l++) A[k][l] = (A[k][l] + (5 - t) * A[i][l]) % 5;
		}
		i++;
	}
	int pc = i - 1;

	scanf("%d", &Q);
	while (Q--) {
		scanf("%s", u + 1);
		for (j = 1; j <= M; j++) qu[j] = u[j] - 'a';
		
		for (i = 1; i <= M; i++) ans[i] = 0;
		for (i = 1; i <= pc; i++) {
			int x = piv[i];
			int t = (qu[x] - ans[x] + 5) * minv[A[i][x]] % 5;
			for (j = 1; j <= M; j++) ans[j] = (ans[j] + A[i][j] * t) % 5;
		}
		for (i = 1; i <= M; i++) if (ans[i] != qu[i]) break;
		
		ll ans = 1;
		if (i <= M) ans = 0;
		for (i = 1; i <= N - pc; i++) ans = (ans * 5) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}