//*
#include <algorithm>
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
const int MOD = 500500507;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;

int in[100050];
int u[100050];

int l[100050];
int r[100050];
vector <pii> V;
int main() {
	int N, Q, i, j, t1, t2;
	scanf("%d %d", &N, &Q);
	for (i = 1; i <= N; i++) scanf("%d", &u[i]);
	for (i = 1; i < N; i++) in[i] = -abs(u[i + 1] - u[i]);

	N--;
	l[1] = 1;
	V.push_back(pii(in[1],1));
	for (i = 2; i <= N; i++) {
		while (!V.empty() && V.back().first >= in[i]) V.pop_back();
		if (V.empty()) l[i] = 1;
		else l[i] = V.back().second + 1;
		V.push_back(pii(in[i], i));
	}

	V.clear();
	r[N] = N;
	V.push_back(pii(in[N], N));
	for (i = N - 1; i >= 1; i--) {
		while (!V.empty() && V.back().first > in[i]) V.pop_back();
		if (V.empty()) r[i] = N;
		else r[i] = V.back().second - 1;
		V.push_back(pii(in[i], i));
	}

	while (Q--) {
		scanf("%d %d", &t1, &t2);
		t2--;

		ll ans = 0;
		for (i = t1; i <= t2; i++) {
			int x = max(t1, l[i]), y = min(t2, r[i]);
			ans += (ll)(i-x+1) * (y-i+1) * in[i];
		}
		printf("%lld\n", -ans);
	}
	return 0;
}