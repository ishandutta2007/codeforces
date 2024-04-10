#include<bits/stdc++.h>
using namespace std;
const int N=5+1e5;
struct Graph{
	struct Edge{ int to,nxt; };
	vector<int> head;
	vector<Edge> edge;
	Graph(int n=0,int m=0){
		head=vector<int>(n+1,-1); 
		edge.clear(); edge.reserve(m);
	}
	inline void add(int x,int y){
		edge.push_back((Edge){y,head[x]});
		head[x]=edge.size()-1;
	}
}G;
struct E{ int x,y; };
vector<pair<E,E> > g;
int dfs(int x,int pre){
	int kx=0;
	vector<pair<E,E> > gx;
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(y==pre) continue;
		int k=dfs(y,x);
		if(k==0) continue;
		if(kx==-1)
			gx.push_back(make_pair((E){k,y},(E){x,y}));
		else if(kx==0) kx=k;
		else{
			gx.push_back(make_pair((E){k,kx},(E){x,pre}));
			kx=-1;
		}
	}
	for(int i=(int)gx.size()-1;i>=0;--i) g.push_back(gx[i]);
	if(kx==0) kx=x;
	if(kx==-1) return 0;
	else{
		if(pre==0){
			g.push_back(make_pair((E){kx,x},(E){x,pre}));
			return 0;
		}return kx;
	}
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		G=Graph(n,n+n); g.clear();
		for(int i=1;i<n;++i){
			int x,y; scanf("%d%d",&x,&y);
			G.add(x,y); G.add(y,x);
		}
		dfs(1,0);
		printf("%d\n",int(g.size())-1);
		for(int i=0;i+1<g.size();++i)
			printf("%d %d %d %d\n",g[i].second.x,g[i].second.y,g[i].first.y,g[i+1].first.x);
	}
	return 0;
}