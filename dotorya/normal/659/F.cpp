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
#include <unordered_set>
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

int IT_MAX = 1 << 17;
const ll MOD = 987654321;
const int INF = 1034567890;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

int in[1050][1050];
bool chk[1050][1050];
bool dchk[1050][1050];
int sz[1000050];
int r[1000050];
int root(int x) {
	return (r[x] == x) ? x : (r[x] = root(r[x]));
}
vector <pii> V;
set <pii> Sx;

int P[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
int main() {

	int N, M, i, j, k;
	ll K;
	scanf("%d %d %lld", &N, &M, &K);
	//	for (i = 0; i < N; i++) for (j = 0; j < M; j++) sz[i*M + j] = 1;
	for (i = 0; i < N; i++) for (j = 0; j < M; j++) r[i*M + j] = i*M + j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%d", &in[i][j]);
			V.push_back(pii(in[i][j], i*M + j));
		}
	}
	sort(V.begin(), V.end());
	for (i = V.size() - 1; i >= 0; i--) {
		if (i != V.size() - 1 && V[i].first != V[i + 1].first) Sx.clear();
		int t = V[i].second;
		int x = V[i].second / M, y = V[i].second%M;
		chk[x][y] = true;
		sz[x*M + y] = 1;
		int r1 = root(t);
		for (j = 0; j < 4; j++) {
			int tx = x + P[j][0], ty = y + P[j][1];
			if (tx < 0 || tx >= N || ty < 0 || ty >= M) continue;
			if (!chk[tx][ty]) continue;

			int r2 = root(tx*M + ty);
			if (r1 != r2) {
				r[r2] = r1;
				Sx.erase(pii(sz[r2], r2));
				sz[r1] += sz[r2];
				sz[r2] = 0;
			}
		}
		Sx.insert(pii(sz[x*M + y], x*M + y));
		
		auto it = Sx.end();
		it--;
		if ((K / V[i].first) > it->first) continue;
		if (K % V[i].first == 0) {
			t = K / V[i].first;
			V.clear();
			x = it->second / M;
			y = it->second % M;
			V.push_back(pii(x, y));
			dchk[x][y] = true;
			for (i = 0; i < t; i++) {
				if (V.size() == t) break;
				pii u = V[i];
				for (j = 0; j < 4; j++) {
					pii u2 = pii(u.first + P[j][0], u.second + P[j][1]);
					if (u2.first < 0 || u2.first >= N || u2.second < 0 || u2.second >= M) continue;
					if (!chk[u2.first][u2.second] || dchk[u2.first][u2.second]) continue;
					V.push_back(u2);
					dchk[u2.first][u2.second] = true;
					if (V.size() == t) break;
				}
				if (V.size() == t) break;
			}
			printf("YES\n");
			for (i = 0; i < N; i++) {
				for (j = 0; j < M; j++) {
					if (dchk[i][j]) printf("%lld ", K / t);
					else printf("0 ");
				}
				printf("\n");
			}
			return 0;
		}
	}
	return !printf("NO\n");
}
//*/