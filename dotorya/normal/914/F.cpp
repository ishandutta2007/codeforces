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

int IT_MAX = 1 << 19;
ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int N;
int bit[31][200050];
void update(int x, int p, int v) {
	for (; p <= 200000; p += p & (-p)) bit[x][p] += v;
}
int getsum(int x, int p) {
	int rv = 0;
	for (; p; p -= p & (-p)) rv += bit[x][p];
	return rv;
}

ll MO = 123456789012347ll;
const int P = 257;
vector <pll> Vq[21];
ll val[21][100050];
int lr[21][100050][2];
ll po[100050];
void updateval(int l, int p) {
	ll v = val[l][p];
	int &st = lr[l][p][0], &en = lr[l][p][1];
	if (st != en) {
		update(l, st, -1);
		update(l, en, 1);
	}

	st = lower_bound(all(Vq[l]), pll(v, p)) - Vq[l].begin() + 1;
	en = lower_bound(all(Vq[l]), pll(v, N + 1)) - Vq[l].begin() + 1;
	if (st != en) {
		update(l, st, 1);
		update(l, en, -1);
	}
}

int qu1[100050][3];
string qu2[100050];
int qu3[100050][2];

char in[100050];
char u[100050];

int pi[100050];
int main() {
	scanf("%s", in + 1);
	N = strlen(in + 1);
	int Q, i, j, k;
	scanf("%d", &Q);

	int X = min(N, 20);
	for (i = 1; i <= Q; i++) {
		scanf("%d %d", &qu1[i][0], &qu1[i][1]);
		if (qu1[i][0] == 2) {
			scanf("%d %s", &qu1[i][2], u);
			qu2[i] = string(u);
			if (qu2[i].size() <= X && qu1[i][2] - qu1[i][1] + 1 >= qu2[i].size()) {
				int L = qu2[i].size();
				ll v = 0;
				for (auto it : qu2[i]) v = (v * P + it) % MO;
				Vq[L].emplace_back(v, qu1[i][1] - 1);
				Vq[L].emplace_back(v, qu1[i][2] - L + 1);
			}
		}
		else {
			scanf("%s", u);
			qu1[i][2] = u[0];
		}
	}

	po[0] = 1;
	for (i = 1; i <= N; i++) po[i] = po[i - 1] * P % MO;

	
	for (i = 1; i <= X; i++) {
		sort(all(Vq[i]));
		Vq[i].erase(unique(all(Vq[i])), Vq[i].end());

		ll v = 0;
		for (j = 1; j <= i; j++) v = (v * P + in[j]) % MO;
		val[i][1] = v;
		updateval(i, 1);
		for (j = i + 1; j <= N; j++) {
			v = v * P + in[j];
			v -= po[i] * in[j - i];
			v = (v%MO + MO) % MO;
			val[i][j - i + 1] = v;
			updateval(i, j - i + 1);
		}
	}

	for (i = 1; i <= Q; i++) {
		int t1 = qu1[i][0], t2 = qu1[i][1], t3 = qu1[i][2];
		if (t1 == 1) {
			ll dx = t3 - in[t2];
			in[t2] = t3;

			for (j = 1; j <= X; j++) {
				int st = t2 - j + 1, en = t2;
				for (k = st; k <= en; k++) {
					if (k < 1 || k > N - j + 1) continue;
					ll dv = dx * po[k - st];
					val[j][k] += dv;
					val[j][k] = (val[j][k] % MO + MO) % MO;
					updateval(j, k);
				}
			}
		}
		else if (t3 - t2 + 1 < qu2[i].size()) printf("0\n");
		else if (qu2[i].size() > X) {
			int L1 = t3 - t2 + 1, L2 = qu2[i].size();
			pi[0] = -1;
			for (j = 0, k = -1; j < L2;) {
				while (k != -1 && qu2[i][j] != qu2[i][k]) k = pi[k];
				pi[++j] = ++k;
			}
			int ans = 0;
			for (j = t2, k = 0; j <= t3;) {
				while (k != -1 && in[j] != qu2[i][k]) k = pi[k];
				j++, k++;
				if (k == L2) {
					ans++;
					k = pi[L2];
				}
			}
			printf("%d\n", ans);
		}
		else {
			int L = qu2[i].size();
			ll v = 0;
			for (auto it : qu2[i]) v = (v * P + it) % MO;

			int p1 = lower_bound(all(Vq[L]), pll(v, qu1[i][1] - 1)) - Vq[L].begin() + 1;
			int p2 = lower_bound(all(Vq[L]), pll(v, qu1[i][2] - L + 1)) - Vq[L].begin() + 1;
			printf("%d\n", getsum(L, p2) - getsum(L, p1));
		}
	}
	return 0;
}
//*/