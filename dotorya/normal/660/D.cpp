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
const ll MOD = 20150523;
const int INF = 2034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-8;

int in[2050][2];

vector <pii> V;
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d %d", &in[i][0], &in[i][1]);

	for (i = 1; i <= N; i++) {
		for (j = 1; j < i; j++) {
			pii u = pii(in[i][0] - in[j][0], in[i][1] - in[j][1]);
			if (u.first < 0) {
				u.first *= -1;
				u.second *= -1;
			}
			if (u.first == 0 && u.second < 0) {
				u.first *= -1;
				u.second *= -1;
			}
			V.push_back(u);
		}
	}

	sort(V.begin(), V.end());

	ll ans = 0;
	int st = 0;
	for (i = 0; i < V.size(); i++) {
		if (i + 1 == V.size() || V[i + 1] != V[st]) {
			ans += (ll)(i + 1 - st) * (i + 1 - st - 1) / 2;
			st = i + 1;
		}
	}
	printf("%lld\n", ans/2);
	return 0;
}