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
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

ll in[100050][2];
ll myrand(int x) {
	ll t = rand() % x;
	t = (t * RAND_MAX + rand()) % x;
	return t;
}
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%lld %lld", &in[i][0], &in[i][1]);
	if (N <= 2) return !printf("YES\n");

	srand(time(0));
	while (clock() < 1.7 * CLOCKS_PER_SEC) {
		int t1, t2;
		do {
			t1 = myrand(N);
			t2 = myrand(N);
		} while (t1 == t2);

		vector <int> Vu;

		ll a = in[t1][1] - in[t2][1], b = in[t2][0] - in[t1][0], c = a * in[t1][0] + b * in[t1][1];
		for (i = 0; i < N; i++) if (a * in[i][0] + b * in[i][1] != c) Vu.push_back(i);

		if (Vu.size() <= 1) return !printf("YES\n");

		ll a2 = in[Vu[0]][1] - in[Vu[1]][1], b2 = in[Vu[1]][0] - in[Vu[0]][0], c2 = a2 * in[Vu[0]][0] + b2 * in[Vu[0]][1];
		for (i = 0; i < Vu.size(); i++) {
			int t = Vu[i];
			if (a2 * in[t][0] + b2 * in[t][1] != c2) break;
		}
		if (i >= Vu.size()) return !printf("YES\n");
	}
	return !printf("NO\n");
}