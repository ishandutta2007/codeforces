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

int IT_MAX = 1 << 17;
int MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define Se second
#define Fi first

vector <int> conn[1050];
bool chk[1050][1050];

int dis[2][1050];
void getdis(int st, int N, int* dis) {
	int i;
	vector <int> Vu;
	for (i = 1; i <= N; i++) dis[i] = INF;
	dis[st] = 0;
	Vu.push_back(st);
	for (i = 0; i < Vu.size(); i++) {
		for (auto it : conn[Vu[i]]) {
			if (dis[it] != INF) continue;
			dis[it] = dis[Vu[i]] + 1;
			Vu.push_back(it);
		}
	}
}
int main() {
	int N, M, S, T, i, j;
	scanf("%d %d %d %d", &N, &M, &S, &T);
	for (i = 1; i <= M; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		chk[t1][t2] = chk[t2][t1] = true;
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}

	getdis(S, N, dis[0]);
	getdis(T, N, dis[1]);

	int ans = 0;
	for (i = 1; i <= N; i++) {
		for (j = i + 1; j <= N; j++) {
			if (chk[i][j]) continue;

			int v1 = dis[0][i] + dis[1][j] + 1;
			int v2 = dis[1][i] + dis[0][j] + 1;
			if (min(v1, v2) < dis[0][T]) continue;
			ans++;
		}
	}
	return !printf("%d\n", ans);
}