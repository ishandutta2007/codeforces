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

typedef pair<ll, char> plc;

vector <plc> in1;
vector <plc> in2;
vector <plc> in3;
int pi[200050];

char u[10];
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		ll v = 0;
		char c;
		scanf("%s", u);
		for (j = 0; u[j] != '-'; j++) v = (10 * v + u[j] - '0');
		c = u[j + 1];

		if (in1.empty() || in1.back().second != c) in1.push_back(plc(v, c));
		else in1.back().first += v;
	}
	for (i = 1; i <= M; i++) {
		ll v = 0;
		char c;
		scanf("%s", u);
		for (j = 0; u[j] != '-'; j++) v = (10 * v + u[j] - '0');
		c = u[j + 1];

		if (in2.empty() || in2.back().second != c) in2.push_back(plc(v, c));
		else in2.back().first += v;
	}

	if (in2.size() == 1) {
		ll ans = 0;
		for (i = 0; i < in1.size(); i++) {
			if (in1[i].second != in2[0].second) continue;
			ans += max(0ll, in1[i].first - in2[0].first + 1);
		}
		return !printf("%lld\n", ans);
	}
	if (in2.size() == 2) {
		ll ans = 0;
		for (i = 0; i + 1 < in1.size(); i++) {
			if (in1[i].second != in2[0].second || in1[i + 1].second != in2[1].second) continue;
			if (in1[i].first < in2[0].first || in1[i + 1].first < in2[1].first) continue;
			ans++;
		}
		return !printf("%lld\n", ans);
	}

	for (i = 1; i + 1 < in2.size(); i++) in3.push_back(in2[i]);

	pi[0] = -1;
	for (i = 0, j = -1; i < in3.size();) {
		while (j != -1 && in3[i] != in3[j]) j = pi[j];
		pi[++i] = ++j;
	}
	
	ll ans = 0;
	for (i = 0, j = 0; i < in1.size();) {
		while (j != -1 && in1[i] != in3[j]) {
			j = pi[j];
		}
		i++, j++;
		if (j == in3.size()) {
			j = pi[j];
			if (i == in1.size()) continue;
			if (in1[i].second != in2.back().second || in1[i + 1 - in2.size()].second != in2[0].second) continue;
			if (in1[i].first < in2.back().first || in1[i + 1 - in2.size()].first < in2[0].first) continue;
			ans++;
		}
	}
	return !printf("%lld\n", ans);
}