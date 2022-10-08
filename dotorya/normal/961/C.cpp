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
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

char in[4][105][105];
char cur[205][205];

int u[4];
int main() {
	int N, i, j, k;
	scanf("%d", &N);
	for (i = 0; i < 4; i++) for (j = 0; j < N; j++) scanf("%s", in[i][j]);

	for (i = 0; i < 4; i++) u[i] = i;

	int ans = INF;
	do {
		for (i = 0; i < 4; i++) {
			for (j = 0; j < N; j++) for (k = 0; k < N; k++) cur[(i / 2)*N + j][(i % 2)*N + k] = in[u[i]][j][k];
		}
		
		int cnt = 0;
		for (i = 0; i < 2 * N; i++) {
			for (j = 0; j < 2 * N; j++) {
				char c = '0' + (i + j) % 2;
				if (c != cur[i][j]) cnt++;
			}
		}
		ans = min(ans, cnt);
	} while (next_permutation(u, u + 4));
	return !printf("%d\n", ans);
}