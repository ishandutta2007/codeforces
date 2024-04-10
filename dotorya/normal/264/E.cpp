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
#include <cmath>
#include <vector>
#include <deque>
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

int IT_MAX = 1<<19;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-10;

int it[2][1100000];
void update(int x, int p, int v) {
	p += IT_MAX;
	it[x][p] = v;
	for (p /= 2; p; p /= 2) it[x][p] = max(it[x][2 * p], it[x][2 * p + 1]);
}
int getmx(int x, int p1, int p2) {
	p1 += IT_MAX;
	p2 += IT_MAX;
	int rv = 0;
	while (p1 <= p2) {
		if(p1%2 == 1) rv = max(rv, it[x][p1++]);
		if (p2 % 2 == 0) rv = max(rv, it[x][p2--]);
		p1 /= 2, p2 /= 2;
	}
	return rv;
}

set <int> Sx;

int in[200050][3];
int dp[200050];
int H[200050];
int chk[200050];
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++) {
		scanf("%d %d", &in[i][0], &in[i][1]);
		if (in[i][0] == 1) {
			scanf("%d", &in[i][2]);
			in[i][2] += M - i;
			H[in[i][1]] = in[i][2];
		}
	}

	for (i = 1; i <= M; i++) {
		if (in[i][0] == 1) {
			vector <int> V;
			for (j = i - 1; j >= i - 10 && j >= 1; j--) {
				if (in[j][0] == 2) {
					chk[in[j][1]] = i;
					continue;
				}
				if (in[j][2] >= in[i][2] || chk[in[j][1]] == i) continue;

				V.push_back(in[j][1]);
				update(0, in[j][2], 0);
				update(1, in[j][1], 0);
			}
			dp[in[i][1]] = 1 + getmx(1, in[i][1] + 1, N);
			update(0, in[i][2], dp[in[i][1]]);
			update(1, in[i][1], dp[in[i][1]]);

			sort(V.begin(), V.end());
			for (j = V.size() - 1; j >= 0; j--) {
				int t = V[j];
				if (t < in[i][1]) dp[t] = max(dp[t], dp[in[i][1]] + 1);
				for (int k = j + 1; k < V.size(); k++) if (H[t] < H[V[k]]) dp[t] = max(dp[t], dp[V[k]] + 1);
				update(0, H[t], dp[t]);
				update(1, t, dp[t]);
			}
			Sx.insert(in[i][1]);
		}
		else {
			vector <int> V;
			while (V.size() < in[i][1]) {
				auto it = Sx.begin();
				V.push_back(*it);
				Sx.erase(*it);

				int t = V.back();
				update(0, H[t], 0);
				update(1, t, 0);
			}
			in[i][1] = V.back();
			V.pop_back();
			
			while (!V.empty()) {
				int t = V.back();
				V.pop_back();
				Sx.insert(t);

				dp[t] = getmx(0, H[t] + 1, IT_MAX - 1) + 1;
				update(0, H[t], dp[t]);
				update(1, t, dp[t]);
			}
		}
		printf("%d\n", getmx(1, 1, N));
	}
	return 0;
}