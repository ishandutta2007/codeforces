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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-12;

string in[105];
char u[30];
int main() {
	int N, i, j, k, l;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%s", u);
		in[i] = string(u);
	}

	while (N >= 1) {
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				if (i == j) continue;
				for (k = 0; k < in[i].size(); k++) if (in[i][k] == in[j][0]) break;
				if (k < in[i].size()) break;
			}
			if (j <= N) break;
		}
		if (i > N) break;

		for (l = 0; l < in[i].size(); l++) u[l] = in[i][l];
		for (l = in[i].size(); l < in[j].size() + k; l++) u[l] = in[j][l-k];
		u[l] = 0;
		string tmp = string(u);

		if (i > j) swap(i, j);
		in[i] = tmp;
		for (l = j; l <= N; l++) in[l] = in[l + 1];
		N--;
	}

	for (i = 1; i <= N; i++) printf("%s", in[i].c_str());
	printf("\n");
	return 0;
}