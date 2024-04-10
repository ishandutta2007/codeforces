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
const ll MOD = 5000000;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-11;

pii in[200050];
pii in2[200050];
int ans[200050];
int oin[200050];

vector <int> Ve;
bool chk[200050];
int main() {
	int N, M, i, c = 0;
	scanf("%d %d", &N, &M);

	for (i = 1; i <= N; i++) {
		scanf("%d", &in[i].first);
		in[i].second = i;
		ans[i] = in[i].first;
		oin[i] = in[i].first;
	}
	sort(in + 1, in + N + 1);

	int dif = 0;
	int N2 = 0;
	for (i = 1; i <= N; i++) {
		if (i == 1 || in[i].first != in[i - 1].first) {
			in2[++N2] = in[i];
			if (in[i].first % 2 == 1) dif++;
			else dif--;
			if (in[i].first <= M) chk[in[i].first] = true;
		}
		else Ve.push_back(in[i].second);
	}

	int o = 1, e = 2;
	for (auto it : Ve) {
		if (dif > 0) {
			while (chk[e] && e <= M) e += 2;
			if (e > M) return !printf("-1\n");
			ans[it] = e;
			e += 2;
			dif--;
		}
		else {
			while (chk[o] && o <= M) o += 2;
			if (o > M) return !printf("-1\n");
			ans[it] = o;
			o += 2;
			dif++;
		}
	}

	for (i = 1; i <= N && dif; i++) {
		if (dif > 0) {
			if (ans[i] % 2 == 0) continue;
			while (chk[e] && e <= M) e += 2;
			if (e > M) return !printf("-1\n");
			ans[i] = e;
			e += 2;
			dif -= 2;
		}
		else {
			if (ans[i] % 2 == 1) continue;
			while (chk[o] && o <= M) o += 2;
			if (o > M) return !printf("-1\n");
			ans[i] = o;
			o += 2;
			dif += 2;
		}
	}
	if (dif) return !printf("-1\n");

	int cnt = 0;
	for (i = 1; i <= N; i++) if (oin[i] != ans[i]) cnt++;
	printf("%d\n", cnt);
	for (i = 1; i <= N; i++) printf("%d ", ans[i]);
	return !printf("\n");
}