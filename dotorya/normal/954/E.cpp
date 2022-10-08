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
int MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define Se second
#define Fi first

typedef pair<int, db> pid;
vector <pid> Vu1;
vector <pid> Vu2;

int in1[200050];
int in2[200050];
int main() {
	int N, T, i, j;
	db ans = 0;
	scanf("%d %d", &N, &T);
	for (i = 1; i <= N; i++) scanf("%d", &in2[i]);
	for (i = 1; i <= N; i++) scanf("%d", &in1[i]);

	for (i = 1; i <= N; i++) {
		if (in1[i] == T) {
			ans += in2[i];
			continue;
		}
		if (in1[i] < T) Vu1.emplace_back(T - in1[i], in2[i]);
		else Vu2.emplace_back(in1[i] - T, in2[i]);
	}
	sort(all(Vu1));
	sort(all(Vu2));

	int p1 = 0, p2 = 0;
	while (p1 < Vu1.size() && p2 < Vu2.size()) {
		db v1 = Vu1[p1].first * Vu1[p1].second;
		db v2 = Vu2[p2].first * Vu2[p2].second;

		db v = min(v1, v2);
		ans += v / Vu1[p1].first;
		ans += v / Vu2[p2].first;
		Vu1[p1].second -= v / Vu1[p1].first;
		Vu2[p2].second -= v / Vu2[p2].first;
		if (Vu1[p1].second <= 1e-8) p1++;
		if (Vu2[p2].second <= 1e-8) p2++;
	}
	return !printf("%.20lf\n", ans);
}