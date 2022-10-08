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
#include <deque>
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

int IT_MAX = 1<<19;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-10;

pii mn[8];
int ch(char c) {
	if (c == 'B') return 1;
	if (c == 'R') return 2;
	return 3;
}
int main() {
	int N, i;
	int x0, y0, x, y;
	scanf("%d %d %d", &N, &x0, &y0);

	char c[2];
	for (i = 0; i < 8; i++) mn[i] = pii(2 * INF, -1);
	for (i = 0; i < N; i++) {
		scanf("%s %d %d", c, &x, &y);
		x -= x0, y -= y0;
		if (abs(x) == 0 || abs(y) == 0) {
			int t = 0;
			if (x == 0) {
				if (y > 0) t = 1;
				if (y < 0) t = 2;
			}
			else if (x < 0) t = 3;

			int d = max(abs(x), abs(y));
			mn[t] = min(mn[t], pii(d, ch(c[0])));
		}
		if (abs(x) == abs(y)) {
			int t = 4;
			if (x > 0) t += 2;
			if (y > 0) t += 1;

			int d = abs(x);
			mn[t] = min(mn[t], pii(d, ch(c[0])));
		}
	}

	for (i = 0; i < 4; i++) if (mn[i].second == 2 || mn[i].second == 3) return !printf("YES\n");
	for (i = 4; i < 8; i++) if (mn[i].second == 1 || mn[i].second == 3) return !printf("YES\n");
	return !printf("NO\n");
}