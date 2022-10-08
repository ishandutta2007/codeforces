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

vector <int> Va;

char in[200050];
int main() {
	int N, A, B, i, j;
	scanf("%d %d %d", &N, &A, &B);
	scanf("%s", in);

	int st = 0;
	for (i = 0; in[i]; i++) {
		if (in[i] == '*') {
			if (st != i) Va.push_back(i - st);
			st = i + 1;
			continue;
		}
	}
	if (st != i) Va.push_back(i - st);

	int ans = 0;
	for (auto it : Va) {
		int c1 = it / 2, c2 = it - it / 2;
		if (A > B) swap(c1, c2);
		ans += min(A, c1);
		ans += min(B, c2);
		A -= min(A, c1);
		B -= min(B, c2);
	}
	return !printf("%d\n", ans);
}