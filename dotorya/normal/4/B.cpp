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

int in[105][2];
int ans[105];
int main() {
	int N, S, i, j;
	scanf("%d %d", &N, &S);
	for (i = 1; i <= N; i++) scanf("%d %d", &in[i][0], &in[i][1]);

	int s1 = 0, s2 = 0;
	for (i = 1; i <= N; i++) {
		s1 += in[i][0];
		s2 += in[i][1];
	}
	if (s1 > S || s2 < S) return !printf("NO\n");

	S -= s1;
	for (i = 1; i <= N; i++) ans[i] = in[i][0];
	for (i = 1; i <= N; i++) {
		int t = min(S, in[i][1] - in[i][0]);
		ans[i] += t;
		S -= t;
	}
	printf("YES\n");
	for (i = 1; i <= N; i++) printf("%d ", ans[i]);
	return !printf("\n");
}