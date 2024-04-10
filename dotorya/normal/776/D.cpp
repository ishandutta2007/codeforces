#include <algorithm>
#include <assert.h>
#include <bitset>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <cmath>
#include <vector>
#include <deque>
//#include <unordered_set>
#include <unordered_map>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;

int IT_MAX = 1 << 20;
const ll MOD = 98765431;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-6;

vector <int> Vu[100050];
int R[100050];

int r[100050][2];
int root(int x) {
	if (r[x][0] == x) return x;
	int pr = r[x][0];
	int nr = root(r[x][0]);
	r[x][1] ^= r[pr][1];
	return r[x][0] = nr;
}

int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) scanf("%d", &R[i]);
	for (i = 1; i <= M; i++) {
		int t1, t2;
		scanf("%d", &t1);
		while (t1--) {
			scanf("%d", &t2);
			Vu[t2].push_back(i);
		}
	}

	for (i = 1; i <= M; i++) r[i][0] = i, r[i][1] = 0;
	for (i = 1; i <= N; i++) {
		int t1 = Vu[i][0], t2 = Vu[i][1], t3 = 1 - R[i];
		int r1 = root(t1), r2 = root(t2);
		t3 ^= r[t1][1];
		t3 ^= r[t2][1];

		if (r1 == r2) {
			if (t3) return !printf("NO\n");
			continue;
		}
		r[r1][0] = r2;
		r[r1][1] = t3;
	}
	return !printf("YES\n");
}