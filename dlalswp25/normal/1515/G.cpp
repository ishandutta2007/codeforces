#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, M;
int A[202020];
int B[202020];
ll C[202020];
ll D[202020];
ll up[202020];

vector<int> adj[202020];
vector<pii> adj2[202020];
vector<pii> rev[202020];

ll G[202020];
int col[202020];
bool vst[202020];
int dfn[202020];
bool fin[202020];
vector<int> V;
int cid, id;

ll gcd(ll a, ll b) { while(b) { a %= b; swap(a, b); } return a; }

void dfs(int v) {
	vst[v] = true;
	for(int i : adj[v]) if(!vst[i]) dfs(i);
	V.push_back(v);
}

void dfs2(int v, int c) {
	col[v] = c;
	for(int i : adj[v]) if(!col[i]) dfs2(i, c);
}

void calc_up(int v) {
	vst[v] = true;
	for(pii i : rev[v]) {
		if(col[v] != col[i.first]) continue;
		if(vst[i.first]) continue;
		up[i.first] = up[v] + i.second;
		calc_up(i.first);
	}
}

void solve(int v) {
	dfn[v] = ++id;
	for(pii i : adj2[v]) {
		if(col[v] != col[i.first]) continue;
		if(dfn[i.first]) {
			if(dfn[i.first] > dfn[v]) {
				G[col[v]] = gcd(G[col[v]], abs(D[i.first] - D[v] - i.second));
			}
			else if(!fin[i.first]) {
				G[col[v]] = gcd(G[col[v]], D[v] - D[i.first] + i.second);
			}
			else {
				G[col[v]] = gcd(G[col[v]], D[v] + i.second + up[i.first]);
			}
		}
		else {
			D[i.first] = D[v] + i.second;
			solve(i.first);
		}
	}

	fin[v] = true;
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++) {
		scanf("%d%d%d", &A[i], &B[i], &C[i]);
		adj[A[i]].push_back(B[i]);
	}

	for(int i = 1; i <= N; i++) if(!vst[i]) dfs(i);
	for(int i = 1; i <= N; i++) adj[i].clear();
	for(int i = 1; i <= M; i++) adj[B[i]].push_back(A[i]);
	reverse(V.begin(), V.end());
	for(int i : V) if(!col[i]) { cid++; dfs2(i, cid); }

	for(int i = 1; i <= N; i++) vst[i] = false;
	for(int i = 1; i <= M; i++) {
		adj2[A[i]].emplace_back(B[i], C[i]);
		rev[B[i]].emplace_back(A[i], C[i]);
	}
	for(int i = 1; i <= N; i++) if(!dfn[i]) { calc_up(i); solve(i); }

	int Q; scanf("%d", &Q);
	while(Q--) {
		int v, s, t; scanf("%d%d%d", &v, &s, &t);
		if(!s) { puts("YES"); continue; }
		ll g = G[col[v]];
		if(!g) { puts("NO"); continue; }
		ll g2 = gcd(g, t);
		if((t - s) % g2 == 0) puts("YES");
		else puts("NO");
	}

	return 0;
}