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
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;

const int IT_MAX = 131072;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;

ll in[200050];
int main() {
	int N, i;
	ll W;
	scanf("%d %I64d", &N, &W);
	for (i = 1; i <= 2 * N; i++) scanf("%I64d", &in[i]);
	sort(in + 1, in + 2 * N + 1);

	double ans = 0;
	if (in[1] * 2 <= in[N + 1]) ans = 3 * N*in[1];
	else ans = 3.0*N*in[N + 1] / 2;
	printf("%.20lf", min(ans, (double)W));
	return 0;
}