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
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int N = 0;
int Mx[1048576];
int Mv[1000];

int u[8];
void aa(int lvl, int s) {
	if (lvl == 5) {
		if (s != 8) return;
		int v = 0;
		for (int i = 4; i >= 0; i--) v = v * 16 + u[i];
		Mv[N] = v;
		Mx[v] = N++;
		return;
	}
	for (int i = 0; i <= 8 - s; i++) {
		u[lvl] = i;
		aa(lvl + 1, s + i);
	}
}

int u1[8];
int u2[8];
void rch(int a, int* u) {
	for (int i = 0; i < 5; i++, a /= 16) u[i] = a % 16;
}
vector <int> conn[300000];
vector <int> rconn[300000];
vector <int> Vl;
int ans[300000];
int outc[300000];
bool dchk[300000];
int main() {
	aa(0, 0);

	int i, j, k;
	for (i = 0; i < N*N; i++) {
		int t1 = i / N, t2 = i%N;
		rch(Mv[t1], u1);
		rch(Mv[t2], u2);
		for (j = 1; j <= 4; j++) {
			if (u1[j] == 0) continue;
			for (k = 1; k <= 4; k++) {
				if (u2[k] == 0) continue;
				int l = (j + k) % 5;
				int nt1 = Mv[t1] - (1 << (4 * j)) + (1 << (4 * l));
				nt1 = Mx[nt1];
				int p = t2*N + nt1;
				conn[i].push_back(p);
				rconn[p].push_back(i);
				outc[i]++;
			}
		}
	}

	for (i = 0; i < N*N; i++) {
		if (!outc[i]) {
			dchk[i] = true;
			Vl.push_back(i);
		}
	}
	for (i = 0; i < Vl.size(); i++) {
		ans[Vl[i]] = -1;
		for (auto it : conn[Vl[i]]) if (ans[it] == -1) ans[Vl[i]] = 1;
		if (Vl[i] >= (N-1) * N) ans[Vl[i]] = 1;

		for (auto it : rconn[Vl[i]]) {
			outc[it]--;
			if (outc[it] == 0 && !dchk[it]) {
				dchk[it] = true;
				Vl.push_back(it);
			}
			if (ans[Vl[i]] == -1 && !dchk[it]) {
				dchk[it] = true;
				Vl.push_back(it);
			}
		}
	}

	int T;
	scanf("%d", &T);
	while (T--) {
		int x;
		scanf("%d", &x);

		int v1 = 0, v2 = 0;
		for (i = 0; i < 8; i++) {
			scanf("%d", &j);
			v1 += 1 << (4 * j);
		}
		for (i = 0; i < 8; i++) {
			scanf("%d", &j);
			v2 += 1 << (4 * j);
		}

		int p = Mx[v1] * N + Mx[v2];
		if (x == 1) p = Mx[v2] * N + Mx[v1];

		p = ans[p];
		if (x == 1) p *= -1;

		if (p == 1) printf("Alice\n");
		else if (p == -1) printf("Bob\n");
		else printf("Deal\n");
	}
	return 0;
}
//*/