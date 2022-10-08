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
#pragma comment(linker, "/STACK:1048576")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple <int, int, int> t3;

int IT_MAX = 1 << 12;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

int main() {
	int N, K, i, j;
	scanf("%d %d", &N, &K);
	int s = 0, c1 = 0, c2 = 0;
	for (i = 1; i <= K; i++) {
		int t;
		scanf("%d", &t);
		s += t;
		c1 += t / 4;
		if (t % 4 >= 2) c2++;
	}

	int v1 = 0, v2 = 0;
	if (s > 7 * N) v1 = s - 7 * N, v2 = 10 * N - s;
	else if (s > 4 * N) v1 = 0, v2 = s - 4 * N;

	if (v1 > c1) return !printf("NO\n");
	c2 += 2 * (c1 - v1);
	if (v2 > c2) printf("NO\n");
	else printf("YES\n");
	return 0;
}