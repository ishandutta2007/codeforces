#include <stdio.h>
#include <algorithm>
#include <assert.h>
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
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
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
const ll MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

bool chk[1000050];
int main() {
	int N, M, K, i;
	scanf("%d %d %d", &N, &M, &K);
	for (i = 1; i <= M; i++) {
		int t;
		scanf("%d", &t);
		chk[t] = true;
	}

	if (chk[1]) return !printf("1\n");

	int p = 1;
	while (K--) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		if (t2 == p) swap(t1, t2);
		if (t1 != p) continue;
		p = t2;
		if (chk[p]) return !printf("%d\n", p);
	}
	return !printf("%d\n", p);
}