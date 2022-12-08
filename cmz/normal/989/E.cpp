#include<bits/stdc++.h>
using namespace std;
const int N=300;
int n,x[N],y[N],m;
int cnt[N];
bool vis[N];
double g[N],tmp[N],f[20][N][N];
vector<int> G[N][N];
vector<pair<int,int> > line;
bool judge(int u,int v,int i){
	return (x[i]-x[v])*(y[v]-y[u])==(x[v]-x[u])*(y[i]-y[v]);
}
int main(){
	scanf("%d",&n);
	int i,j;	
	for(i=1;i<=n;++i) 
		scanf("%d%d",&x[i],&y[i]);
	for(i=1;i<=n;++i){
		memset(vis,0,sizeof(vis));
		for(j=1;j<=n;++j){
			if(vis[j]) continue;
			if(i==j) continue;
			++cnt[i];
			for(int u=1;u<=n;++u)
				if(judge(i,j,u)) G[i][j].push_back(u),vis[u]=1;
			line.push_back(make_pair(G[i][j][0],G[i][j][1]));
		} 
	} 
	
	sort(line.begin(),line.end());
	line.erase(unique(line.begin(),line.end()),line.end());
	
	for(int i=0;i<line.size();++i){
		vector<int> &vec=G[line[i].first][line[i].second];
		for(int u=0;u<vec.size();++u)
			for(int v=0;v<vec.size();++v) f[0][vec[u]][vec[v]]+=1.0/(1.0*vec.size()); 
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j) f[0][i][j]/=cnt[i];
	for(int i=1;i<=15;++i)
	{
		for(int u=1;u<=n;++u)
			for(int v=1;v<=n;++v)
				for(int k=1;k<=n;++k)
			     	f[i][u][v]+=f[i-1][u][k]*f[i-1][k][v];
	}
	scanf("%d",&m);
	for(int t=1;t<=m;++t){
		int goal,stp;
		scanf("%d%d",&goal,&stp);
		stp--;
		memset(g,0,sizeof(g));
		g[goal]=1;
		
		for(int i=0;(1<<i)<=stp;++i){
			if((1<<i)&stp){
				memset(tmp,0,sizeof(tmp));
				for(int u=1;u<=n;++u) if(g[u]>1e-6)
					for(int v=1;v<=n;++v)
						tmp[v]+=f[i][v][u]*g[u];
				memcpy(g,tmp,sizeof(tmp));
			}
		}
		double ans=-1;
		double hh=0;
		for(int i=0;i<line.size();++i){
			hh=0;
			vector<int> &vec=G[line[i].first][line[i].second];
			for(int j=0;j<vec.size();++j) hh+=g[vec[j]];
			hh/=1.0*vec.size();
			ans=max(ans,hh);
		}
		memset(tmp,0,sizeof(tmp));
		for(int u=1;u<=n;++u) if(g[u]>1e-6)
			for(int v=1;v<=n;++v)
				tmp[v]+=f[0][v][u]*g[u];
		for(int i=1;i<=n;++i) ans=max(ans,tmp[i]);
		printf("%lf\n",ans); 
	}
	return 0;
}