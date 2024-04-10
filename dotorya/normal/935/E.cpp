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
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

char in[10050];

int son[10050][2];
int N1, N2;
int opm = 0;

int nc = 1;
int pos = 0;
void getNode(int n, int &pos) {
	if (in[pos] >= '1' && in[pos] <= '9') {
		son[n][0] = son[n][1] = -(in[pos] - '0');
		pos++;
		return;
	}

	son[n][0] = ++nc;
	son[n][1] = ++nc;
	pos++;
	getNode(son[n][0], pos);
	pos++;
	getNode(son[n][1], pos);
	pos++;
}

int dp[10050][105][2];
void DFS(int n) {
	if (son[n][0] < 0) {
		dp[n][0][0] = dp[n][0][1] = -son[n][0];
		return;
	}

	DFS(son[n][0]);
	DFS(son[n][1]);

	int n0 = son[n][0], n1 = son[n][1];
	for (int i = 0; i <= N1; i++) {
		for (int j = 0; i + j <= N1; j++) {
			for (int k = 0; k < 2; k++) {
				for (int l = 0; l < 2; l++) {
					if (abs(dp[n0][i][k]) == INF || abs(dp[n1][j][l]) == INF) continue;
					
					int v;
					if (opm == 0) v = dp[n0][i][k] - dp[n1][j][l];
					else v = dp[n0][i][k] + dp[n1][j][l];

					dp[n][i + j][0] = min(dp[n][i + j][0], v);
					dp[n][i + j][1] = max(dp[n][i + j][1], v);
				}
			}
		}
	}

	for (int i = 0; i < N1; i++) {
		for (int j = 0; i + j < N1; j++) {
			for (int k = 0; k < 2; k++) {
				for (int l = 0; l < 2; l++) {
					if (abs(dp[n0][i][k]) == INF || abs(dp[n1][j][l]) == INF) continue;

					int v;
					if (opm == 1) v = dp[n0][i][k] - dp[n1][j][l];
					else v = dp[n0][i][k] + dp[n1][j][l];

					dp[n][i + j + 1][0] = min(dp[n][i + j + 1][0], v);
					dp[n][i + j + 1][1] = max(dp[n][i + j + 1][1], v);
				}
			}
		}
	}
}
int main() {
	scanf("%s %d %d", in, &N1, &N2);
	if (N1 > N2) {
		opm = 1;
		swap(N1, N2);
	}

	getNode(1, pos);
	for (int i = 1; i <= nc; i++) for (int j = 0; j <= N1; j++) dp[i][j][0] = INF, dp[i][j][1] = -INF;
	DFS(1);

	return !printf("%d\n", dp[1][N1][1]);
}