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

char in[300050];
vector <int> conn[300050];
int inc[300050];
int dp[300050];
vector <int> Vl;
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	scanf("%s", in + 1);
	for (i = 1; i <= M; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		inc[t2]++;
	}
	for (i = 1; i <= N; i++) if (!inc[i]) Vl.push_back(i);
	for (i = 0; i < Vl.size(); i++) {
		for (auto it : conn[Vl[i]]) {
			if (--inc[it] == 0) Vl.push_back(it);
		}
	}
	if (Vl.size() != N) return !printf("-1\n");

	int ans = 0;
	for (i = 0; i < 26; i++) {
		for (j = 1; j <= N; j++) dp[j] = 0;
		for (auto it : Vl) {
			if (i + 'a' == in[it]) dp[it]++;
			for (auto it2 : conn[it]) dp[it2] = max(dp[it2], dp[it]);
			ans = max(ans, dp[it]);
		}
	}
	return !printf("%d\n", ans);
}
//*/