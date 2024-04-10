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

int IT_MAX = 1 << 17;
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

pii in[300050];
int u[300050];

int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		u[i] = i;
		scanf("%d %d", &in[i].first, &in[i].second);
	}
	sort(u + 1, u + N + 1, [](int a, int b) {
		if (in[a].first != in[b].first) return in[a].first < in[b].first;
		else return in[a].second > in[b].second;
	});

	int mxp = u[1];
	for (i = 2; i <= N; i++) {
		if (in[u[i]].second <= in[mxp].second) return !printf("%d %d\n", u[i], mxp);
		else mxp = u[i];
	}
	return !printf("-1 -1\n");
}