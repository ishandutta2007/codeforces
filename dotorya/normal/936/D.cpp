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

pii in[1000050];
int dp[1000050][2][2][8];
char rev[1000050][2][2][8];
bool Conflicts(int x, int y) {
	if (x <= 0 || y <= 0) return false;
	pii u1 = in[x], u2 = in[y];
	if (u1.first == u2.first) return true;
	if (abs(u1.first - u2.first) == 1 && u1.second != u2.second) return true;
	return false;
}

set <int> Sx[3];

vector <pii> Vp;
int main() {
	int N, M1, M2, T, i, j, k, l, m, M;
	scanf("%d", &N);
	scanf("%d %d %d", &M1, &M2, &T);
	M = M1 + M2;
	for (i = 1; i <= M1; i++) {
		scanf("%d", &in[i].first);
		in[i].second = 1;
		Sx[1].insert(in[i].first);
	}
	for (i = M1 + 1; i <= M; i++) {
		scanf("%d", &in[i].first);
		in[i].second = 2;
		Sx[2].insert(in[i].first);
	}
	sort(in + 1, in + M + 1);

	memset(dp, 0x3f, sizeof(dp));
	dp[0][0][0][0] = 0;
	in[0].first = 1;
	for (i = 0; i < M; i++) {
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 2; k++) {
				for (l = 0; l < 8; l++) {
					if (dp[i][j][k][l] >= in[i].first) continue;

					pii u = in[i + 1];
					
					for (m = 0; m < 3; m++) if (l & (1 << m)) if (Conflicts(i + 1, i - m)) break;
					if (m >= 3) {
						int ni = i + 1, nj = j, nk = k, nl = (l * 2 + 1) & 7;
						if (u.second == 1) nj = 1;
						else nk = 1;
						if (dp[ni][nj][nk][nl] > dp[i][j][k][l]) {
							dp[ni][nj][nk][nl] = dp[i][j][k][l];
							rev[ni][nj][nk][nl] = j * 16 + k * 8 + l;
						}
					}

					int vu = j;
					if (u.second == 2) vu = k;

					int tx = dp[i][j][k][l] + T;
					if (vu == 1) {
						auto it = Sx[u.second].lower_bound(u.first);
						if (it != Sx[u.second].begin()) {
							it--;
							tx = max(tx, *it + 1);
						}
					}
					
					int ni = i + 1, nj = j, nk = k, nl = (l * 2) & 7;
					if (u.second == 1) nj = 0;
					else nk = 0;
					if (dp[ni][nj][nk][nl] > tx) {
						dp[ni][nj][nk][nl] = tx;
						rev[ni][nj][nk][nl] = 32 + j * 16 + k * 8 + l;
					}
				}
			}
		}
	}

	int a1 = M, a2 = -1, a3 = -1, a4 = -1;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 8; k++) {
				if (dp[M][i][j][k] >= in[M].first) continue;
				a2 = i, a3 = j, a4 = k;
				break;
			}
			if (a2 >= 0) break;
		}
		if (a2 >= 0) break;
	}
	if (a2 < 0) return !printf("No\n");

	vector <int> Va1;
	vector <pii> Va2;
	while (a1) {
		int x = rev[a1][a2][a3][a4];
		
		int tu = (x >> 5);
		int na2 = (x >> 4) & 1;
		int na3 = (x >> 3) & 1;
		int na4 = x & 7;

		if (tu) {
			Va2.emplace_back(dp[a1][a2][a3][a4], in[a1].second);
			Sx[in[a1].second].erase(in[a1].first);
			Vp.emplace_back(dp[a1][a2][a3][a4], in[a1].second);
		}
		a1--;
		a2 = na2;
		a3 = na3;
		a4 = na4;
	}
	reverse(all(Va2));
	for (auto it : Sx[1]) Vp.emplace_back(it - 1, 2);
	for (auto it : Sx[2]) Vp.emplace_back(it - 1, 1);
	sort(all(Vp));

	int lan = 1;
	for (auto it : Vp) {
		if (lan != it.second) {
			Va1.push_back(it.first);
			lan = 3 - lan;
		}
	}

	printf("Yes\n");
	printf("%d\n", (int)Va1.size());
	for (auto it : Va1) printf("%d ", it);
	printf("\n");
	printf("%d\n", (int)Va2.size());
	for (auto it : Va2) printf("%d %d\n", it.first, it.second);
	return 0;
}