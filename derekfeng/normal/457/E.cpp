#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int inf=2147483646;
int n,m;
int u[200005],v[200005],w[200005];
vector<pii>g[200005];
int cmp[200005];
bool vis[200005];
int f[200005];
int mn[200005],mx[200005];
bool dfs(int u){
	vis[u]=1;
	mn[cmp[u]]=min(mn[cmp[u]],f[u]);
	mx[cmp[u]]=max(mx[cmp[u]],f[u]);
	for(auto [v,w]:g[u]){
		if(!vis[v]){
			f[v]=f[u]+w,cmp[v]=cmp[u];
			if(!dfs(v))return 0;
		}else if(f[v]!=f[u]+w)return 0;
	}
	return 1;
}
int check(int N){
	for(int i=1;i<=n;i++)g[i].clear(),vis[i]=0,mn[i]=inf,mx[i]=-inf;
	for(int i=1;i<=N;i++){
		g[u[i]].push_back({v[i],w[i]});
		g[v[i]].push_back({u[i],-w[i]});
	}
	for(int i=1;i<=n;i++)if(!vis[i]){
		f[i]=0,cmp[i]=i;
		if(!dfs(i))return -1;
	}
	for(int i=1;i<=n;i++){
		if(i>1&&cmp[i]==cmp[1]&&f[i]<=f[1])return -1;
		if(i<n&&cmp[i]==cmp[n]&&f[i]>=f[n])return -1;
	}
	if(cmp[n]!=1)return 0;
	for(int i=2;i<=n;i++)if(cmp[i]==i)
		if(f[n]-f[1]<=mx[i]-mn[i])return -1;
	return f[n];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,p,q;i<=m;i++)
		scanf("%d%d%d%d",&u[i],&v[i],&p,&q),w[i]=p*q;
	int l=0,r=m+2;
	while(r>l+1){
		int md=(l+r)>>1;
		if(md>m||check(md)<0)r=md;
		else l=md;
	}
	if(r<=m)printf("BAD %d",r);
	else{
		int tmp=check(m);
		if(tmp==0)puts("UNKNOWN");
		else printf("%d",tmp);
	}
}