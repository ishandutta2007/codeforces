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
const ll MOD = 31991;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		ll N;
		scanf("%lld", &N);
		if (N <= 5) {
			printf("%lld\n", N - 1);
			continue;
		}

		ll st = 3, en = N, mi, rv = 2, ans = 0;
		while (st <= en) {
			mi = (st + en) / 2;
			ans = max(ans, (N - mi) + min(mi*(mi - 1) / 2, N - mi));
			if (mi*(mi - 1) / 2 <= N - mi) {
				rv = mi;
				st = mi + 1;
			}
			else en = mi - 1;
		}
		for (ll i = rv - 5; i <= rv + 5; i++) {
			if (i < 3 || i > N) continue;
			ans = max(ans, (N - i) + min(i*(i - 1) / 2, N - i));
		}
		printf("%lld\n", ans);
	}
	return 0;
}