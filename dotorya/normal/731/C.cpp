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

int IT_MAX = 524288;
const int MOD = 100000000;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-12;

vector <int> conn[200050];
int in[200050];
bool chk[200050];
int main() {
	int N, M, K, i, j, t1, t2;
	scanf("%d %d %d", &N, &M, &K);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);
	for (i = 1; i <= M; i++) {
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}

	int ans = 0;
	for (i = 1; i <= N; i++) {
		if (chk[i]) continue;
		vector <int> V;

		chk[i] = true;
		V.push_back(i);
		for (j = 0; j < V.size(); j++) {
			for (auto it : conn[V[j]]) {
				if (chk[it]) continue;
				V.push_back(it);
				chk[it] = true;
			}
		}
		map <int, int> Mx;
		for (auto it : V) Mx[in[it]]++;

		int s = V.size(), mx = 0;
		for (auto it : Mx) mx = max(mx, it.second);
		ans += s - mx;
		V.clear();
		Mx.clear();
	}
	return !printf("%d\n", ans);
}