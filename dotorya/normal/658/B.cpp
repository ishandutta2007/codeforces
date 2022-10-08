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
const ll MOD = 987654321;
const int INF = 1034567890;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

bool chk[200000];
int T[200000];
priority_queue <pii, vector<pii>, greater<pii>> H;

int main() {
	int N, K, Q, i, t1, t2;
	scanf("%d %d %d", &N, &K, &Q);
	for (i = 1; i <= N; i++) scanf("%d", &T[i]);
	for (i = 1; i <= Q; i++) {
		scanf("%d %d", &t1, &t2);

		if (t1 == 1) {
			chk[t2] = true;
			H.push(pii(T[t2], t2));
			if (H.size() > K) {
				chk[H.top().second] = false;
				H.pop();
			}
		}
		else {
			if (chk[t2]) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
//*/