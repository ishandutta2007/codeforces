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

int IT_MAX = 131072;
const ll MOD = 1000000007;
const int INF = 2034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-10;

int cnt = 0;
vector <int> conn[200050];

bool dchk[200050];
bool DFS(int n) {
	int c = 0;
	dchk[n] = true;
	for (auto it : conn[n]) {
		if (dchk[it]) continue;
		if (DFS(it)) c++;
	}
	if (c >= 2) {
		cnt += c - 1;
		return false;
	}
	else return true;
}
int main() {
	ll x, y;
	int N, i, t1, t2;
	scanf("%d %lld %lld ", &N, &x, &y);
	for (i = 1; i < N; i++) {
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}

	if (x < y) {
		if(DFS(1)) cnt++;
		ll ans = (N - 1)*x;
		ans += (cnt - 1)*(y - x);
		printf("%lld\n", ans);
	}
	else {
		ll ans = y * (N-1);
		for (i = 1; i <= N; i++) if ((int)conn[i].size() == N - 1) break;
		if (i <= N) ans += x - y;
		printf("%lld\n", ans);
	}
	return 0;
}