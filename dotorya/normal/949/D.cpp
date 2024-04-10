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
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define Se second
#define Fi first

ll in[100050];
ll uin[100050];
vector <pll> Vl;
int main() {
	int N, D, B, i, j;
	scanf("%d %d %d", &N, &D, &B);
	for (i = 1; i <= N; i++) scanf("%lld", &in[i]);

	int st = 0, en = N / 2 - 1 , mi, rv = N / 2;
	while (st <= en) {
		mi = (st + en) / 2;

		int s1 = mi + 1, e1 = N / 2 - 1;
		int s2 = (N + 4) / 2, e2 = N - mi;
		if (N % 2 == 0) {
			e1 = N / 2 - 1;
			s2 = N / 2 + 2;
		}
		else {
			e1 = N / 2;
			s2 = N / 2 + 2;
		}

		for (i = 1; i <= N; i++) uin[i] = in[i];

		int pst = 1, pen = N;
		for (i = s1; i <= e1; i++) {
			ll tl = (ll)i*D;

			ll v = B;
			int sp = INF, ep = -INF;
			while (v) {
				if (uin[pst] == 0) {
					pst++;
					continue;
				}

				sp = min(sp, pst);
				ep = max(ep, pst);
				if (uin[pst] > v) {
					uin[pst] -= v;
					break;
				}
				else {
					v -= uin[pst];
					uin[pst] = 0;
					pst++;
				}
			}
			if (abs(sp - i) > tl) break;
			if (abs(ep - i) > tl) break;
		}
		if (i <= e1) {
			st = mi + 1;
			continue;
		}

		for (i = e2; i >= s2; i--) {
			ll tl = (ll)(N+1-i)*D;

			ll v = B;
			int sp = INF, ep = -INF;
			while (v) {
				if (uin[pen] == 0) {
					pen--;
					continue;
				}

				sp = min(sp, pen);
				ep = max(ep, pen);
				if (uin[pen] > v) {
					uin[pen] -= v;
					break;
				}
				else {
					v -= uin[pen];
					uin[pen] = 0;
					pen--;
				}
			}
			if (abs(sp - i) > tl) break;
			if (abs(ep - i) > tl) break;
		}
		if (i >= s2) {
			st = mi + 1;
			continue;
		}

		int p1 = N / 2, p2 = p1 + 1;
		if (N % 2 == 1) p1 = p2;
		ll cnt[3] = { 0,0,0 };
		for (i = 1; i <= N; i++) {
			ll tl = (ll)((N + 1) / 2) * D;
			ll st = i - tl, en = i + tl;
			
			bool c1 = false, c2 = false;
			if (st <= p1 && p1 <= en) c1 = true;
			if (st <= p2 && p2 <= en) c2 = true;

			if (c1 || c2) cnt[2] += uin[i];
			if (c1) cnt[0] += uin[i];
			if (c2) cnt[1] += uin[i];
		}

		bool chk = false;
		if (N % 2 == 1) chk = (cnt[0] >= B);
		else chk = (cnt[0] >= B && cnt[1] >= B && cnt[2] >= 2 * B);
		if (chk) {
			rv = mi;
			en = mi - 1;
		}
		else st = mi + 1;
	}
	return !printf("%d\n", rv);
}