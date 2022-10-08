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


bool vchk[20][1100000];

vector <int> Va;
vector <int> Vl;
void aa(int lvl) {
	int ran = 1 << lvl, i, j;

	for (i = -ran; i <= ran; i++) if (vchk[lvl][i + ran] && i) break;
	if (i > ran) {
		if (Va.size() > Vl.size()) Va = Vl;
		return;
	}
	if (lvl == 0) return;

	int cc = 0;
	for (i = -ran; i <= ran; i++) if (i % 2 && vchk[lvl][i+ran]) cc = 1;
	if (!cc) {
		for (i = -ran / 2; i <= ran / 2; i++) vchk[lvl - 1][i+ran / 2] = false;
		for (i = -ran; i <= ran; i++) if(vchk[lvl][i+ran]) vchk[lvl - 1][i / 2 + ran / 2] = true;
		aa(lvl - 1);
	}
	else {
		for (i = -ran / 2; i <= ran / 2; i++) vchk[lvl - 1][i + ran / 2] = false;
		for (i = -ran; i <= ran; i++) {
			if (!vchk[lvl][i + ran]) continue;

			if (i % 2 == 0) vchk[lvl - 1][i / 2 + ran / 2] = true;
			else vchk[lvl - 1][(i - 1) / 2 + ran / 2] = true;
		}
		Vl.push_back(1 << (19 - lvl));
		aa(lvl - 1);
		Vl.pop_back();

		for (i = -ran / 2; i <= ran / 2; i++) vchk[lvl - 1][i + ran / 2] = false;
		for (i = -ran; i <= ran; i++) {
			if (!vchk[lvl][i + ran]) continue;

			if (i % 2 == 0) vchk[lvl - 1][i / 2 + ran / 2] = true;
			else vchk[lvl - 1][(i + 1) / 2 + ran / 2] = true;
		}
		Vl.push_back(-(1 << (19 - lvl)));
		aa(lvl - 1);
		Vl.pop_back();
	}
}
int main() {
	int N, i;
	scanf("%d", &N);
	

	for (i = 1; i <= N; i++) {
		int t;
		scanf("%d", &t);
		vchk[19][t + (1 << 19)] = true;
	}
	for (i = 1; i <= 100; i++) Va.push_back(0);
	aa(19);
	printf("%d\n", (int)Va.size());
	for (auto it : Va) printf("%d ", it);
	return !printf("\n");
}