#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second 
int tms,low[300004],vis[300004],cmp[300004],cnt;
vector<pii>g[300004];
int p[300004],d[300004],c[300004];
stack<int>st;
void tarjan(int x){
	vis[x]=low[x]=++tms;
	st.push(x); 
	for(auto y:g[x])if(p[x]!=y.fi){
		if(vis[y.fi])low[x]=min(low[x],vis[y.fi]);
		else p[y.fi]=x,d[y.fi]=y.se,tarjan(y.fi),low[x]=min(low[x],low[y.fi]);
	}
	if(low[x]==vis[x]){
		++cnt;
		while(1){
			int u=st.top();st.pop();
			cmp[u]=cnt;if(u==x)break;
		}
	}
}
int n,m,a,b;
void dfs(int x){
	if(low[x]==vis[x]){
		if(d[x]||c[cmp[x]]){
			puts("YES");
			exit(0);
		}
	}
	if(x!=a)dfs(p[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		g[u].push_back(mkp(v,w)),g[v].push_back(mkp(u,w));
	}
	scanf("%d%d",&a,&b);
	tarjan(a);
	for(int i=1;i<=n;i++)for(auto y:g[i])
		if(cmp[y.fi]==cmp[i])c[cmp[i]]|=y.se;
	dfs(b);
	puts("NO");
}