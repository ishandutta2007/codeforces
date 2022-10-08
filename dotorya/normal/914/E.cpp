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

int IT_MAX = 1 << 19;
ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

class edge {
public:
	int s, e;
	bool chk;
	edge(int s, int e) : s(s), e(e) {
		chk = false;
	}
};
vector <edge> Ve;
vector <int> conn[200050];
void epush(int s, int e) {
	conn[s].push_back(Ve.size());
	conn[e].push_back(Ve.size());
	Ve.emplace_back(s, e);
}

int DB[21] = { 0, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288 };

char in[200050];

vector <int> son[200050];
int sz[200050];
vector <int> Vl;
bool dchk[200050];
int val[200050];
void DFS1(int n) {
	sz[n] = 1;
	dchk[n] = true;
	Vl.push_back(n);
	for (auto tus : conn[n]) {
		if (Ve[tus].chk) continue;

		int it = Ve[tus].s ^ Ve[tus].e ^ n;
		if (dchk[it]) continue;
		son[n].push_back(it);
		val[it] = val[n] ^ (1 << (in[it] - 'a'));
		DFS1(it);
		sz[n] += sz[it];
	}
}

ll cnt1[1100000];
ll cnt2[1100000];

ll ans[200050];
ll tans[200050];
void init() {
	for (auto it : Vl) {
		son[it].clear();
		sz[it] = 0;
		dchk[it] = false;
		tans[it] = 0;
	}
	Vl.clear();
}



int gpar[200050];
vector <int> Vl2;
void DFS2(int x, int n, ll* cnt, int c) {
	Vl2.push_back(n);
	cnt[val[n]] += c;
	if (x) gpar[n] = x;
	for (auto it : son[n]) DFS2(x, it, cnt, c);
}

void DFS3(int n) {
	for (auto it : son[n]) {
		DFS3(it);
		tans[n] += tans[it];
	}
}

void DFS(int n) {
	DFS1(n);

	int r = n;
	while (1) {
		if (son[r].empty()) break;
		int mx = son[r][0];
		for (int i = 1; i < son[r].size(); i++) if (sz[mx] < sz[son[r][i]]) mx = son[r][i];
		if (sz[mx] * 2 <= Vl.size()) break;
		else r = mx;
	}
	init();

	val[r] = 0;
	DFS1(r);
	DFS2(0, r, cnt1, 1);
	Vl2.clear();
	cnt1[0]--;

	int i;
	for (i = 0; i <= 20; i++) DB[i] ^= 1 << (in[r] - 'a');
	for (auto tus : conn[r]) {
		if (Ve[tus].chk) continue;
		int it = Ve[tus].s ^ Ve[tus].e ^ r;

		DFS2(it, it, cnt2, 1);
		for (auto it2 : Vl2) {
			int g = it;

			for (i = 0; i <= 20; i++) if (val[it2] == DB[i]) break;
			if (i <= 20) {
				tans[it2]++;
				tans[r]++;
			}
			for (i = 0; i <= 20; i++) {
				int v = val[it2] ^ DB[i];

				int c = cnt1[v] - cnt2[v];
				tans[it2] += c;
			}
		}
		Vl2.clear();
		DFS2(it, it, cnt2, -1);
		Vl2.clear();
	}
	DFS2(0, r, cnt1, -1);
	cnt1[0]++;
	for (i = 0; i <= 20; i++) DB[i] ^= 1 << (in[r] - 'a');

	DFS3(r);
	for (auto it : Vl) {
		if (r == it) ans[r] += tans[r] / 2;
		else ans[it] += tans[it];
	}
	ans[r]++;
	init();

	vector <int> Vc;
	for (auto tus : conn[r]) {
		if (Ve[tus].chk) continue;
		int it = Ve[tus].s ^ Ve[tus].e ^ r;
		Vc.push_back(it);
	}
	for (auto it : conn[r]) Ve[it].chk = true;
	for (auto it : Vc) DFS(it);
}


int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i < N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		epush(t1, t2);
	}
	scanf("%s", in + 1);
	DFS(1);

	for (i = 1; i <= N; i++) printf("%lld ", ans[i]);
	return !printf("\n");
}
//*/