#include<bits/stdc++.h>
using namespace std;
const int N = 200005, S = N*2, T = N*19*2, C = 26;
int cnt, last, tot, q, m, pos[N], len[S], fa[S], f[S], root[S], s[T], lson[T], rson[T], ch[S][C];
char a[N];
vector<int> e[S];
int extend(int c){
	int np=++cnt, p=last;
	last=cnt, len[np]=len[p]+1;
	while(p && !ch[p][c]) ch[p][c]=np, p=fa[p];
	if(!p) fa[np]=1;
	else{
		int q=ch[p][c];
		if(len[q]==len[p]+1) fa[np]=q;
		else{
			int nq=++cnt;
			len[nq]=len[p]+1, memcpy(ch[nq], ch[q], C<<2);
			fa[nq]=fa[q], fa[q]=fa[np]=nq;
			while(ch[p][c]==q) ch[p][c]=nq, p=fa[p];
		}
	}
	return np;
}
void insert(int l, int r, int &t, int x){
	t?t:t=++tot;
	if(l==r) return (void)(++s[t]);
	int mid=(l+r)>>1;
	if(x<=mid) insert(l, mid, lson[t], x);
	else insert(mid+1, r, rson[t], x);
	s[t]=s[lson[t]]+s[rson[t]];
}
int query(int l, int r, int t, int L, int R){
	if(L<=l && r<=R) return s[t];
	int mid=(l+r)>>1;
	int ans=0;
	if(L<=mid) ans+=query(l, mid, lson[t], L, R);
	if(R>mid) ans+=query(mid+1, r, rson[t], L, R);
	return ans;
}
void merge(int &x, int y){
	if(!x || !y) return (void)(x|=y);
	int t=++tot;
    s[t]=s[x]+s[y];
    merge(lson[t]=lson[x], lson[y]), merge(rson[t]=rson[x], rson[y]);
	x=t;
}
void dfs(int u){
	for(int v:e[u]) f[v]=len[v]==len[u]?f[u]:v, dfs(v), merge(root[u], root[v]);
}
int main() {
	scanf("%d%d", &m, &q);
	cnt=1;
	for(int i=1; i<=m; ++i){
		scanf("%s", a+1), last=1;
		for(int j=1; a[j]; ++j) insert(1, m, root[pos[i]=extend(a[j]-'a')], i);
	}
	for(int i=1; i<=cnt; ++i) e[fa[i]].push_back(i);
	f[1]=1, dfs(1);
	for(int i=1, l, r, x; i<=q; ++i){
		scanf("%d%d%d", &l, &r, &x), x=f[pos[x]];
		printf("%d\n", query(1, m, root[x], l, r));
	}
	return 0;
}