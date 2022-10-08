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
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define Se second
#define Fi first

multiset <int> Sx;

int in1[300050];
int in2[300050];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in1[i]);
	for (i = 1; i <= N; i++) {
		scanf("%d", &in2[i]);
		Sx.insert(in2[i]);
	}

	for (i = 1; i <= N; i++) {
		int ans = 0;
		int cur = 0;
		for (j = 29; j >= 0; j--) {
			int t = in1[i] & (1 << j);

			int st = cur + t, en = cur + t + (1 << j) - 1;
			auto it = Sx.lower_bound(st);
			if (it == Sx.end() || *it > en) t ^= (1 << j);
			cur += t;
		}
		printf("%d ", in1[i] ^ cur);
		Sx.erase(Sx.lower_bound(cur));
	}
	return !printf("\n");
}