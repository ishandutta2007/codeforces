#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, q, rt, top, lim, cnt, f[N], fa[N], col[N], siz[N], stk[N], lazy[N], ch[N][2], s[N<<1];
bool rev[N];
vector<int> e[N];
void dfs(int u){ for(int v:e[u]) if(v!=fa[u]) fa[v]=u, dfs(v);}
inline void update(int x){ siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+1;}
inline void pushdown(int x){
	if(rev[x]) swap(ch[x][0], ch[x][1]), rev[ch[x][0]]^=1, rev[ch[x][1]]^=1, rev[x]=0;
	if(lazy[x]) lazy[ch[x][0]]=lazy[ch[x][1]]=col[ch[x][0]]=col[ch[x][1]]=lazy[x], lazy[x]=0;
}
inline void rotate(int x){
	int f=fa[x], g=fa[f], k=ch[f][0]==x;
	fa[f]=x, fa[x]=g, fa[ch[x][k]]=f;
	ch[f][!k]=ch[x][k], ch[x][k]=f;
	if(ch[g][0]==f || ch[g][1]==f) ch[g][ch[g][1]==f]=x;
	update(f);
}
inline void splay(int x){
	stk[top=1]=x;
	for(int i=x; ch[fa[i]][0]==i || ch[fa[i]][1]==i; i=fa[i]) stk[++top]=fa[i];
	while(top) pushdown(stk[top--]);
	for(int f; f=fa[x], ch[f][0]==x || ch[f][1]==x; rotate(x))
		if(ch[fa[f]][0]==f || ch[fa[f]][1]==f) rotate((ch[fa[f]][0]==f)^(ch[f][0]==x)?x:f);
	update(x);
}
inline void modify(int x, int y){ if(!x) return; while(x<=lim) s[x]+=y, x+=x&-x;}
inline void access(int x){
	int t=0;
	while(x) splay(x), modify(col[x], -siz[ch[x][0]]-1), ch[x][1]=t, t=x, update(x), x=fa[x];
	col[t]=lazy[t]=++cnt, modify(cnt, siz[t]);
}
inline void makeroot(int x){ access(x), splay(x), rev[x]^=1;}
inline int query(int x){
	int ans=0;
	while(x) ans+=s[x], x^=x&-x;
	return ans;
}
inline int solve(int x){ return splay(x), siz[ch[x][1]]+1+query(col[x]-1);}
int main() {
	scanf("%d%d", &n, &q), lim=n+q;
	for(int i=1, x, y; i<n; ++i) scanf("%d%d", &x, &y), e[x].push_back(y), e[y].push_back(x);
	dfs(n);
	for(int i=1; i<=n; ++i) siz[i]=1;
	for(int i=1; i<=n; ++i) makeroot(i);
	for(int i=0, x, y; i<q; ++i){
		char c;
		while(isspace(c=getchar()));
		while(isalpha(getchar()));
		if(c=='u') scanf("%d", &x), makeroot(x);
		else if(c=='w') scanf("%d", &x), printf("%d\n", solve(x));
		else scanf("%d%d", &x, &y), printf("%d\n", solve(x)<solve(y)?x:y);
	}
	return 0;
}