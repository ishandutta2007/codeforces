#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int M=998244353;
int myp(int x,int t){
	int r=1;
	for(;t;t>>=1,x=(ll)x*x%M)
		if(t&1)r=(ll)r*x%M;
	return r;
}
vector<int>fc[200004];
int n,inv[200004],ans;
vector<pair<int,pii> >g[200004];
int mn[200004],val[200004];
void dfs(int u,int fa){
	for(auto [v,w]:g[u])if(v!=fa){
		auto [x,y]=w;
		for(auto t:fc[x]){
			val[t]--;
			mn[t]=max(mn[t],-val[t]);
		}
		for(auto t:fc[y])val[t]++;
		dfs(v,u);
		for(auto t:fc[y])val[t]--;
		for(auto t:fc[x])val[t]++;
	}
}
void dfs1(int u,int fa,int val){
	(ans+=val)%=M;
	for(auto [v,w]:g[u])if(v!=fa){
		auto [x,y]=w;
		int vv=val;
		for(auto t:fc[x])vv=(ll)vv*inv[t]%M;
		for(auto t:fc[y])vv=(ll)vv*t%M;
		dfs1(v,u,vv);
	}
}
void sol(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)g[i].clear(),mn[i]=val[i]=0;
	for(int i=1;i<n;i++){
		int u,v,x,y;
		scanf("%d%d%d%d",&u,&v,&x,&y);
		int G=__gcd(x,y);x/=G,y/=G;
		g[u].push_back({v,{x,y}});
		g[v].push_back({u,{y,x}});
	}
	dfs(1,0);
	int cur=1;
	for(int i=1;i<=n;i++)while(mn[i]--)cur=(ll)cur*i%M;
	ans=0,dfs1(1,0,cur);
	printf("%d\n",ans);
}
int main(){
	for(int i=0;i<=2e5;i++)inv[i]=myp(i,M-2);
	for(int i=1;i<=2e5;i++){
		int ii=i;
		for(int j=2;j*j<=ii;j++)if(ii%j==0)
			while(ii%j==0)
				fc[i].push_back(j),ii/=j;
		if(ii>1)fc[i].push_back(ii);
	}
	int t;scanf("%d",&t);
	while(t--)sol();
}