#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

struct EDGE {
	int head[MAXN],edgesize;
	int nxt[MAXN << 1],to[MAXN << 1];
	inline void addedge(int x,int y) {
		nxt[++edgesize] = head[x];
		to[edgesize] = y;
		head[x] = edgesize;
	}
} e,ve;

int n,m,q,a[MAXN];
int fa[MAXN],p[MAXN][21],dfn[MAXN],dep[MAXN],cnt;
int tag[MAXN],ans;
int st[MAXN],top;
bool flag;

void DFS(int x,int f) {
	p[x][0] = fa[x] = f;
	dfn[x] = ++cnt,dep[x] = dep[f] + 1;
	for(register int i = 1;i <= 20; ++i) 
		p[x][i] = p[p[x][i - 1]][i - 1];
	for(register int i = e.head[x],to;i;i = e.nxt[i]) {
		to = e.to[i];
		if(to == f) continue;
		DFS(to,x);
	}
}

inline int LCA(int x,int y) {
	if(dep[x] < dep[y]) swap(x,y);
	for(register int i = 20;~i;--i) 
		if(dep[p[x][i]] >= dep[y]) x = p[x][i];
	if(x == y) return x;
	for(register int i = 20;~i;--i) 
		if(p[x][i] != p[y][i]) x = p[x][i],y = p[y][i];
	return p[x][0];
}

inline bool dfncmp(int a,int b) {return dfn[a] < dfn[b];}

inline void InsertVT(int x) {
	if(x == 1) return;
	if(!top) return (void)(st[++top] = x);
	int lca = LCA(x,st[top]);
	while(top > 1 && dep[lca] < dep[st[top - 1]]) {
		ve.addedge(st[top - 1],st[top]);
		top--;
	}
	if(dep[lca] < dep[st[top]]) ve.addedge(lca,st[top--]);
	if((!top) || st[top] != lca) st[++top] = lca;
	st[++top] = x;
}

void solve(int x) {
	if(tag[x]) {
		for(register int i = ve.head[x],to;i;i = ve.nxt[i]) {
			to = ve.to[i];
			solve(to);
			if(tag[to]) {
				tag[to] = 0;
				ans++;
			}
		}
	} else {
		for(register int i = ve.head[x],to;i;i = ve.nxt[i]) {
			to = ve.to[i];
			solve(to);
			tag[x] += tag[to];
			tag[to] = 0;
		}
		if(tag[x] > 1) ans++,tag[x] = 0;
	}
	//cout << x << ' ' << ans << endl;
	ve.head[x] = 0;
}

int main () {
	scanf("%d",&n);
	for(register int i = 1,x,y;i < n; ++i) {
		scanf("%d%d",&x,&y);
		e.addedge(x,y);
		e.addedge(y,x);
	}
	DFS(1,0);
	scanf("%d",&q);
	while(q--) {
		scanf("%d",&m);
		ve.edgesize = ans = tag[1] = 0;
		flag = true;
		for(register int i = 1;i <= m; ++i) {
			scanf("%d",&a[i]);
			tag[a[i]] = 1;
		}
		for(register int i = 1;i <= m; ++i)
			if(tag[fa[a[i]]]) {flag = false; break;}
		if(!flag) {
			for(register int i = 1;i <= m; ++i)
				tag[a[i]] = 0;
			puts("-1");
			continue;
		}
		sort(a + 1,a + m + 1,dfncmp);
		st[top = 1] = 1;
		for(register int i = 1;i <= m; ++i) 
			InsertVT(a[i]);
		while(top > 1) {
			ve.addedge(st[top - 1],st[top]);
			top--;
		}
		solve(1);
		for(register int i = 1;i <= m; ++i)
			tag[a[i]] = 0;
		printf("%d\n",ans);
	}
	return 0;
}