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

vector <pll> Vl[100050];
ll in[100050][3];

vector <pll> Vq;
int main() {
	int N, M, i, j;
	ll Bo, Inc, Dam;
	scanf("%d %d", &N, &M);
	scanf("%lld %lld %lld", &Bo, &Inc, &Dam);

	for (i = 1; i <= N; i++) {
		scanf("%lld %lld %lld", &in[i][0], &in[i][1], &in[i][2]);
		Vl[i].emplace_back(0, in[i][1]);
	}

	for (i = 1; i <= M; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		Vl[t2].emplace_back(t1, t3);
	}
	
	for (i = 1; i <= N; i++) {
		sort(all(Vl[i]));
		Vl[i].emplace_back(LL_INF, 1);
		for (j = 0; j + 1 < Vl[i].size(); j++) {
			ll s = Vl[i][j].first, e = Vl[i][j + 1].first - 1;
			if (s > e) continue;

			ll h = Vl[i][j].second, rg = in[i][2], mh = in[i][0];
			if (h > Dam) continue;
			if (mh <= Dam || rg == 0) {
				Vq.emplace_back(s, 1);
				Vq.emplace_back(e+1, -1);
			}
			else {
				ll t = min(e, s + (Dam - h) / rg);
				Vq.emplace_back(s, 1);
				Vq.emplace_back(t+1, -1);
			}
		}
	}
	sort(all(Vq));

	int c = 0;
	ll ans = 0;
	for (i = 0; i + 1 < Vq.size(); i++) {
		c += Vq[i].second;
		if (i + 1 == Vq.size() || Vq[i].first != Vq[i + 1].first) {
			if (c == 0) continue;
			ll t = Vq[i + 1].first - 1;
			if (t > 1e18 && Inc != 0) return !printf("-1\n");
			ans = max(ans, (Bo + t * Inc) * c);
		}
	}
	return !printf("%lld\n", ans);
}