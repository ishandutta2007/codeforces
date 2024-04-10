// Problem: CF1110F Nearest Leaf
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1110F
// Memory Limit: 500 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
#define int long long
typedef long long ll;
const int N=5e5+100;
const int inf=0x3f3f3f3f3f3f3f3f;
int n,q,cnt,l[N],r[N],ans[N];
vector<int>id[N];
vector<pair<int,int>>e[N];
int dfn[N],dis[N],sz[N],val[N];;//val[dfn[i]] i   
struct SGT{
	int tag[N<<2],mn[N<<2];
	#define lc (x<<1)
	#define rc (x<<1|1)
	#define mid ((l+r)>>1)
	void pushdown(int x){
		if(tag[x]){
			mn[lc]+=tag[x];
			mn[rc]+=tag[x];
			tag[lc]+=tag[x];
			tag[rc]+=tag[x];
			tag[x]=0;
		}
	}
	void pushup(int x){
		mn[x]=min(mn[lc],mn[rc]);
	}
	void build(int x,int l,int r){
		if(l==r)return mn[x]=val[l],void();
		build(lc,l,mid);build(rc,mid+1,r);
		pushup(x);
	}
	void upd(int x,int l,int r,int ql,int qr,int val){
		if(ql<=l&&r<=qr)return tag[x]+=val,mn[x]+=val,void();
		if(r<ql||qr<l)return;
		pushdown(x);
		upd(lc,l,mid,ql,qr,val);
		upd(rc,mid+1,r,ql,qr,val);
		pushup(x);
	}
	int qry(int x,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return mn[x];
		if(r<ql||qr<l)return inf;
		pushdown(x);
		return min(qry(lc,l,mid,ql,qr),qry(rc,mid+1,r,ql,qr));
	}
} T;
void dfs1(int u){
	sz[u]=1;dfn[u]=++cnt;
	for(auto [v,w]:e[u]){
		dis[v]=dis[u]+w;
		dfs1(v);sz[u]+=sz[v];
	}
	if(u!=1&&sz[u]==1)val[dfn[u]]=dis[u];
	else val[dfn[u]]=inf;
}
void dfs2(int u){
	for(auto x:id[u])ans[x]=T.qry(1,1,n,l[x],r[x]);
	for(auto [v,w]:e[u]){
		T.upd(1,1,n,dfn[v],dfn[v]+sz[v]-1,-w);
		T.upd(1,1,n,1,dfn[v]-1,w);
		T.upd(1,1,n,dfn[v]+sz[v],n,w);
		dfs2(v);
		T.upd(1,1,n,dfn[v],dfn[v]+sz[v]-1,w);
		T.upd(1,1,n,1,dfn[v]-1,-w);
		T.upd(1,1,n,dfn[v]+sz[v],n,-w);
	}
}
signed main(){
	read(n,q);
	for(int i=2,fa,w;i<=n;i++)
		read(fa,w),e[fa].pb(mp(i,w));
	dfs1(1);T.build(1,1,n);
	for(int i=1,x;i<=q;i++)
		read(x,l[i],r[i]),id[x].pb(i);
	dfs2(1);
	for(int i=1;i<=q;i++)write(ans[i]),putchar('\n');
}