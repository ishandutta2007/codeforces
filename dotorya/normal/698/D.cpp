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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

int gcd(int a, int b) {
	return (a == 0) ? b : gcd(b%a, a);
}

map <pii, int> Mx;
vector <int> V[1050];
int ch(pii x) {
	if (Mx.count(x)) return Mx[x];
	int t = Mx.size();
	Mx[x] = t;
	return t;
}

int in1[1050][2];
int in2[7][2];

int K;
bool over7[1050][7];
vector <int> useList[1050][7];
bool chk[1050][7];

bool used[7];

bool aa(vector <int> V) {
	vector <int> u = V;
	if (u.empty()) return true;

	int c = 0;
	for (int i = 0; i < K; i++) if (!used[i]) c++;
	if (c < u.size()) return false;

	for (int t = 0; t < u.size(); t++) {
		int x = u[t];

		int i;
		for (i = 0; i < K; i++) {
			if (used[i]) continue;
			if (over7[x][i]) continue;

			vector <int> u2;
			for (int j = 0; j < u.size(); j++) if (j != t) u2.push_back(u[j]);
			for (auto it : useList[x][i]) u2.push_back(it);
			sort(u2.begin(), u2.end());
			u2.erase(unique(u2.begin(), u2.end()), u2.end());

			used[i] = true;
			if (aa(u2)) return true;
			used[i] = false;

			u2.clear();
		}
	}
	return false;
}

ll getdis(ll a, ll b) {
	return a*a + b*b;
}
int main() {
	int N, i, j, k, l;
	scanf("%d %d", &K, &N);
	for (i = 0; i < K; i++) for(j = 0; j < 2; j++) scanf("%d", &in2[i][j]);
	for (i = 0; i < N; i++) for(j = 0; j < 2; j++) scanf("%d", &in1[i][j]);

	for (i = 0; i < K; i++) {
		for (j = 0; j < N; j++) {
			int x = in2[i][0] - in1[j][0];
			int y = in2[i][1] - in1[j][1];
			int g = gcd(abs(x), abs(y));
			x /= g, y /= g;

			int t = ch(pii(x, y));
			V[t].push_back(j);
		}
		for (j = 0; j < Mx.size(); j++) {
			sort(V[j].begin(), V[j].end(), [&i](int x, int y) {
				return getdis(in2[i][0] - in1[x][0], in2[i][1] - in1[x][1]) < getdis(in2[i][0] - in1[y][0], in2[i][1] - in1[y][1]);
			});
			for (k = 0; k < 7 && k < V[j].size(); k++) for (l = 0; l < k; l++) useList[V[j][k]][i].push_back(V[j][l]);
			for (k = 7; k < V[j].size(); k++) over7[V[j][k]][i] = true;

			V[j].clear();
		}
		Mx.clear();
	}

	int ans = 0;
	for (i = 0; i < N; i++) {
		vector <int> V;
		V.push_back(i);

		if (aa(V)) ans++;
		for (j = 0; j < K; j++) used[j] = false;
		V.clear();
	}
	return !printf("%d\n", ans);
}