#include <iostream>
#include <cstdio>
#include <cstring>
#define ccf f***
#define ll long long
using namespace std;
int n;
ll a[200005],dist[200005],w[400005],ch[200005],sum[200005];
int u[400005],v[400005],first[200005],nxt[400005];
int depth[200005],fa[200005][25];
void swp(int &x,int &y){
	int t=x;
	x=y;
	y=t;
	return;
}
void add(int i,int uu,int vv,ll ww){
	u[i]=uu,v[i]=vv,w[i]=ww;
	nxt[i]=first[u[i]];
	first[u[i]]=i;
	return;
}
void dfs(int now,int f,int d,ll s){
	dist[now]=s;
	fa[now][0]=f;
	depth[now]=d;
	for (int i=1;i<=20;i++)fa[now][i]=fa[fa[now][i-1]][i-1];
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=f)dfs(v[i],now,d+1,s+w[i]);
	return;
}
ll dis(int u,int v){
	if (depth[u]>depth[v])swp(u,v);
	return dist[v]-dist[u];
}
void getsum(int now){
	sum[now]=ch[now];
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=fa[now][0]){
			getsum(v[i]);
			sum[now]+=sum[v[i]];
		}
	return;
}
int main(){
//	freopen("739B.in","r",stdin);
//	freopen("739B.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%I64d",&a[i]);
	for (int i=2;i<=n;i++){
		int vv;
		ll ww;
		scanf("%d%I64d",&vv,&ww);
		add(i,i,vv,ww);
		add(i+n,vv,i,ww);
	}
	memset(depth,-1,sizeof(depth));
	dfs(1,0,0,0);
	for (int i=1;i<=n;i++){
		int x=i;
		for (int j=20;j>=0;j--){
			if (fa[x][j]!=0&&dis(fa[x][j],i)<=a[i])x=fa[x][j];
		}
		ch[fa[i][0]]++,ch[fa[x][0]]--;
	}
	getsum(1);
	for (int i=1;i<n;i++)
		printf("%I64d ",sum[i]);
	cout<<sum[n]<<endl; 
	return 0;
}