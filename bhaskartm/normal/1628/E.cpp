#include<bits/stdc++.h>
using namespace std;
int n,q,fa[600100],N,val[600100],f[601000][20],d[600100];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
vector<int>g[601000];
struct qq{
	int x,y,w;
}a[300100];
bool cmp(qq a,qq b){return a.w<b.w;}
void dfs(int x){
	for(int v:g[x]){
		f[v][0]=x;d[v]=d[x]+1;
		for(int i=1;i<20;i++)f[v][i]=f[f[v][i-1]][i-1];
		dfs(v);
	}
}
int lca(int x,int y){
	if(!x||!y)return x+y;
	if(d[x]<d[y])swap(x,y);int a=d[x]-d[y];
	for(int i=19;i>=0;i--)if((a>>i)&1)x=f[x][i];
	if(x==y)return x;
	for(int i=19;i>=0;i--)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}
int tag[1201000][2],lc[1201000],su[1200100];
void build(int p,int l,int r){
	if(l==r){lc[p]=l;return;}
	int mid=(l+r)>>1;
	build(p<<1,l,mid),build(p<<1|1,mid+1,r);
	lc[p]=lca(lc[p<<1],lc[p<<1|1]);
}
void ad(int p,int z){
	su[p]=z?lc[p]:0;
	tag[p][z^1]=0,tag[p][z]=1;
}
void pd(int p){
	for(int z=0;z<2;z++)if(tag[p][z])
		ad(p<<1,z),ad(p<<1|1,z),tag[p][z]=0;
}
void up(int p,int l,int r,int x,int y,int z){
	if(x<=l&&r<=y)return ad(p,z);
	if(y<l||x>r)return;
	pd(p);int mid=(l+r)>>1;
	up(p<<1,l,mid,x,y,z),up(p<<1|1,mid+1,r,x,y,z);
	su[p]=lca(su[p<<1],su[p<<1|1]);
}
int main(){
	cin>>n>>q;N=2*n-1;
	for(int i=1;i<=N;i++)fa[i]=i;
	for(int i=1;i<n;i++)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
	for(int i=1;i<=n;i++)val[i]=-1;
	sort(a+1,a+n,cmp);
	for(int i=1;i<n;i++){
		int u=find(a[i].x),v=find(a[i].y);
		g[n+i].push_back(u),g[n+i].push_back(v);
		fa[u]=fa[v]=n+i;val[n+i]=a[i].w;
	}
	dfs(N);build(1,1,n);
	for(int i=0,ty,x,y;i<q;i++){
		scanf("%d%d",&ty,&x);
		if(ty<=2)scanf("%d",&y),up(1,1,n,x,y,2-ty);
		else printf("%d\n",val[lca(x,su[1])]);
	}
	return 0;
}