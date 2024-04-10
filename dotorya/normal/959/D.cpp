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
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

vector <int> Vl[3000050];

bool pchk[3000050];
int prv[3000050];
vector <int> Vp;

int in[100050];
int ans[100050];

bool chk[3000050];
int main() {
	int N, i, j;
	

	for (i = 2; i <= 3000000; i++) {
		if (pchk[i]) continue;
		Vp.push_back(i);
		for (j = 2 * i; j <= 3000000; j += i) pchk[j] = true;
		for (j = i; j <= 3000000; j += i) prv[j] = i;
	}
	for (i = 2; i <= 3000000; i++) {
		int t = i;
		while (t != 1) {
			int x = prv[t];
			Vl[i].push_back(x);
			while (t % x == 0) t /= x;
		}
	}

	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);

	for (i = 1; i <= N; i++) {
		int t = in[i];
		for (j = 0; j < Vl[t].size(); j++) if (chk[Vl[t][j]]) break;
		if (j < Vl[t].size()) break;

		ans[i] = t;
		for (j = 0; j < Vl[t].size(); j++) chk[Vl[t][j]] = true;
	}
	if (i <= N) {
		for (j = in[i] + 1;; j++) {
			int k;
			for (k = 0; k < Vl[j].size(); k++) if (chk[Vl[j][k]]) break;
			if (k >= Vl[j].size()) {
				ans[i] = j;
				for (auto it : Vl[j]) chk[it] = true;
				break;
			}
		}

		int v = 2;
		for (i = i + 1; i <= N; i++) {
			while (1) {
				for (j = 0; j < Vl[v].size(); j++) if (chk[Vl[v][j]]) break;
				if (j >= Vl[v].size()) break;
				v++;
			}
			ans[i] = v;
			for (auto it : Vl[v]) chk[it] = true;
		}
	}
	for (i = 1; i <= N; i++) printf("%d ", ans[i]);
	return !printf("\n");
}