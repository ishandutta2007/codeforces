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
#pragma comment(linker, "/STACK:1048576")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple <int, int, int> t3;

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

vector <int> in[100050];
int dp[100050];
int mx[100050];
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		in[i].resize(M + 2);
		for (j = 1; j <= M; j++) scanf("%d", &in[i][j]);
	}

	for (j = 1; j <= M; j++) {
		dp[N] = N;
		for (i = N - 1; i >= 1; i--) {
			if (in[i][j] <= in[i + 1][j]) dp[i] = dp[i + 1];
			else dp[i] = i;
		}
		for (i = 1; i <= N; i++) mx[i] = max(mx[i], dp[i]);
	}

	int Q;
	scanf("%d", &Q);
	while (Q--) {
		scanf("%d %d", &i, &j);
		if (mx[i] >= j) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}