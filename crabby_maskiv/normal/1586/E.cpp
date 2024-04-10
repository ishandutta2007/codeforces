#include<bits/stdc++.h>
#define fr first
#define sc second
#define mkp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=3e5+5;
int n,m;
vector<int> g[N];
int fa[N];
int rt(int u){
	if(fa[u]==u) return u;
	return fa[u]=rt(fa[u]);
}
int h[N],par[N];
void dfs(int u){
	h[u]=h[par[u]]+1;
	for(auto v:g[u]){
		if(v==par[u]) continue;
		par[v]=u;
		dfs(v);
	}
}
vector<int> ans[N];
int vis[N];
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) fa[i]=i;
	for(i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		if(rt(u)==rt(v)) continue;
		fa[rt(u)]=rt(v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1);
	int q;scanf("%d",&q);
	for(j=1;j<=q;j++){
		int x,y;cin>>x>>y;
		vis[x]^=1;vis[y]^=1;
		vector<int> ans1,ans2;
		while(x!=y){
			if(h[x]>h[y]){
				ans1.pb(x);
				x=par[x];
			}
			else{
				ans2.pb(y);
				y=par[y];
			}
		}
		for(i=0;i<ans1.size();i++) ans[j].pb(ans1[i]);
		ans[j].pb(x);
		for(i=(int)ans2.size()-1;i>=0;i--) ans[j].pb(ans2[i]);
	}
	int cnt=0;
	for(i=1;i<=n;i++) cnt+=vis[i];
	if(cnt==0){
		puts("YES");
		for(i=1;i<=q;i++){
			printf("%d\n",(int)ans[i].size());
			for(auto x:ans[i]) printf("%d ",x);
			puts("");
		}
	}
	else{
		printf("NO\n%d",(cnt/2)+(cnt%2)*2);
	}
	return 0;
}