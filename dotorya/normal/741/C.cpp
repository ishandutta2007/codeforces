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
const ll MOD = 10007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-10;

vector <int> conn[200050];
int ans[200050];

int in[200050][2];
int main() {
	int N, i, t1, t2;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
		in[i][0] = t1, in[i][1] = t2;
	}
	for (i = 1; i <= N; i++) {
		t1 = 2 * i - 1, t2 = 2 * i;
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}

	for (i = 1; i <= 2*N; i++) {
		if (ans[i]) continue;
		vector <int> V;
		V.push_back(i);
		ans[i] = 1;
		for (int j = 0; j < V.size(); j++) {
			for (auto it : conn[V[j]]) {
				if (ans[it]) continue;
				V.push_back(it);
				ans[it] = 3 - ans[V[j]];
			}
		}
		V.clear();
	}
	for (i = 1; i <= N; i++) printf("%d %d\n", ans[in[i][0]], ans[in[i][1]]);
	return 0;
}