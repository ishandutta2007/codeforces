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
#include <string>
#include <time.h>
#include <vector>
//#include <unordered_set>
//#include <unordered_map>

#pragma warning(disable:4996)
using namespace std;

#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

const int NMX = 1000000 + 50;

int pval[NMX];
vector <int> Vp[NMX];

vector <int> plist;
bool pchk[NMX];

int in[NMX];

int r[NMX];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}

int pch[NMX];
int rpch[NMX];
int leftc[NMX];

ll F[NMX];
int main() {
	int N, i, j, t1, t2;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) pval[i] = 1;
	
	F[0] = 1;
	for (i = 1; i <= N; i++) F[i] = (F[i - 1] * i) % MOD;
	for (i = 2; i <= N; i++) {
		if (pchk[i]) continue;
		plist.push_back(i);
		for (j = 2 * i; j <= N; j += i) pchk[j] = true;
		for (j = i; j <= N; j += i) {
			pval[j] *= i;
			Vp[j].push_back(i);
		}
	}

	r[1] = 1;
	for (i = 0; i < plist.size(); i++) r[plist[i]] = plist[i];
	for (i = 0; i + 1 < plist.size(); i++) {
		if (N / plist[i] != N / plist[i + 1]) continue;
		t1 = root(plist[i]);
		t2 = root(plist[i + 1]);
		if (t1 != t2) r[t1] = t2;
	}
	t1 = root(1);
	t2 = root(plist.back());
	if (t1 != t2) r[t1] = t2;

	for (i = 1; i <= N; i++) leftc[pval[i]]++;
	for (i = 1; i <= N; i++) {
		scanf("%d", &in[i]);
		if (in[i] == 0) continue;

		if (i == 1 || in[i] == 1) {
			t1 = root(i);
			t2 = root(in[i]);
			if (t1 != t2) return !printf("0\n");
			t1 = i;
			t2 = in[i];
			if (pch[t1] != 0 && pch[t1] != t2) return !printf("0\n");
			if (rpch[t2] != 0 && rpch[t2] != t1) return !printf("0\n");
			pch[t1] = t2;
			rpch[t2] = t1;
			leftc[pval[in[i]]]--;
			continue;
		}

		if (Vp[i].size() != Vp[in[i]].size()) return !printf("0\n");
		for (j = 0; j < Vp[i].size(); j++) {
			t1 = root(Vp[i][j]);
			t2 = root(Vp[in[i]][j]);
			if (t1 != t2) return !printf("0\n");
			t1 = Vp[i][j];
			t2 = Vp[in[i]][j];
			if (pch[t1] != 0 && pch[t1] != t2) return !printf("0\n");
			if (rpch[t2] != 0 && rpch[t2] != t1) return !printf("0\n");
			pch[t1] = t2;
			rpch[t2] = t1;
		}
		leftc[pval[in[i]]]--;
	}
	
	ll ans = 1;
	for (i = 1; i <= N; i++) ans = (ans * F[leftc[i]]) % MOD;

	for (i = 1; i <= N; i++) leftc[i] = 0;
	leftc[root(1)]++;
	for (auto it : plist) leftc[root(it)]++;
	for (i = 1; i <= N; i++) if (pch[i] != 0) leftc[root(pch[i])]--;
	for (i = 1; i <= N; i++) ans = (ans * F[leftc[i]]) % MOD;
	return !printf("%lld\n", ans);
}