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

vector <int> conn[100050];
int inc[100050][2];
int in[100050];
set <pii> Sx;
void update(int n) {
	if (Sx.count(pii(1, n))) {
		Sx.erase(pii(1, n));
		Sx.emplace(0, n);
	}
	in[n] = 0;
	for (auto it : conn[n]) {
		inc[it][1]--;
		inc[it][0]++;
	}
}

vector <int> Vu;
vector <int> Vl;
void DoBFS() {
	int i, j;
	for (i = 0; i < Vu.size(); i++) {
		for (auto it : conn[Vu[i]]) {
			inc[it][1]--;
			Vl.push_back(it);
			if (!inc[it][0] && !inc[it][1] && in[it] == 1) Vu.push_back(it);
		}
	}
	for (auto it : Vl) inc[it][1]++;
	Vl.clear();
	for (auto it : Vu) update(it);
	Vu.clear();
}
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) scanf("%d", &in[i]);
	for (i = 1; i <= M; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		inc[t2][in[t1]]++;
	}
	for (i = 0; i < N; i++) if (!inc[i][0] && !inc[i][1]) Sx.emplace(in[i], i);
	
	int ans = 0;
	while (1) {
		while (!Sx.empty()) {
			pii u = *Sx.begin();
			if (u.first == 1) break;

			Sx.erase(u);
			for (auto it : conn[u.second]) {
				inc[it][0]--;
				if (!inc[it][0] && !inc[it][1]) Sx.emplace(in[it], it);
			}
		}
		if (Sx.empty()) break;

		ans++;
		for (auto it : Sx) Vu.push_back(it.second);
		DoBFS();
	}
	return !printf("%d\n", ans);
}