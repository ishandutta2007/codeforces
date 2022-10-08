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
const ldb ERR = 1E-8;

set <int> Sx;
map <int, int> Mx;
bool chk[100050][2];
int main() {
	int N, i, t;
	scanf("%d", &N);
	scanf("%d", &t);
	Mx[t] = 1;
	Sx.insert(t);
	for (i = 2; i <= N; i++) {
		scanf("%d", &t);
		Mx[t] = i;

		auto it = Sx.lower_bound(t);
		if (it == Sx.end()) {
			it--;
			int r = *it;
			printf("%d ", r);
			chk[Mx[r]][1] = true;
		}
		else if (it == Sx.begin()) {
			int r = *it;
			printf("%d ", r);
			chk[Mx[r]][0] = true;
		}
		else if (!chk[Mx[*it]][0]) {
			printf("%d ", *it);
			chk[Mx[*it]][0] = true;
		}
		else {
			it--;
			int r = *it;
			printf("%d ", r);
			chk[Mx[r]][1] = true;
		}
		Sx.insert(t);
	}
	return !printf("\n");
}