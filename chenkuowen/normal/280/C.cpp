#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
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
ld dfs(int x,int pre,int dep){
	ld ret=1.0/dep;
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(y!=pre)
			ret+=dfs(y,x,dep+1);
	}
	return ret;
}
int main(){
	int n; scanf("%d",&n);
	G=Graph(n,n);
	for(int i=1;i<n;++i){
		int x,y; scanf("%d%d",&x,&y);
		G.add(x,y); G.add(y,x);
	}
	printf("%.14Lf\n",dfs(1,0,1));
	return 0;
}