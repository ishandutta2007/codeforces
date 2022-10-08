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

int IT_MAX = 1 << 16;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int in[15];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 0; i <= 10; i++, N /= 10) in[i] = N % 10;

	int c = 0;
	for (i = 10; i >= 0; i--) if (in[i]) break;
	c = i + 1;

	int ans = INF;
	for (i = 1; i < 2048; i++) {
		vector <int> Vu;
		for (j = 10; j >= 0; j--) if (i & (1 << j)) Vu.push_back(in[j]);
		if (Vu[0] == 0) continue;

		int v = 0;
		for (auto it : Vu) v = v * 10 + it;

		int x = (int)sqrt(v);
		for (j = x - 2; j <= x + 2; j++) if (j*j == v) break;
		if (j <= x + 2) ans = min(ans, c - (int)Vu.size());
	}
	if (ans == INF) ans = -1;
	return !printf("%d\n", ans);
}