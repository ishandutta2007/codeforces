#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
 
const int maxn = 200009;
struct Trie { int p[26], fail, fa; } T[maxn];
struct ask { int k, p, op; } tmp;
vector<ask> q[maxn]; vector<int> e[maxn];
int cur[maxn], in[maxn], out[maxn], c[maxn], ans[maxn<<3], Q[maxn];
int size, n, m, l, r, k, clk;
char s[maxn];
 
void update(int x) {
	for (; x<=size+1; x+=lowbit(x)) c[x]++;
}
 
int query(int x) {
	int res = 0;
	for (; x; x-=lowbit(x)) res += c[x];
	return res;
}
 
void insert(int p, char s[]) {
	int o = 0;
	for (int i=0; s[i]; i++) {
		if (!T[o].p[s[i]-'a']) {
			T[o].p[s[i]-'a'] = ++size;
			T[size].fa = o;
		}
		o = T[o].p[s[i]-'a'];
	}
	cur[p] = o;
}
 
void build() {
	int l = 0, r = 0, o = 0;
	for (int i=0; i<26; i++)
		if (T[o].p[i]) Q[r++] = T[o].p[i];
	while (l < r) {
		o = Q[l++];
		e[T[o].fail].push_back(o);
		for (int i=0; i<26; i++)
			if (!T[o].p[i]) T[o].p[i] = T[T[o].fail].p[i];
			else {
				T[T[o].p[i]].fail = T[T[o].fail].p[i];
				Q[r++] = T[o].p[i];
			}
	}
}
 
void dfs(int u) {
	in[u] = ++clk;
	rep (i, 0, e[u].size()-1) dfs(e[u][i]);
	out[u] = clk;
}
 
void add(int u) {
	while (u) { update(in[u]); u = T[u].fa; }
}
 
int main() {
	scanf("%d%d", &n, &m);
	rep (i, 1, n) {
		scanf("%s", s);
		insert(i, s);
	}
	build();
	rep (i, 1, m) {
		scanf("%d%d%d", &l, &r, &k);
		tmp.k = cur[k]; tmp.p = i; 
		tmp.op = 1; q[r].push_back(tmp);
		tmp.op = -1; q[l-1].push_back(tmp);
	}
	dfs(0);
	rep (i, 1, n) {
		add(cur[i]);
		rep (j, 0, q[i].size()-1) 
			ans[q[i][j].p] += q[i][j].op * (query(out[q[i][j].k]) - query(in[q[i][j].k]-1));
	}
	rep (i, 1, m) printf("%d\n", ans[i]);
	return 0;
}