#include <stdio.h>
#include <algorithm>
#include <assert.h>
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
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
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
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1034567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

int ans = INF;
char in[10][10];
bool chk[20];
void aa(int lvl) {
	if (lvl == 16) {
		int i, j;
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8; j++) {
				if (in[i][j] == 'W' && (chk[i] || chk[8 + j])) break;
				if (in[i][j] == 'B' && (!chk[i] && !chk[8 + j])) break;
			}
			if (j < 8) break;
		}
		if (i >= 8) {
			int c = 0;
			for (i = 0; i < 16; i++) if (chk[i]) c++;
			ans = min(ans, c);
		}
		return;
	}

	chk[lvl] = true;
	aa(lvl + 1);
	chk[lvl] = false;
	aa(lvl + 1);
}

int main() {
	int i, j;
	for (i = 0; i < 8; i++) scanf("%s", in[i]);

	aa(0);
	return !printf("%d\n", ans);
}