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
namespace G{
	const int N=1000,M=8000;
	int head[N],cur[N],dis[N];
	int v[M],w[M],nxt[M],cnt;
	int s,t;
	void init(int _s,int _t){
		s=_s,t=_t;cnt=1;
		memset(head,0,sizeof head);
	}
	void adde(int U,int V,int W){++cnt;v[cnt]=V,w[cnt]=W,nxt[cnt]=head[U],head[U]=cnt;}
	void add(int u,int v,int w){adde(u,v,w);adde(v,u,0);}
	bool bfs(){
		memset(dis,0xff,sizeof dis);
		memcpy(cur,head,sizeof cur);
		static int q[N];int hd=1,tl=0;
		dis[q[++tl]=s]=1;
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
		for(int&i=cur[u];i&&rest;i=nxt[i])if(w[i]&&dis[v[i]]==dis[u]+1){
			int tmp=dfs(v[i],min(rest,w[i]));
			w[i]-=tmp;w[i^1]+=tmp;rest-=tmp;
		}
		if(flow)dis[u]=-1;
		return flow-rest;
	}
	int dinic(){
		int ans=0;
		while(bfs())ans+=dfs(s,2e9);
		return ans;
	}
	int Q(int x,int y){
		for(int i=head[x];i;i=nxt[i])if(v[i]==y)return w[i];
		exit(114514);
	}
}
const int N=2e5+10,M=10;
int n,m=1,cnt[M],lim=1,c;vector<int>ids[N];
int e[M][M],id[M][M],key[M];
int get(){
	char c=0;int cnt=0;
	for(;c!='?';c=getchar());
	for(;c=='?';c=getchar())cnt++;
	return cnt;
}
void dfs(int u,vector<pair<int,int>>edges){
	//
	if(u==m+1){
		//
		G::init(c+m+1,c+m+2);
		for(int i=1;i<=m;i++)for(int j=i;j<=m;j++)G::add(G::s,id[i][j],e[i][j]);
		for(int i=1;i<=m;i++)for(int j=i;j<=m;j++)G::add(id[i][j],c+i,e[i][j]);
		for(int i=1;i<=m;i++)for(int j=i;j<=m;j++)G::add(id[i][j],c+j,e[i][j]);
		for(int i=1;i<=m;i++)G::add(c+i,G::t,cnt[i]-1);
		if(G::dinic()==n-m){
			for(int i=1;i<=m;i++)key[i]=ids[i].back(),ids[i].pop_back();
			for(auto E:edges)writeln(key[E.fi],key[E.se]);
			for(int i=1;i<=m;i++)for(int j=i;j<=m;j++){
				int fi=G::Q(id[i][j],c+j);//i
				int se=e[i][j]-fi;//j
				assert(fi<=(int)ids[i].size()&&se<=(int)ids[j].size());
				while(fi--)writeln(ids[i].back(),key[j]),ids[i].pop_back();
				while(se--)writeln(ids[j].back(),key[i]),ids[j].pop_back();
			}
			exit(0);
		}
		return;
	}
	int fa[M];for(int i=1;i<=m;i++)fa[i]=i;
	function<int(int)>find;
	find=[&](int x){return x==fa[x]?x:fa[x]=find(fa[x]);};
	auto merge=[&](int x,int y){fa[find(x)]=find(y);};
	for(auto E:edges)merge(E.fi,E.se);
	for(int v=1;v<=m;v++)if(find(u)!=find(v)&&e[min(u,v)][max(u,v)]){
		edges.pb(mp(u,v));e[min(u,v)][max(u,v)]--;
		dfs(u+1,edges);
		edges.pop_back();e[min(u,v)][max(u,v)]++;
	}
}
signed main(){
	read(n);
	while(1){
		for(int i=lim;i<=n&&i<lim*10;i++)
			cnt[m]++,ids[m].pb(i);
		if(lim*10>n)break;
		lim*=10,m++;
	}
	for(int i=1;i<n;i++){
		int u=get(),v=get();
		if(u>v)swap(u,v);
		e[u][v]++;
	}
	for(int i=1;i<=m;i++)for(int j=i;j<=m;j++)id[i][j]=++c;
	dfs(2,{});
	puts("-1");
}