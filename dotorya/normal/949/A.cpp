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

vector <int> Vp[2];
char in[200050];

int prv[200050];
int nxt[200050];
bool dchk[200050];
int main() {
	int N, i;
	scanf("%s", in + 1);
	N = strlen(in + 1);

	for (i = 1; i <= N; i++) Vp[in[i] - '0'].push_back(i);
	if (Vp[0].size() <= Vp[1].size()) return !printf("-1\n");

	for (i = 0; i < Vp[1].size(); i++) {
		int t1 = Vp[0][i], t2 = Vp[1][i];
		if (t1 > t2) return !printf("-1\n");

		nxt[t1] = t2;
	}
	for (i = 0; i < Vp[1].size(); i++) {
		int t1 = Vp[0][Vp[0].size() - Vp[1].size() + i], t2 = Vp[1][i];
		if (t1 < t2) return !printf("-1\n");
		nxt[t2] = t1;
	}

	vector <vector<int>> Va;
	for (i = 1; i <= N; i++) {
		if (dchk[i]) continue;

		vector <int> Vu;
		Vu.push_back(i);
		while (nxt[Vu.back()]) Vu.push_back(nxt[Vu.back()]);
		Va.push_back(Vu);
		for (auto it : Vu) dchk[it] = true;
	}

	printf("%d\n", (int)Va.size());
	for (auto it : Va) {
		printf("%d ", (int)it.size());
		for (auto it2 : it) printf("%d ", it2);
		printf("\n");
	}
	return 0;
}