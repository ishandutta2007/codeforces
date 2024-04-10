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
const int N=1e5+100,M=18;
int n,m,lst,leaves,tot;
vector<pair<int,int>>e[N];
int dis[N];pair<int,int>mx;
void dfs(int u,int fa){
	chkmx(mx,mp(dis[u],u));
	for(auto E:e[u])if(E.fi!=fa)dis[E.fi]=dis[u]+E.se,dfs(E.fi,u);
}
struct Tree{
	int fa[N][M],top[N],son[N],rk[N],dep[N],dis[N],h[N],pre[N];
	void dfs1(int u){
		for(int i=1;i<M;i++)fa[u][i]=fa[fa[u][i-1]][i-1];
		for(auto E:e[u]){
			int v,w;tie(v,w)=E;
			if(v==fa[u][0])continue;
			fa[v][0]=u;dep[v]=dep[u]+1;dis[v]=dis[u]+w;
			dfs1(v);if(h[v]+w>h[u])h[u]=h[v]+w,son[u]=v;
		}
	}
	void dfs2(int u){
		if(!top[u])top[u]=u;
		if(son[u])top[son[u]]=top[u];
		for(auto E:e[u]){
			int v,w;tie(v,w)=E;
			if(v==fa[u][0])continue;
			dfs2(v);
		}
	}
	void init(int rt){
		dfs1(rt);
		dfs2(rt);
		vector<pair<int,int>>kk;
		for(int i=1;i<=n;i++)if(top[i]==i)
			kk.eb(h[i]+dis[i]-dis[fa[i][0]],i);
		sort(kk.begin(),kk.end());reverse(kk.begin(),kk.end());
		for(int i=0;i<(int)kk.size();i++)rk[kk[i].se]=i+1,pre[i+1]=pre[i]+kk[i].fi;
		for(int i=1;i<=n;i++)if(i!=top[i])rk[i]=rk[top[i]];
	}
	int calc1(int x,int y){
		//y-1x
		int u=x;
		for(int i=M-1;~i;i--)if(rk[fa[u][i]]>=y)
			u=fa[u][i];
		return pre[y-1]+h[x]+dis[x]-dis[fa[u][0]];
	}
	int calc2(int x,int y){
		//
		int u=x;
		for(int i=M-1;~i;i--)if(rk[fa[u][i]]>y)
			u=fa[u][i];
		return pre[y]-h[fa[u][0]]+h[x]+dis[x]-dis[fa[u][0]];
	}
	int calc(int x,int y){
		(y*=2)--;
		return rk[x]<=y?pre[y]:max(calc1(x,y),calc2(x,y));
	}
}T[2];
signed main(){
	//freopen("1.in","r",stdin);
	read(n,m);
	for(int i=1,u,v,w;i<n;i++)read(u,v,w),e[u].eb(v,w),e[v].eb(u,w),tot+=w;
	dfs(1,0);int st=mx.se;mx=mp(0,0);dfs(st,0);int ed=mx.se;//writeln(st,ed);
	for(int i=1;i<=n;i++)if(e[i].size()==1u)leaves++;
	T[0].init(st);T[1].init(ed);
	while(m--){
		int x,y;read(x,y);x=(x+lst-1)%n+1,y=(y+lst-1)%n+1;//writeln(x,y);
		writeln(lst=(leaves<=2*y?tot:max(T[0].calc(x,y),T[1].calc(x,y))));
	}
}