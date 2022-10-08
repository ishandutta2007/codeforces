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
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-9;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int gcd(int a, int b) {
	return (a == 0) ? b : gcd(b%a, a);
}

int in[2050];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);

	int g = 0;
	for (i = 1; i <= N; i++) g = gcd(g, in[i]);
	if (g != 1) return !printf("-1\n");

	int c = 0;
	for (i = 1; i <= N; i++) if (in[i] == 1) c++;
	if (c) return !printf("%d\n", N - c);

	int mn = INF;
	for (i = 1; i <= N; i++) {
		int g = in[i];
		for (j = i - 1; j >= 1; j--) {
			g = gcd(g, in[j]);
			if (g == 1) break;
		}
		if (j >= 1) mn = min(mn, i - j);

		g = in[i];
		for (j = i + 1; j <= N; j++) {
			g = gcd(g, in[j]);
			if (g == 1) break;
		}
		if (j <= N) mn = min(mn, j - i);
	}
	return !printf("%d\n", mn + N - 1);
}