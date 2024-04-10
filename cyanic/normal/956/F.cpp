// Hopcroft's algorithm

#include <bits/stdc++.h>
using namespace std;
typedef bitset<73> bits;
typedef long long ll;

inline char gc() {
	static char buf[1<<16], *S = buf, *E = buf;
	return S == E && (E = (S = buf) + fread(buf, 1, 1<<16, stdin), S == E) ? EOF : *S ++;
}

#define gc getchar

template <class T> void read(T &x) {
	int f = 0; x = 0; char ch = gc();
	for(; !isdigit(ch); ch = gc()) f |= (ch == '-');
	for(; isdigit(ch); ch = gc()) x = x * 10 + ch - '0';
	if (f) x = -x;
}

const int N = 100005, L = 10, M = 750;

namespace DFA {
	int e[N][L], bel[N], cc[N], ins[N], stk[N], cnt[N], mark[N];
	vector<int> s[N], t[N], rev[N][L];
	int n, m, sz, top;
	void init(int _n, int _m, int _sz) {
		n = _n, m = _m, sz = _sz;
	}
	void set(int u, int p) {
		s[p].push_back(u), bel[u] = p, cc[p] ++;
	}
	void add(int u, int v, int c) {
		e[u][c] = v, rev[v][c].push_back(u);
	}
	void push(int k) {
		stk[++ top] = k, ins[k] = 1;
	}
	void refresh(int k) {
		int flag = 0;
		for (auto x : s[k]) {
			if (bel[x] != k) {
				flag = 1; break;
			}
		}
		if (!flag) {
			assert(cc[k] == s[k].size());
			return;
		}
		vector<int> nw;
		for (auto x : s[k]) {
			if (bel[x] == k) {
				nw.push_back(x);
			}
		}
		s[k] = nw;
		assert(cc[k] == s[k].size());
	}
	void split(int k) {
		if (t[k].size() * 2 <= cc[k]) {
			s[++ m] = t[k];
			for (auto x : s[m]) {
				bel[x] = m;
			}
		}
		else {
			m ++;
			refresh(k);
			for (auto x : s[k]) {
				if (!mark[x]) {
					s[m].push_back(x);
					bel[x] = m;
				}
			}
		}
		cc[k] -= s[m].size();
		cc[m] = s[m].size();
		push(m);
	}
	void solve() {
		for (int i = 2; i <= m; i ++) {
			push(i);
		}
		for (; top; ) {
			int k = stk[top --];
			ins[k] = 0, refresh(k);
			vector<int> A = s[k];
			for (int c = 0; c < sz; c ++) {
				vector<int> X;
				for (auto u : A) {
					for (auto v : rev[u][c]) {
						X.push_back(v);
					}
				}
				static int vis[N];
				for (auto u : X) {
					cnt[bel[u]] ++;
					vis[bel[u]] = 0;
				}
				for (auto u : X) {
					if (!mark[u]) {
						t[bel[u]].push_back(u);
						mark[u] = 1;
					}
				}
				vector<int> id;
				for (auto u : X) {
					if (!vis[bel[u]]) {
						vis[bel[u]] = 1;
						id.push_back(bel[u]);
					}
				}
				for (auto k : id) {
					split(k);
					t[k].clear();
					cnt[k]=0;
				}
				for (auto u : X) {
					mark[u] = 0;
				}
			}
		}
	}
}

unordered_map<bits, int> id;
int val[N], tot;

int dfs(bits s) {
	int u = id[s];
	if (u) return u;
	id[s] = u = ++ tot;
	val[u] = s._Find_first();
	DFA::set(u, val[u] + 1);
	for (int c = 0; c < L; c ++) {
		bits nw = (s << c) | (s >> c);
		for (int i = 0; i < c; i ++) {
			if (s[i]) nw.set(abs(i - c));
		}
		DFA::add(u, dfs(nw), c);
	}
	return u;
}

int trans[M][L], w[M], cnt, start;

void init() {
	dfs(bits(1));
	DFA::init(tot, L, L);
	DFA::solve();
	unordered_map<int, int> cur;
	vector<int> node;
	for (int i = 1; i <= tot; i ++) {
		int x = DFA::bel[i];
		if (!cur[x]) {
			cur[x] = ++ cnt;
			node.push_back(i);
		}
	}
	start = cur[DFA::bel[1]];
	for (auto x : node) {
		int u = cur[DFA::bel[x]];
		w[u] = val[x];
		for (int c = 0; c < L; c ++) {
			trans[u][c] = cur[DFA::bel[DFA::e[x][c]]];
		}
	}	
}

ll dp[20][L][M][L];

void calc() {
	for (int i = 1; i <= cnt; i ++) {
		dp[0][L - 1][i][w[i]] = 1;
	}
	for (int i = 1; i <= 19; i ++) {
		for (int j = 0; j < L; j ++) {
			for (int s = 1; s <= cnt; s ++) {
				for (int t = 0; t < L; t ++) {
					dp[i][j][s][t] = dp[i - 1][L - 1][trans[s][j]][t];
					if (j) {
						dp[i][j][s][t] += dp[i][j - 1][s][t];
					}
				}
			}
		}
	}
	for (int i = 1; i <= 19; i ++) {
		for (int j = 0; j < L; j ++) {
			for (int s = 1; s <= cnt; s ++) {
				for (int t = 1; t < L; t ++) {
					dp[i][j][s][t] += dp[i][j][s][t - 1];
				}
			}
		}
	}
}

int num[20], len;

ll solve(ll x, int k) {
	for (len = 0; x; x /= 10) {
		num[++ len] = x % 10;
	}
	ll ans = 0; int s = start;
	for (int i = len; i >= 1; i --) {
		if (num[i]) {
			ans += dp[i][num[i] - 1][s][k];
		}
		s = trans[s][num[i]];
	}
	return ans;
}

int main() {
	init(), calc();
	int Q; read(Q);
	for (; Q; Q --) {
		ll l, r; int k;
		read(l), read(r), read(k);
		printf("%lld\n", solve(r + 1, k) - solve(l, k));
	}
	return 0;
}