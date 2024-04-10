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
const int N=2e5+100;
int n,vis[N];vector<int>e[N],a[N],b[N];
void add(int u,int v){e[u].pb(v);e[v].pb(u);}
void dfs(int u){for(auto v:e[u])if(vis[v]==-1)vis[v]=vis[u]^1,dfs(v);}
signed main(){
	read(n);memset(vis,0xff,sizeof vis);
	for(int i=1,x,y;i<=n;i++)read(x,y),a[x].pb(i),b[y].pb(i);
	for(int i=1;i<N;i++)for(int j=0;j+1<(int)a[i].size();j+=2)add(a[i][j],a[i][j+1]);
	for(int i=1;i<N;i++)for(int j=0;j+1<(int)b[i].size();j+=2)add(b[i][j],b[i][j+1]);
	for(int i=1;i<=n;i++)if(vis[i]==-1)vis[i]=0,dfs(i);
	for(int i=1;i<=n;i++)pc(vis[i]?'r':'b');
}