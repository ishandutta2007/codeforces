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

int IT_MAX = 1 << 12;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

int N;
int in[45][45];

int val[1100000];
bool chk1[25];
void aa1(int lvl, int s, int c) {
	if (lvl == N / 2) {
		val[s] = c;
		return;
	}
	aa1(lvl + 1, s, c);

	for (int i = 0; i < lvl; i++) if (chk1[i] && !in[i][lvl]) return;
	chk1[lvl] = true;
	aa1(lvl + 1, s | (1 << lvl), c + 1);
	chk1[lvl] = false;
}

int v2[25];
bool chk2[45];
int ans;
void aa2(int lvl, int c) {
	if (lvl == N) {
		int i, v = 0;
		for (i = 0; i < N / 2; i++) if (v2[i] == 0) v |= 1 << i;
		ans = max(ans, c + val[v]);
		return;
	}

	aa2(lvl + 1, c);
	for (int i = N / 2; i < lvl; i++) if (chk2[i] && !in[i][lvl]) return;
	chk2[lvl] = true;
	for (int i = 0; i < N / 2; i++) if (!in[lvl][i]) v2[i]--;
	aa2(lvl + 1, c + 1);
	chk2[lvl] = false;
	for (int i = 0; i < N / 2; i++) if (!in[lvl][i]) v2[i]++;
}
int main() {
	int K, i, j;
	scanf("%d %d", &N, &K);
	for (i = 0; i < N; i++) for (j = 0; j < N; j++) scanf("%d", &in[i][j]);
	if (N == 1) return !printf("0\n");

	aa1(0, 0, 0);
	int N1 = N / 2, N2 = N - N1;
	for (i = 1; i < (1 << N1); i++) {
		for (j = 0; j < N1; j++) if (i & (1 << j)) val[i] = max(val[i], val[i ^ (1 << j)]);
	}

	aa2(N / 2, 0);

//	printf("%d\n", ans);

	db A = 1.0 * (ans - 1) / (2 * ans) * K * K;
	return !printf("%.20lf\n", A);
}