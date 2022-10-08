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

int in[5050][1050];
char u[1050];

int v[5000];
map <string, int> Mx;

int ans[2][5000];
int main() {
	int N, M, i, j, k;
	scanf("%d %d", &N, &M);
	Mx[string("?")] = 0;
	for (i = 1; i <= N; i++) {
		scanf("%s", u);
		Mx[string(u)] = i;
		scanf("%s", u);
		scanf("%s", u);
		if (u[0] == '0' || u[0] == '1') {
			for (j = 0; j < M; j++) in[i][j] = u[j] - '0';
			in[i][1000] = 0;
			continue;
		}
		in[i][0] = Mx[string(u)];
		scanf("%s", u);
		if (u[0] == 'A') in[i][1000] = 1;
		else if (u[0] == 'O') in[i][1000] = 2;
		else in[i][1000] = 3;
		scanf("%s", u);
		in[i][1] = Mx[string(u)];
	}

	for (i = 0; i < M; i++) {
		int sum[2] = { 0,0 };
		for (j = 0; j < 2; j++) {
			v[0] = j;
			for (k = 1; k <= N; k++) {
				if (in[k][1000] == 0) v[k] = in[k][i];
				if (in[k][1000] == 1) v[k] = v[in[k][0]] & v[in[k][1]];
				if (in[k][1000] == 2) v[k] = v[in[k][0]] | v[in[k][1]];
				if (in[k][1000] == 3) v[k] = v[in[k][0]] ^ v[in[k][1]];
				sum[j] += v[k];
			}
		}
		if (sum[0] < sum[1]) ans[0][i] = 0, ans[1][i] = 1;
		else if (sum[0] == sum[1]) ans[0][i] = ans[1][i] = 0;
		else ans[0][i] = 1, ans[1][i] = 0;
	}

	for (i = 0; i < M; i++) printf("%d", ans[0][i]);
	printf("\n");
	for (i = 0; i < M; i++) printf("%d", ans[1][i]);
	return !printf("\n");
}