#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int INF = 10101010;

int N, M;
set<int> adj[505050];
set<int> rem;
vector<int> vs[505050];
int deg[505050];
int P[505050];
int Q[505050];
bool chk[505050];
int id;

struct SegTree {
	int T[4 * 505050];

	void init(int idx, int s, int e) {
		if(s == e) { T[idx] = deg[s]; return; }
		int m = s + e >> 1;
		init(idx << 1, s, m);
		init(idx << 1 | 1, m + 1, e);
		T[idx] = max(T[idx << 1], T[idx << 1 | 1]);
	}

	void upd(int idx, int s, int e, int p, int x) {
		if(p < s || e < p) return;
		if(s == e) {
			T[idx] += x;
			if(T[idx] < -INF) T[idx] = -INF;
			return;
		}
		int m = s + e >> 1;
		upd(idx << 1, s, m, p, x);
		upd(idx << 1 | 1, m + 1, e, p, x);
		T[idx] = max(T[idx << 1], T[idx << 1 | 1]);
	}

	pii get() {
		int idx = 1, mx = T[1], s = 1, e = N;
		while(s != e) {
			int m = s + e >> 1;
			if(T[idx << 1] == mx) { idx = idx << 1; e = m; }
			else { idx = idx << 1 | 1; s = m + 1; }
		}
		return pii(s, mx);
	}

	void upd(int p, int x) { upd(1, 1, N, p, x); }
}seg;

void ers(int v) {
	// printf("erase %d\n", v);
	for(int i : adj[v]) {
		seg.upd(i, -1);
		adj[i].erase(v);
	}
	seg.upd(v, -INF);
	rem.erase(v);
	adj[v].clear();
	chk[v] = true;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {

	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) {
		adj[i].clear(); deg[i] = 0;
		chk[i] = false;
		vs[i].clear();
	}
	rem.clear();
	id = 0;

	for(int i = 1; i <= M; i++) {
		int a, b; scanf("%d%d", &a, &b);
		deg[a]++; deg[b]++;
		adj[a].insert(b);
		adj[b].insert(a);
	}

	seg.init(1, 1, N);

	for(int i = 1; i <= N; i++) rem.insert(i);
	set<int> roots;
	while(1) {
		int n = rem.size();
		if(!roots.size()) {

			int d, v; tie(v, d) = seg.get();
			if(d < 0 && !roots.size()) break;

			// printf("%d %d\n", d, v);
			if(d == n - 1) {
				P[v] = ++id;
				Q[v] = id;
				ers(v);
				continue;
			}

			if(d < n - 2) {
				rem.erase(v);
				for(int i : adj[v]) rem.erase(i);
				auto it = rem.begin();
				int u1 = *it; it++;
				int u2 = *it;
				rem.insert(v);
				for(int i : adj[v]) rem.insert(i);
				if(d == n - 3 && adj[u1].size() == n - 3 && adj[u2].size() == n - 3 && adj[u1].find(u2) == adj[u1].end()) {
					P[v] = ++id; P[u1] = ++id; P[u2] = ++id;
					Q[v] = P[u1]; Q[u1] = P[u2]; Q[u2] = P[v];
					ers(v); ers(u1); ers(u2);
					continue;
				}
				if(adj[u1].size() < adj[u2].size()) swap(u1, u2);
				ers(u1); ers(v);
				P[u1] = ++id;
				Q[u1] = ++id;
				P[v] = Q[u1]; Q[v] = P[u1];
				continue;
			}

		}

		while(1) {
			int d, v; tie(v, d) = seg.get();
			if(d < n - 2) break;
			rem.erase(v);
			for(int i : adj[v]) rem.erase(i);
			int u = *rem.begin();
			rem.insert(v);
			for(int i : adj[v]) rem.insert(i);
			if(roots.find(u) == roots.end()) roots.insert(u);
			vs[u].push_back(v);
			seg.upd(v, -INF);
		}

		auto it = roots.begin();
		while(roots.size()) {
			auto it = roots.begin();
			if(chk[*it]) roots.erase(it);
			else break;
		}
		if(!roots.size()) continue;
		int r = *roots.begin();

		for(int j : vs[r]) {
			P[j] = ++id;
			Q[j] = P[j] + 1;
			ers(j);
		}
		P[r] = ++id;
		Q[r] = P[vs[r][0]];
		ers(r);
		roots.erase(r);
	}

	for(int i = 1; i <= N; i++) printf("%d ", P[i]); puts("");
	for(int i = 1; i <= N; i++) printf("%d ", Q[i]); puts("");

	}

	return 0;
}

/*
1
7 11
5 7
2 4
1 7
1 2
2 5
1 3
3 7
2 3
4 6
4 7
1 5

1
11 40
5 9
2 7
1 5
5 6
2 10
1 6
6 7
4 11
5 8
3 11
3 5
3 4
3 10
1 4
1 3
4 9
3 9
7 11
5 10
5 7
2 6
6 11
4 6
5 11
9 10
6 9
1 10
8 9
2 4
6 10
8 10
8 11
4 7
1 8
2 5
2 9
2 11
1 2
10 11
4 10
*/