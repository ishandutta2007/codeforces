#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
int n,m,u[500005],v[500005];
int bel[500005],num[500005],mx[500005],mn[500005],dp[500005],f[500005];
vector<int>g[500005],edg[500005];
vector<pii>G[500005];
int p[500005],tms,cnt,low[500005],vis[500005];
stack<int>st;
void tarjan(int x){
	vis[x]=low[x]=++tms;
	st.push(x);
	for(auto y:g[x]){
		if(vis[y])low[x]=min(low[x],vis[y]);
		else{
			tarjan(y),low[x]=min(low[x],low[y]);
			if(low[y]==vis[x]){
				++cnt;
				while(1){
					int u=st.top();st.pop();p[u]=cnt;
					if(u==y)break;
				}
			}
		}
	}
}
bool got(int x,int fa,int c,int id){
	for(auto y:G[x])if(y.fi!=fa){
		if(y.se==id)return 1;
		if(y.se<c)return 0;
		return got(y.fi,x,y.se,id);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u[i],&v[i]);
		g[u[i]].push_back(v[i]),g[v[i]].push_back(u[i]);
	}
	tarjan(1),p[1]=++cnt;
	for(int i=1;i<=cnt;i++)mx[i]=0,mn[i]=1e9;
	for(int i=1;i<=m;i++){
		if(p[v[i]]<p[u[i]])swap(u[i],v[i]);
		bel[i]=p[u[i]],num[p[u[i]]]++,edg[bel[i]].push_back(i);
		mx[bel[i]]=max(mx[bel[i]],i);
		mn[bel[i]]=min(mn[bel[i]],i);
	}
	for(int i=1;i<=n;i++)dp[i]=1;
	for(int i=m;i;i--){
		int x=u[i],y=v[i];
		f[i]=dp[x]+dp[y];
		if(num[bel[i]]!=1&&mn[bel[i]]==i){
			for(auto x:edg[bel[i]])G[u[x]].push_back({v[x],x}),G[v[x]].push_back({u[x],x});
			if(got(x,y,i,mx[bel[i]])&&got(y,x,i,mx[bel[i]]))f[i]-=f[mx[bel[i]]];
			for(auto x:edg[bel[i]])G[u[x]].clear(),G[v[x]].clear();
		}
		dp[x]=f[i],dp[y]=f[i];
	}
	for(int i=1;i<=n;i++)printf("%d ",dp[i]-1);
}