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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-13;

ldb sum1[200050];
ldb sum2[200050];
ldb in[200050];
ldb dp[200050][2];

vector <pdd> V;

int ccw(pdd u1, pdd u2, pdd u3) {
	ldb x = (u2.first - u1.first) * (u3.second - u1.second) - (u3.first - u1.first)*(u2.second - u1.second);
	if (x > ERR) return 1;
	else if (x < -ERR) return -1;
	else return 0;
}
int main() {
	int N, K, i, j, t;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) {
		scanf("%d", &t);
		in[i] = t;
		sum1[i] = sum1[i - 1] + in[i];
		sum2[i] = sum2[i - 1] + 1.0 / in[i];
	}

	int st = 0;
	for (j = 1; j < K; j++) {
		V.emplace_back(0, 0);
		st = 0;
		for (i = 1; i <= N; i++) {
			while ((int)V.size() >= st + 2) {
				if (V[st].first*sum2[i] + V[st].second > V[st + 1].first*sum2[i] + V[st + 1].second) break;
				st++;
			}
			dp[i][j%2] = V[st].first*sum2[i] + V[st].second;

			while ((int)V.size() >= st + 2) {
				pdd u1 = pdd(sum1[i], dp[i][1-j%2] - sum1[i] * sum2[i]);
				pdd u2 = V[V.size() - 1];
				pdd u3 = V[V.size() - 2];
				if (ccw(u3, u2, u1) == -1) break;
				V.pop_back();
			}
			V.emplace_back(sum1[i], dp[i][1-j%2] - sum1[i] * sum2[i]);
		}
		V.clear();
	}

	ldb ans = 0;
	for (i = 2; i <= N; i++) ans += sum1[i - 1] / in[i];
	return !printf("%.20lf\n", (db)(ans - dp[N][(K-1)%2] + N));
}