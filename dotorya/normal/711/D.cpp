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
#include <vector>
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

int IT_MAX = 262144;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-11;

ll po2[200050];
int in[200050];
bool chk[200050];
vector <int> V;
int main() {
	int N, i, j;
	po2[0] = 1;
	for (i = 1; i <= 200000; i++) po2[i] = (po2[i - 1] * 2) % MOD;

	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);

	ll ans = 1;
	for (i = 1; i <= N; i++) {
		if (chk[i]) continue;
		V.push_back(i);
		chk[i] = true;
		int t = in[i];
		while (!chk[t]) {
			V.push_back(t);
			chk[t] = true;
			t = in[t];
		}
		for (j = V.size() - 1; j >= 0; j--) if (V[j] == t) break;
		if (j < 0) ans = (ans * po2[V.size()]) % MOD;
		else {
			ans = (ans * (po2[V.size() - j] + MOD - 2)) % MOD;
			ans = (ans * po2[j]) % MOD;
		}
		V.clear();
	}
	return !printf("%lld\n", ans);
}