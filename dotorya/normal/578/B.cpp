//*
#include <algorithm>
#include <ctype.h>
#include <functional>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <char, int> pci;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX;
const int MOD = 9901;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;

ll in[200050];
ll s1[200050];
ll s2[200050];
int main() {
	int N, K, X, i, j;
	scanf("%d %d %d", &N, &K, &X);
	for (i = 1; i <= N; i++) scanf("%lld", &in[i]);

	for (i = 1; i <= N; i++) s1[i] = (s1[i - 1] | in[i]);
	for (i = N; i >= 1; i--) s2[i] = (s2[i + 1] | in[i]);

	ll ans = 0;
	for (i = 1; i <= N; i++) {
		ll t = in[i];
		for (j = 1; j <= K; j++) t *= X;
		ans = max(ans, (t | s1[i - 1]) | s2[i + 1]);
	}
	printf("%lld", ans);
	return 0;
}
//*/