#include<bits/stdc++.h>
using namespace std;

const int maxn=300005;
const long long mdn=998244353ll;

int n;
vector<int> adj[maxn];
bool vis[maxn];
bool col[maxn];
long long pwr2[maxn];
long long c0=0,c1=0;
bool nok=0;

void dfs(int u){
	if(col[u]) c1++;
	else c0++;
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i];
		if(vis[v]){
			if(col[v]!=(!col[u]))nok=1;
			continue;
		}
		col[v]=(!col[u]);
		vis[v]=1;
		dfs(v);
	}
}

int main(){
	pwr2[0]=1;
	for(int i=1;i<maxn;i++) pwr2[i]=(pwr2[i-1]*2ll)%mdn;
	int t;
	scanf("%d",&t);
	while(t--){
		int m;
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++) adj[i].clear();
		for(int i=1;i<=n;i++) vis[i]=0;
		while(m--){
			int u,v;
			scanf("%d %d",&u,&v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		nok=0;
		long long ans=1;
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				vis[i]=1;
				col[i]=0;
				c0=c1=0;
				dfs(i);
				long long cur=(pwr2[c0]+pwr2[c1])%mdn;
				ans=(ans*cur)%mdn;
			}
		}
		if(nok) cout<<0<<endl;
		else cout<<ans<<endl;
	}
	return 0; 
} //qwq
//eiakioifwjeifpwejfiweajfiwehfipuwefiejwaf