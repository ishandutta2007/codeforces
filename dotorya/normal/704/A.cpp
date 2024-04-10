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

int IT_MAX = 1 << 21;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-12;

set <int> Sx;
vector <int> V[300050];

int main() {
	int N, Q, i, t1, t2, c = 0;
	scanf("%d %d", &N, &Q);
	while (Q--) {
		scanf("%d %d", &t1, &t2);
		if (t1 == 1) {
			c++;
			Sx.insert(c);
			V[t2].push_back(c);
		}
		if (t1 == 2) {
			for (auto it : V[t2]) Sx.erase(it);
			V[t2].clear();
		}
		if (t1 == 3) {
			while (!Sx.empty()) {
				auto it = Sx.begin();
				if (*it > t2) break;
				Sx.erase(it);
			}
		}
		printf("%d\n", Sx.size());
	}
	return 0;
}