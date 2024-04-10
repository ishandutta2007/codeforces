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

int IT_MAX = 1 << 18;
const ll MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db EPS = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

bool isValid(int a, int b, int c, int d) {
	if (a <= c && b <= d) return true;
	swap(a, b);
	return a <= c && b <= d;
}

int in[105][2];
int main() {
	int N, A, B, i, j, k;
	scanf("%d %d %d", &N, &A, &B);
	for (i = 1; i <= N; i++) scanf("%d %d", &in[i][0], &in[i][1]);

	int ans = 0;
	for (i = 1; i <= N; i++) {
		for (j = i + 1; j <= N; j++) {
			for (k = 1; k < A; k++) if (isValid(in[i][0], in[i][1], k, B) && isValid(in[j][0], in[j][1], A - k, B)) break;
			if (k < A) ans = max(ans, in[i][0] * in[i][1] + in[j][0] * in[j][1]);
			for (k = 1; k < B; k++) if (isValid(in[i][0], in[i][1], A, k) && isValid(in[j][0], in[j][1], A, B - k)) break;
			if (k < B) ans = max(ans, in[i][0] * in[i][1] + in[j][0] * in[j][1]);
		}
	}
	return !printf("%d\n", ans);
}