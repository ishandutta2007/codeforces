#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,q;
vector<int>g[200004],num[200004];
int cmp[200004],cnt,low[200004],vis[200004],t;
stack<int>st;
bool instack[200004];
void tarjan(int x){
	vis[x]=low[x]=++cnt;
	st.push(x),instack[x]=1; 
	for (int i=0;i<g[x].size();i++){
		if (!vis[g[x][i]]) tarjan(g[x][i]);
		if (instack[g[x][i]]) low[x]=min(low[x],low[g[x][i]]);
	}
	if (vis[x]==low[x]){
		t++;
		while (st.top()!=x){
			cmp[st.top()]=t,instack[st.top()]=0,st.pop();
		}
		st.pop(),cmp[x]=t,instack[x]=0;
	}
}
ll gcd(ll A,ll B){
	return B==0?A:gcd(B,A%B);
}
ll dis[200004],C[200004];
void dfs(int x,int p){
	vis[x]=1;
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if(cmp[y]!=p)continue; 
		if(!vis[y])dis[y]=dis[x]+num[x][i],dfs(y,p);
		ll W=dis[x]+num[x][i]-dis[y];
		if(W!=0){
			if(C[p]==0)C[p]=W;
			else C[p]=gcd(C[p],abs(W));
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		g[u].push_back(v),num[u].push_back(w);
	}
	for(int i=1;i<=n;i++)if(!vis[i])tarjan(i);
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i,cmp[i]);
	scanf("%d",&q);
	while(q--){
		int V,S,T;scanf("%d%d%d",&V,&S,&T);
		if(C[cmp[V]]==0)puts(S==0?"YES":"NO");
		else puts(S%gcd(T,C[cmp[V]])==0?"YES":"NO"); 
	}
}