#include<bits/stdc++.h>
using namespace std;
int T,t[403],cnt[403],vis[403],n;
const int MAX_V=1003,INF=233333;
struct edge{int to,cap,cost,rev;};
vector<edge>G[MAX_V];
int dist[MAX_V],prevv[MAX_V],preve[MAX_V],V;
void add_edge(int from,int to,int cap,int cost){
	//cout<<from<<' '<<to<<' '<<cap<<' '<<cost<<endl;
	G[from].push_back((edge){to,cap,cost,G[to].size()});
	G[to].push_back((edge){from,0,-cost,G[from].size()-1});
}
int min_cost_flow(int s,int t,int f){
	int res=0;
	while(f>0){
		for(int i=s;i<=t;i++)
			dist[i]=233333;
		dist[s]=0;
		bool upd=1;
		while(upd){
			upd=0;
			for(int v=0;v<=800;v++){
				if(dist[v]==INF)continue;
				for(int i=0;i<G[v].size();i++){
					edge &e=G[v][i];
					if(e.cap>0&&dist[e.to]>dist[v]+e.cost){
						dist[e.to]=dist[v]+e.cost;
						prevv[e.to]=v;
						preve[e.to]=i;
						upd=1;
					}
				}
			}
		}
		if(dist[t]==INF)
			return -1;
		int d=f;
		for(int v=t;v!=s;v=prevv[v])
			d=min(d,G[prevv[v]][preve[v]].cap);
		f-=d;
		res+=d*dist[t];
		for(int v=t;v!=s;v=prevv[v]){
			edge &e=G[prevv[v]][preve[v]];
			e.cap-=d;
			G[v][e.rev].cap+=d;
		}
	}
	return res;
}
int main(){
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=403;i++)
			G[i].clear();
		for(int i=1;i<=n;i++)
			cin>>t[i];
		for(int i=1;i<=n;i++)
			add_edge(0,i,1,0);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=400;j++)
				add_edge(i,j+300,1,fabs(t[i]-j));
		for(int j=301;j<=700;j++)
			add_edge(j,800,1,0);
		cout<<min_cost_flow(0,800,n)<<endl;
	}
}