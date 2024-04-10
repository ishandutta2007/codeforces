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
ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

bool chk[205];
bool tchk[205];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, K, i, j;
		scanf("%d %d", &N, &K);

		for (i = 0; i <= N + 1; i++) chk[i] = false;
		for (i = 1; i <= K; i++) {
			int t;
			scanf("%d", &t);
			chk[t] = true;
		}
		for (i = 0;; i++) {
			int c = 0;
			for (j = 1; j <= N; j++) if (chk[j]) c++;
			if (c == N) break;

			for (j = 1; j <= N; j++) tchk[j] = chk[j - 1] | chk[j] | chk[j + 1];
			for (j = 1; j <= N; j++) chk[j] = tchk[j];
		}
		printf("%d\n", i + 1);
	}
	return 0;
}
//*/