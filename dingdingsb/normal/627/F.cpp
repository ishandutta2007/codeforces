#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef long long ll;
const int mod=998244353;
struct mint{
	int x;mint(int o=0){x=o;}mint&operator+=(mint a){return(x+=a.x)%=mod,*this;}mint&operator-=(mint a){return(x+=mod-a.x)%=mod,*this;}
	mint&operator*=(mint a){return(x=1ll*x*a.x%mod),*this;}mint&operator^=( int b){mint a=*this;x=1;while(b)(b&1)&&(*this*=a,1),a*=a,b>>=1;return*this;}
	mint&operator/=(mint a){return*this*=(a^=mod-2);}friend mint operator+(mint a,mint b){return a+=b;}friend mint operator-(mint a,mint b){return a-=b;}
	friend mint operator*(mint a,mint b){return a*=b;}friend mint operator/(mint a,mint b){return a/=b;}friend mint operator^(mint a, int b){return a^=b;}
};
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
#define orz puts("-1"),exit(0)
const int N=2e5+100;
int n,a[N],b[N],s,t,p,d[N];vector<int>e[N],A,B,diff;
int fa[N],dep[N];pair<int,int>mn=mp(0x3f3f3f3f,0);
bool vis[N];
vector<int>g;
bool dfs1(int u,int fa){
	g.pb(u);
	if(u==t)return 1;
	for(auto v:e[u])if(v^fa)if(dfs1(v,u))return 1;
	g.pop_back();return 0;
}
void dfs2(int u){
	dep[u]=dep[fa[u]]+1;
	if(a[u]^b[u]){
		vis[u]=1;diff.pb(u);
		if(mn.fi==dep[u]-1&&mn.se!=fa[u])orz;
		chkmn(mn,mp(dep[u]-1,fa[u]));
	}
	for(auto v:e[u])if(v!=fa[u])fa[v]=u,dfs2(v);
}
void dfs3(int u,int fa){
	if(u^p)A.pb(a[u]),B.pb(b[u]);
	for(auto v:e[u])if(vis[v]&&v!=fa)dfs3(v,u);
}
int lca(int u,int v){
	while(u!=v){
		if(dep[u]>=dep[v])u=fa[u];
		else v=fa[v];
	}
	return u;
}
int dis(int u,int v){return dep[u]+dep[v]-2*dep[lca(u,v)];}
int calc(){
	for(int i=0;i<(int)A.size();i++)if(B[i]==A[0]){
		for(int j=0;j<(int)A.size();j++)if(B[(i+j)%B.size()]!=A[j])return 0;
		return i;
	}return 0;
}
ll solve(int x,int y){
	int c=calc();
	return dis(s,x)+1ll*(c-1)*(A.size()+1)+1+dis(y,t);
}
signed main(){
	read(n);
	for(int i=1;i<=n;i++)read(a[i]),(a[i]==0)&&(s=i);
	for(int i=1;i<=n;i++)read(b[i]),(b[i]==0)&&(t=i);
	for(int i=1,u,v;i<n;i++)read(u,v),e[u].pb(v),e[v].pb(u);
	assert(dfs1(s,0));
	for(int i=0;i+1<(int)g.size();i++)swap(a[g[i]],a[g[i+1]]);
	for(int i=1;i<=n;i++)if(a[i]^b[i])goto wyhakioi;
	writeln(0,g.size()-1);return 0;wyhakioi:;
	dfs2(t);
	diff.pb(p=mn.se);vis[p]=1;
	for(auto u:diff)for(auto v:e[u])if(vis[v])d[u]++;
	vector<int>arr;
	for(auto u:diff)if(d[u]==1)arr.pb(u);else if(d[u]!=2)orz;
	if((int)arr.size()!=2)orz;
	if(arr[0]>arr[1])swap(arr[0],arr[1]);
	dfs3(arr[0],0);
	if(!calc())orz;
	ll ans=solve(arr[0],arr[1]);
	reverse(A.begin(),A.end());reverse(B.begin(),B.end());
	chkmn(ans,solve(arr[1],arr[0]));
	writeln(arr[0],arr[1],ans);
}