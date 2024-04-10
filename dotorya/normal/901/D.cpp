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

class edge {
public:
	int s, e;
	edge() {
		*this = edge(0, 0);
	}
	edge(int s, int e) : s(s), e(e) {}
};
vector <edge> Ve;
vector <int> conn[300050];
void epush(int s, int e) {
	conn[s].push_back(Ve.size());
	conn[e].push_back(Ve.size());
	Ve.emplace_back(s, e);
}

ll in[100050];
ll ans[300050];

int dep[100050];
pii par[100050];
bool dchk[100050];
vector <int> Vb;
vector <int> son[100050];
void DFS(int n) {
	dchk[n] = true;
	for (auto it : conn[n]) {
		edge &ed = Ve[it];
		int x = ed.s ^ ed.e ^ n;
		if (x == par[n].second) continue;
		if (dchk[x]) Vb.push_back(it);
		else {
			dep[x] = dep[n] + 1;
			par[x] = pii(it, n);
			son[n].push_back(x);
			DFS(x);
			
		}
	}
}
void DFS2(int n) {
	for (auto it : son[n]) {
		DFS2(it);
		in[n] -= ans[par[it].first];
	}
	if (n != 1) ans[par[n].first] = in[n];
}
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) scanf("%lld", &in[i]);
	for (i = 1; i <= M; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		epush(t1, t2);
	}
	DFS(1);

	ll s[2] = { 0,0 };
	for (i = 1; i <= N; i++) s[dep[i] % 2] += in[i];

	if ((s[0] - s[1]) % 2) return !printf("NO\n");

	sort(all(Vb));
	Vb.erase(unique(all(Vb)), Vb.end());
	for (auto it : Vb) {
		int x = Ve[it].s, y = Ve[it].e;
		if (dep[x] % 2 != dep[y] % 2) continue;

		int z = dep[x] % 2;
		ll a = (s[z] - s[1 - z]) / 2;
		in[x] -= a, in[y] -= a;
		ans[it] = a;
		s[z] -= 2 * a;
	}
	if (s[0] != s[1]) return !printf("NO\n");
	DFS2(1);
	
	printf("YES\n");
	for (i = 0; i < M; i++) printf("%lld\n", ans[i]);
	return 0;
}