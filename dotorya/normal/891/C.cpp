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
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-9;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int r[500050];
int sz[500050];
vector <pair<int, pii>> Vl;
int root(int x) {
	return (x == r[x]) ? x : root(r[x]);
}
bool mymerge(int a, int b) {
	a = root(a), b = root(b);
	if (a == b) return false;

	Vl.emplace_back(a, pii(r[a], sz[a]));
	Vl.emplace_back(b, pii(r[b], sz[b]));
	if (sz[a] > sz[b]) swap(a, b);
	r[a] = b;
	sz[b] += sz[a];
	return true;
}

vector <int> Vx;

int in[500050][3];

bool achk[500050];
vector <pair<int, vector<int>>> Vq[500050];
vector <int> Ve[500050];
int main() {
	int N, M, i, j, k;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++) {
		scanf("%d %d %d", &in[i][0], &in[i][1], &in[i][2]);
		Vx.push_back(in[i][2]);
	}
	sort(all(Vx));
	Vx.erase(unique(all(Vx)), Vx.end());
	for (i = 1; i <= M; i++) in[i][2] = lower_bound(all(Vx), in[i][2]) - Vx.begin() + 1;
	for (i = 1; i <= M; i++) Ve[in[i][2]].push_back(i);

	int Q;
	scanf("%d", &Q);
	for (i = 1; i <= Q; i++) {
		int t1, t2;
		vector <int> Vu;
		scanf("%d", &t1);
		while (t1--) {
			scanf("%d", &t2);
			Vu.push_back(t2);
		}
		sort(all(Vu), [](int a, int b) {
			return in[a][2] < in[b][2];
		});

		int st = 0;
		for (j = 0; j < Vu.size(); j++) {
			if (j + 1 == Vu.size() || in[Vu[j]][2] != in[Vu[j + 1]][2]) {
				vector <int> Vu2;
				for (k = st; k <= j; k++) Vu2.push_back(Vu[k]);
				Vq[in[Vu[j]][2]].emplace_back(i, Vu2);
				st = j + 1;
			}
		}
	}

	for (i = 1; i <= N; i++) r[i] = i, sz[i] = 1;
	for (i = 1; i <= Vx.size(); i++) {
		for (auto it : Vq[i]) {
			for (j = 0; j < it.second.size(); j++) {
				int t = it.second[j];
				int x = in[t][0], y = in[t][1];
				if (!mymerge(x, y)) break;
			}
			if (j < it.second.size()) achk[it.first] = true;
			for (auto it : Vl) {
				int t1 = it.first, t2 = it.second.first, t3 = it.second.second;
				r[t1] = t2;
				sz[t1] = t3;
			}
			Vl.clear();
		}
		for (auto it : Ve[i]) mymerge(in[it][0], in[it][1]);
		Vl.clear();
	}
	for (i = 1; i <= Q; i++) {
		if (achk[i]) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}