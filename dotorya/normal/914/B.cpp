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

int IT_MAX = 1 << 20;
ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int in[100050];
int dp[100050];

set <int> Sx;
int c = 0;
int sum[100050];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);
	sort(in + 1, in + N + 1);

	dp[N + 1] = 0;

	int st, en;
	for (i = N; i >= 1; i = st-1) {
		en = i;
		for (j = en; j >= 1; j--) if (in[j] != in[en]) break;
		st = j + 1;
		for (j = en; j >= st; j--) {
			if (c) dp[j] = 1;
			else dp[j] = !dp[j + 1];
		}
		if (!dp[st + 1]) c = 1;
	}
	if (dp[1]) printf("Conan\n");
	else printf("Agasa\n");
}
//*/