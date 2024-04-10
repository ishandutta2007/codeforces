#include<bits/stdc++.h>
using namespace std;
struct edge{
	int to,cap;
	long long cst;
	int rev;
};
vector<edge>g[53];
void add_edge(int x,int y,int cap,long long cst){
	g[x].push_back((edge){y,cap,cst,g[y].size()});
	g[y].push_back((edge){x,0,-cst,g[x].size()-1});
}
vector<int>v;
int prevv[53],preve[53];
long long dist[53];
long long min_cost_flow(int s,int t){
	long long ret=0;
	while(1){
		memset(dist,31,sizeof(dist));
		priority_queue<pair<long long,int> >Q;
		dist[s]=0;
		Q.push(make_pair(0,s));
		while(Q.size()){
			long long len=-Q.top().first;
			int nw=Q.top().second;Q.pop();
			if(dist[nw]<len)continue;
			for(int i=0;i<g[nw].size();i++){
				edge &e=g[nw][i];
				if(e.cap>0&&dist[e.to]>dist[nw]+e.cst)
					dist[e.to]=dist[nw]+e.cst,
					prevv[e.to]=nw,preve[e.to]=i,
					Q.push(make_pair(-dist[e.to],e.to));
			}
		}
		if(dist[t]>=192608172)break;
		v.push_back(dist[t]);
		int f=2333;
		for(int v=t;v!=s;v=prevv[v])
			f=min(f,g[prevv[v]][preve[v]].cap);
		ret+=1ll*f*dist[t];
		for(int v=t;v!=s;v=prevv[v]){
			edge &e=g[prevv[v]][preve[v]];
			e.cap-=f,g[v][e.rev].cap+=f;
		}
	}return ret;
}
int n,m;
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y,w;
		cin>>x>>y>>w;x--;y--;
		add_edge(x,y,1,w);
	}min_cost_flow(0,n-1);
	int T;
	cin>>T;
	while(T--){
		int xi;
		cin>>xi;
		double ans=114514191,sum=0;
		for(int i=0;i<v.size();i++)
			sum+=v[i],
			ans=min(ans,(sum+xi)/(i+1));
		printf("%.9lf\n",ans);
	}
}