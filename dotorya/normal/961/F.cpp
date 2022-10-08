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

int IT_MAX = 1 << 18;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int P[3] = { 359, 1039, 2797 };
ll MO[3] = { MOD, MOD + 2, 1000000087 };

char in[1000050];
ll po[3][1000050];
ll sum[3][1000050];
bool isEqual(int s1, int e1, int s2, int e2) {
	for (int i = 0; i < 3; i++) {
		ll v1 = (sum[i][e1] - sum[i][s1 - 1]) % MO[i];
		v1 = (v1 + MO[i]) % MO[i];
		v1 = v1 * po[i][1000000 - e1] % MO[i];

		ll v2 = (sum[i][e2] - sum[i][s2 - 1]) % MO[i];
		v2 = (v2 + MO[i]) % MO[i];
		v2 = v2 * po[i][1000000 - e2] % MO[i];
		if (v1 != v2) return false;
	}
	return true;
}
int main() {
	int N, i, j;
	scanf("%d", &N);
	scanf("%s", in + 1);

	for (i = 0; i < 3; i++) {
		po[i][0] = P[i];
		for (j = 1; j <= 1000000; j++) po[i][j] = po[i][j - 1] * P[i] % MO[i];
		for (j = 1; j <= N; j++) sum[i][j] = (sum[i][j - 1] + po[i][j] * in[j]) % MO[i];
	}

	vector <int> Va;
	int prv = -1;
	for (i = (N + 1) / 2; i >= 1; i--) {
		int st = i, en = N + 1 - st;
		int L = en - st + 1;
		int mx = min(L - 1, prv + 2);
		if (mx % 2 == 0) mx--;
		for (j = mx; j >= 1; j-=2) {
			if (isEqual(st, st + j - 1, en - j + 1, en)) break;
		}
		if (j >= 1) Va.push_back(j);
		else Va.push_back(-1);
		prv = j;
	}
	reverse(all(Va));
	for (auto it : Va) printf("%d ", it);
	return !printf("\n");
}