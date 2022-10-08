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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

char u[55][55];
int main() {
	int N, i, j, k, l;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%s", u[i]);

	int ans = INF;
	int L = strlen(u[1]);
	for (i = 1; i <= L; i++) {
		char c = u[1][0];
		for (j = 1; j < L; j++) u[1][j - 1] = u[1][j];
		u[1][L - 1] = c;

		int s = i%L;
		for (j = 2; j <= N; j++) {
			for (k = 0; k < L; k++) {
				for (l = 0; l < L; l++) if (u[1][l] != u[j][(k+l)%L]) break;
				if (l >= L) {
					s += k;
					break;
				}
			}
			if (k >= L) break;
		}
		if (j > N) ans = min(ans, s);
	}
	if (ans == INF) return !printf("-1\n");
	return !printf("%d\n", ans);
}