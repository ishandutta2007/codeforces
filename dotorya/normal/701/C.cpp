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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

map <char, int> Mx;
int ch(char c) {
	if (Mx.count(c)) return Mx[c];
	int t = Mx.size();
	Mx[c] = t;
	return t;
}

char u[100050];
int in[100050];

int ctot;
int cnt[100050];
int main() {
	int st = 0, en = 0, L, N, i;
	scanf("%d %s", &L, u);
	for (i = 0; i < L; i++) in[i] = ch(u[i]);
	N = Mx.size();

	int ans = INF;
	for (st = 0; st < L; st++) {
		while (en < L && ctot != N) {
			cnt[in[en]]++;
			if (cnt[in[en]] == 1) ctot++;
			en++;
		}
		if (ctot != N) break;
		ans = min(ans, en - st);

		cnt[in[st]]--;
		if (cnt[in[st]] == 0) ctot--;
	}
	return !printf("%d\n", ans);
}