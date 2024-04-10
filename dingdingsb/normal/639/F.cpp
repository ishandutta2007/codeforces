#pragma GCC optimize(2)
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
const int N=3e5+100;
int n,m,q,tot;vector<pair<int,int>>e[N];
int encode(int x){x=(x+tot)%n;return x==0?n:x;}
int low[N],dfn[N],cnt,sz;bool bridge[N];
vector<int>g[N];int col[N];
void dfs1(int u,int fa){
	low[u]=dfn[u]=++cnt;
	for(auto E:e[u]){
		int v,id;tie(v,id)=E;
		if(id==fa)continue;
		if(!dfn[v]){
			dfs1(v,id),chkmn(low[u],low[v]);
			if(dfn[u]<low[v])bridge[id]=1;
		}
		else chkmn(low[u],dfn[v]);
	}
}
void dfs2(int u){
	col[u]=sz;
	for(auto E:e[u]){
		int v,id;tie(v,id)=E;
		if(bridge[id])continue;
		if(col[v])continue;
		dfs2(v);
	}
}
int siz[N],fath[N],top[N],dep[N],root[N];
void dfs3(int u,int rt){
	siz[u]=1;dfn[u]=++cnt;
	dep[u]=dep[fath[u]]+1;root[u]=rt;
	for(auto v:g[u]){
		if(v==fath[u])continue;
		fath[v]=u;dfs3(v,rt);
		siz[u]+=siz[v];
	}
}
void dfs4(int u){
	if(!top[u])top[u]=u;
	pair<int,int>mx=mp(0,0);
	for(auto v:g[u])if(v!=fath[u])chkmx(mx,mp(siz[v],v));
	if(!mx.se)return;
	top[mx.se]=top[u];
	for(auto v:g[u])if(v!=fath[u])dfs4(v);
}
int lca(int u,int v){
	assert(root[u]==root[v]);int cnt=0;
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		u=fath[top[u]];
		assert(++cnt<=30);
	}
	return dep[u]<dep[v]?u:v;
}
struct SGT{
	int tag[N<<2];
	SGT(){memset(tag,0xff,sizeof tag);}
	void pushtag(int x,int t){tag[x]=t;}
	void pushdown(int x){if(~tag[x])pushtag(lc,tag[x]),pushtag(rc,tag[x]),tag[x]=-1;}
	void mdf(int x,int l,int r,int ql,int qr,int t){
		if(ql<=l&&r<=qr)return pushtag(x,t);
		if(r<ql||qr<l)return;
		pushdown(x);
		mdf(lc,l,mid,ql,qr,t);
		mdf(rc,mid+1,r,ql,qr,t);
	}
	int qry(int x,int l,int r,int pos){
		if(l==r)return tag[x];
		pushdown(x);
		if(pos<=mid)return qry(lc,l,mid,pos);
		else return qry(rc,mid+1,r,pos);
	}
}T;
int xcnt;//
vector<pair<int,int>>edge[N];
int dn[N],lw[N];bool vis[N];
void dfs5(int u,int fa){
	dn[u]=lw[u]=++cnt;
	for(auto E:edge[u]){
		int v,id;tie(v,id)=E;
		if(id==fa)continue;
		if(!dn[v]){
			dfs5(v,id);
			chkmn(lw[u],lw[v]);
			if(dn[u]<lw[v])bridge[id]=1;
		}else chkmn(lw[u],dn[v]);
	}
}
void dfs6(int u){
	vis[u]=1;
	for(auto E:edge[u]){
		int v,id;tie(v,id)=E;
		if(bridge[id])continue;
		if(!vis[v])dfs6(v);
	}
}
signed main(){
	read(n,m,q);
	for(int i=1,a,b;i<=m;i++)read(a,b),e[a].eb(b,i),e[b].eb(a,i);
	for(int i=1;i<=n;i++)if(!dfn[i])dfs1(i,0);
	for(int i=1;i<=n;i++)if(!col[i])++sz,dfs2(i);
	for(int i=1;i<=n;i++)for(auto E:e[i]){
		int j,id;tie(j,id)=E;
		if(col[i]^col[j])g[col[i]].pb(col[j]);
	}
	//
	//
	//EV
	//
	memset(dfn,0,sizeof dfn);cnt=0;
	memset(bridge,0,sizeof bridge);
	for(int i=1;i<=sz;i++)if(!dfn[i])dfs3(i,i);
	for(int i=1;i<=sz;i++)if(!fath[i])dfs4(i);
	for(int i=1;i<=q;i++){
		T.mdf(1,1,n,1,n,0);
		vector<int>V,arr,keys;vector<pair<int,int>>E;
		int v,e,x,y;read(v,e);
		while(v--)read(x),x=col[encode(x)],V.pb(x),arr.pb(x);
		while(e--)read(x,y),x=col[encode(x)],y=col[encode(y)],E.eb(x,y),arr.pb(x),arr.pb(y);
		sort(arr.begin(),arr.end(),[&](int x,int y){return dfn[x]<dfn[y];});
		arr.resize(unique(arr.begin(),arr.end())-arr.begin());
		keys=arr;
		for(int i=0;i<(int)arr.size();){
			int j=i;while(j!=(int)arr.size()&&root[arr[j]]==root[arr[i]])j++;
			for(int k=i;k+1<j;k++)keys.pb(lca(arr[k],arr[k+1]));
			keys.pb(lca(arr[i],arr[j-1]));i=j;
		}
		sort(keys.begin(),keys.end(),[&](int x,int y){return dfn[x]<dfn[y];});
		keys.resize(unique(keys.begin(),keys.end())-keys.begin());
		for(auto x:keys){
			int f=T.qry(1,1,n,dfn[x]);
			if(f){
				++xcnt;
				edge[f].eb(x,xcnt);
				edge[x].eb(f,xcnt);
			}
			T.mdf(1,1,n,dfn[x],dfn[x]+siz[x]-1,x);
		}
		for(auto e:E)++xcnt,edge[e.fi].eb(e.se,xcnt),edge[e.se].eb(e.fi,xcnt);
		dfs5(V[0],0);dfs6(V[0]);
		
		bool flag=1;for(auto x:V)if(!vis[x])flag=0;
		puts(flag?"YES":"NO");tot+=flag*i;tot%=n;
		for(auto x:keys)edge[x].clear(),dn[x]=lw[x]=vis[x]=0;
		for(int i=1;i<=xcnt;i++)bridge[i]=0;
		xcnt=0;cnt=0;
	}
}