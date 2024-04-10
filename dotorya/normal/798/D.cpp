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

pair<pii, int> in[100050];

bool chk[100050];
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i].first.first);
	for (i = 1; i <= N; i++) scanf("%d", &in[i].first.second);
	for (i = 1; i <= N; i++) in[i].second = i;

	sort(in + 1, in + N + 1);

	int t = N - 1;
	if (N % 2 == 0) t = N - 2;
	for (i = 1; i <= t; i += 2) {
		if (in[i].first.second < in[i + 1].first.second) chk[in[i].second] = true;
		else chk[in[i + 1].second] = true;
	}
	printf("%d\n", N / 2 + 1);
	for (i = 1; i <= N; i++) if (!chk[i]) printf("%d ", i);
	return !printf("\n");
}