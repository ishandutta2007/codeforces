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
const ll MOD = 1000000009;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

multiset <int> S;
int main() {
	int N, i, t;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &t);
		S.insert(t);
	}

	int ans = 0;
	while (!S.empty()) {
		int t = *(S.begin());
		S.erase(S.begin());
		while (1) {
			auto it = S.lower_bound(t + 1);
			if (it == S.end()) break;
			ans++;
			t = *it;
			S.erase(it);
		}
	}
	printf("%d\n", ans);
	return 0;
}