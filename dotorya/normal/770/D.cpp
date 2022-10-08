#include <stdio.h>
#include <algorithm>
#include <assert.h>
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
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
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
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

char in[105];
int dep[105];
char ans[305][305];
int main() {
	int N, i, j;
	scanf("%d", &N);
	scanf("%s", in);

	int d = 0;
	for (i = 0; i < N; i++) {
		if (in[i] == ']') d--;
		dep[i] = d;
		if (in[i] == '[') d++;
	}
	
	int mx = 0;
	for (i = 0; i < N; i++) mx = max(mx, dep[i]);

	for (i = 0; i <= 300; i++) for (j = 0; j <= 300; j++) ans[i][j] = ' ';
	int p = 0;
	for (i = 0; i < N; i++) {
		int st = dep[i], en = mx * 2 + 2 - dep[i];
		ans[st][p] = ans[en][p] = '+';
		for (j = st + 1; j < en; j++) ans[j][p] = '|';

		if (in[i] == '[') ans[st][p + 1] = ans[en][p + 1] = '-';
		else ans[st][p - 1] = ans[en][p - 1] = '-';

		if (i + 1 == N) break;
		if (in[i] == '[' && in[i + 1] == ']') p += 4;
		else p++;
	}
	
	for (i = 300; i >= 0; i--) if (ans[0][i] != ' ') break;
	int x = i;
	for (i = 0; i <= mx * 2 + 2; i++) {
		for (j = 0; j <= x; j++) printf("%c", ans[i][j]);
		printf("\n");
	}
	return 0;
}