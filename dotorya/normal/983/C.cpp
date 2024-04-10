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

map <vector<int>, int> Mx;
vector <int> Mv[1050];

int nxt1[1050][10]; // 1 ~ 9 : get on
int nxt2[1050][10]; // 1 ~ 9 : get off

int dis[1050][10];
int tdis[1050][10];
priority_queue <pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> Hx;
void updatedis(int d, int x, int y) {
	if (tdis[x][y] > d) {
		tdis[x][y] = d;
		Hx.emplace(d, pii(x, y));
	}
}
int main() {
	int i, j, k, l, C = 0; // C = 715
	for (i = 0; i <= 9; i++) {
		for (j = i; j <= 9; j++) {
			for (k = j; k <= 9; k++) {
				for (l = k; l <= 9; l++) {
					vector <int> Vu;
					Vu.push_back(i);
					Vu.push_back(j);
					Vu.push_back(k);
					Vu.push_back(l);
					Mx[Vu] = ++C;
					Mv[C] = Vu;
				}
			}
		}
	}
	for (i = 1; i <= C; i++) {
		vector <int> Vu = Mv[i];
		
		if (Vu[0] == 0) {
			for (j = 1; j <= 9; j++) {
				vector <int> Vu2 = Vu;
				Vu2[0] = j;
				sort(all(Vu2));
				nxt1[i][j] = Mx[Vu2];
			}
		}
		for (j = 1; j <= 9; j++) {
			vector <int> Vu2 = Vu;
			for (k = 0; k < 4; k++) {
				if (Vu2[k] == j) {
					Vu2[k] = 0;
					break;
				}
			}
			sort(all(Vu2));
			nxt2[i][j] = Mx[Vu2];
		}
	}

	memset(dis, 0x3f, sizeof(dis));
	for (i = 1; i <= 9; i++) dis[1][i] = i - 1;

	int N;
	scanf("%d", &N);
	while (N--) {
		int S, E;
		scanf("%d %d", &S, &E);
		memset(tdis, 0x3f, sizeof(tdis));
		for (i = 1; i <= C; i++) {
			if (dis[i][S] == INF) continue;

			int ni = nxt1[i][E];
			if (ni == 0) continue;
			tdis[ni][S] = min(tdis[ni][S], dis[i][S] + 1);
		}
		
		for (i = 1; i <= C; i++) for (j = 1; j <= 9; j++) if (tdis[i][j] != INF) Hx.emplace(tdis[i][j], pii(i, j));

		while (!Hx.empty()) {
			auto it = Hx.top();
			Hx.pop();
			
			int d = it.first, x = it.second.first, y = it.second.second;
			if (d != tdis[x][y]) continue;

			if (y != 1) updatedis(d + 1, x, y - 1);
			if (y != 9) updatedis(d + 1, x, y + 1);
			updatedis(d + 1, nxt2[x][y], y);
		}
		for (i = 1; i <= C; i++) for (j = 1; j <= 9; j++) dis[i][j] = tdis[i][j];
	}
	
	int ans = INF;
	for (i = 1; i <= 9; i++) ans = min(ans, dis[1][i]);
	return !printf("%d\n", ans);
}