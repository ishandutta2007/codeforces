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
ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

map <pii, int> Mx;
int main() {
	int N, Q, i, j;
	scanf("%d %d", &N, &Q);
	Mx[pii(1, N)] = 2;
	int c = N;
	while (Q--) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		
		auto it = Mx.lower_bound(pii(t1 + 1, -INF));
		it--;
		if (it->first.first != t1) {
			pii u = it->first;
			int v = it->second;
			Mx.erase(it);
			Mx[pii(u.first, t1 - 1)] = v;
			Mx[pii(t1, u.second)] = v;
		}
		
		it = Mx.lower_bound(pii(t2 + 1, -INF));
		it--;
		if (it->first.second != t2) {
			pii u = it->first;
			int v = it->second;
			Mx.erase(it);
			Mx[pii(u.first, t2)] = v;
			Mx[pii(t2 + 1, u.second)] = v;
		}
		
		while (1) {
			it = Mx.lower_bound(pii(t1, -1));
			if (it == Mx.end() || it->first.first > t2) break;
			if (it->second == 2) c -= it->first.second - it->first.first + 1;
			Mx.erase(it);
		}
		if (t3 == 2) c += t2 - t1 + 1;
		Mx[pii(t1, t2)] = t3;

		printf("%d\n", c);
	}
	return 0;
}
//*/