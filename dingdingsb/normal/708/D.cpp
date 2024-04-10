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
const int N=1e2+10,M=1e3+10,inf=2e9;
namespace G{
	int head[N],dis[N];bool inq[N];
	int v[M],w[M],c[M],nxt[M];
	int cnt=1,S,T;
	int lste[N],pre[N],flow[N];
	void adde(int U,int V,int W,int C){++cnt;v[cnt]=V,w[cnt]=W,c[cnt]=C,nxt[cnt]=head[U],head[U]=cnt;}
	void add(int U,int V,int W,int C){adde(U,V,W,C);adde(V,U,0,-C);}
	bool spfa(){
		static int q[N*M];int hd=1,tl=0;
		memset(inq,0,sizeof inq);memset(dis,0x3f,sizeof dis);memset(pre,0xff,sizeof pre);
		dis[q[++tl]=S]=0;inq[S]=1;flow[S]=2e9;
		while(hd<=tl){
			int u=q[hd++];inq[u]=0;
			for(int i=head[u];i;i=nxt[i])if(w[i]&&dis[v[i]]>dis[u]+c[i]){
				dis[v[i]]=dis[u]+c[i];
				pre[v[i]]=u,lste[v[i]]=i;
				flow[v[i]]=min(flow[u],w[i]);
				if(!inq[v[i]])inq[q[++tl]=v[i]]=1;
			}
		}
		return ~pre[T];
	}
	ll MCMF(){
		int res=0;
		while(spfa()){
			res+=flow[T]*dis[T];
			int x=T;
			while(x!=S){
				w[lste[x]]-=flow[T];
				w[lste[x]^1]+=flow[T];
				x=pre[x];
			}
		}
		return res;
	}
}
int n,m,d[N],res;
signed main(){
	read(n,m);
	G::S=n+1,G::T=n+2;
	for(int i=1,u,v,f,c;i<=m;i++){
		read(u,v,c,f);
		d[u]-=f,d[v]+=f;
		if(f<=c)G::add(u,v,c-f,1),G::add(u,v,inf,2),G::add(v,u,f,1);
		else res+=f-c,G::add(u,v,inf,2),G::add(v,u,f-c,0),G::add(v,u,c,1);
	}
	G::add(n,1,inf,0);
	for(int i=1;i<=n;i++)
		if(d[i]>=0)G::add(G::S,i,d[i],0);
		else G::add(i,G::T,-d[i],0);
	writeln(res+G::MCMF());
}