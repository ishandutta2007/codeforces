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
ll MOD = 1000000007;
//const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first
const int INF = 2e9;

int Y;
int nc = 0;
vector <int> Vu;
int Mx[512];

ll mul[30][505][505];
ll tmul[505][505];
ll rv[505][505];
ll u[505][505];
void aa(int K) {
	int Z = Y*nc;
	int i, j, k;
	for (i = 0; i < Z; i++) for (j = 0; j < Y*nc; j++) rv[i][j] = LL_INF;
	for (i = 0; i < Z; i++) rv[i][i] = 0;

	for(int q = 0; q < 30; q++) {
		if (K & (1 << q));
		else continue;

		for (i = 0; i < Z; i++) for (j = 0; j < Z; j++) u[i][j] = LL_INF;
		for (i = 0; i < Z; i++) {
			for (k = 0; k < Z; k++) {
				if (rv[i][k] * 2 > LL_INF) continue;
				for (j = 0; j < Z; j++) u[i][j] = min(rv[i][k] + mul[q][k][j], u[i][j]);
			}
		}
		for (i = 0; i < Z; i++) for (j = 0; j < Z; j++) rv[i][j] = u[i][j];
	}
}

vector <pair<pii, ll>> conn[1000];
ll val[1000];

map <int, ll> Mq;

int cur;
ll dp[505];
ll udp[505];

int DEBUG = 0;

ll tval[20];
int main() {
	int X, K, N, Q, i, j, k, l;
	if(!DEBUG) scanf("%d %d %d %d", &X, &K, &N, &Q);
	else X = 4, K = 8, N = 100000000, Q = 25;

	for (i = 1; i <= K; i++) {
		if (!DEBUG) scanf("%lld", &val[i]);
		else val[i] = 10;
	}

	for (i = 1; i <= Q; i++) {
		int t1;
		ll t2;
		if(!DEBUG) scanf("%d %lld", &t1, &t2);
		else t1 = 1000000 * i, t2 = -100;
		Mq[t1] = t2;
	}
	if(!Mq.count(N)) Mq[N] = 0;
	for (i = 1; i <= K; i++) Mq[N + i] = LL_INF;

	for (i = 0; i < 512; i++) Mx[i] = -1;
	Mx[(1 << X) - 1] = 0;
	nc++;
	Vu.push_back((1 << X) - 1);
	for (i = 0; i < Vu.size(); i++) {
		vector <int> Vt;
		for (j = 0; j < K; j++) if(Vu[i] & (1<<j)) Vt.push_back(j);
		for (j = 1; j <= K; j++) {
			vector <int> Vt2 = Vt;
			Vt2[0] += j;
			sort(all(Vt2));
			Vt2.erase(unique(all(Vt2)), Vt2.end());
			if (Vt2.size() != Vt.size()) continue;

			int x = Vt2[0];
			int v = 0;
			for (auto it : Vt2) v |= 1 << (it - x);
			if (Mx[v] == -1) {
				Mx[v] = nc++;
				Vu.push_back(v);
			}
			conn[i].emplace_back(pii(x, Mx[v]), j);
		}
	}

	for (i = 0; i < 8; i++) for (j = 0; j < nc; j++) dp[i*nc+j] = LL_INF;
	dp[0] = 0;
	cur = 1;

	Y = K-X+1;
	for (i = 0; i < Y*nc; i++) {
		for (j = 0; j < Y*nc; j++) mul[0][i][j] = LL_INF;
		if(i >= nc) mul[0][i][i - nc] = 0;
	}
	for (i = 0; i < nc; i++) {
		for (auto it : conn[i]) mul[0][it.first.second][(it.first.first-1) * nc + i] = min(mul[0][it.first.second][(it.first.first-1)*nc + i], val[it.second]);
	}
	for (int q = 1; q < 30; q++) {
		int Z = Y*nc;
		for (i = 0; i < Z; i++) for (j = 0; j < Z; j++) u[i][j] = LL_INF;
		for (i = 0; i < Z; i++) {
			for (k = 0; k < Z; k++) {
				if (mul[q-1][i][k] * 2 > LL_INF) continue;
				for (j = 0; j < Z; j++) u[i][j] = min(mul[q-1][i][k] + mul[q-1][k][j], u[i][j]);
			}
		}
		for (i = 0; i < Z; i++) for (j = 0; j < Z; j++) mul[q][i][j] = u[i][j];
	}

	//printf("%d %d\n", Y, nc);
	for (auto it : Mq) {
		//printf("Running...\n");
		int p = it.first;
		if (p > N) break;
		if (cur < p - 8) {
			if(DEBUG) printf("aa = %d\n", p - 8 - cur);
			aa(p - 8 - cur);
			
			if(DEBUG) printf("aa end\n");
			for (i = 0; i < Y*nc; i++) udp[i] = LL_INF;
			for (i = 0; i < Y*nc; i++) for (j = 0; j < Y*nc; j++) udp[i] = min(udp[i], dp[j] + rv[i][j]);
			for (i = 0; i < Y*nc; i++) dp[i] = udp[i];
			cur = p - 8;
		}

		for (i = 0; i < 20; i++) {
			tval[i] = 0;
			if (Mq.count(p + i)) tval[i] = Mq[p + i];
		}
		while (cur < p + 8 && cur < N-X+1) {
			cur++;
			for (i = (Y+1)*nc - 1; i >= nc; i--) dp[i] = dp[i - nc];
			for (i = 0; i < nc; i++) dp[i] = LL_INF;
			for (i = 0; i < nc; i++) {
				for (auto it : conn[i]) {
					int st = it.first.first * nc + i;
					int en = it.first.second;
					int p2 = (cur - it.first.first) + it.second;
					ll v = val[it.second];
					if (p2 >= p) v += tval[p2-p];
					dp[en] = min(dp[en], dp[st] + v);
				}
			}
		}
	}
	if (DEBUG) printf("%d\n", clock());
	return !printf("%lld\n", dp[(cur - (N - X + 1))*nc]);
}
//*/