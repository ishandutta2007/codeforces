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
//#include <unordered_map>
//#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")

using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()

//typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18; // segment tree size
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f; // memset(dp, 0x3f, sizeof(dp)), 2*INF < INT_MAX
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10; // double EPS

int X, Y;
vector <int> conn[300050];
vector <int> son[300050];
int par[300050];
int gpar[300050];
int sz[300050];
bool dchk[300050];
void DFS(int n) {
	if (n != Y) {
		if (par[n] == Y) gpar[n] = n;
		else gpar[n] = gpar[par[n]];
	}
	
	dchk[n] = true;
	sz[n] = 1;
	for (auto it : conn[n]) {
		if (dchk[it]) continue;
		son[n].push_back(it);
		par[it] = n;
		DFS(it);
		sz[n] += sz[it];
	}
}
int main() {
	int N, i;
	scanf("%d %d %d", &N, &X, &Y);
	for (i = 1; i < N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}
	DFS(Y);

	int c1 = sz[X], c2 = N - sz[gpar[X]];

	ll ans = (ll)N*(N - 1) - (ll)c1*c2;
	return !printf("%lld\n", ans);
}