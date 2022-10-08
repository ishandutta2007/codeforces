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
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
//#define Se second
#define Fi first

class segtree {
public:
	vector <ll> Vx;
	vector <ll> indt;
	int it_max;
	segtree() {
		indt.clear();
		it_max = 0;
	}
	void update(ll p, ll v) {
		p = lower_bound(all(Vx), p) - Vx.begin() + 1;
		p += it_max - 1;
		for (; p; p /= 2) indt[p] = max(indt[p], v);
	}
	ll getmx(ll p1, ll p2) {
		p1 = lower_bound(all(Vx), p1) - Vx.begin() + 1;
		p2 = lower_bound(all(Vx), p2 + 1) - Vx.begin();
		p1 += it_max - 1;
		p2 += it_max - 1;

		ll rv = 0;
		for (; p1 <= p2; p1 /= 2, p2 /= 2) {
			if (p1 % 2 == 1) rv = max(rv, indt[p1++]);
			if (p2 % 2 == 0) rv = max(rv, indt[p2--]);
		}
		return rv;
	}
} seg[100050];

int in[100050][3];
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++) {
		for (j = 0; j < 3; j++) scanf("%d", &in[i][j]);
		seg[in[i][1]].Vx.push_back(in[i][2]);
	}
	for (i = 1; i <= N; i++) {
		vector<ll> &Vx = seg[i].Vx;
		vector<ll> &indt = seg[i].indt;
		int &it_max = seg[i].it_max;

		sort(all(Vx));
		Vx.erase(unique(all(Vx)), Vx.end());
		for (it_max = 2; it_max <= Vx.size(); it_max *= 2);
		indt.resize(2 * it_max);
		for (j = 1; j < 2 * it_max; j++) indt[j] = 0;
	}

	int ans = 0;
	for (i = 1; i <= M; i++) {
		int t1 = in[i][0], t2 = in[i][1], t3 = in[i][2];

		int v = seg[t1].getmx(-INF, t3);
		seg[t2].update(t3, v + 1);
		ans = max(ans, v + 1);
	}
	return !printf("%d\n", ans);
}