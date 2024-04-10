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
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

map <int, int> Mx;

int B[200050];
int C[200050];
int main() {
	int N, M, i;
	auto ans = mp(pii(-1, -1), -1);

	scanf("%d", &N);
	while (N--) {
		scanf("%d", &i);
		Mx[i]++;
	}
	scanf("%d", &M);
	for (i = 1; i <= M; i++) scanf("%d", &B[i]);
	for (i = 1; i <= M; i++) scanf("%d", &C[i]);
	for (i = 1; i <= M; i++) {
		int t1, t2;
		t1 = Mx[B[i]], t2 = Mx[C[i]];
		ans = max(ans, mp(pii(t1, t2), i));
	}
	printf("%d\n", ans.second);
	return 0;
}