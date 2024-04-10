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

pii in[105];
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d %d", &in[i].first, &in[i].second);
	sort(in + 1, in + N + 1);

	int lcnt, rcnt;
	for (i = 1; i <= N; i++) if (in[i].first > 0) break;
	lcnt = i - 1;
	rcnt = N - lcnt;
	if (lcnt <= rcnt) {
		int ans = 0;
		for (i = 1; i <= lcnt; i++) ans += in[i].second;
		for (i = lcnt + 1; i <= 2 * lcnt; i++) ans += in[i].second;
		if (lcnt != rcnt) ans += in[i].second;
		printf("%d", ans);
	}
	else {
		int ans = 0;
		for (i = lcnt + 1; i <= lcnt+rcnt; i++) ans += in[i].second;
		for (i = lcnt; i >= lcnt - rcnt; i--) ans += in[i].second;
		printf("%d", ans);
	}
	return 0;
}