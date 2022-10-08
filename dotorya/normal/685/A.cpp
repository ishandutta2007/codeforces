//*
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

int IT_MAX = 1024;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

int N, M;
int a, b;
int getval(int x) {
	if (x == 1) return 1;
	ll i = 0, t = 1;
	while (x > t) {
		t *= 7;
		i++;
	}
	return (int)i;
}

int val[15];
bool chk[15];
int ans = 0;
void aa(int lvl) {
	if (lvl == a + b) {
		ll v1 = 0, v2 = 0;
		for (int i = 0; i < a; i++) v1 = v1 * 7 + val[i];
		for (int i = a; i < a+b; i++) v2 = v2 * 7 + val[i];
		if (v1 < N && v2 < M) ans++;
		return;
	}
	for (int i = 0; i < 7; i++) {
		if (!chk[i]) {
			chk[i] = true;
			val[lvl] = i;
			aa(lvl + 1);
			chk[i] = false;
		}
	}	
}
int main() {
	
	scanf("%d %d", &N, &M);

	a = getval(N);
	b = getval(M);
	if (a + b > 7) return !printf("0\n");

	aa(0);
	return !printf("%d\n", ans);
}