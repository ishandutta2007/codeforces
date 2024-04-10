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
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

vector <int> in[100050];
vector <int> ans[100050];

int ch[10];

bool chk1[10][10];
bool chk2[10][10];
int u[100050];
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) for(j = 0; j < M; j++) in[i].push_back(i*M + j + 1);
	for (i = 0; i < N; i++) ans[i].resize(M);

	if (N >= 4) {
		printf("YES\n");
		int p = 0;

		for (i = 1; i < N; i += 2) {
			for (j = 0; j < M; j++) ans[p][j] = in[i][j];
			p++;
		}
		for (i = 0; i < N; i += 2) {
			for (j = 0; j < M; j++) ans[p][j] = in[i][j];
			p++;
		}

		if (N % 2 == 0) {
			for (i = 1; i < M; i += 2) {
				for (j = 0; j < N - 1 - j; j++) swap(ans[j][i], ans[N - 1 - j][i]);
			}
		}
		else {
			for (i = 1; i < M; i += 2) {
				for (j = 0; j < N; j++) u[j] = ans[j][i];
				for (j = 0; j < N; j++) ans[j][i] = u[(j + N / 2) % N];
			}
		}
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) printf("%d ", ans[i][j]);
			printf("\n");
		}
		return 0;
	}
	if (M >= 4) {
		printf("YES\n");

		int p = 0;
		for (i = 1; i < M; i += 2) {
			for (j = 0; j < N; j++) ans[j][p] = in[j][i];
			p++;
		}
		for (i = 0; i < M; i += 2) {
			for (j = 0; j < N; j++) ans[j][p] = in[j][i];
			p++;
		}
		
		if (M % 2 == 0) {
			for (i = 1; i < N; i += 2) {
				for (j = 0; j < M - 1 - j; j++) swap(ans[i][j], ans[i][M - 1 - j]);
			}
		}
		else {
			for (i = 1; i < N; i += 2) {
				for (j = 0; j < M; j++) u[j] = ans[i][j];
				for (j = 0; j < M; j++) ans[i][j] = u[(j + M / 2) % M];
			}
		}

		for (i = 0; i < N; i++) {
			for (auto it : ans[i]) printf("%d ", it);
			printf("\n");
		}
		return 0;
	}

	for (i = 1; i <= N*M; i++) ch[i] = i;
	do {
		for (i = 0; i < N; i++) for (j = 0; j < M; j++) ans[i][j] = ch[in[i][j]];

		for (i = 1; i <= N*M; i++) for (j = 1; j <= N*M; j++) chk1[i][j] = chk2[i][j] = false;
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				for (int k = 0; k < 2; k++) {
					int x = i + "12"[k] - '1';
					int y = j + "21"[k] - '1';
					if (x >= N || y >= M) continue;
					chk1[in[i][j]][in[x][y]] = true;
					chk1[in[x][y]][in[i][j]] = true;
					chk2[ans[i][j]][ans[x][y]] = true;
					chk2[ans[i][j]][ans[x][y]] = true;
				}
			}
		}
		for (i = 1; i <= N*M; i++) {
			for (j = 1; j <= N*M; j++) if (chk1[i][j] && chk2[i][j]) break;
			if (j <= N*M) break;
		}
		if (i > N*M) {
			printf("YES\n");
			for (i = 0; i < N; i++) {
				for (j = 0; j < M; j++) printf("%d ", ans[i][j]);
				printf("\n");
			}
			return 0;
		}
	} while (next_permutation(ch + 1, ch + N*M + 1));
	return !printf("NO\n");
}