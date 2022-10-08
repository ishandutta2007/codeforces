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
//#include <unordered_map>
//#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")

using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()

//typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18; // segment tree size
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f; // memset(dp, 0x3f, sizeof(dp)), 2*INF < INT_MAX
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10; // double EPS

vector <int> bit[100050];
void update(int x, int p, int v) {
	for (; p*x <= 100000; p += p & (-p)) bit[x][p] += v;
}
int getsum(int x, int p) {
	p = min(p, 100000);
	p = p / x;
	int rv = 0;
	for (; p; p -= p & (-p)) rv += bit[x][p];
	return rv;
}
int main() {
	for (int i = 1; i <= 100000; i++) bit[i].resize(100000 / i + 5);
	for (int i = 1; i <= 100000; i++) for (auto &it : bit[i]) it = 0;

	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int t1, t2, t3, t4;
		scanf("%d %d", &t1, &t2);
		if (t1 == 1) {
			for (int i = 1; i * i <= t2; i++) {
				if (t2 % i) continue;
				update(i, t2 / i, 1);
				update(t2 / i, i, 1);
			}
		}
		else {
			scanf("%d %d", &t3, &t4);
			if (t2 % t3 != 0 || t2 >= t4) {
				printf("-1\n");
				continue;
			}

			int x = t2, k = t3, s = t4;

			int S = 1, E = s - x;
			if (getsum(k, E) == 0) {
				printf("-1\n");
				continue;
			}

			int curv = 0;
			for (int i = 16; i >= 0; i--) {
				int ts = curv, te = curv + (1 << i) - 1;

				if (x & (1 << i));
				else ts += (1 << i), te += (1 << i);

				ts = max(S, ts), te = min(E, te);
				if (ts <= te && getsum(k, te) != getsum(k, ts - 1)) {
					if (x & (1 << i));
					else curv += 1 << i;
				}
				else {
					if (x & (1 << i)) curv += 1 << i;
				}
			}
			printf("%d\n", curv);
		}
	}
	return 0;
}