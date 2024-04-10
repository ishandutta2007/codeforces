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
	mint operator-(){return 0-*this;}
};
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
const int N=210,M=2100*2;
int n,m,q;
int v[M],w[M],nxt[M],head[N],cur[N],dis[N],tot=1;
void adde(int U,int V,int W){++tot,v[tot]=V,w[tot]=W,nxt[tot]=head[U],head[U]=tot;}
void add(int u,int v,int w){adde(u,v,w);adde(v,u,w);}
int s,t;
void init(int _s,int _t){
	s=_s,t=_t;
	for(int i=2;i<=tot;i+=2)
		w[i]=w[i^1]=(w[i]+w[i^1])/2;
}
bool bfs(){
	memset(dis,0xff,sizeof dis);
	memcpy(cur,head,sizeof cur);
	static int q[N],hd,tl;
	dis[q[hd=tl=1]=s]=0;
	while(hd<=tl){
		int u=q[hd++];
		for(int i=head[u];i;i=nxt[i])if(w[i]&&dis[v[i]]==-1)
			dis[q[++tl]=v[i]]=dis[u]+1;
	}
	return ~dis[t];
}
int dfs(int u,int flow){
	if(u==t)return flow;
	int rest=flow;
	for(int i=cur[u];i&&rest;i=nxt[i]){
		if(dis[v[i]]==dis[u]+1&&w[i]){
			int tmp=dfs(v[i],min(rest,w[i]));
			rest-=tmp;w[i]-=tmp;w[i^1]+=tmp;
		}
		cur[u]=i;
	}
	if(rest)dis[u]=-1;
	return flow-rest;
}
int dinic(){
	int res=0;
	while(bfs())
		while(int wyh=dfs(s,2e9))
			res+=wyh;
	return res;
}
vector<tuple<int,int,int>>e;
set<int>g[N];
void build(vector<int>p){
	if(p.size()==1u)return;
	int u=p[0],v=p[1];
	init(u,v);
	e.eb(u,v,dinic());
	vector<int>a,b;
	for(auto x:p)(~dis[x]?a:b).pb(x);
	build(a);build(b);
}
set<int>tmp;
void get(int u,int fa){
	tmp.insert(u);
	for(auto v:g[u])if(v!=fa)
		get(v,u);
}
void calc(int rt){
	tmp.clear();get(rt,0);
	if(tmp.size()==1u)return write(rt),pc(' '),void();
	tuple<int,int,int>mn(1e9,0,0);
	for(auto [u,v,w]:e)if(tmp.count(u)&&tmp.count(v))chkmn(mn,mt(w,u,v));
	int u=get<1>(mn),v=get<2>(mn);
	g[u].erase(v);g[v].erase(u);
	calc(u),calc(v);
}
signed main(){
	read(n,m);
	for(int i=1,u,v,w;i<=m;i++)
		read(u,v,w),add(u,v,w);
	vector<int>tmp(n);iota(tmp.begin(),tmp.end(),1);
	build(tmp);
	sort(e.begin(),e.end());int res=0;
	for(auto[u,v,w]:e)g[u].insert(v),g[v].insert(u),res+=w;
	writeln(res);calc(1);
	cerr<<""<<endl;
}