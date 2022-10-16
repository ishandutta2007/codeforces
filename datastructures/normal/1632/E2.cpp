#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define inf 1000000000
using namespace std;
int t,n,u[600005],v[600005],first[300005],nxt[600005];
int fa[300005][25],depth[300005];
vector<int> qwq[300005];
int ans[300005];
void dfs(int now,int f,int d){
	fa[now][0]=f;
	for (int i=1;i<=20;i++)fa[now][i]=fa[fa[now][i-1]][i-1];
	depth[now]=d;
	qwq[d].push_back(now);
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=f)dfs(v[i],now,d+1);
	return;
}
int lca(int a,int b){
	if (depth[a]<depth[b])swap(a,b);
	for (int i=20;i>=0;i--)
		if (depth[fa[a][i]]>=depth[b])a=fa[a][i];
	if (a==b)return a;
	for (int i=20;i>=0;i--)
		if (fa[a][i]!=fa[b][i])a=fa[a][i],b=fa[b][i];
	return fa[a][0];
}
int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	memset(depth,-1,sizeof(depth));
	while(t--){
		cin>>n;
		for (int i=1;i<n;i++){
			cin>>u[i]>>v[i];
			nxt[i]=first[u[i]],first[u[i]]=i;
			u[i+n]=v[i],v[i+n]=u[i];
			nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
		}
		dfs(1,0,0);
		int mxd=0;
		for (int i=1;i<=n;i++)mxd=max(mxd,depth[i]);
		int x=n;
		int mn=inf,mx=-inf;
		int delta=mn-mx;
		int val=mxd;
		for (int i=mxd;i>=1;i--){
			int l=qwq[i][0];
			for (int j=0;j<(int)qwq[i].size();j++)l=lca(l,qwq[i][j]);
			int c=val-x-(i-depth[l]);
			mx=max(mx,depth[l]-c);
			delta=min(delta,(depth[l]+c)-mx);
			mn=min(mn,depth[l]+c);
			int last=x;
			val--;
			mn--,mx++,delta-=2;
			while(x>0&&delta<0)x--,mn++,mx--,delta+=2;
			for (int j=x+1;j<=last;j++)ans[j]=val+1;
			if (x==0)break;
		}
		for (int i=1;i<=n;i++)cout<<ans[i]<<' ';
		cout<<endl;
		for (int i=0;i<=n;i++)first[i]=0,depth[i]=-1,qwq[i].clear();
		for (int i=1;i<=2*n;i++)nxt[i]=0;
	}
	return 0;
}