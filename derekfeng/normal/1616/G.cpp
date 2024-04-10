#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
vector<int>g[150004],rg[150004];
bool t[150004],vis[150004][2];
int l[150004],r[150004];
void dfs1(int x,int v){
	for(auto y:rg[x+1])if(l[x]<=y+1&&!vis[y][v^1])
		vis[y][v^1]=1,dfs1(y,v^1);
}
void dfs2(int x,int v){
	for(auto y:g[x])if(r[x+1]>=y-1&&!vis[y-1][v^1])
		vis[y-1][v^1]=1,dfs2(y-1,v^1);
}
int check(int l,int r){
	return (vis[l][0]&&vis[r-1][0])||(vis[l][1]&&vis[r-1][1]);
}
void sol(){
	scanf("%d%d",&n,&m);for(int i=0;i<=n+1;i++)g[i].clear(),rg[i].clear();
	for(int i=1;i<=n;i++){
		if(i>1)rg[i].push_back(0);
		if(i<n)g[i].push_back(n+1);
	}
	memset(t,0,sizeof(t)),t[0]=t[n]=1;
	for(int i=0;i<m;i++){
		int a,b;scanf("%d%d",&a,&b);
		if(a+1==b)t[a]=1;
		else g[a].push_back(b),rg[b].push_back(a);
	}
	ll ans=0;bool ok=1;l[0]=0;
	for(int i=1;i<=n+1;i++)l[i]=t[i-1]?l[i-1]:i;
	if(l[n+1]==0){printf("%lld\n",(ll)n*(n-1)/2);return;}
	r[n+1]=n+1;
	for(int i=n;i>=0;i--)r[i]=t[i]?r[i+1]:i;
	memset(vis,0,sizeof(vis));
	vis[r[1]][1]=1;
	dfs1(r[1],1),dfs2(r[1],1);
	int cnt0=0,cnt1=0;
	for(int i=0;i<=r[1];i++)cnt0+=vis[i][1];
	for(int i=n;i>=l[n]-1;i--)cnt1+=vis[i][1];
	ans+=(ll)cnt0*cnt1;
	cnt0=0,cnt1=0;
	for(int i=0;i<=r[1];i++)cnt0+=vis[i][0];
	for(int i=n;i>=l[n]-1;i--)cnt1+=vis[i][0];
	ans+=(ll)cnt0*cnt1;
	cnt0=0,cnt1=0;
	for(int i=0;i<=r[1];i++)cnt0+=vis[i][0]&&vis[i][1];
	for(int i=n;i>=l[n]-1;i--)cnt1+=vis[i][0]&&vis[i][1];
	ans-=(ll)cnt0*cnt1;
	if(r[1]==l[n]-1)ans-=check(r[1],r[1])+check(l[n],l[n])+check(r[1],l[n]);
	else if(r[1]==l[n]-2)ans-=check(r[1]+1,l[n]-1);
	printf("%lld\n",ans);
}
int main(){
	int T;scanf("%d",&T);
	while(T--)sol();
}