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

int IT_MAX = 1 << 18;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int indt[600000];
void update(int p, int v) {
	p += IT_MAX;
	for (; p; p /= 2) indt[p] += v;
}
int getsum(int p1, int p2) {
	p1 += IT_MAX;
	p2 += IT_MAX;
	int rv = 0;
	for (; p1 <= p2; p1 /= 2, p2 /= 2) {
		if (p1 % 2 == 1) rv = rv + indt[p1++];
		if (p2 % 2 == 0) rv = rv + indt[p2--];
	}
	return rv;
}

int in[200050];

vector <int> Vq[200050];
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &in[i]);
		if (in[i] <= N) Vq[in[i]].push_back(i);
	}

	for (i = 1; i <= N; i++) update(i, 1);
	
	ll ans = 0;
	for (i = 1; i <= N; i++) {
		for (auto it : Vq[i - 1]) update(it, -1);
		ans += getsum(i + 1, min(N, in[i]));
	}
	return !printf("%lld\n", ans);
}