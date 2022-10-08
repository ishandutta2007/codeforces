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
const int INF = 0x1f3f3f3f;
const ll LL_INF = 1034567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

int in[1000050];
int lr[1000050][2];
bool chk[1000050];
int totc;
void lpop(int x) {
	lr[lr[x][0]][1] = lr[x][1];
	lr[lr[x][1]][0] = lr[x][0];
	chk[x] = true;
	totc--;
}

int u[1000050];
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);

	for (i = 1; i <= N; i++) u[i] = i;
	sort(u + 1, u + N + 1, [](int a, int b) { return in[a] < in[b]; });
	
	for (i = 1; i < N; i++) {
		lr[i][1] = i + 1;
		lr[i + 1][0] = i;
	}
	lr[1][0] = N, lr[N][1] = 1;

	ll ans = 0;
	totc = N;
	for (i = 1; i <= N; i++) {
		int t = u[i];
		if (chk[t]) continue;

		int l = t;
		do {
			l = lr[l][0];
		} while (l != t && in[l] <= in[t]);

		int r = t;
		do {
			r = lr[r][1];
		} while (r != t && in[r] <= in[t]);

		if (l == r) {
			ans += (ll)totc * (totc - 1) / 2;
			break;
		}
		
		int c = 0;
		for (l = lr[l][1]; l != r; l = lr[l][1]) {
			c++;
			lpop(l);
		}
		ans += (ll)c * (c - 1) / 2 + 2 * c;
	}
	return !printf("%lld\n", ans);
}