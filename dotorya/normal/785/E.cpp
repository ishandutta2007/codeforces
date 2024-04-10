#include <stdio.h>
#include <algorithm>
#include <assert.h>
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
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
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
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

class Node {
public:
	vector <int> Vxn;
	vector <int> bitn;
	int it_max;
	void nupdate(int p, int v) {
		p = lower_bound(Vxn.begin(), Vxn.end(), p) - Vxn.begin();
		for (p++; p <= it_max; p += p & (-p)) bitn[p] += v;
	}
	int ngetsum(int p1, int p2) {
		p1 = lower_bound(Vxn.begin(), Vxn.end(), p1) - Vxn.begin();
		p2 = lower_bound(Vxn.begin(), Vxn.end(), p2 + 1) - Vxn.begin();

		int rv = 0;
		if(p1) for (; p1; p1 -= p1 & (-p1)) rv -= bitn[p1];
		if(p2) for (; p2; p2 -= p2 & (-p2)) rv += bitn[p2];
		return rv;
	}
};
Node it[600050];
void update(int p, int v1, int v2) {
	p += IT_MAX - 1;
	for (; p; p /= 2) it[p].nupdate(v1, v2);
}
int getsum(int p1, int p2, int p3, int p4) {
	p1 += IT_MAX - 1;
	p2 += IT_MAX - 1;
	
	int rv = 0;
	while (p1 <= p2) {
		if (p1 % 2 == 1) rv += it[p1++].ngetsum(p3, p4);
		if (p2 % 2 == 0) rv += it[p2--].ngetsum(p3, p4);
		p1 /= 2, p2 /= 2;
	}
	return rv;
}
void init(int p, int v) {
	p += IT_MAX - 1;
	for (; p; p /= 2) it[p].Vxn.push_back(v);
}

int in[200050];
int Qu[200050][2];
int main() {
	int N, Q, i, j;
	scanf("%d %d", &N, &Q);

	for (IT_MAX = 2; IT_MAX <= N; IT_MAX *= 2);
	for (i = 1; i <= N; i++) init(i, i);
	for (i = 1; i <= N; i++) in[i] = i;
	for (i = 1; i <= Q; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		Qu[i][0] = t1, Qu[i][1] = t2;

		init(t1, in[t2]);
		init(t2, in[t1]);
		swap(in[t1], in[t2]);
	}

	for (i = 1; i < 2 * IT_MAX; i++) {
		if (it[i].Vxn.empty()) continue;
		sort(it[i].Vxn.begin(), it[i].Vxn.end());
		it[i].Vxn.erase(unique(it[i].Vxn.begin(), it[i].Vxn.end()), it[i].Vxn.end());
		for (it[i].it_max = 2; it[i].it_max < it[i].Vxn.size(); it[i].it_max *= 2);
		for (j = 0; j <= it[i].it_max; j++) it[i].bitn.push_back(0);
	}

	ll ans = 0;
	for (i = 1; i <= N; i++) update(i, i, 1);
	for (i = 1; i <= N; i++) in[i] = i;
	for (i = 1; i <= Q; i++) {
		int t1 = Qu[i][0], t2 = Qu[i][1];
		if (t1 > t2) swap(t1, t2);

		ans -= getsum(1, t2 - 1, in[t2] + 1, N);
		ans -= getsum(t2 + 1, N, 1, in[t2] - 1);
		update(t2, in[t2], -1);

		ans -= getsum(1, t1 - 1, in[t1] + 1, N);
		ans -= getsum(t1 + 1, N, 1, in[t1] - 1);
		update(t1, in[t1], -1);

		swap(in[t1], in[t2]);

		ans += getsum(1, t2 - 1, in[t2] + 1, N);
		ans += getsum(t2 + 1, N, 1, in[t2] - 1);
		update(t2, in[t2], 1);

		ans += getsum(1, t1 - 1, in[t1] + 1, N);
		ans += getsum(t1 + 1, N, 1, in[t1] - 1);
		update(t1, in[t1], 1);
		printf("%lld\n", ans);
	}
	return 0;
}