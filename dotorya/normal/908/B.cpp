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

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

pii P[4] = { pii(-1, 0), pii(0, -1), pii(0, 1), pii(1, 0) };

char in[55][55];
char in2[100050];
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) scanf("%s", in[i]);
	scanf("%s", in2);

	int sx, sy, ex, ey;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (in[i][j] == 'S') sx = i, sy = j;
			if (in[i][j] == 'E') ex = i, ey = j;
		}
	}
	int ans = 0;
	sort(P, P + 4);
	do {
		bool chk = false;
		int x = sx, y = sy;
		for (i = 0; in2[i] != 0; i++) {
			int t = in2[i] - '0';
			x += P[t].first;
			y += P[t].second;
			if (x < 0 || x >= N || y < 0 || y >= M) break;
			if (in[x][y] == '#') break;
			if (in[x][y] == 'E') {
				chk = true;
				break;
			}
		}
		if (chk) ans++;
	} while (next_permutation(P, P + 4));
	return !printf("%d\n", ans);
}