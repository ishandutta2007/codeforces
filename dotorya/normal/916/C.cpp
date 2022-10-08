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


bool pchk[300050];
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);

	pchk[1] = true;
	for (i = 2; i <= 300000; i++) {
		if (pchk[i]) continue;
		for (j = 2 * i; j <= 300000; j += i) pchk[j] = true;
	}

	vector <pair<pii, int>> Va;
	for (i = 1; i + 1 < N; i++) Va.emplace_back(pii(i, i + 1), 1);
	for (i = N - 1;; i++) if (!pchk[i]) break;
	Va.emplace_back(pii(N - 1, N), i - (N - 2));
	printf("%d %d\n", i, i);

	for (i = 1; i <= N; i++) {
		for (j = i + 2; j <= N; j++) {
			if (Va.size() == M) break;
			Va.emplace_back(pii(i, j), 1000000000);
		}
		if (Va.size() == M) break;
	}

	for (auto it : Va) printf("%d %d %d\n", it.first.first, it.first.second, it.second);
	return 0;
}
//*/