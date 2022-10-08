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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

vector <int> conn[200050];
vector <int> son[200050];
ll ans = 0;
int N, K;

bool chk[200050];
ll cnt[200050];
bool dchk[200050];
void DFS(int n) {
	dchk[n] = true;

	for (auto it : conn[n]) {
		if (dchk[it]) continue;
		son[n].push_back(it);
		DFS(it);
		cnt[n] += cnt[it];
	}
	if (chk[n]) cnt[n]++;

	for (auto it : son[n]) ans += min(cnt[it], 2 * K - cnt[it]);
}
int main() {
	int i;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= 2 * K; i++) {
		int t1;
		scanf("%d", &t1);
		chk[t1] = true;
	}
	for (i = 1; i < N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}
	DFS(1);
	printf("%lld\n", ans);
	return 0;
}