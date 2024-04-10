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

char u[1050];
char A[1050];
int B[1050][1050];
int S[1050][1050];
int dp[1050][1050];
int rch[1050];
int val[10];
int u2[1050];
int main() {
	scanf("%s", A);
	int La = strlen(A);
	reverse(A, A + La);
	int N, i, j, k, l;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%s", u);
		int L = (int)strlen(u);
		for (j = 0; j < L; j++) B[i][j] = u[L - 1 - j] - '0';
	}
	for (i = 0; i < 10; i++) scanf("%d", &val[i]);

	for (i = 1; i <= N; i++) u2[i] = i;
	for (i = 1; i <= N; i++) S[0][i] = i;
	for (i = 1; i <= 1000; i++) {
		for (j = 1; j <= N; j++) rch[S[i - 1][j]] = N+1-j;
		sort(u2 + 1, u2 + N + 1, [&](int a, int b) {
			if (B[a][i-1] != B[b][i-1]) return B[a][i-1] < B[b][i-1];
			else return rch[a] < rch[b];
		});
		for (j = 1; j <= N; j++) S[i][j] = u2[N+1-j];
	}

	for (i = 0; i <= 1000; i++) for (j = 0; j <= N; j++) dp[i][j] = -INF;
	dp[0][0] = 0;
	for (i = 0; i < La; i++) {
		int uc = 0;
		int c[10] = { 0, };
		for (j = 1; j <= N; j++) c[B[j][i]]++;
		for (j = 0; j <= N; j++) {
			if (j != 0) {
				int t = S[i][j];
				t = B[t][i];
				c[t]--;
				if (t == 9) uc++;
				c[(t + 1) % 10]++;
			}
			if (dp[i][j] == -INF) continue;

			for (k = 0; k < 10; k++) {
				if (i + 1 == La && k == 0) continue;
				if (A[i] != '?' && A[i] != k + '0') continue;
				int uc2 = uc;
				int v = dp[i][j];
				for (l = 0; l < 10; l++) {
					if (k + l >= 10) uc2 += c[l];
					v += val[(k + l) % 10] * c[l];
				}
				dp[i + 1][uc2] = max(dp[i + 1][uc2], v);
			}
		}
	}

	int ans = -INF;
	int sum = 0;
	for (i = 1; i <= N; i++) {
		for (j = 1000; j >= La; j--) if (B[i][j] != 0) break;
		for (; j >= La; j--) sum += val[B[i][j]];
	}
	for (i = 0; i <= N; i++) {
		if (i != 0) {
			int t = S[La][i];
			for (j = 1000; j >= La; j--) if (B[t][j] != 0) break;
			for (; j >= La; j--) sum -= val[B[t][j]];

			B[t][La]++;
			for (j = La; j <= 1000; j++) {
				if (B[t][j] >= 10) {
					B[t][j] -= 10;
					B[t][j + 1]++;
				}
			}
			for (j = 1000; j >= La; j--) if (B[t][j] != 0) break;
			for (; j >= La; j--) sum += val[B[t][j]];
		}
		ans = max(ans, sum + dp[La][i]);
	}
	return !printf("%d\n", ans);
}