//*
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


#define pow10 pasiodfiopsdjviozjxciovjxcviozj
#define pow2 qpowdskopjkcoizxnzoicn

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <char, int> pci;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef pair <ldb, int> pdi;
typedef pair <ldb, ll> pdl;

int IT_MAX;
const ll MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-10;

ll A[500050];
ll B[500050];
ll Bsum[500050];
char in[500050];

int main() {
	int N, H, W, i;
	scanf("%d %d %d %s", &N, &H, &W, in);
	
	int* xlr = (int*)calloc(1000050, sizeof(int));
	int* ylr = (int*)calloc(1000050, sizeof(int));
	xlr += 500000;
	ylr += 500000;

	int xp = 0, yp = 0, xtot = 0, ytot = 0, xmx = 0, xmn = 0, ymx = 0, ymn = 0;
	for (i = 0; i < N; i++) {
		if (in[i] == 'L') {
			xp--;
			if (xlr[xp] == 0) xlr[xp] = i + 1;
		}
		if (in[i] == 'R') {
			xp++;
			if (xlr[xp] == 0) xlr[xp] = i + 1;
		}
		if (in[i] == 'U') {
			yp--;
			if (ylr[yp] == 0) ylr[yp] = i + 1;
		}
		if (in[i] == 'D') {
			yp++;
			if (ylr[yp] == 0) ylr[yp] = i + 1;
		}
		xmx = max(xmx, xp);
		ymx = max(ymx, yp);
		xmn = min(xmn, xp);
		ymn = min(ymn, yp);
	}
	xtot = xp, ytot = yp;

	for (i = 1; i <= H; i++) {
		A[i] = LL_INF;
		
		if (ylr[-i] != 0) A[i] = min(A[i], (ll)ylr[-i]);
		else if (ytot < 0) {
			ll t = (i + ymn + abs(ytot) - 1) / abs(ytot);
			ll p = i + t * ytot;
			A[i] = min(A[i], t*N + ylr[-p]);
		}

		if (ylr[H + 1 - i] != 0) A[i] = min(A[i], (ll)ylr[H + 1 - i]);
		else if (ytot > 0) {
			ll t = (H + 1 - ymx - i + ytot - 1) / ytot;
			ll p = i + t * ytot;
			A[i] = min(A[i], t*N + ylr[H + 1 - p]);
		}
	}

	for (i = 1; i <= W; i++) {
		B[i] = LL_INF;
		if (xlr[-i] != 0) B[i] = min(B[i], (ll)xlr[-i]);
		else if (xtot < 0) {
			ll t = (i + xmn + abs(xtot) - 1) / abs(xtot);
			ll p = i + t * xtot;
			B[i] = min(B[i], t*N + xlr[-p]);
		}

		if (xlr[W + 1 - i] != 0) B[i] = min(B[i], (ll)xlr[W + 1 - i]);
		else if (xtot > 0) {
			ll t = (W + 1 - xmx - i + xtot - 1) / xtot;
			ll p = i + t * xtot;
			B[i] = min(B[i], t*N + xlr[W + 1 - p]);
		}
	}

	sort(A + 1, A + H + 1);
	sort(B + 1, B + W + 1);
	if (A[H] == LL_INF && B[W] == LL_INF) return !printf("-1\n");

	for (i = 1; i <= W; i++) Bsum[i] = (Bsum[i - 1] + B[i]) % MOD;
	ll ans = 0;
	for (i = 1; i <= H; i++) {
		int rv = 0, st = 1, en = W, mi;
		while (st <= en) {
			mi = (st + en) / 2;
			if (B[mi] > A[i]) en = mi - 1;
			else {
				rv = mi;
				st = mi + 1;
			}
		}
		ans = (ans + Bsum[rv]) % MOD;
		ans = (ans + (W - rv) * A[i]) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}