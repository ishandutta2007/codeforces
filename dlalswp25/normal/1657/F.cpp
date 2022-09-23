#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> tre[404040];
vector<int> adj[808080];
char A[404040][2];
int B[404040];
int C[404040];
int X[404040];
int Y[404040];
string S[404040];
char ans[404040];

int dep[404040];
int st[20][404040];

bool vst[808080];
int col[808080];
int cid;
vector<int> U, V;
vector<int> stk;

void no() {
	puts("NO"); exit(0);
}

void dfs(int v, int p) {
	dep[v] = dep[p] + 1;
	st[0][v] = p;
	for(int i : tre[v]) {
		if(i == p) continue;
		dfs(i, v);
	}
}

int lca(int a, int b) {
	if(dep[a] < dep[b]) swap(a, b);
	for(int i = 19; i >= 0; i--) {
		if(dep[st[i][a]] < dep[b]) continue;
		a = st[i][a];
	}
	if(a == b) return a;
	for(int i = 19; i >= 0; i--) {
		if(st[i][a] == st[i][b]) continue;
		a = st[i][a]; b = st[i][b];
	}
	return st[0][a];
}

void add_edge(int a, int b) {
	U.push_back(a); V.push_back(b);
	adj[a].push_back(b);
}

void set_true(int x) {
	if(C[x] != -1 && C[x] == 0) no();
	C[x] = 1;
	add_edge(2 * x, 2 * x + 1);
}

void set_false(int x) {
	if(C[x] != -1 && C[x] == 1) no();
	C[x] = 0;
	add_edge(2 * x + 1, 2 * x);
}

void fg(int a, int b) {
	add_edge(a, b);
	add_edge(b ^ 1, a ^ 1);
}

void dfs1(int v) {
	vst[v] = true;
	for(int i : adj[v]) if(!vst[i]) dfs1(i);
	stk.push_back(v);
}

void dfs2(int v, int c) {
	col[v] = c;
	for(int i : adj[v]) if(!col[i]) dfs2(i, c);
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		tre[a].push_back(b);
		tre[b].push_back(a);
	}
	dfs(1, 0);
	for(int i = 1; i <= 19; i++) for(int j = 1; j <= N; j++) st[i][j] = st[i - 1][st[i - 1][j]];

	for(int i = 1; i <= M; i++) C[i] = -1;

	for(int i = 1; i <= M; i++) {
		int x, y; scanf("%d%d", &x, &y);
		X[i] = x; Y[i] = y;
		int l = lca(x, y);
		vector<int> vs;
		int v = x;
		while(v != l) {
			vs.push_back(v);
			v = st[0][v];
		}
		vs.push_back(v);
		vector<int> tmp;
		v = y;
		while(v != l) {
			tmp.push_back(v);
			v = st[0][v];
		}
		reverse(tmp.begin(), tmp.end());
		vs.insert(vs.end(), tmp.begin(), tmp.end());

		cin >> S[i];
		int len = S[i].size();
		for(int j = 0; j < len; j++) {
			char s = S[i][j], t = S[i][len - j - 1];
			int v = vs[j];

			if(!B[v]) {
				A[v][0] = s; A[v][1] = t;
				B[v] = i;
				continue;
			}

			if(C[B[v]] != -1) {
				char c = A[v][C[B[v]]];
				if(c != s && c != t) no();
				if(s != t) {
					if(c == s) set_false(i);
					else set_true(i);
				}
			}

			if(min(A[v][0], A[v][1]) == min(s, t) && max(A[v][0], A[v][1]) == max(s, t)) {
				if(A[v][0] == A[v][1]) continue;
				if(A[v][0] == s) {
					fg(2 * B[v], 2 * i);
					fg(2 * B[v] + 1, 2 * i + 1);
				}
				else {
					fg(2 * B[v], 2 * i + 1);
					fg(2 * B[v] + 1, 2 * i);
				}
				continue;
			}

			if(s != A[v][0] && s != A[v][1]) set_true(i);
			else if(A[v][0] != A[v][1]) {
				if(s == A[v][0]) fg(2 * i, 2 * B[v]);
				else fg(2 * i, 2 * B[v] + 1);
			}
			if(t != A[v][0] && t != A[v][1]) set_false(i);
			else if(A[v][0] != A[v][1]) {
				if(t == A[v][0]) fg(2 * i + 1, 2 * B[v]);
				else fg(2 * i + 1, 2 * B[v] + 1);
			}
		}
	}

	for(int i = 2; i <= 2 * M + 1; i++) if(!vst[i]) dfs1(i);
	for(int i = 2; i <= 2 * M + 1; i++) adj[i].clear();
	for(int i = 0; i < U.size(); i++) adj[V[i]].push_back(U[i]);
	reverse(stk.begin(), stk.end());
	for(int i : stk) if(!col[i]) { cid++; dfs2(i, cid); }

	for(int i = 1; i <= M; i++) if(col[2 * i] == col[2 * i + 1]) no();

	for(int i = 1; i <= M; i++) {
		if(col[2 * i] < col[2 * i + 1]) swap(X[i], Y[i]);
		int l = lca(X[i], Y[i]);
		int p = 0;
		int v = X[i];
		while(v != l) {
			ans[v] = S[i][p++];
			v = st[0][v];
		}
		ans[v] = S[i][p];
		int q = (int)S[i].size() - 1;
		v = Y[i];
		while(v != l) {
			ans[v] = S[i][q--];
			v = st[0][v];
		}
	}

	puts("YES");
	for(int i = 1; i <= N; i++) printf("%c", ans[i] ? ans[i] : 'q'); puts("");
	return 0;
}