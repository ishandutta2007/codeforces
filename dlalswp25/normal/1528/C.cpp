#include <bits/stdc++.h>

using namespace std;

int N;
int dfn[303030];
int ed[303030];
int id, ans, cur;

vector<int> adjA[303030];
vector<int> adjB[303030];

struct Node {
	int x = 0, lz = 0;
};

struct SegTree {
	Node T[4 * 303030];

	void init(int idx, int s, int e) {
		T[idx].x = 0; T[idx].lz = -1;
		if(s == e) return;
		int m = s + e >> 1;
		init(idx << 1, s, m);
		init(idx << 1 | 1, m + 1, e);
	}

	void propa(int idx, int s, int e) {
		if(T[idx].lz != -1) T[idx].x = T[idx].lz;
		if(s != e) {
			if(T[idx].lz != -1) T[idx << 1].lz = T[idx << 1 | 1].lz = T[idx].lz;
		}
		T[idx].lz = -1;
	}

	void upd(int idx, int s, int e, int p, int q, int x) {
		propa(idx, s, e);
		if(q < s || e < p) return;
		if(p <= s && e <= q) {
			T[idx].lz = x;
			propa(idx, s, e);
			return;
		}
		int m = s + e >> 1;
		upd(idx << 1, s, m, p, q, x);
		upd(idx << 1 | 1, m + 1, e, p, q, x);
		T[idx].x = max(T[idx << 1].x, T[idx << 1 | 1].x);
	}

	int get(int idx, int s, int e, int p, int q) {
		propa(idx, s, e);
		if(q < s || e < p) return 0;
		if(p <= s && e <= q) return T[idx].x;
		int m = s + e >> 1;
		return max(get(idx << 1, s, m, p, q), get(idx << 1 | 1, m + 1, e, p, q));
	}
}seg;

void dfsB(int v, int p) {
	dfn[v] = ++id;
	for(int i : adjB[v]) {
		if(i == p) continue;
		dfsB(i, v);
	}
	ed[v] = id;
}

void dfsA(int v, int p) {
	int t = seg.get(1, 1, N, dfn[v], ed[v]);
	bool chk = false, over = false;

	if(!t) {
		chk = true;
		cur++;
		seg.upd(1, 1, N, dfn[v], ed[v], v);
	}
	else if(dfn[t] < dfn[v]) {
		chk = true;
		over = true;
		seg.upd(1, 1, N, dfn[t], ed[t], 0);
		seg.upd(1, 1, N, dfn[v], ed[v], v);
	}

	ans = max(ans, cur);
	for(int i : adjA[v]) {
		if(i == p) continue;
		dfsA(i, v);
	}

	if(chk) seg.upd(1, 1, N, dfn[v], ed[v], 0);
	if(over) seg.upd(1, 1, N, dfn[t], ed[t], t);
	if(chk && !over) cur--;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) { adjA[i].clear(); adjB[i].clear(); }
		for(int i = 2; i <= N; i++) {
			int p; scanf("%d", &p);
			adjA[i].push_back(p);
			adjA[p].push_back(i);
		}
		for(int i = 2; i <= N; i++) {
			int p; scanf("%d", &p);
			adjB[i].push_back(p);
			adjB[p].push_back(i);
		}

		id = 0;
		dfsB(1, 0);
		seg.init(1, 1, N);

		ans = cur = 0;
		dfsA(1, 0);
		printf("%d\n", ans);
	}
	return 0;
}