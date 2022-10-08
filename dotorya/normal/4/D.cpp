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

pair<pii, int> in[5050];
int dp[5050];
int rev[5050];
int main() {
	int N, W, H, i, j;
	scanf("%d %d %d", &N, &W, &H);
	for (i = 1; i <= N; i++) {
		scanf("%d %d", &in[i].first.first, &in[i].first.second);
		in[i].second = i;
	}
	sort(in + 1, in + N + 1);
	for (i = N; i >= 1; i--) {
		rev[i] = -1;
		dp[i] = 1;
		for (j = i + 1; j <= N; j++) {
			if (in[j].first.first > in[i].first.first && in[j].first.second > in[i].first.second) {
				if (dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
					rev[i] = j;
				}
			}
		}
	}

	int ans = 0, t = 0;
	for (i = 1; i <= N; i++) {
		if (W >= in[i].first.first || H >= in[i].first.second) continue;
		if (ans < dp[i]) {
			ans = dp[i];
			t = i;
		}
	}
	printf("%d\n", ans);
	if (!ans) return 0;

	while (t != -1) {
		printf("%d ", in[t].second);
		t = rev[t];
	}
	return !printf("\n");
}