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

int gcd(int a, int b) {
	return (a == 0) ? b : gcd(b%a, a);
}
int main() {
	int N, K, i, t1, t2, t3;
	scanf("%d %d", &N, &K);

	t1 = K;
	for (i = 1; i <= N; i++) {
		scanf("%d", &t2);
		t2 /= gcd(K / t1, t2);
		t1 /= gcd(t1, t2);
	}
	if (t1 == 1) printf("Yes\n");
	else printf("No\n");
	return 0;
}