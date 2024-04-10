#include<bits/stdc++.h>
using namespace std;

inline int read(){
	char ch = getchar(); int x = 0;
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') { x = x*10 + ch-'0'; ch = getchar(); }
	return x;
}
const int maxn = 500009;
const int maxm = 22;
struct edge { int v, link; } e[maxn];
int head[maxn], s[maxn], size[maxn];
int son[maxn], dep[maxn], f[1<<maxm];
int n, a, anc, ans[maxn]; char c;

void addEdge(int k, int u, int v){
	e[k].v = v; e[k].link = head[u]; head[u] = k;
}

void dfs(int u){
	size[u] = 1;
	for (int k=head[u]; k; k=e[k].link){
		s[e[k].v] ^= s[u];
		dep[e[k].v] = dep[u] + 1;
		dfs(e[k].v);
		size[u] += size[e[k].v];
		if (size[e[k].v] > size[son[u]]) son[u] = e[k].v;
	}
}

void calc(int u){
	ans[anc] = max(ans[anc], dep[u]+f[s[u]]-2*dep[anc]);
	for (int i=0; i<22; i++)
		ans[anc] = max(ans[anc], dep[u]+f[(1<<i)^s[u]]-2*dep[anc]);
	for (int k=head[u]; k; k=e[k].link)
		calc(e[k].v);
}

void spcial_calc(){
	ans[anc] = max(ans[anc], f[s[anc]]-dep[anc]);
	for (int i=0; i<22; i++)
		ans[anc] = max(ans[anc], f[s[anc]^(1<<i)]-dep[anc]);
}

void update(int u, int op){ 
	if (op) f[s[u]] = max(f[s[u]], dep[u]);
	else f[s[u]] = -1e9;
	for (int k=head[u]; k; k=e[k].link)
		update(e[k].v, op);
}

void dfs(int u, int keep){
	for (int k=head[u]; k; k=e[k].link)
		if (e[k].v != son[u]){
			dfs(e[k].v, 0);
			ans[u] = max(ans[u], ans[e[k].v]);
		}
	if (son[u]){
		dfs(son[u], 1); 
		ans[u] = max(ans[u], ans[son[u]]);
	}
	anc = u; f[s[anc]] = max(f[s[anc]], dep[anc]);
	spcial_calc(); 
	for (int k=head[u]; k; k=e[k].link)
		if (e[k].v != son[u]){
			calc(e[k].v);
			update(e[k].v, 1);
		}
	if (!keep){
		f[s[anc]] = -1e9;
		for (int k=head[u]; k; k=e[k].link)
			update(e[k].v, 0);
	}
}

int main(){
	n = read();
	for (int i=2; i<=n; i++){
		a = read(); c = getchar();
		addEdge(i-1, a, i);
		s[i] = (1 << (c-'a'));
	}
	memset(f, 0xc0, sizeof f);
	dfs(1); dfs(1, 1);
	for (int i=1; i<=n; i++) printf("%d ", ans[i]);
	return 0;
}