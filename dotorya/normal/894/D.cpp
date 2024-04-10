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

vector <ll> Vl[2000050];
vector <ll> Vsum[2000050];
ll in[2000050];

ll getv(int x, ll t) {
	int p = lower_bound(all(Vl[x]), t + 1) - Vl[x].begin();
	if (p == 0) return 0;

	return t * p - Vsum[x][p - 1];
}
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 2; i <= N; i++) scanf("%lld", &in[i]);

	for (i = N; i >= 1; i--) {
		int n1 = 2 * i, n2 = 2 * i + 1;
		
		int p1 = 0, p2 = 0;
		Vl[i].push_back(0);
		while (p1 < Vl[n1].size() || p2 < Vl[n2].size()) {
			if (p2 >= Vl[n2].size() || (p1 < Vl[n1].size() && Vl[n1][p1] + in[n1] <= Vl[n2][p2] + in[n2])) {
				Vl[i].push_back(Vl[n1][p1] + in[n1]);
				p1++;
			}
			else {
				Vl[i].push_back(Vl[n2][p2] + in[n2]);
				p2++;
			}
		}
		Vsum[i].push_back(Vl[i][0]);
		for (j = 1; j < Vl[i].size(); j++) Vsum[i].push_back(Vsum[i].back() + Vl[i][j]);
	}

	while (M--) {
		ll t1, t2;
		scanf("%lld %lld", &t1, &t2);
		
		ll prv = -1, cur = t1, ans = 0;
		while(cur) {
			if (t2 < 0) break;

			ans += t2;
			if (2 * cur <= N && prv != 2 * cur) ans += getv(2 * cur, t2 - in[2*cur]);
			if (2 * cur + 1 <= N && prv != 2 * cur + 1) ans += getv(2 * cur + 1, t2 - in[2*cur+1]);
			t2 -= in[cur];
			prv = cur;
			cur /= 2;
		}
		printf("%lld\n", ans);
	}
	return 0;
}