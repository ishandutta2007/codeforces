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
#include <string>
#include <time.h>
#include <vector>
//#include <unordered_set>
//#include <unordered_map>

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

int IT_MAX = 262144;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-11;

vector <pii> in[2050];
ll sum[2050][2050];
pii chk[8000050];
inline int ch(pii a, pii b) {
	if (a > b) swap(a, b);
	if (a.first != b.first) return a.first * 2000 + a.second;
	else return 4000000 + a.first * 2000 + a.second;
}

bool lchk[2050];

vector <int> V[2050];
int main() {
	int N, M, K, Q, t1, t2, t3, t4, i, j, k;
	scanf("%d %d %d", &N, &M, &K);
	for (i = 1; i <= K; i++) {
		scanf("%d", &k);
		for (j = 0; j < k; j++) {
			scanf("%d %d %d", &t1, &t2, &t3);
			t1--, t2--;
			in[i].emplace_back(t1, t2);
			sum[i][j] = t3;
			if (j != 0) sum[i][j] += sum[i][j - 1];
		}
		for (j = 0; j + 1 < k; j++) chk[ch(in[i][j], in[i][j + 1])] = pii(i, j);
	}

	for (i = 1; i <= K; i++) lchk[i] = true;
	char c[10];
	scanf("%d", &Q);
	for(i = 1; i <= Q; i++) {
		scanf("%s", c);
		if (c[0] == 'S') {
			scanf("%d", &t1);
			lchk[t1] = !lchk[t1];
			continue;
		}

		for (j = 1; j <= K; j++) V[j].clear();
		scanf("%d %d %d %d", &t1, &t2, &t3, &t4);
		t1--, t2--, t3--, t4--;

		if (t1 != 0) {
			for (j = t2; j <= t4; j++) {
				pii u = chk[ch(pii(t1 - 1, j), pii(t1, j))];
				if (u.first != 0) V[u.first].push_back(u.second);
			}
		}
		if (t2 != 0) {
			for (j = t1; j <= t3; j++) {
				pii u = chk[ch(pii(j, t2 - 1), pii(j, t2))];
				if (u.first != 0) V[u.first].push_back(u.second);
			}
		}
		if (t3 != N-1) {
			for (j = t2; j <= t4; j++) {
				pii u = chk[ch(pii(t3, j), pii(t3 + 1, j))];
				if (u.first != 0) V[u.first].push_back(u.second);
			}
		}
		if (t4 != M-1) {
			for (j = t1; j <= t3; j++) {
				pii u = chk[ch(pii(j, t4), pii(j, t4+1))];
				if (u.first != 0) V[u.first].push_back(u.second);
			}
		}

		ll ans = 0;
		for (j = 1; j <= K; j++) {
			if (!lchk[j]) continue;
			V[j].push_back(in[j].size() - 1);
			sort(V[j].begin(), V[j].end());

			pii u = in[j][0];
			int st = 0;
			if (u.first >= t1 && u.first <= t3 && u.second >= t2 && u.second <= t4) {
				ans += sum[j][V[j][0]];
				st = 1;
			}
			for (; st + 1 < V[j].size(); st += 2) ans += sum[j][V[j][st + 1]] - sum[j][V[j][st]];
		}
		printf("%lld\n", ans);
	}
	return 0;
}