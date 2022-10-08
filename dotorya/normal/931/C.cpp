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

int IT_MAX = 1 << 20;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
//#define Se second
#define Fi first

int in[100050];
int cnt[3];
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);
	sort(in + 1, in + N + 1);

	if (in[N] - in[1] <= 1) {
		printf("%d\n", N);
		for (i = 1; i <= N; i++) printf("%d ", in[i]);
		return !printf("\n");
	}

	int s = 0;
	for (i = 1; i <= N; i++) {
		s += in[i] - in[1];
		cnt[in[i] - in[1]]++;
	}

	int mn = INF, a1 = -1, a2 = -1, a3 = -1;
	for (i = 0; i <= N; i++) {
		int y = s - N + i, x = s - 2 * y;
		if (x < 0 || y < 0) continue;

		int v = min(cnt[0], i) + min(cnt[1], x) + min(cnt[2], y);
		if (mn > v) {
			mn = v;
			a1 = i;
			a2 = x;
			a3 = y;
		}
	}
	printf("%d\n", mn);
	for (i = 1; i <= a1; i++) printf("%d ", in[1]);
	for (i = 1; i <= a2; i++) printf("%d ", in[1] + 1);
	for (i = 1; i <= a3; i++) printf("%d ", in[1] + 2);
	return !printf("\n");
}