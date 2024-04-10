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
const int N=2e5+100,M=19;
int n,m,q;vector<pair<int,int>>ori[N];vector<int>e[N];
int dfn[N],low[N],col[N],cnt,bcc;bool bridge[N];
int up[N],dw[N],fa[N][M],dep[N],rt[N];
void dfs1(int u,int fa){
	//
	dfn[u]=low[u]=++cnt;
	for(auto E:ori[u]){
		int v,id;tie(v,id)=E;
		if(id==fa)continue;
		if(!dfn[v]){
			dfs1(v,id),chkmn(low[u],low[v]);
			if(low[v]>dfn[u])bridge[id]=1;
		}else chkmn(low[u],dfn[v]);
	}
}
void dfs2(int u,int now){
	col[u]=now;
	for(auto E:ori[u]){
		int v,id;tie(v,id)=E;
		if(col[v]||bridge[id])continue;
		dfs2(v,now);
	}
}
void dfs3(int u,int rt){
	dep[u]=dep[fa[u][0]]+1;::rt[u]=rt;
	for(int i=1;i<M;i++)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(auto v:e[u])if(v!=fa[u][0])fa[v][0]=u,dfs3(v,rt);
}
void dfs4(int u){
	for(auto v:e[u])if(v!=fa[u][0]){
		dfs4(v);dw[u]+=dw[v],up[u]+=up[v];
	}
	if(dw[u]&&up[u])puts("No"),exit(0);
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=M-1;~i;i--)if(dep[fa[u][i]]>=dep[v])u=fa[u][i];
	if(u==v)return u;
	for(int i=M-1;~i;i--)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
signed main(){
	read(n,m,q);
	for(int i=1,u,v;i<=m;i++)read(u,v),ori[u].eb(v,i),ori[v].eb(u,i);
	for(int i=1;i<=n;i++)if(!dfn[i])dfs1(i,-1);
	for(int i=1;i<=n;i++)if(!col[i])dfs2(i,++bcc);
	for(int i=1;i<=n;i++)for(auto E:ori[i]){
		int j,id;tie(j,id)=E;
		if(bridge[id])e[col[i]].pb(col[j]);
	}
	for(int i=1;i<=n;i++)if(!dep[i])dfs3(i,i);
	for(int i=1,s,t;i<=q;i++){
		read(s,t);
		s=col[s],t=col[t];
		if(rt[s]!=rt[t])return puts("No"),0;
		int l=lca(s,t);
		up[s]++,up[l]--;
		dw[t]++,dw[l]--;
	}
	for(int i=1;i<=n;i++)if(dep[i]==1)dfs4(i);
	puts("Yes");
	cerr<<"More and more strong,what should luogu's crawler do???";
}