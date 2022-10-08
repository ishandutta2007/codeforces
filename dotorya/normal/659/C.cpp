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
const ll MOD = 987654321;
const int INF = 1034567890;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

set <int> Sx;
vector <int> ans;
int main() {
	int N, M, i, t;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		scanf("%d", &t);
		Sx.insert(t);
	}

	int sum = 0;
	for (i = 1;; i++) {
		if (Sx.count(i)) continue;
		if (sum + i > M) break;
		ans.push_back(i);
		sum += i;
	}
	printf("%d\n", ans.size());
	for (auto it : ans) printf("%d ", it);
	printf("\n");
	return 0;
}
//*/