#include <algorithm>
#include <assert.h>
#include <bitset>
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
#include <string>
#include <time.h>
#include <cmath>
#include <vector>
#include <deque>
//#include <unordered_set>
#include <unordered_map>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
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

int IT_MAX = 1 << 20;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-6;

class Node {
public:
	set <pii> Sx1;
	set <int> Sx2;
} it[300050];

void update(int st, int en, int S, int E, int n, pii v) {
	if (st == S && en == E) {
		it[n].Sx1.insert(v);
		it[n].Sx2.insert(v.second);
		return;
	}

	int M = (S + E) / 2;
	if (en <= M) update(st, en, S, M, 2 * n, v);
	else if (st > M) update(st, en, M + 1, E, 2 * n + 1, v);
	else {
		update(st, M, S, M, 2 * n, v);
		update(M + 1, en, M + 1, E, 2 * n + 1, v);
	}
}
int getv(int x, int h) {
	int rv = 0;
	int n = x + IT_MAX - 1;
	for(; n; n /= 2) {
		while (!it[n].Sx1.empty()) {
			auto u = it[n].Sx1.begin();
			if (u->first > h) break;
			it[n].Sx2.erase(u->second);
			it[n].Sx1.erase(u);
		}
		if (it[n].Sx1.empty()) continue;
		auto u = it[n].Sx2.end();
		u--;
		rv = max(rv, *u);
	}
	return rv;
}

pair<pii, pii> in[100050];
int nxt[100050][2];
ll cnt[100050];
int main() {
	int H, W, N, i;
	scanf("%d %d %d", &H, &W, &N);
	for (i = 1; i <= N; i++) {
		scanf("%d %d %d %d", &in[i].first.first, &in[i].first.second, &in[i].second.first, &in[i].second.second);
	}
	for (IT_MAX = 2; IT_MAX <= W; IT_MAX *= 2);

	sort(in + 1, in + N + 1);
	for (i = 1; i <= N; i++) {
		int u = in[i].first.first;
		int l = in[i].first.second;
		int r = in[i].second.first;
		int s = in[i].second.second;
		nxt[i][0] = getv((l == 1) ? r + 1 : l - 1, u);
		nxt[i][1] = getv((r == W) ? l - 1 : r + 1, u);
		update(l, r, 1, IT_MAX, 1, pii(u + s + 1, i));
	}

	for (i = 1; i <= W; i++) {
		int p = getv(i, H + 1);
		cnt[p]++;
	}
	for (i = N; i >= 1; i--) {
		cnt[i] %= MOD;
		cnt[nxt[i][0]] += cnt[i];
		cnt[nxt[i][1]] += cnt[i];
	}
	return !printf("%lld\n", cnt[0] % MOD);
}