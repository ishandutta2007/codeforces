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

int IT_MAX = 1 << 20;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-9;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int ans[1050];
void updateans(int p, int v) {
	printf("%d\n", p);
	fflush(stdout);
	ans[p] = v;
}
int main() {
	int N, M, C;
	scanf("%d %d %d", &N, &M, &C);
	
	int Lv = 1, Rv = C;
	int Lp = 0, Rp = N + 1;
	while (M--) {
		int t;
		scanf("%d", &t);
		if (Lv <= t && t <= Rv) {
			if (abs(t - Lv) > abs(Rv - t)) {
				updateans(--Rp, t);
				Rv = t;
			}
			else {
				updateans(++Lp, t);
				Lv = t;
			}
			if (Lp + 1 == Rp) return 0;
		}
		else if (t < Lv) {
			int i;
			for (i = 1; i <= Lp; i++) if (ans[i] > t) break;
			updateans(i, t);
			if (i == Lp) Lv = t;
		}
		else {
			int i;
			for (i = N; i >= Rp; i--) if (ans[i] < t) break;
			updateans(i, t);
			if (i == Rp) Rv = t;
		}
	}
	return 0;
}