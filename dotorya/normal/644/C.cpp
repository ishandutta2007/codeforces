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
const int INF = 1034567891;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-12;

unordered_map <string, int> Mx;
string Mv[100050];
int ch(string x) {
	if (Mx.count(x)) return Mx[x];
	int t = Mx.size();
	Mx[x] = t;
	Mv[t] = x;
	return t;
}

vector <string> V[100050];

char u[105];
bool cmp(int a, int b) {
	if (V[a].size() != V[b].size()) return V[a].size() < V[b].size();

	for (int i = 0; i < V[a].size(); i++) if (V[a][i] != V[b][i]) return V[a][i] < V[b][i];
	return false;
}
int v[100050];

vector <pii> ans;
int main() {
	int N, i, j, k;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%s", u);
		for (j = 7; u[j] != 0; j++) if (u[j] == '/') break;

		int t = ch(string(u + 7, u + j));
		if (u[j] == 0) V[t].push_back(string(""));
		else {
			for (k = j; u[k] != 0; k++);
			V[t].push_back(string(u + j, u + k));
		}
	}

	for (i = 0; i < Mx.size(); i++) {
		v[i] = i;
		sort(V[i].begin(), V[i].end());
		V[i].erase(unique(V[i].begin(), V[i].end()), V[i].end());
	}

	sort(v, v + Mx.size(), cmp);

	int st = 0;
	for (i = 0; i < Mx.size(); i++) {
		if (i + 1 == Mx.size() || cmp(v[i], v[i+1])) {
			if (st != i) ans.push_back(pii(st, i));
			st = i + 1;
		}
	}

	printf("%d\n", ans.size());
	for (auto it : ans) {
		for (i = it.first; i <= it.second; i++) printf("http://%s ", Mv[v[i]].c_str());
		printf("\n");
	}
	return 0;
}