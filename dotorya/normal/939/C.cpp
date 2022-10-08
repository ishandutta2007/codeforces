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

int IT_MAX = 1 << 18;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

ll in[100050];
ll sum[100050];
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%lld", &in[i]);
		sum[i] = sum[i - 1] + in[i];
	}
	
	int S, F;
	scanf("%d %d", &S, &F);

	ll mx = -1, ans = 0;
	for (i = 1; i <= N; i++) {
		int st = S - i + 1, en = F - i;
		while (st < 1) {
			st += N;
			en += N;
		}

		ll v;
		if (en <= N) v = sum[en] - sum[st - 1];
		else v = sum[en - N] + sum[N] - sum[st - 1];
		if (mx < v) {
			mx = v;
			ans = i;
		}
	}
	return !printf("%lld\n", ans);
}