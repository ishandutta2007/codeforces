// Problem: G. Gates to Another World
// Contest: Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1556/problem/G
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

const int maxnds = 3000005, maxm = 50005;
int N, M;
ll NN;
int op[maxm], ans[maxm];
ll lp[maxm], rp[maxm];
int son[maxnds][2], rt, nds;
int bel[maxnds];
map<ll, int> pos[55];
char tmp[20];
vector<pair<ll, ll> > ars;
vector<pair<int, int> > egs[maxm];

struct Segment {
	ll l, r;
	int id, p;
};

vector<Segment> ss;

struct UnionFind {
	int fa[maxnds];
	UnionFind() { memset(fa, -1, sizeof(fa)); }
	int inline root(int x) { return fa[x] < 0 ? x : fa[x] = root(fa[x]); }
	bool inline conn(int a, int b) {
		a = root(a); b = root(b);
		if (a == b) return 0;
		if (fa[a] < fa[b]) swap(a, b);
		return fa[b] += fa[a], fa[a] = b, 1;
	}
} uf;

void inline build(ll l, ll r, int id, int &now, int dep = 0, ll nl = 0, ll nr = NN - 1) {
	if (nl > r || nr < l) return;
	if (!now) now = ++nds;
	if (nl >= l && nr <= r) {
		bel[now] = id;
		pos[dep][nl] = now;
		return;
	}
	ll m = (nl + nr) >> 1;
	build(l, r, id, son[now][0], dep + 1, nl, m);
	build(l, r, id, son[now][1], dep + 1, m + 1, nr);
}

pair<int, int> inline solve(int now, ll nl = 0, ll nr = NN - 1) {
	if (bel[now]) {
		ss.push_back({nl, nr, bel[now], now});
		return make_pair(SZ(ss) - 1, SZ(ss) - 1);
	}
	ll m = (nl + nr) >> 1, nmd = m - nl + 1;
	pair<int, int> ls = solve(son[now][0], nl, m);
	pair<int, int> rs = solve(son[now][1], m + 1, nr);
	for (int i = ls.first, j = rs.first; i <= ls.second && j <= rs.second; ) {
		if (ss[i].l <= ss[j].r - nmd && ss[j].l - nmd <= ss[i].r) {
			egs[min(ss[i].id, ss[j].id)].emplace_back(ss[i].p, ss[j].p);
		}
		if (ss[i].r <= ss[j].r - nmd) ++i;
		else ++j;
	}
	return make_pair(ls.first, rs.second);
}

int main() {
	scanf("%d%d", &N, &M);
	NN = 1ll << N;
	repi(i, M) {
		scanf("%s", tmp);
		scanf("%lld%lld", lp + i, rp + i);
		op[i] = 'b' - tmp[0];
		if (!op[i]) {
			ars.emplace_back(lp[i], rp[i]);
			build(lp[i], rp[i], i, rt);
		}
	}
	sort(ars.begin(), ars.end());
	ll lst = 0;
	rep(i, SZ(ars)) {
		if (lst < ars[i].first) build(lst, ars[i].first - 1, M + 1, rt);
		lst = ars[i].second + 1;
	}
	if (lst < NN) build(lst, NN - 1, M + 1, rt);
	solve(rt);
	for (int i = M + 1; i; --i) {
		for (auto &e : egs[i]) uf.conn(e.first, e.second);
		if (op[i]) {
			int lvl = N, lvr = N;
			ll ls = lp[i], rs = rp[i];
			while (!pos[lvl].count(ls)) {
				if ((ls >> (N - lvl)) & 1) ls ^= 1ll << (N - lvl);
				--lvl;
			}
			while (!pos[lvr].count(rs)) {
				if ((rs >> (N - lvr)) & 1) rs ^= 1ll << (N - lvr);
				--lvr;
			}
			ans[i] = uf.root(pos[lvl][ls]) == uf.root(pos[lvr][rs]);
		}
	}
	repi(i, M) if (op[i]) printf("%d\n", ans[i]);
	return 0;
}