// Problem: CF487E Tourists
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF487E
// Memory Limit: 250 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define pb push_back
#define pc putchar
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T&x){
	x=0;char c=getchar();bool f=false;
	for (;!isdigit(c);c=getchar())f|=c=='-';
	for (;isdigit(c);c=getchar())x=x*10+c-'0';
	if(f)x=-x;
}
template<typename T,typename ...Arg>inline void read(T&x,Arg&...args){
	read(x);read(args...);
}

template<typename T>inline void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x / 10);
	putchar(x%10+'0');
}
//#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
typedef long long ll;
const int N=2e5+100;
const int inf=0x3f3f3f3f;
int n,m,q,val[N];
multiset<int>v[N];
int w[N];
int tot;
namespace SGT{
	int mn[N << 2];
	void pushup(int x){
		mn[x]=min(mn[lc],mn[rc]);
	}
	void build(int x,int l,int r){
		if (l==r){
			mn[x]=val[l];
			return;
		}
		build(lc,l,mid);
		build(rc,mid+1,r);
		pushup(x);
	}
	void upd(int x,int l,int r,int pos){
		if (l==r){
			mn[x]=val[l];
			return;
		}
		if(pos<=mid)upd(lc,l,mid,pos);
		else upd(rc,mid+1,r,pos);
		pushup(x);
	}
	int qry(int x,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return mn[x];
		if(qr<l||r<ql)return inf;
		return min(qry(lc,l,mid,ql,qr),qry(rc,mid+1,r,ql,qr));
	}
}

namespace TC{
	vector<int>e[N];
	int fa[N];
	int sz[N];
	int dep[N];
	int top[N];
	int dfn[N];
	int cnt;
	void add(int u,int v){
		e[u].pb(v);
		e[v].pb(u);
		//printf("%d %d\n",u,v);
	}
	void dfs1(int u){
		dep[u]=dep[fa[u]]+1;
		sz[u]=1;
		for (auto v:e[u])
			if(v!=fa[u])
				fa[v]=u,dfs1(v),sz[u]+=sz[v];
	}
	void dfs2(int u){
		dfn[u]=++cnt;
		if(!top[u])top[u]=u;
		pair<int,int>son={-1,-1};
		for(auto v:e[u])
			if(v!=fa[u])
				chkmx(son,mp(sz[v],v));
		if(son.fi==-1)
			return;
		top[son.second]=top[u];
		dfs2(son.second);
		for(auto v:e[u])
			if(v!=fa[u]&&v!=son.second)
				dfs2(v);
	}
	void upd(int pos,int val){
		if (fa[pos]>n){
			v[fa[pos]].erase(v[fa[pos]].find(w[pos]));
			w[pos]=::val[dfn[pos]]=val;
			v[fa[pos]].insert(w[pos]);
			::val[dfn[fa[pos]]]=*v[fa[pos]].begin();
			SGT::upd(1,1,tot,dfn[fa[pos]]);
		}else w[pos]=::val[dfn[pos]]=val;
		SGT::upd(1,1,tot,dfn[pos]);
	}
	int qry(int u,int v){
		int ans=inf;
		while (top[u]!=top[v]){
			if (dep[top[u]]<dep[top[v]])
				swap(u,v);
			chkmn(ans,SGT::qry(1,1,tot,dfn[top[u]],dfn[u]));
			u=fa[top[u]];
		}
		if(dep[u]>dep[v])
			swap(u,v);
		chkmn(ans,SGT::qry(1,1,tot,dfn[u],dfn[v]));
		if(u>n)
			chkmn(ans,w[fa[u]]);
		return ans;
	}
	void init(){
		dfs1(1);
		dfs2(1);
		for(int i=1;i<=n;i++){
			if(fa[i]>n)
				v[fa[i]].insert(w[i]),chkmn(val[dfn[fa[i]]],w[i]);
			if(i<=n)val[dfn[i]]=w[i];
		}
		SGT::build(1,1,tot);
	}
}

namespace Tarjan{
	vector<int>e[N];
	void add(int u,int v){
		e[u].pb(v);
		e[v].pb(u);
	}
	int dfn[N],low[N],cnt;
	stack<int>s;
	void dfs(int u){
		dfn[u]=low[u]=++cnt;
		s.push(u);
		for(auto v:e[u]){
			if(!dfn[v]){
				dfs(v),chkmn(low[u],low[v]);
				if(low[v]>=dfn[u]){
					int o;
					++tot;
					do{
						o=s.top();
						s.pop();
						TC::add(tot,o);
					}while(o!=v);
					TC::add(tot,u);
				}
			}else chkmn(low[u],dfn[v]);
		}
	}
	void init(){
		for(int i=1;i<=n;i++)
			if(!dfn[i])dfs(i);
	}
}

signed main(){
	memset(val,0x3f,sizeof val);
	read(n,m,q);tot=n;
	for(int i=1;i<=n;i++)
		read(w[i]);
	for(int i=1,u,v;i<=m;i++)
		read(u,v),Tarjan::add(u,v);
	Tarjan::init();
	TC::init();
	while(q--){
		char c=getchar();
		while(!isalpha(c))c=getchar();
		if (c=='C'){
			int x,vv;read(x,vv);
			TC::upd(x,vv);
		}else{
			int u,v;read(u,v);
			write(TC::qry(u,v));
			pc('\n');
		}
	}
}