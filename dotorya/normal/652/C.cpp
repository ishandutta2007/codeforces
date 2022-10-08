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

int ch[300050];
int mx[300050];
pii in[300050];
int main() {
	int N, M, i, j, t;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		scanf("%d", &t);
		ch[t] = i;
	}

	for (i = 1; i <= M; i++) {
		scanf("%d %d", &in[i].first, &in[i].second);
		in[i].first = ch[in[i].first];
		in[i].second = ch[in[i].second];
		if (in[i].first > in[i].second) swap(in[i].first, in[i].second);
	}
	sort(in + 1, in + M + 1);

	ll ans = 0;
	mx[N + 1] = N + 1;
	j = M;
	for (i = N; i >= 1; i--) {
		mx[i] = mx[i + 1];
		while (j) {
			if (in[j].first != i) break;
			mx[i] = min(mx[i], in[j--].second);
		}
		ans += mx[i] - i;
	}
	printf("%lld\n", ans);
	return 0;
}
//*/