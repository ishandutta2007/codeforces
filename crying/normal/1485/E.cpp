#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define next Cry_For_theMoon
typedef long long ll;  
using namespace std;
const ll MAXN=2e5+10,INF=1e18;
int T,n,v,a[MAXN];
vector<int>edge[MAXN],vertix[MAXN];
int depth[MAXN],fa[MAXN];
ll f[MAXN],ans=0,d;
void dfs(int u,int f){
	vertix[depth[u]].push_back(u);
	d=max(d,(ll)depth[u]);
	int sz=edge[u].size(); 
	for(int j=0;j<sz;j++){
		int v=edge[u][j];
		if(v==f)continue;
		depth[v]=depth[u]+1;
		fa[v]=u;
		dfs(v,u);	
	}
}
bool cmp(int x,int y){
	return a[x]<a[y];
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		d=ans=0;
		rep(i,1,n)edge[i].clear(),vertix[i].clear();
		rep(i,2,n){
			scanf("%d",&v);
			edge[i].push_back(v);
			edge[v].push_back(i);
		}
		rep(i,2,n)scanf("%d",&a[i]);
		depth[1]=0,fa[1]=0;
		f[1]=0;
		dfs(1,0);
		rep(i,1,d){
			sort(vertix[i].begin(),vertix[i].end(),cmp);
			int sz=vertix[i].size();
			// 
			rep(j,0,sz-1){
				int u=vertix[i][j];
				f[u]=f[fa[u]]+max(abs(a[u]-a[vertix[i][0]]),abs(a[u]-a[vertix[i][sz-1]]));
			}
			//
			ll val=-INF;
			rep(j,0,sz-1){
				int u=vertix[i][j];
				f[u]=max(f[u],a[u]+val);
				val=max(val,f[fa[u]]-a[u]);
			} 
			val=-INF;
			per(j,sz-1,0){
				int u=vertix[i][j];
				f[u]=max(f[u],val-a[u]);
				val=max(val,f[fa[u]]+a[u]);
			}
			if(i==d){
				rep(j,0,sz-1)ans=max(ans,f[vertix[d][j]]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}