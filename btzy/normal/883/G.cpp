#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

#define SZ(a) (int)(a).size()

struct Edge {
	int dir; // 1 = undir, 2 = u->v, 3 = v->u
	int v;
	int pos;
	Edge(int _dir, int _v, int _pos = 0) {
		dir = _dir;
		v = _v;
		pos = _pos;
	}
};

struct EdgePos {
	int u;
	int v;
	int upos;
	int vpos;
	EdgePos(int _u, int _v, int _upos, int _vpos) {
		u = _u;
		v = _v;
		upos = _upos;
		vpos = _vpos;
	}
};

int getpos(int u, EdgePos epos) {
	return u == epos.u ? epos.upos : epos.vpos;
}

vector<vector<Edge>> gal1, gal2;
vector<bool> vis;
vector<EdgePos> eposs;

int dfs1(int u) {
	// printf("u: %d\n", u);
	vis[u] = true;
	int ret = 1;
	for (auto& e: gal1[u]) {
		auto v = e.v;
		if (vis[v]) continue;
		if (e.dir == 3) continue;
		if (e.dir == 1) {
			e.dir = 2;
			assert(eposs[e.pos].u == u || eposs[e.pos].u == v);
			assert(eposs[e.pos].v == u || eposs[e.pos].v == v);
			auto pos = getpos(u, eposs[e.pos]);
			gal1[v][pos].dir = 3;
		}
		ret += dfs1(v);
	}
	return ret;
}

int dfs2(int u) {
	vis[u] = true;
	int ret = 1;
	for (auto& e: gal2[u]) {
		auto v = e.v;
		if (vis[v]) continue;
		if (e.dir == 3) continue;
		if (e.dir == 1) {
			e.dir = 3;
			gal2[v][getpos(u, eposs[e.pos])].dir = 2;
			continue;
		}
		ret += dfs2(v);
	}
	return ret;
}

int main()
{
	int n, m, s;
	cin >> n >> m >> s;
	s--;
	// printf("s: %d\n", s);
	vector<vector<Edge>> al(n);
	for (int i = 0; i < m; i++) {
		int dir;
		cin >> dir;
		int u, v;
		cin >> u >> v;
		u--; v--;
		if (dir == 1) {
			al[u].emplace_back(2, v);
		} else {
			int sv = SZ(al[v]);
			int su = SZ(al[u]);
			int se = SZ(eposs);
			eposs.emplace_back(u, v, sv, su);
			al[u].emplace_back(1, v, se);
			al[v].emplace_back(1, u, se);
		}
	}
	gal1 = al;
	vis.assign(n, false);
	int ans1 = dfs1(s);
	printf("%d\n", ans1);
	for (auto epos: eposs) {
		printf(gal1[epos.u][epos.vpos].dir == 2 ? "+" : "-");
	}
	puts("");
	gal2 = al;
	vis.assign(n, false);
	int ans2 = dfs2(s);
	printf("%d\n", ans2);
	for (auto epos: eposs) {
		printf(gal2[epos.u][epos.vpos].dir == 2 ? "+" : "-");
	}
	puts("");
	return 0;
}