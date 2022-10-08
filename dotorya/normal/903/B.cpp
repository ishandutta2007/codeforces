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

int IT_MAX = 1 << 20;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-9;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int main() {
	int H1, A1, C1, H2, A2, i;
	scanf("%d %d %d %d %d", &H1, &A1, &C1, &H2, &A2);

	int ans = INF;
	for (i = 0; i <= 10000; i++) {
		int h = H1 + i*(C1 - A2);
		ll tur = (h + A2 - 1) / A2;
		if (tur * A1 >= H2) {
			ans = min(ans, (H2 + A1 - 1) / A1 + i);
			printf("%d\n", ans);
			for (int j = 1; j <= i; j++) printf("HEAL\n");
			for (int j = 1; j <= (H2 + A1 - 1) / A1; j++) printf("STRIKE\n");
			return 0;
		}
	}
	return !printf("%d\n", ans);
}