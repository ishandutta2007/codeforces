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

typedef tuple<int, int, int> t3;
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

int nc = 1;
int son[100050][26];
int dep[100050];

map <int, int> Mx[200050];
int mc = 0;
int ch[200050];
bool chk[100050];
void DFS(int n) {
	vector <int> Vs;
	for (int i = 0; i < 26; i++) {
		if (!son[n][i]) continue;
		int n2 = son[n][i];
		dep[n2] = dep[n] + 1;
		DFS(n2);
		Vs.push_back(n2);
	}

	if (Vs.empty()) {
		ch[n] = ++mc;
		Mx[mc][dep[n]] = 1;
		return;
	}
	
	int mxp = Vs[0];
	for (auto it : Vs) if (Mx[ch[mxp]].size() < Mx[ch[it]].size()) mxp = it;

	ch[n] = ch[mxp];
	for (auto it : Vs) {
		if (it == mxp) continue;
		for (auto it2 : Mx[ch[it]]) Mx[ch[n]][it2.first] += it2.second;
	}
	if (chk[n]) Mx[ch[n]][dep[n]]++;
	else {
		auto it = Mx[ch[n]].end();
		it--;
		if (it->second == 1) Mx[ch[n]].erase(it);
		else Mx[ch[n]][it->first]--;

		Mx[ch[n]][dep[n]]++;
	}
}

char u[100050];
int main() {
	int N, i, j, k;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%s", u);
		for (j = 0, k = 1; u[j] != 0; j++) {
			int t = u[j] - 'a';
			if (!son[k][t]) son[k][t] = ++nc;
			k = son[k][t];
		}
		chk[k] = true;
	}
	chk[1] = true;
	DFS(1);

	int ans = 0;
	for (auto it : Mx[ch[1]]) ans += it.first * it.second;
	return !printf("%d\n", ans);
}