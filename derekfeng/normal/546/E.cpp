#include <bits/stdc++.h>
using namespace std;
int n;
void outno(){
	puts("NO");exit(0); 
}
struct edge{
	int to,cap,rev;
};
vector<edge>g[1003];
bool vis[1003];
void add_edge(int from,int to,int val){
	g[from].push_back((edge){to,val,g[to].size()}); 
	g[to].push_back((edge){from,0,g[from].size()-1}); 
}
int dfs(int v,int t,int f){
	if (v==t) return f;
	vis[v]=1;
	for(int i=0;i<g[v].size();i++){
		edge &e=g[v][i];
		if (!vis[e.to] && e.cap>0){
			int d=dfs(e.to,t,min(f,e.cap));
			if (d>0){
				e.cap-=d;
				g[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s,int t){
	int flow=0;
	for (;;){
		memset (vis,0,sizeof(vis));
		int f=dfs(s,t,1e7);
		if (f==0) return flow;
		flow+=f;
	}
}
int ans[103][103];
int main(){
	int n,m,num1=0,num2=0;cin>>n>>m;
	for (int i=1;i<=n;i++){
		int x; 
		scanf("%d",&x);
		add_edge(0,i,x);
		num1+=x;
	}
	for (int i=1;i<=n;i++){
		int x;
		scanf ("%d",&x);
		add_edge(i+n,n*2+1,x);
		num2+=x;
	}
	if (num1!=num2) outno();
	for (int i=0;i<m;i++){
		int x,y;scanf ("%d%d",&x,&y);
		add_edge(x,y+n,1e7);
		add_edge(y,x+n,1e7); 
	}
	for (int i=1;i<=n;i++){
		add_edge(i,i+n,1e7);
	}
	int tmp=max_flow(0,2*n+1);
	if (tmp!=num1) outno();
	puts("YES");
	for (int i=1;i<=n;i++){
		for(int j=0;j<g[i+n].size();j++){
			if (g[i+n][j].to<=n)ans[g[i+n][j].to][i]=g[i+n][j].cap;
		}
	}
	for (int i=1;i<=n;i++,puts(""))for (int j=1;j<=n;j++) printf("%d ",ans[i][j]);
}