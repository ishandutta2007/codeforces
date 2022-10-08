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

int IT_MAX = 1 << 19;
ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int gcd(int a, int b) {
	return (a == 0) ? b : gcd(b%a, a);
}

int indt[1100000];
void update(int p, int v) {
	p += IT_MAX - 1;
	indt[p] = v;
	for (p /= 2; p; p /= 2) indt[p] = gcd(indt[2 * p], indt[2 * p + 1]);
}
int getgcd(int p1, int p2) {
	p1 += IT_MAX - 1;
	p2 += IT_MAX - 1;
	int rv = 0;
	for (; p1 <= p2; p1 /= 2, p2 /= 2) {
		if (p1 % 2 == 1) rv = gcd(rv, indt[p1++]);
		if (p2 % 2 == 0) rv = gcd(rv, indt[p2--]);
	}
	return rv;
}
int getright(int p, int g) {
	p += IT_MAX - 1;
	while (1) {
		if (indt[p] % g) break;
		if (p & (p + 1)) p = (p + 1) / 2;
		else return INF;
	}
	while (p < IT_MAX) {
		if (indt[2 * p] % g) p = 2 * p;
		else p = 2 * p + 1;
	}
	return p - (IT_MAX - 1);
}

int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		int t;
		scanf("%d", &t);
		update(i, t);
	}
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int t1, t2, t3, t4;
		scanf("%d", &t1);
		if (t1 == 1) {
			scanf("%d %d %d", &t2, &t3, &t4);
			int p = getright(t2, t4);
			int g = getgcd(p + 1, t3);
			if (g % t4 == 0) printf("YES\n");
			else printf("NO\n");
		}
		else {
			scanf("%d %d", &t2, &t3);
			update(t2, t3);
		}
	}
	return 0;
}
//*/