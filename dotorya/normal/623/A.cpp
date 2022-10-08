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
#include <time.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>

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

int IT_MAX = 131072;
const ll MOD = 1000;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-10;

bool chk[505][505];
bool bchk[505];
char ans[505];
vector <int> V;
int main() {
	int N, M, i, j, k, t1, t2;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++) {
		scanf("%d %d", &t1, &t2);
		chk[t1][t2] = true;
		chk[t2][t1] = true;
	}

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (i == j) continue;
			if (!chk[i][j]) break;
		}
		if (j > N) {
			bchk[i] = true;
			ans[i] = 'b';
		}
	}

	for (i = 1; i <= N; i++) if (!bchk[i]) break;
	if (i > N) {
		printf("Yes\n");
		for (i = 1; i <= N; i++) printf("b");
		printf("\n");
		return 0;
	}

	int tchk = 0;
	for (i = 1; i <= N; i++) {
		if (bchk[i]) continue;
		if (tchk == 2) return !printf("No\n");
		tchk++;
		V.clear();
		V.push_back(i);
		for (j = 0; j < V.size(); j++) {
			if (tchk == 1) ans[V[j]] = 'a';
			else ans[V[j]] = 'c';
			for (k = 1; k <= N; k++) {
				if (bchk[k] || !chk[V[j]][k]) continue;
				bchk[k] = true;
				
				V.push_back(k);
			}
		}
	}

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (i == j) continue;
			if (ans[i] == 'a' && ans[j] == 'c') {
				if (chk[i][j]) return !printf("No\n");
			}
			else if (ans[i] == 'c' && ans[j] == 'a') {
				if (chk[i][j]) return !printf("No\n");
			}
			else if (!chk[i][j]) return !printf("No\n");
		}
	}
	printf("Yes\n");
	for (i = 1; i <= N; i++) printf("%c", ans[i]);
	printf("\n");
	return 0;
}