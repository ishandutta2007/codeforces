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
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

#define gc getchar
#define pc putchar

int getint() {
	unsigned int c;
	int x = 0;
	while (((c = gc()) - '0') >= 10) {
		if (c == '-') return -getint();
		if (!~c) exit(0);
	}
	do {
		x = (x << 3) + (x << 1) + (c - '0');
	} while (((c = gc()) - '0') < 10);
	return x;
}

void putint(int n) {
	int i = 32, a[128];
	if (n < 0) pc('-');
	do {
		a[--i] = 48 + abs(n % 10);
		n /= 10;
	} while (n);
	while (i < 32) pc(a[i++]);
}

#define N 1000100

int n, q, a, b[N];

int calc(int m) {
	return (m + n - 1) % n + 1;
}

int main() {
	//	freopen("b.in", "r", stdin);
	scanf("%d %d", &n, &q);
	int sum = 0, k = 0;
	while (q--) {
		a = getint();
		if (a == 1) a = getint(), sum = (sum + a + n) % n;
		else {
			if ((sum + k) & 1) k--;
			else k++;
			k = (k + n) % n;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (i & 1) b[calc(i + sum + k)] = i;
		else b[calc(i + sum - k)] = i;
	}
	for (int i = 1; i <= n; i++) {
		putint(b[i]);
		if (i < n) printf(" ");
		else puts("");
	}
	return 0;
}