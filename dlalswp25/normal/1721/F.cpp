#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int INF = 1010101010;

int N1, N2, M, Q;

struct Dinic {
	int S[1212121];
	int E[1212121];
	int F[1212121];
	int I[1212121];
	vector<int> adj[404040];
	int cur[404040];
	int dist[404040];
	bool chk[404040];
	int id, n;

	void init(int _n) { n = _n; id = 0; }

	void add_edge(int s, int e, int f, int i) {
		S[id] = s; E[id] = e; F[id] = f; I[id] = i;
		adj[s].push_back(id++);
		S[id] = e; E[id] = s; F[id] = 0; I[id] = i;
		adj[e].push_back(id++);
	}

	void bfs(int s) {
		for(int i = 1; i <= n; i++) dist[i] = 0;
		queue<int> q;
		dist[s] = 1;
		q.push(s);
		while(q.size()) {
			int x = q.front(); q.pop();
			for(int i : adj[x]) {
				if(!F[i] || dist[E[i]]) continue;
				dist[E[i]] = dist[x] + 1;
				q.push(E[i]);
			}
		}
	}

	int dfs(int v, int sink, int f) {
		if(v == sink) return f;
		for(; cur[v] < adj[v].size(); cur[v]++) {
			int i = adj[v][cur[v]];
			if(!F[i] || dist[E[i]] != dist[v] + 1) continue;
			int t = dfs(E[i], sink, min(f, F[i]));
			if(t == -1) continue;
			F[i] -= t; F[i ^ 1] += t;
			return t;
		}
		return -1;
	}

	int max_flow(int s, int t) {
		int ret = 0;
		while(1) {
			bfs(s);
			if(!dist[t]) break;
			for(int i = 1; i <= n; i++) cur[i] = 0;
			while(1) {
				int f = dfs(s, t, INF);
				if(f == -1) break;
				ret += f;
			}
		}
		return ret;
	}

	vector<pii> get(int s, int t) {
		vector<pii> ret;
		bfs(s);
		for(int i = 0; i < id; i++) {
			if(F[i]) continue;
			if(!(dist[S[i]] && !dist[E[i]])) continue;
			if(S[i] == s) chk[E[i]] = true;
			else chk[S[i]] = true;
		}
		for(int i = 1; i <= N1; i++) {
			if(!chk[i]) continue;
			for(int j : adj[i]) {
				if(F[j] == INF - 1) {
					ret.emplace_back(i, I[j]);
					break;
				}
			}
		}
		for(int i = N1 + 1; i <= N1 + N2; i++) {
			if(!chk[i]) continue;
			for(int j : adj[i]) {
				if(F[j] == 1) {
					ret.emplace_back(i, I[j]);
					break;
				}
			}
		}
		return ret;
	}
}flow;

int main() {
	scanf("%d%d%d%d", &N1, &N2, &M, &Q);
	flow.init(N1 + N2 + 2);
	for(int i = 1; i <= N1; i++) flow.add_edge(N1 + N2 + 1, i, 1, 0);
	for(int i = 1; i <= N2; i++) flow.add_edge(N1 + i, N1 + N2 + 2, 1, 0);
	for(int i = 1; i <= M; i++) {
		int a, b; scanf("%d%d", &a, &b);
		flow.add_edge(a, N1 + b, INF, i);
	}
	flow.max_flow(N1 + N2 + 1, N1 + N2 + 2);
	auto ans = flow.get(N1 + N2 + 1, N1 + N2 + 2);
	ll sum = 0;
	for(auto i : ans) sum += i.second;
	while(Q--) {
		int x; scanf("%d", &x);
		if(x == 1) {
			puts("1");
			int t = ans.back().first;
			if(t <= N1) printf("%d\n", t);
			else printf("-%d\n", t - N1);
			sum -= ans.back().second;
			ans.pop_back();
			printf("%lld\n", sum);
		}
		else {
			printf("%d\n", ans.size());
			for(auto i : ans) printf("%d ", i.second); puts("");
		}
		fflush(stdout);
	}
	return 0;
}