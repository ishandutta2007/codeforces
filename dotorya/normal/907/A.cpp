#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int main() {
	int V1, V2, V3, Vm, i, j, k;
	scanf("%d %d %d %d", &V1, &V2, &V3, &Vm);
	for (i = V1; i <= 2 * V1; i++) {
		for (j = V2; j <= 2 * V2; j++) {
			for (k = V3; k <= 2 * V3; k++) {
				if (i <= j || j <= k) continue;
				if (Vm > k) continue;
				if (2 * Vm < k) continue;
				if (j <= 2 * Vm) continue;
				return !printf("%d\n%d\n%d\n", i, j, k);
			}
		}
	}
	return !printf("-1\n");
}