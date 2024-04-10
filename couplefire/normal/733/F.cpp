#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <queue>
using namespace std;
 
typedef long long LL;
typedef pair<int,int> mp;
#define pb push_back
const int maxn = 200005;
 
int n,m,a[maxn],b[maxn],c[maxn],w[maxn];
int ehead[maxn],ecnt,mst[maxn];
LL ans;int X,VX,S,dep[maxn],disp;
struct edge{
	int u,v,id,next;
}edg[maxn*2];
void add(int u,int v,int id) {
	edg[++ecnt]=(edge){u,v,id,ehead[u]};
	ehead[u]=ecnt;
	edg[++ecnt]=(edge){v,u,id,ehead[v]};
	ehead[v]=ecnt;
}
 
int par[20][maxn],maw[20][maxn];
void dfs(int u,int fa) {
	for (int v,j=ehead[u];j;j=edg[j].next)
	if ((v=edg[j].v)!=fa) {
		par[0][v]=u;maw[0][v]=edg[j].id;
		dep[v]=dep[u]+1;dfs(v,u);
	}
}
int maxE(int u,int v) {
	return w[u]>w[v]?u:v;
}
void sparse_table() {
	for (int j=1;j<20;j++)
	for (int i=1;i<=n;i++) {
		par[j][i]=par[j-1][par[j-1][i]];
		maw[j][i]=maxE(maw[j-1][i],maw[j-1][par[j-1][i]]);
	}
}
int lcaw(int u,int v) {
	int res=0;
	if (dep[u]<dep[v]) swap(u,v);
	for (int j=0,d=dep[u]-dep[v];d;d>>=1,++j)
	if (d&1) {
		res=maxE(res,maw[j][u]);
		u=par[j][u];
	}
	if (u==v) return res;
	for (int j=19;j>=0;j--)
	if (par[j][u]!=par[j][v]) {
		res=maxE(res,maw[j][u]);
		res=maxE(res,maw[j][v]);
		u=par[j][u];v=par[j][v];
	}
	res=maxE(res,maw[0][u]);
	res=maxE(res,maw[0][v]);
	return res;
}
 
 
 
int jpar[maxn];LL sum;
int findp(int t) {
	return jpar[t]?jpar[t]=findp(jpar[t]):t;
}
void merge(int u,int v,int id) {
	if (findp(u)==findp(v)) return ;
	sum+=w[id];jpar[findp(u)]=findp(v);
	mst[++mst[0]]=id;add(u,v,id);
}
struct node {
	int u,v,w,id;
	bool operator<(const node &v) const {
		return w<v.w;
	}
}p[maxn];
 
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("dissatisfaction.in","r",stdin);
		freopen("dissatisfaction.out","w",stdout);
	#endif
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d",&w[i]);
	for (int i=1;i<=m;i++) scanf("%d",&c[i]);
	for (int i=1;i<=m;i++) scanf("%d %d",&a[i],&b[i]);
	for (int i=1;i<=m;i++) p[i]=(node){a[i],b[i],w[i],i};
	scanf("%d",&S);sort(p+1,p+m+1);
	for (int i=1;i<=m;i++) merge(p[i].u,p[i].v,p[i].id);
	ans=sum;X=disp=mst[1];VX=w[X];dfs(1,0);sparse_table();
	for (int i=1;i<=m;i++) {
		int res=lcaw(a[i],b[i]);
		int nw=w[i]-S/c[i];
		if (sum-w[res]+nw<ans) {
			ans=sum-w[res]+nw;X=i;VX=nw;disp=res;
		}
	}
	printf("%lld\n",ans);
	for (int i=1;i<n;i++)
	if (mst[i]!=disp) printf("%d %d\n",mst[i],w[mst[i]]);
	printf("%d %d\n",X,VX);
	return 0;
}