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
#include <cmath>
#include <vector>
#include <deque>
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

int IT_MAX = 1<<21;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-10;


map <int, int> Mx;

int in[100050];
vector <int> V[100050];
int dp[100050];

bool pchk[100050];
vector <int> plist;
int main() {
	int N, i, j, t;
	for (i = 2; i <= 100000; i++) {
		if (pchk[i]) continue;
		plist.push_back(i);
		for (j = 2 * i; j <= 100000; j += i) pchk[j] = true;
	}
	
	scanf("%d", &N);
	int ans = 0;
	for (i = 1; i <= N; i++) {
		scanf("%d", &t);
		for (auto it : plist) {
			if (it*it > t) break;
			if (t%it) continue;

			if (Mx.count(it)) V[i].push_back(Mx[it]);
			Mx[it] = i;
			while (t%it == 0) t /= it;
		}
		if (t != 1) {
			if (Mx.count(t)) V[i].push_back(Mx[t]);
			Mx[t] = i;
		}

		dp[i] = 1;
		for (auto it : V[i]) dp[i] = max(dp[i], dp[it] + 1);
		ans = max(ans, dp[i]);
	}
	return !printf("%d\n", ans);
}