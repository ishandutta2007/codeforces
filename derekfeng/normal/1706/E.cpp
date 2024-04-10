#include<bits/stdc++.h>
using namespace std;
int t,n,m,q,f[300005],rt,lg[600005],sn[300005][2];
int N,st[20][600005],pos[600005],ver[600005];
int F(int x){return x==f[x]?x:f[x]=F(f[x]);}
void dfs(int x){
	pos[x]=++N,ver[N]=x,st[0][N]=N;
	if(x<=n)return;
	dfs(sn[x][0]);
	st[0][++N]=pos[x];
	dfs(sn[x][1]);
}
int qry(int u,int v){
	if(!u||!v)return u|v;
	int l=pos[u],r=pos[v];
	if(r<l)swap(l,r);
	int Lg=lg[r-l];
	return ver[min(st[Lg][l],st[Lg][r-(1<<Lg)+1])];
}
int dat[262200];
void built(int i,int l,int r){
	if(l==r)dat[i]=l;
	else{
		int md=(l+r)>>1;
		built(i<<1,l,md),built(i<<1|1,md+1,r);
		dat[i]=qry(dat[i<<1],dat[i<<1|1]);
	}
}
int ask(int i,int l,int r,int a,int b){
	if(r<a||b<l)return 0;
	if(a<=l&&r<=b)return dat[i];
	int md=(l+r)>>1;
	return qry(ask(i<<1,l,md,a,b),ask(i<<1|1,md+1,r,a,b));
}
void sol(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		u=F(u),v=F(v);
		if(u==v)continue;
		sn[n+i][0]=u,sn[n+i][1]=v,rt=n+i;
		f[n+i]=f[u]=f[v]=n+i;
	}
	N=0,dfs(rt);
	for(int i=1;i<=lg[N];i++)
		for(int j=1;j+(1<<i)-1<=N;j++)
			st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	built(1,1,n);
	while(q--){
		int l,r;scanf("%d%d",&l,&r);
		if(l==r)printf("0 ");
		else printf("%d ",ask(1,1,n,l,r)-n);
	}puts("");
}
int main(){
	for(int i=2;i<=6e5;i++)lg[i]=lg[i>>1]+1;
	for(scanf("%d",&t);t--;)sol();
}