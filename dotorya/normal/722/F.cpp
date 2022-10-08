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
const db PI = 3.141592653589793238;
const ldb ERR = 1E-11;

vector <int> Vp[100050];
vector <int> in[100050];

bool vlist[50][50][13][50];
int plist[12] = { 32,27,25,7,11,13,17,19,23,29,31,37 };

int dp[100050];
int tot2[100050];
int tot[100050];

vector <int> Vu[100050];
int main() {
	int N, M, i, j, k, l, m, t1, t2;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		scanf("%d", &t1);
		while (t1--) {
			scanf("%d", &t2);
			in[i].push_back(t2);
			Vp[t2].push_back(i);
		}
	}

	for (i = 1; i <= 40; i++) {
		for (j = 0; j < i; j++) {
			for (k = 0; k < 12; k++) {
				for (m = 0; m < plist[k]; m++) {
					int t = i*m + j;
					vlist[i][j][k][t%plist[k]] = true;
				}
			}
		}
	}

	for (i = 1; i <= M; i++) {
		unique(Vp[i].begin(), Vp[i].end());
		int mn = N;
		for (j = 0; j < Vp[i].size(); j++) {
			for (k = 0; k < in[Vp[i][j]].size(); k++) if (in[Vp[i][j]][k] == i) Vu[j].push_back(k);
		}

		for (j = 0; j < Vp[i].size(); j++) tot2[j] = INF;
		for (j = 0; j < 12; j++) {
			fill(tot, tot + Vp[i].size(), 0);
			for (k = 0; k < plist[j]; k++) {
				for (l = 0; l < Vp[i].size(); l++) {
					for (m = 0; m < Vu[l].size(); m++) if (vlist[in[Vp[i][l]].size()][Vu[l][m]][j][k]) break;
					if (m >= Vu[l].size()) dp[l] = 0;
					else if (l == 0 || Vp[i][l] != Vp[i][l - 1] + 1) dp[l] = 1;
					else dp[l] = dp[l - 1] + 1;
					tot[l] = max(tot[l], dp[l]);
				}
			}
			for (k = 0; k < Vp[i].size(); k++) tot2[k] = min(tot2[k], tot[k]);
		}
		int ans = 0;
		for (j = 0; j < Vp[i].size(); j++) ans = max(ans, tot2[j]);
		printf("%d\n", ans);
		for (j = 0; j < Vp[i].size(); j++) Vu[j].clear();
	}
	return 0;
}