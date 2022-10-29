#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
vector<int>G[303000];
int n,m,T,x,y,l,r,fa[303000],dep[303000],nex[303000];
ll val[303000];
 
void doit(int x,int y){
	if (dep[x]<dep[y]) return;
	int mx=max(x,y), mn=min(x,y);
	for (;x-y; mx=max(x,mx), mn=min(x,mn)) x=fa[x];
	nex[mn]=min(nex[mn],mx-1);
}
 
void dfs(int x,int fff){
	fa[x]=fff, dep[x]=dep[fff]+1;
	for (auto y:G[x]) if (y-fff){
		if (dep[y]) doit(x,y);
		else dfs(y,x);
	}
}
 
int main(){
	for (cin>>n>>m;m--;){
		scanf("%d%d",&x,&y), G[x].push_back(y), G[y].push_back(x);
	}
	for (int i=1;i<=n;++i) nex[i]=n;
	for (int i=1;i<=n;++i) if (!dep[i]) dfs(i,0);
	for (int i=n-1;i;--i) nex[i]=min(nex[i],nex[i+1]);
	for (int i=1;i<=n;++i) val[i]=val[i-1]+nex[i]-i+1;
	for (cin>>T;T--;){
		scanf("%d%d",&l,&r);
		x=lower_bound(nex+1,nex+n+1,r)-nex;
		x=max(x-1,l-1);
		printf("%I64d\n",val[x]-val[l-1]+(r-x)*(r-x+1ll)/2);
	}
}