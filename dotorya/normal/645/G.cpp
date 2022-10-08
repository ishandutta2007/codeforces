#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#pragma warning(disable:4996)
using namespace std;

#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;

int IT_MAX = 1 << 17;
const ll MOD = 987654321;
const int INF = 1034567890;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

inline ldb sq(ldb a) {
	return a*a;
}
class Circle {
public:
	ldb x, y, r;
	Circle() {
		*this = Circle(0, 0, 0);
	}
	Circle(int X, int Y, ldb R) {
		x = X, y = Y, r = R;
	}

	pdd meets(Circle k) {
		ldb d = sqrt(sq(x - k.x) + sq(y - k.y));
		if (d + ERR > r + k.r) return pdd(0, -1);
		if (d < abs(r - k.r) + ERR) return pdd(0, -1);

		ldb rt = atan2(k.y - y, k.x - x);
		ldb u = acos((d*d + r*r - k.r*k.r) / (2 * d*r));

		ldb r1 = rt - u;
		ldb r2 = rt + u;
		if (r1 < 0) r1 += 2 * PI;
		if (r2 < 0) r2 += 2 * PI;
		if (r1 >= 2 * PI) r1 -= 2 * PI;
		if (r2 >= 2 * PI) r2 -= 2 * PI;
		if (r1 > r2) swap(r1, r2);
		return pdd(r1, r2);
	}
};

int in[100050][2];
vector <pdd> V;
vector <pii> V2;
map <ldb, int> Mx;

int bit[600000];
void update(int p, int v) {
	for (; p <= IT_MAX; p += p & (-p)) bit[p] += v;
}
int getsum(int p) {
	int rv = 0;
	for (; p > 0; p -= p & (-p)) rv += bit[p];
	return rv;
}
int main() {
	int N, A, i;
	scanf("%d %d", &N, &A);
	for (i = 1; i <= N; i++) scanf("%d %d", &in[i][0], &in[i][1]);

	ldb st = ERR, en = 2 * A, mi;
	for (int iter = 1; iter <= 100; iter++) {
		mi = (st + en) / 2;
		V.clear();
		V2.clear();
		Mx.clear();

		Circle c = Circle(A, 0, mi);
		for (i = 1; i <= N; i++) {
			Circle u = Circle(in[i][0], in[i][1], sqrt(sq(in[i][0] + A) + sq(in[i][1])));
			
			pdd rv = c.meets(u);
			if (rv.first > rv.second) continue;
			V.push_back(pdd(rv.first, rv.second));
			Mx[rv.first] = 0;
			Mx[rv.second] = 0;
		}

		i = 1;
		for (auto &it : Mx) it.second = i++;
		for (auto it : V) V2.push_back(pii(Mx[it.first], Mx[it.second]));

		sort(V2.begin(), V2.end());
		for (IT_MAX = 2; IT_MAX < i; IT_MAX *= 2);
		for (i = 1; i <= IT_MAX; i++) bit[i] = 0;

		for (i = 0; i < V2.size(); i++) {
			int rv = getsum(V2[i].second) - getsum(V2[i].first - 1);
			if (rv != 0) break;
			update(V2[i].second, 1);
		}
		if (i < V2.size()) en = mi;
		else st = mi;
	}
	printf("%.20lf\n", (db)mi);
	return 0;
}
//*/