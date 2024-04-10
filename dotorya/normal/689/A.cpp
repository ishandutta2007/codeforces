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

int IT_MAX = 1 << 17;
const ll MOD = 97654321;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-13;

int pos[10][2] = { {3,1}, {0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2} };
char in[1050];
int main() {
	int N, i, j, k;
	scanf("%d", &N);
	scanf("%s", in);
	int c = 0;
	for (i = 0; i <= 9; i++) {
		int x = pos[i][0], y = pos[i][1];
		for (j = 1; in[j] != 0; j++) {
			x += pos[in[j] - '0'][0] - pos[in[j - 1] - '0'][0];
			y += pos[in[j] - '0'][1] - pos[in[j - 1] - '0'][1];
			for (k = 0; k <= 9; k++) if (x == pos[k][0] && y == pos[k][1]) break;
			if (k > 9) break;
		}
		if (in[j] == 0) c++;
	}
	if (c == 1) printf("YES\n");
	else printf("NO\n");
	return 0;
}