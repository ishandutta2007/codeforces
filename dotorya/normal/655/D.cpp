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
const ll MOD = 987654321;
const int INF = 1034567891;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-12;

map <pii, int> Mx;

vector <int> out[100050];
int in[100050];
int dp[100050];
int rev[100050];

vector <int> V;
int main() {
	int N, M, i, t1, t2;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++) {
		scanf("%d %d", &t1, &t2);
		Mx[pii(t1, t2)] = i;
		out[t1].push_back(t2);
		in[t2]++;
	}

	for (i = 1; i <= N; i++) if (in[i] == 0) V.push_back(i);
	for (i = 0; i < V.size(); i++) {
		dp[V[i]]++;
		for (auto it : out[V[i]]) {
			if (dp[V[i]] >= dp[it]) {
				rev[it] = V[i];
				dp[it] = dp[V[i]];
			}
			in[it]--;
			if (in[it] == 0) V.push_back(it);
		}
	}
	if (dp[V.back()] != N) return !printf("-1\n");

	int ans = 0;
	int t = V.back();
	while (rev[t] != 0) {
		ans = max(ans, Mx[pii(rev[t], t)]);
		t = rev[t];
	}
	printf("%d\n", ans);
	return 0;
}