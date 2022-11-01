#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>

using namespace std;
#define ll long long

const int N = 200005, M = N*19*2, C = 26;
int n, ans, cnt, cnt2, last, b[N], pos[N<<1], f[N<<1], g[N<<1], a[N<<1], fa[N<<1], len[N<<1], root[N<<1], lson[M], rson[M], ch[N<<1][C];
char s[N];
void insert(int l, int r, int &t, int x){
	t=++cnt2;
	if(l==r) return;
	int mid=(l+r)>>1;
	if(x<=mid) insert(l, mid, lson[t], x); else insert(mid+1, r, rson[t], x);
}
void merge(int &x, int y){
	if(!x || !y) return (void)(x|=y);
	int t=++cnt2;
	lson[t]=lson[x], rson[t]=rson[x];
	merge(lson[t], lson[y]), merge(rson[t], rson[y]), x=t;
}
bool query(int l, int r, int t, int L, int R){
	if((L<=l && r<=R) || !t) return t;
	int mid=(l+r)>>1;
	if(L<=mid && query(l, mid, lson[t], L, R)) return 1;
	if(R>mid && query(mid+1, r, rson[t], L, R)) return 1;
	return 0;
}
void extend(int c){
	int p=last, np=++cnt;
	last=cnt, len[np]=len[p]+1;
	while(!ch[p][c]) ch[p][c]=np, p=fa[p];
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
	insert(1, n, root[np], len[np]), pos[np]=len[np];
}
int main() {
	scanf("%d%s", &n, s);
	last=cnt=1;
	for(int i=0; i<n; ++i) extend(s[i]-'a');
	for(int i=1; i<=cnt; ++i) ++b[len[i]];
	for(int i=1; i<=n; ++i) b[i]+=b[i-1];
	for(int i=1; i<=cnt; ++i) a[b[len[i]]--]=i;
	for(int i=cnt; i; --i) merge(root[fa[a[i]]], root[a[i]]), pos[fa[a[i]]]=pos[a[i]];
	for(int i=2; i<=cnt; ++i){
		int u=a[i];
		if(fa[u]==1) f[u]=1, g[u]=u;
		else{
			int v=g[fa[u]];
			if(query(1, n, root[v], pos[u]-len[u]+len[v], pos[u]-1))
				f[u]=f[fa[u]]+1, g[u]=u;
			else f[u]=f[fa[u]], g[u]=v;
		}
		ans=max(ans, f[u]);
	}
	return printf("%d", ans), 0;
}