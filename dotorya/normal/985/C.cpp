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
//#include <unordered_map>
//#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")

using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()

//typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18; // segment tree size
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f; // memset(dp, 0x3f, sizeof(dp)), 2*INF < INT_MAX
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10; // double EPS

ll in[100050];
int main() {
	ll N, K, L, i, j;
	scanf("%lld %lld %lld", &N, &K, &L);
	for (i = 1; i <= N*K; i++) scanf("%lld", &in[i]);
	sort(in + 1, in + N*K + 1);

	int c = 0;
	for (i = 1; i <= N*K; i++) if (in[i] - in[1] <= L) c++;
	if (c < N) return !printf("0\n");

	vector <int> Vl;
	Vl.push_back(1);
	for (i = N-1; i >= 1; i--) {
		ll t = Vl.back() + K;
		if (t >= c - i + 1) {
			for (j = c - i + 1; j <= c; j++) Vl.push_back(j);
			break;
		}
		else Vl.push_back(t);
	}

	ll ans = 0;
	for (auto it : Vl) ans += in[it];
	return !printf("%lld\n", ans);
}