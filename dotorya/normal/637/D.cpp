#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#pragma warning(disable:4996)
using namespace std;

#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 2034567891;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

int in[200050];
int dp[200050];
int sum[200050];
int rev[200050];

vector <int> ans;
int main() {
	int N, M, S, D, i;
	scanf("%d %d %d %d", &N, &M, &S, &D);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);
	sort(in + 1, in + N + 1);
	in[0] = -1;
	in[N+1] = INF;
	
	if (in[1] <= S) return !printf("IMPOSSIBLE\n");
	dp[0] = 1;
	sum[0] = 1;
	for (i = 1; i <= N; i++) {
		if (in[i + 1] - 1 - in[i] - 1 < S) {
			sum[i] = sum[i - 1];
			continue;
		}

		int st = 0, en = i - 1, mi, rv = i;
		while (st <= en) {
			mi = (st + en) / 2;
			if (in[i] + 1 - in[mi + 1] - 1 <= D) {
				rv = mi;
				en = mi - 1;
			}
			else st = mi + 1;
		}

		st = rv, en = i - 1, mi, rv = -1;
		while (st <= en) {
			mi = (st + en) / 2;
			if (sum[i - 1] - ((mi == 0)? 0 : sum[mi - 1]) != 0) {
				rv = mi;
				st = mi + 1;
			}
			else en = mi - 1;
		}
		if (rv == -1 || in[i] + 1 - in[rv+1] + 1 > D) {
			sum[i] = sum[i - 1];
			continue;
		}
		
		dp[i] = 1;
		rev[i] = rv;
		sum[i] = sum[i - 1] + 1;
	}
	if (dp[N] == 0) return !printf("IMPOSSIBLE\n");

	int p = N;
	while (p != 0) {
		ans.push_back(p);
		p = rev[p];
	}
	ans.push_back(0);
	reverse(ans.begin(), ans.end());

	int st = 0;
	for (i = 0; i + 1 < ans.size(); i++) {
		printf("RUN %d\n", in[ans[i] + 1] - 1 - st);
		printf("JUMP %d\n", in[ans[i + 1]] + 1 - in[ans[i] + 1] + 1);
		st = in[ans[i + 1]] + 1;
	}
	if (in[ans.back()] != M - 1) printf("RUN %d\n", M - 1 - in[ans.back()]);
	return 0;
}