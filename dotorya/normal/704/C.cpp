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
#include <unordered_map>

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

int IT_MAX = 1 << 21;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-12;

vector <pii> E;
vector <int> conn[100050];
int cnt[100050][2];

vector <int> V;

vector <int> V2;
int dp1[100050][2][2][2];
int val[100050];
int dis[100050];

vector <pii> dpv;
ll dp2[100050][2];
int main() {
	int N, M, i, j, k, l, m, o, t1, t2, t3;

	int fuv = 1;
	scanf("%d %d", &M, &N);
	for(i = 0; i < M; i++) { 
		scanf("%d %d", &t1, &t2);
		if (t1 == 1) t3 = t2;
		else scanf("%d", &t3);

		if (abs(t2) != abs(t3)) {
			E.emplace_back(t2, t3);
			conn[abs(t2)].push_back(E.size()-1);
			conn[abs(t3)].push_back(E.size()-1);
		}
		else if (t2 != t3) fuv = 1 - fuv;
		else if (t2 > 0) cnt[t2][0]++;
		else cnt[-t2][1]++;
	}
	for (i = 1; i <= N; i++) cnt[i][0] %= 2, cnt[i][1] %= 2;

	fill(dis + 1, dis + N + 1, INF);
	for (i = 1; i <= N; i++) {
		if (dis[i] != INF) continue;
		if (conn[i].size() == 0) {
			pii u = pii(0, 0);
			if (cnt[i][0] % 2 == 0) u.first++;
			else u.second++;

			if (cnt[i][1] % 2 == 0) u.first++;
			else u.second++;

			dpv.push_back(u);
			continue;
		}

		dis[i] = 0;
		V.push_back(i);
		for (j = 0; j < V.size(); j++) {
			for (auto it : conn[V[j]]) {
				int t = abs(E[it].first) + abs(E[it].second) - V[j];
				if (dis[t] == INF) {
					dis[t] = dis[V[j]] + 1;
					V.push_back(t);
				}
			}
		}
		int s = V.back();
		for (auto it : V) dis[it] = INF;
		V.clear();
		
		dis[s] = 0;
		V.push_back(s);
		V2.push_back(s);
		for (j = 0; j < V.size(); j++) {
			for (k = 0; k < conn[V[j]].size(); k++) {
				if (j == 0 && k == 1) continue;
				auto it = conn[V[j]][k];
				int t = abs(E[it].first) + abs(E[it].second) - V[j];
				if (dis[t] == INF) {
					dis[t] = dis[V[j]] + 1;
					V.push_back(t);

					V2.push_back(t);
					pii u = E[it];
					if (abs(u.first) != V[j]) swap(u.first, u.second);
					int d = dis[V[j]];
					val[d] = 0;
					if (u.first < 0) val[d] += 2;
					if (u.second < 0) val[d] += 1;
				}
			}
		}
		V.clear();

		for (j = 0; j < V2.size(); j++) for (k = 0; k < 2; k++) for (l = 0; l < 2; l++) for (m = 0; m < 2; m++) dp1[j][k][l][m] = 0;
		dp1[0][0][0][cnt[V2[0]][0]] = 1;
		dp1[0][1][1][cnt[V2[0]][1]] = 1;

		for (j = 0; j + 1 < V2.size(); j++) {
			for (k = 0; k < 2; k++) {
				for (l = 0; l < 2; l++) {
					for (m = 0; m < 2; m++) {
						for (o = 0; o < 2; o++) {
							int v = 2 * l + o;
							int v2 = (m + cnt[V2[j+1]][o]) % 2;
							if (val[j] + v != 3) v2 = (v2 + 1) % 2;
							dp1[j + 1][k][o][v2] += dp1[j][k][l][m];
							dp1[j + 1][k][o][v2] %= MOD;
						}
					}
				}
			}
		}
		pii u = pii(0, 0);
		if (conn[V2[0]].size() == 2) u = E[conn[V2[0]][1]];
		if (abs(u.first) != V2[0]) swap(u.first, u.second);
		int tv = 0;
		if (u.first < 0) tv += 2;
		if (u.second < 0) tv += 1;

		int tcnt[2] = { 0,0 };
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 2; k++) {
				for (l = 0; l < 2; l++) {
					int v = 2 * j + k;
					int v2 = l;
					if (u.first != 0 && v + tv != 3) v2 = (v2 + 1) % 2;
					tcnt[v2] = (tcnt[v2] + dp1[V2.size()-1][j][k][l]) % MOD;
				}
			}
		}
		dpv.emplace_back(tcnt[0], tcnt[1]);
		V2.clear();
	}

	dp2[0][0] = dpv[0].first;
	dp2[0][1] = dpv[0].second;
	for (i = 1; i < dpv.size(); i++) {
		dp2[i][0] = (dp2[i - 1][0] * dpv[i].first + dp2[i - 1][1] * dpv[i].second) % MOD;
		dp2[i][1] = (dp2[i - 1][1] * dpv[i].first + dp2[i - 1][0] * dpv[i].second) % MOD;
	}
	printf("%lld\n", dp2[dpv.size() - 1][fuv]);
	return 0;
}