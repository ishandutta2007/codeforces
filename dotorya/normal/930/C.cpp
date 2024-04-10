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
#define Se second
#define Fi first

int indt[300000];
void update(int p, int v) {
	p += IT_MAX;
	for (; p; p /= 2) indt[p] = max(indt[p], v);
}
int getmx(int p1, int p2) {
	p1 += IT_MAX;
	p2 += IT_MAX;
	int rv = 0;
	for (; p1 <= p2; p1 /= 2, p2 /= 2) {
		if (p1 % 2 == 1) rv = max(rv, indt[p1++]);
		if (p2 % 2 == 0) rv = max(rv, indt[p2--]);
	}
	return rv;
}

int del[100050];
int cnt[100050];

int dp1[100050];
int dp2[100050];
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	while (N--) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		del[t1]++;
		del[t2+1]--;
	}

	for (i = 1; i <= M; i++) del[i] = del[i - 1] + del[i];

	for (i = 1; i <= M; i++) {
		dp1[i] = getmx(0, del[i]) + 1;
		update(del[i], dp1[i]);
	}
	memset(indt, 0, sizeof(indt));
	for (i = M; i >= 1; i--) {
		dp2[i] = getmx(0, del[i]) + 1;
		update(del[i], dp2[i]);
	}

	int ans = 0;
	for (i = 1; i <= M; i++) ans = max(ans, dp1[i] + dp2[i] - 1);
	return !printf("%d\n", ans);
}