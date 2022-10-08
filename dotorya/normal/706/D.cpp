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
const int MOD = 1000003;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-11;

multiset <int> Mx;
int main() {
	Mx.insert(0);

	int Q, t, i;
	char c[2];
	scanf("%d", &Q);
	while (Q--) {
		scanf("%s %d", c, &t);
		if (c[0] == '+') Mx.insert(t);
		else if (c[0] == '-') {
			auto it = Mx.lower_bound(t);
			Mx.erase(it);
		}
		else {
			int v = 0;
			for (i = 29; i >= 0; i--) {
				
				int chk = 1;
				if (t & (1 << i)) chk = 0;
				int st = v + (chk << i);

				auto it = Mx.lower_bound(st);
				if (it != Mx.end() && *it < st + (1 << i)) v += chk << i;
				else v += (1 - chk) << i;
			}
			printf("%d\n", t^v);
		}
	}
	return 0;
}