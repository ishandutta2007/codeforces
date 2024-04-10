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

int IT_MAX = 1 << 19;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

char in[5050];
bool dp[5050];

bool dp2[14][5050];

int DEBUG = 0;
int main() {
	int N, i, j, k;
	if(!DEBUG) scanf("%s", in);
	else for (i = 0; i < 5000; i++) in[i] = 'a';
	N = strlen(in);
	int c = (int)(log2(N) + 1e-9);

	int M = N - ((1 << c) - 1);
	dp[0] = true;
	for (i = 0; i < M; i++) {
		for (j = 0; j <= c; j++) for (k = 0; k < (1 << c); k++) dp2[j][k] = false;
		for (j = 0; j < (1 << c); j++) dp2[0][j] = dp[j];
		for (j = 0; j < c; j++) {
			for (k = 0; k < (1<<c); k++) {
				dp2[j + 1][k] |= dp2[j][k];
				dp2[j + 1][k | (1 << j)] |= dp2[j][k];
			}
		}
		for (j = 0; j < (1 << c); j++) dp[j] = dp2[c][j];

		char mn = 'z' + 1;
		for (j = 0; j < (1 << c); j++) {
			int p = j + i;
			if (!dp[j] || p >= N) continue;
			mn = min(mn, in[p]);
		}
		for (j = 0; j < (1 << c); j++) {
			int p = j + i;
			if (!dp[j] || p >= N || in[p] != mn) dp[j] = false;
		}
		printf("%c", mn);
	}
	return !printf("\n");
}