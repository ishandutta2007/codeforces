#include<bits/stdc++.h>
using namespace std;
const int N=5005,MOD=998244353;
inline int mo1(int x){ return x>=MOD?x-MOD:x; }
inline void mo(int& x){x>=MOD?x-=MOD:x; }
struct Graph{
	struct Edge{int to,nxt; };
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
vector<int> dfs(int x,int pre,int k){
	vector<int> f({1});
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(y==pre) continue;
		vector<int> g=dfs(y,x,k);
		int sum=0; for(auto d:g) mo(sum+=d);
		g.insert(g.begin(),sum);
		while(g.size()>k+1) g.pop_back();
//		for(auto x:g) printf("<%d>",x); puts("");
		vector<int> f1(max(g.size(),f.size()));
		for(int i=0;i<g.size();++i)
			for(int j=0;j<f.size();++j)
				if(i+j<=k) f1[max(i,j)]=(f1[max(i,j)]+1ll*g[i]*f[j])%MOD;
		swap(f,f1);
	}
//	printf("[%d]",x);
//	for(auto d:f) printf("<%d>",d); puts("");
	return f;
}
int main(){
	int n,k; scanf("%d%d",&n,&k);
	G=Graph(n,n);
	for(int i=1;i<n;++i){
		int x,y; scanf("%d%d",&x,&y);
		G.add(x,y); G.add(y,x);
	}
	vector<int> f=dfs(1,0,k);
	int ans=0;
	for(int i=0;i<f.size();++i)
		mo(ans+=f[i]);
	printf("%d\n",ans);
	return 0;
}