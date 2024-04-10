#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 300005
#define maxp 20
#define ull unsigned long long 
using namespace std;

int n,q,i,j,k,a[maxn],L[maxn],R[maxn],l[maxn],r[maxn],id[maxn];
int em,e[maxn*2],nx[maxn*2],ls[maxn];
int fa[maxn][maxp],dep[maxn],tot,st[maxn],ed[maxn],d[maxn*2],ans;

ull sd;
ull v[maxn],t[maxn*maxp*2];
int tl[maxn*maxp*2],tr[maxn*maxp*2],cnt,rt[maxn*2];
ull rd(){
	sd^=sd<<29,sd^=sd<<13;
	sd^=(sd<<5)*(sd>>7);
	return sd;
}

void read(int &x){
	x=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
}

void insert(int x,int y){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
	em++; e[em]=x; nx[em]=ls[y]; ls[y]=em;
}

void dfs(int x,int p){
	fa[x][0]=p,dep[x]=dep[p]+1,st[x]=++tot,d[tot]=a[x];
	for(int i=1;i<maxp;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=ls[x];i;i=nx[i]) if (e[i]!=p)
		dfs(e[i],x);
	ed[x]=++tot,d[tot]=a[x];
}

int lca(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	for(int i=maxp-1;i>=0;i--) if (dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	if (x==y) return x;
	for(int i=maxp-1;i>=0;i--) if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

void add(int &x,int y,int l,int r,int p){
	x=++cnt; t[x]=t[y]^v[p];
	if (l==r) return;
	int mid=(l+r)>>1;
	if (p<=mid) add(tl[x],tl[y],l,mid,p),tr[x]=tr[y];
	else add(tr[x],tr[y],mid+1,r,p),tl[x]=tl[y];
}

void find(int x,int y,int l,int r,int L,int R,int p){
	if (ans||l>R||r<L||(t[x]^t[y]^((l<=p&&p<=r)?v[p]:0))==0) return;
	if (l==r) {ans=l;return;}
	int mid=(l+r)>>1;
	find(tl[x],tl[y],l,mid,L,R,p);
	find(tr[x],tr[y],mid+1,r,L,R,p);
}

int main(){
	read(n),read(q);
	for(i=1,sd=19260817;i<=n;i++) v[i]=rd();
	for(i=1;i<=n;i++) read(a[i]);
	for(i=1;i<n;i++) read(j),read(k),insert(j,k);
	dfs(1,0);
	for(i=1;i<=n*2;i++) add(rt[i],rt[i-1],1,n,d[i]);
	for(i=1;i<=q;i++) {
		int x,y,z; read(x),read(y),read(l[i]),read(r[i]);
		if (st[x]>st[y]) swap(x,y); z=lca(x,y);
		if (z==x) L[i]=st[x],R[i]=st[y]; 
		else L[i]=ed[x],R[i]=st[y],id[i]=a[z];
		ans=0,find(rt[R[i]],rt[L[i]-1],1,n,l[i],r[i],id[i]);
		if (!ans) printf("-1\n"); else printf("%d\n",ans);
	}
}