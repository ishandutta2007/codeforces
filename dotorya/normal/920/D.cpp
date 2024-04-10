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
ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

bool dp[5050][5050];
bool prv[5050][5050];
int in[5050];
int main() {
	int N, K, V, i, j;
	scanf("%d %d %d", &N, &K, &V);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);

	int s = 0;
	for (i = 1; i <= N; i++) s += in[i];
	if (s < V) return !printf("NO\n");

	dp[0][0] = true;
	for (i = 1; i <= N; i++) {
		int x = in[i] % K;
		for (j = 0; j < K; j++) {
			if (!dp[i - 1][j]) continue;
			dp[i][j] = true;
			prv[i][j] = false;

			dp[i][(j + x) % K] = true;
			prv[i][(j + x) % K] = true;
		}
	}

	if (!dp[N][V%K]) return !printf("NO\n");

	vector <int> Vl[2];
	int v = V%K;
	for (i = N; i >= 1; i--) {
		int x = in[i] % K;
		if (prv[i][v]) {
			Vl[1].push_back(i);
			v = (v - x + K) % K;
		}
		else Vl[0].push_back(i);
	}
	sort(all(Vl[0]));
	sort(all(Vl[1]));

	printf("YES\n");
	if (!Vl[0].empty()) {
		for (i = 1; i < Vl[0].size(); i++) printf("%d %d %d\n", 100000, Vl[0][i], Vl[0][0]);
	}
	if (!Vl[1].empty()) {
		for (i = 1; i < Vl[1].size(); i++) printf("%d %d %d\n", 100000, Vl[1][i], Vl[1][0]);
	}

	s = 0;
	for (auto it : Vl[1]) s += in[it];

	int p0, p1;
	if (Vl[0].empty()) p0 = Vl[1][1], p1 = Vl[1][0];
	else if (Vl[1].empty()) p0 = Vl[0][0], p1 = Vl[0][1];
	else p0 = Vl[0][0], p1 = Vl[1][0];

	if (s > V) printf("%d %d %d\n", (s - V) / K, p1, p0);
	if (s < V) printf("%d %d %d\n", (V - s) / K, p0, p1);
	return 0;
}
//*/