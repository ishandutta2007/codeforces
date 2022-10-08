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
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

vector <int> Vin[3];
int in[300050][2];
int getans(vector<int> Vu) {
	if (Vu.empty()) return 0;
	return in[Vu.back()][0] - in[Vu[0]][0];
}
int main() {
	int N, i, j, k;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		int t;
		char c[2];
		scanf("%d %s", &t, c);
		in[i][0] = t;
		if (c[0] == 'R') in[i][1] = 0;
		else if (c[0] == 'B') in[i][1] = 1;
		else in[i][1] = 2;
		Vin[in[i][1]].push_back(i);
	}
	if (Vin[2].empty()) return !printf("%d\n", getans(Vin[0]) + getans(Vin[1]));

	vector <int> Vu[2];
	
	int ans = 0;
	int x = Vin[2][0];
	int v1 = in[x][0], v2 = in[x][0];
	for (i = 1; i < x; i++) {
		if (in[i][1] == 0) v1 = min(v1, in[i][0]);
		else v2 = min(v2, in[i][0]);
	}
	ans += in[x][0] - v1;
	ans += in[x][0] - v2;

	x = Vin[2].back();
	v1 = v2 = in[x][0];
	for (i = x + 1; i <= N; i++) {
		if (in[i][1] == 0) v1 = max(v1, in[i][0]);
		else v2 = max(v2, in[i][0]);
	}
	ans += v1 + v2 - in[x][0] * 2;

	for (i = 0; i + 1 < Vin[2].size(); i++) {
		int s = Vin[2][i], e = Vin[2][i + 1];
		Vu[0].clear();
		Vu[1].clear();
		Vu[0].push_back(in[s][0]);
		Vu[1].push_back(in[s][0]);
		for (j = s + 1; j < e; j++) Vu[in[j][1]].push_back(in[j][0]);
		Vu[0].push_back(in[e][0]);
		Vu[1].push_back(in[e][0]);

		int mx[2] = { 0,0 };
		for (j = 0; j < 2; j++) {
			for (k = 0; k + 1 < Vu[j].size(); k++) mx[j] = max(mx[j], Vu[j][k + 1] - Vu[j][k]);
		}

		ans += (int)min((ll)2 * (in[e][0] - in[s][0]), (ll)3 * (in[e][0] - in[s][0]) - mx[0] - mx[1]);
	}
	return !printf("%d\n", ans);
}