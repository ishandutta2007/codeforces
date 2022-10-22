#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define pb push_back
using namespace std;
const int N=3e5+10;
int n,m,x;long long a[N];vector<pair<int,int>>e[N];
struct DSU{
	int fa[N];
	void init(){for(int i=1;i<=n;i++)fa[i]=i;}
	int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
	void merge(int x,int y){x=find(x),y=find(y);x!=y&&(fa[x]=y);}
}D;
long long sum;
bool vis[N];
int ans[N],l,r;
void dfs(int u,int fa,int from){
	vis[u]=true;
	for(auto [v,id]:e[u]){
		if(vis[v])continue;
		dfs(v,u,id);
	}
	if(u==1)return;
	if(a[u]>=x)a[fa]+=a[u]-x,ans[l++]=from;
	else ans[--r]=from;
}
signed main(){
	scanf("%d%d%d",&n,&m,&x);D.init();l=1,r=n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		e[x].pb(mp(y,i));e[y].pb(mp(x,i));D.merge(x,y);
	}
	for(int i=1;i<=n;i++)if(D.find(i)!=D.find(1))return puts("NO"),0;
	if(1ll*(n-1)*x>sum)return puts("NO"),0;
	puts("YES");;dfs(1,0,0);
	for(int i=1;i<n;i++)printf("%d\n",ans[i]);
}