#include<bits/stdc++.h>
using namespace std;
int n,m,K;
vector<int>g[100004];
int par[18][100004],d[100004];
int res=1e9,ans[3];
bool vis[100004];
void mk(int x,int p,int depth){
	par[0][x]=p,d[x]=depth,vis[x]=1;
	for(int i=0;i<g[x].size();i++)if(!vis[g[x][i]])mk(g[x][i],x,depth+1);
}
int lca(int u,int v){
	if (d[u]>d[v]) swap(u,v);
	for (int i=17;i>=0;i--) if ((d[v]-d[u])&(1<<i)) v=par[i][v];
	if (u==v) return u;
	for (int i=17;i>=0;i--)
		if (par[i][u]!=par[i][v]) u=par[i][u],v=par[i][v];
	return par[0][u];
}
vector<int>ret;
void go(int now,int W,bool w){
	if(W==now)return;
	if(!w)ret.push_back(now);
	go(par[0][now],W,w);
	if(w)ret.push_back(now);
}
int main(){
	cin>>n>>m>>K;
	for(int i=0;i<m;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u); 
	}
	memset(par,-1,sizeof(par));
	mk(1,-1,0);
	for(int i=1;i<18;i++)
		for(int j=1;j<=n;j++)if(par[i-1][j]>=0)
			par[i][j]=par[i-1][par[i-1][j]];
	for(int i=1;i<=n;i++)
		for(int j=0;j<g[i].size();j++)if(g[i][j]!=par[0][i] && par[0][g[i][j]]!=i){
			int pos=lca(i,g[i][j]);
			if(d[i]+d[g[i][j]]-2*d[pos]<res)res=d[i]+d[g[i][j]]-2*d[pos]+1,ans[0]=pos,ans[1]=i,ans[2]=g[i][j];
		}
		go(ans[1],ans[0],0);
		ret.push_back(ans[0]);
		go(ans[2],ans[0],1);
	if(res<=K){
		puts("2");cout<<res<<"\n";
		for(int i=0;i<res;i++)printf("%d ",ret[i]); 
		return 0;
	}
	puts("1");
	if(res==1e9){
		vector<int>ver[2];
		for(int i=1;i<=n;i++){
			if(d[i]%2==0)ver[0].push_back(i);
			else ver[1].push_back(i);
		}
		if(ver[0].size()>=(K+1)/2)for(int i=0,j=0;j<(K+1)/2;i++,j++) cout<<ver[0][i]<<" ";
		else for(int i=0,j=0;j<(K+1)/2;i++,j++) cout<<ver[1][i]<<" ";
	}else for(int i=0,j=0;j<(K+1)/2;i+=2,j++)cout<<ret[i]<<" ";
}