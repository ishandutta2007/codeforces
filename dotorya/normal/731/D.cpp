#include <algorithm>
#include <assert.h>
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
//#include <unordered_set>
//#include <unordered_map>

#pragma warning(disable:4996)
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

int IT_MAX = 524288;
const int MOD = 100000000;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-12;

int sum[1000050];
void update(int a, int b) {
	sum[a]++;
	sum[b + 1]--;
}

vector <int> V[500050];
int main() {
	int N, L, i, j, t1, t2;
	scanf("%d %d", &N, &L);
	for (i = 1; i <= N; i++) {
		scanf("%d", &t1);
		while (t1--) {
			scanf("%d", &t2);
			V[i].push_back(t2-1);
		}
	}

	for (i = 1; i < N; i++) {
		t1 = min(V[i].size(), V[i + 1].size());

		for (j = 0; j < t1; j++) if (V[i][j] != V[i + 1][j]) break;
		if (j >= t1) {
			if (V[i].size() > V[i + 1].size()) return !printf("-1\n");
			continue;
		}

		t1 = V[i][j], t2 = V[i + 1][j];
		if (t1 < t2) update(L - t2, L - t1 - 1);
		else {
			update(0, L - t1 - 1);
			update(L - t2, L - 1);
		}
	}
	for (i = 1; i < L; i++) sum[i] += sum[i - 1];
	for (i = 0; i < L; i++) if (sum[i] == 0) return !printf("%d\n", i);
	return !printf("-1\n");
}