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
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

const int BK = 400;
int N;
inline int getleft(int bn) { return bn * BK; }
inline int getright(int bn) { return min((bn + 1) * BK, N) - 1; }

int in[200050];
int ch[300000 / BK][105];
int rch[300000 / BK][105];
bool echk[300000 / BK][105];
void update(int bn) {
	int st = getleft(bn), en = getright(bn);
	for (int i = st; i <= en; i++) in[i] = ch[bn][in[i]];
	for (int i = 1; i <= 100; i++) ch[bn][i] = rch[bn][i] = i;
}
void recalc(int bn) {
	int st = getleft(bn), en = getright(bn);
	for (int i = 1; i <= 100; i++) echk[bn][i] = false;
	for (int i = st; i <= en; i++) echk[bn][in[i]] = true;
}

int main() {
	int i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &in[i]);
	
	int mx = (N - 1) / BK;
	for (i = 0; i <= mx; i++) {
		int st = getleft(i), en = getright(i);
		for (j = st; j <= en; j++) echk[i][in[j]] = true;
		for (j = 1; j <= 100; j++) ch[i][j] = rch[i][j] = j;
	}

	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int t1, t2, t3, t4;
		scanf("%d %d %d %d", &t1, &t2, &t3, &t4);
		t1--, t2--;

		int sn = t1 / BK, en = t2 / BK;
		if (sn == en) {
			update(sn);
			for (i = t1; i <= t2; i++) if (in[i] == t3) in[i] = t4;
			recalc(sn);
		}
		else {
			update(sn);
			for (i = t1; i <= getright(sn); i++) if (in[i] == t3) in[i] = t4;
			recalc(sn);

			update(en);
			for (i = getleft(en); i <= t2; i++) if (in[i] == t3) in[i] = t4;
			recalc(en);

			for (i = sn + 1; i < en; i++) {
				if (!echk[i][t3]) continue;
				if (echk[i][t4]) {
					update(i);
					for (j = getleft(i); j <= getright(i); j++) if (in[j] == t3) in[j] = t4;
					recalc(i);
				}
				else {
					int x = rch[i][t3];
					rch[i][t3] = 0;
					ch[i][x] = t4;
					rch[i][t4] = x;
					echk[i][t3] = false;
					echk[i][t4] = true;
				}
			}
		}
	}
	for (i = 0; i <= mx; i++) update(i);
	for (i = 0; i < N; i++) printf("%d ", in[i]);
	return !printf("\n");
}