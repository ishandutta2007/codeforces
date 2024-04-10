#include<bits/stdc++.h>
//ll
typedef long long ll;
const ll INF=1e18;
const int N=1e5+3,K=20;
int n,a[N],b[N],mn,mx,ls[N*K],rs[N*K],t,rt[N];
struct line{
	ll a,b;
	inline ll F(ll x){return a*x+b;}
}s[N*K];
ll dp[N];
std::vector<int>g[N];
#define M (L+R>0?(L+R)/2:(L+R-1)/2)
void Insert(line a,int L,int R,int&k){
	if(!k){s[k=++t]=a;return;}
	if(a.F(M)<s[k].F(M))std::swap(a,s[k]);
	if(L==R)return;
	a.a>s[k].a?Insert(a,L,M,ls[k]):Insert(a,M+1,R,rs[k]);
}
void Merge(int L,int R,int&k0,int k1){
	if(!k0||!k1){k0|=k1;return;}
	Merge(L,M,ls[k0],ls[k1]),Merge(M+1,R,rs[k0],rs[k1]);
	Insert(s[k1],L,R,k0);
}
ll Min(int x,int L,int R,int k){
	if(!k)return INF;
	if(L==R)return s[k].F(x);
	return std::min(s[k].F(x),x<=M?Min(x,L,M,ls[k]):Min(x,M+1,R,rs[k]));
}
void Dfs(int u,int fa){
	for(int v:g[u])if(v!=fa){
		Dfs(v,u);
		Merge(mn,mx,rt[u],rt[v]);
	}
	dp[u]=rt[u]?Min(a[u],mn,mx,rt[u]):0;
	Insert((line){b[u],dp[u]},mn,mx,rt[u]);
}
int main(){
	int u,v;
	scanf("%d",&n);
	mx=-N,mx=+N;
	for(u=1;u<=n;u++)scanf("%d",a+u),mx=std::max(mx,a[u]),mn=std::min(mn,a[u]);
	for(u=1;u<=n;u++)scanf("%d",b+u);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),g[u].push_back(v),g[v].push_back(u);
	Dfs(1,0);
	for(u=1;u<=n;u++)printf("%lld ",dp[u]);puts("");
	return 0;
}