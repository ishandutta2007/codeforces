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
const ll MOD = 1000000009;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-10;

int in[100050];
unordered_map <int, int> Mc;

int main() {
	int N, i, j, k, l, cnt0 = 0;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &in[i]);
		if (in[i] == 0) cnt0++;
		Mc[in[i]]++;
	}

	int ans = cnt0;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (i == j) continue;
			if (in[i] == 0 && in[j] == 0) continue;
			
			int t1 = in[i], t2 = in[j];
			Mc[t1]--, Mc[t2]--;
			for (k = 2;; k++) {
				if (Mc.count(t1 + t2) == 0 || Mc[t1 + t2] == 0) break;
				Mc[t1 + t2]--;
				t2 = t1 + t2;
				t1 = t2 - t1;
			}
			ans = max(ans, k);
			if (k == 11) {
				i = i;
			}

			t1 = in[i], t2 = in[j];
			Mc[t1]++, Mc[t2]++;
			for (l = 2; l < k; l++) {
				if (Mc.count(t1 + t2) == 0) break;
				Mc[t1 + t2]++;
				t2 = t1 + t2;
				t1 = t2 - t1;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}