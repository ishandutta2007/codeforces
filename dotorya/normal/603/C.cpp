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

int IT_MAX = 1024;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-12;

int getgr(int x) {
	if (x == 0) return 0;
	if (x == 1 || x == 3) return 1;
	if (x == 2) return 0;

	if (x % 2 == 1) return 0;

	int t1 = getgr(x / 2), t2 = getgr(x - 1);
	if (t1 != 0 && t2 != 0) return 0;
	if (t1 != 1 && t2 != 1) return 1;
	return 2;
}
int main() {
	int N, K, GR = 0, t;
	scanf("%d %d", &N, &K);
	if (K % 2 == 0) {
		while (N--) {
			scanf("%d", &t);
			if (t == 1) GR ^= 1;
			else if (t == 2) GR ^= 2;
			else GR ^= (t + 1) % 2;
		}
	}
	else {
		while (N--) {
			scanf("%d", &t);
			GR ^= getgr(t);
		}
	}
	if (GR == 0) printf("Nicky\n");
	else printf("Kevin\n");
	return 0;
}