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
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-9;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

char DB1[105] = "What are you doing at the end of the world? Are you busy? Will you save us?";
char DB2[105] = "What are you doing while sending \"@\"? Are you busy? Will you send \"@\"?";
int L1, L2;
ll dp[100050];
char aa(int N, ll K) {
	if (N == 0) return DB1[K];

	for (int i = 0; i < L2; i++) {
		if (DB2[i] == '@') {
			if (K < dp[N - 1]) return aa(N - 1, K);
			K -= dp[N - 1];
		}
		else {
			if (K == 0) return DB2[i];
			K--;
		}
	}
	return '.';
}

int main() {
	L1 = strlen(DB1);
	L2 = strlen(DB2);
	int i, j;
	dp[0] = L1;
	for (i = 1; i <= 100000; i++) dp[i] = min(2 * dp[i - 1] + L2 - 2, LL_INF);

	int T;
	scanf("%d", &T);
	while (T--) {
		int N;
		ll K;
		scanf("%d %lld", &N, &K);
		if (dp[N] < K) printf(".");
		else printf("%c", aa(N, K - 1));
	}
	return 0;
}