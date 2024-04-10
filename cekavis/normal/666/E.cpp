#include<bits/stdc++.h>
using namespace std;
const int N = 500005, M = 50005, S = (N+M)*2, K = 21, T = M*17*2, C = 26;
int cnt, last, tot, q, m, pos[N], len[S], fa[S], root[S], lson[T], rson[T], f[K][S], ch[S][C];
char a[N];
pair<int,int> s[T];
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
	if(l==r) return (void)(++s[t].first, s[t].second=-l);
	int mid=(l+r)>>1;
	if(x<=mid) insert(l, mid, lson[t], x);
	else insert(mid+1, r, rson[t], x);
	s[t]=max(s[lson[t]], s[rson[t]]);
}
pair<int,int> query(int l, int r, int t, int L, int R){
	if(L<=l && r<=R) return s[t];
	int mid=(l+r)>>1;
	pair<int,int> ans;
	assert(!ans.first && !ans.second);
	if(L<=mid) ans=max(ans, query(l, mid, lson[t], L, R));
	if(R>mid) ans=max(ans, query(mid+1, r, rson[t], L, R));
	return ans;
}
void merge(int &x, int y){
	if(!x || !y) return (void)(x|=y);
	int t=++tot;
	if(!lson[x] && !rson[x]) s[t]=s[x], s[t].first+=s[y].first;
	else{
		merge(lson[t]=lson[x], lson[y]), merge(rson[t]=rson[x], rson[y]);
		s[t]=max(s[lson[t]], s[rson[t]]);
	}
	x=t;
}
void dfs(int u){
	for(int v:e[u]) dfs(v), merge(root[u], root[v]);
}
int main() {
	scanf("%s%d", a+1, &m);
	last=cnt=1;
	for(int i=1; a[i]; ++i) pos[i]=extend(a[i]-'a');
	for(int i=1; i<=m; ++i){
		scanf("%s", a+1), last=1;
		for(int j=1; a[j]; ++j) insert(1, m, root[extend(a[j]-'a')], i);
	}
	for(int i=1; i<=cnt; ++i) e[fa[i]].push_back(i), f[0][i]=fa[i];
	for(int i=1; i<K; ++i) for(int j=1; j<=cnt; ++j) f[i][j]=f[i-1][f[i-1][j]];
	dfs(1);
	scanf("%d", &q);
	for(int i=1, l, r, pl, pr; i<=q; ++i){
		scanf("%d%d%d%d", &l, &r, &pl, &pr);
		int x=pos[pr];
		for(int j=K; j--;) if(len[f[j][x]]>=pr-pl+1) x=f[j][x];
		auto ans=query(1, m, root[x], l, r);
		printf("%d %d\n", max(l, -ans.second), ans.first);
	}
	return 0;
}