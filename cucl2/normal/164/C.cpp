#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int Inf=0x3f3f3f3f;

struct Edge{
	int to,cap,rev,cost;
	Edge(int to,int cap,int rev,int cost):to(to),cap(cap),rev(rev),cost(cost){}
};

vector<Edge> egs[2005];
int prv[2005],pre[2005];
int dist[2005],sh[2005];
int whr[2005][2005];
int n,m;

void NewEdge(int u,int v,int cap,int cost){
	//cerr<<u<<' '<<v<<' '<<cost<<endl;
	whr[u][v]=egs[u].size();
	whr[v][u]=egs[v].size();
	egs[u].push_back(Edge(v,cap,egs[v].size(),cost));
	egs[v].push_back(Edge(u,0,egs[u].size()-1,-cost));
}

bool Bellman_ford(int frm,int to){
	memset(dist,0x3f,sizeof(dist));
	dist[frm]=0;
	bool upd=1;
	while(upd){
		upd=0;
		for(int i=0;i<=2*n+2;i++){
			if(dist[i]==Inf){
				continue;
			}
			for(int j=0;j<egs[i].size();j++){
				Edge &e=egs[i][j];
				if(e.cap&&dist[i]+e.cost<dist[e.to]){
					dist[e.to]=dist[i]+e.cost;
					prv[e.to]=i;
					pre[e.to]=j;
					//cerr<<i<<' '<<j<<' '<<dist[i]<<' '<<dist[to]<<endl;
					upd=1;
				}
			}
		}
	}
	return dist[to]!=Inf;
}

int calc(int frm,int to){
	int cost=0;
	while(Bellman_ford(frm,to)){
		int Cap=Inf;
		for(int i=to;i!=frm;i=prv[i]){
			Cap=min(Cap,egs[prv[i]][pre[i]].cap);
		}
		for(int i=to;i!=frm;i=prv[i]){
			egs[prv[i]][pre[i]].cap-=Cap;
			egs[i][egs[prv[i]][pre[i]].rev].cap+=Cap;
		}
		cost+=Cap*dist[to];
	}
	return cost;
}

int s[1005],t[1005],c[1005];

int main(){
	scanf("%d%d",&n,&m);
	NewEdge(0,2*n+1,m,0);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",s+i,t+i,c+i);
		t[i]+=s[i];
		NewEdge(2*n+1,i,1,0);
		NewEdge(i,i+n,1,-c[i]);
		NewEdge(i+n,2*n+2,1,0);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(t[i]<=s[j]){
				NewEdge(i+n,j,1,0);
			}
		}
	}
	calc(0,2*n+2);
	for(int i=1;i<=n;i++){
		if(egs[i][whr[i][i+n]].cap==0){
			printf("1 ");
		}else{
			printf("0 ");
		}
	}
	return 0;
}