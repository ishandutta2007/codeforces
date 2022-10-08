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

int IT_MAX = 1 << 17;
const ll MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db EPS = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

char in[5050];
bool dp1[5050][5050];
int dp2[5050][5050];
int cnt[5050];
int main() {
	scanf("%s", in + 1);
	int N = strlen(in + 1), i, j;
	for (i = 1; i <= N + 1; i++) dp1[i][i] = dp1[i][i-1] = true;
	for (i = N; i >= 1; i--) {
		for (j = i + 1; j <= N; j++) {
			if (dp1[i + 1][j - 1] && in[i] == in[j]) dp1[i][j] = true;
		}
	}

	for (i = 1; i <= N; i++) dp2[i][i] = 1;
	for (i = N; i >= 1; i--) {
		for (j = i + 1; j <= N; j++) {
			if (!dp1[i][j]) continue;
			int l = j - i + 1;
			dp2[i][j] = min(dp2[i][i + l / 2 - 1], dp2[j - l / 2 + 1][j]) + 1;
		}
	}

	for (i = 1; i <= N; i++) for (j = i; j <= N; j++) cnt[dp2[i][j]]++;
	for (i = N - 1; i >= 1; i--) cnt[i] += cnt[i + 1];
	for (i = 1; i <= N; i++) printf("%d ", cnt[i]);
	return !printf("\n");
}