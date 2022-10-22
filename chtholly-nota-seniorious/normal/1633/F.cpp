#include <bits/stdc++.h>
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...); 1;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
#define Plus
//#define Times
//#define Cover
//#define Max
#define Min
//#define Sum
template<typename T,const int N> struct sgt
{
	int l[N*4],r[N*4],ys[N];
	T a[N];
#ifdef Plus
	T plz[N*4];
#endif
#ifdef Times
	T clz[N*4];
#endif
#ifdef Cover
	T cov[N*4];bool flg[N*4];
#endif
#ifdef Max
	T mx[N*4];
#endif
#ifdef Min
	T mn[N*4];
#endif
#ifdef Sum
	T s[N*4],len[N*4];
#endif
	int z,y;
	T dt;
private:
	void pushup(int x)
	{
		int c=x<<1;
	#ifdef Max
		mx[x]=max(mx[c],mx[c|1]);
	#endif
	#ifdef Min
		mn[x]=min(mn[c],mn[c|1]);
	#endif
	#ifdef Sum
		s[x]=s[c]+s[c|1];
	#endif
	}
#ifdef Plus
	void plus(int x,T y)
	{
	#ifdef Cover
		if (flg[x]) {cov[x]+=y;goto cv;}
	#endif
	plz[x]+=y;
	cv:;
	#ifdef Max
		mx[x]+=y;
	#endif
	#ifdef Min
		mn[x]+=y;
	#endif
	#ifdef Sum
		s[x]+=y*len[x];
	#endif
	}
#endif
#ifdef Times
	void times(int x,T y)
	{
	#ifdef Cover
		if (flg[x]) {cov[x]*=y;goto cv;}
	#endif
	#ifdef Plus
		plz[x]*=y;
	#endif
		clz[x]*=y;
	cv:;
	#ifdef Max
		mx[x]*=y;
	#endif
	#ifdef Min
		mn[x]*=y;
	#endif
	#ifdef Sum
		s[x]*=y;
	#endif
	#if defined(Max)&&defined(Min)
		if (y<0) swap(mx[x],mn[x]);
	#endif
	}
#endif
#ifdef Cover
	void cov(int x,T y)
	{
		flg[x]=1;
		cov[x]=y;
	#ifdef Plus
		plz[x]=0;
	#endif
	#ifdef Times
		clz[x]=1;
	#endif
	#ifdef Max
		mx[x]=y;
	#endif
	#ifdef Min
		mn[x]=y;
	#endif
	#ifdef Sum
		s[x]=y*len[x];
	#endif
	}
#endif
	void pushdown(int x)
	{
		int c=x<<1;
	#ifdef Cover
		if (flg[x])
		{
			cov(c,cover[x]);cov(c|1,cover[x]);
			flg[x]=0;
			return;
		}
	#endif
	#ifdef Times
		if (clz[x]!=1)
		{
			times(c,clz[x]);times(c|1,clz[x]);
			clz[x]=1;
		}
	#endif
	#ifdef Plus
		if (plz[x])
		{
			plus(c,plz[x]);plus(c|1,plz[x]);
			plz[x]=0;
		}
	#endif
	}
	void build(int x)
	{
	#ifdef Plus
		plz[x]=0;
	#endif
	#ifdef Times
		clz[x]=1;
	#endif
	#ifdef Cover
		flg[x]=0; 
	#endif
	#ifdef Sum
		len[x]=r[x]-l[x]+1;
	#endif
		if (l[x]==r[x])
		{
			ys[l[x]]=x;
		#ifdef Max
			mx[x]=a[l[x]];
		#endif
		#ifdef Min
			mn[x]=a[l[x]];
		#endif
		#ifdef Sum
			s[x]=a[l[x]];
		#endif
			return;
		}
		int c=x<<1;
		l[c]=l[x];r[c]=l[x]+r[x]>>1;
		l[c|1]=r[c]+1;r[c|1]=r[x];
		build(c);build(c|1);
		pushup(x); 
	}
public: void init(int n)
	{
		assert(n>0&&n<N);
		memset(a+1,0,n*sizeof a[0]);
		r[l[1]=1]=n;build(1);
	}
	template<typename TT> void init(int n,TT *b)
	{
		assert(n>0&&n<N);
		for (int i=1;i<=n;i++) a[i]=b[i];
		r[l[1]=1]=n;build(1);
	}
#ifdef Plus
private: void modify_plus(int x)
	{
		if (z<=l[x]&&r[x]<=y)
		{
			plus(x,dt);
			return;
		}
		int c=x<<1;
		pushdown(x);
		if (z<=r[c]) modify_plus(c);
		if (y>r[c]) modify_plus(c|1);
		pushup(x);
	}
public: void modify_plus(int l,int r,T x)
	{
		dt=x;z=l;y=r;
		modify_plus(1);
	}
#endif
#ifdef Times
private: void modify_times(int x)
	{
		if (z<=l[x]&&r[x]<=y)
		{
			times(x,dt);
			return;
		}
		int c=x<<1;
		pushdown(x);
		if (z<=r[c]) modify_times(c);
		if (y>r[c]) modify_times(c|1);
		pushup(x);
	}
public: void modify_times(int l,int r,T x)
	{
		dt=x;z=l;y=r;
	#if defined(Max)^defined(Min)
		assert(x>=0);
	#endif
		modify_times(1);
	}
#endif
#ifdef Cover
private: void modify_cover(int x)
	{
		if (z<=l[x]&&r[x]<=y)
		{
			cov(x,dt);
			return;
		}
		int c=x<<1;
		pushdown(x);
		if (z<=r[c]) modify_cover(c);
		if (y>r[c]) modify_cover(c|1);
		pushup(x);
	}
public: void modify_cover(int l,int r,T x)
	{
		dt=x;z=l;y=r;
		modify_cover(1);
	}
#endif
#ifdef Max
private: void ask_max(int x)
	{
		if (z<=l[x]&&r[x]<=y)
		{
			dt=max(dt,mx[x]);
			return;
		}
		pushdown(x);
		int c=x<<1;
		if (z<=r[c]) ask_max(c);
		if (y>r[c]) ask_max(c|1);
	}
public: T ask_max(int l,int r)
	{
		z=l;y=r;dt=numeric_limits<T>::min();
		ask_max(1);return dt;
	}
#endif
#ifdef Min
private: void ask_min(int x)
	{
		if (z<=l[x]&&r[x]<=y)
		{
			dt=min(dt,mn[x]);
			return;
		}
		pushdown(x);
		int c=x<<1;
		if (z<=r[c]) ask_min(c);
		if (y>r[c]) ask_min(c|1);
	}
public: T ask_min(int l,int r)
	{
		z=l;y=r;dt=numeric_limits<T>::max();
		ask_min(1);return dt;
	}
#endif
#ifdef Sum
private: void ask_sum(int x)
	{
		if (z<=l[x]&&r[x]<=y)
		{
			dt+=s[x];
			return;
		}
		pushdown(x);
		int c=x<<1;
		if (z<=r[c]) ask_sum(c);
		if (y>r[c]) ask_sum(c|1);
	}
public: T ask_sum(int l,int r)
	{
		z=l;y=r;dt=0;
		ask_sum(1);return dt;
	}
#endif
	void allpd(int x)
	{
		if (l[x]==r[x]) return;
		pushdown(x);
		allpd(x<<1);allpd(x<<1|1);
	}
};
#undef Plus
#undef Min
#define Times
//#define Cover
//#define Max
//#define Min
#define Sum
template<typename T,const int N> struct sgt_2
{
	int l[N*4],r[N*4],ys[N];
	T a[N];
#ifdef Plus
	T plz[N*4];
#endif
#ifdef Times
	T clz[N*4];
#endif
#ifdef Cover
	T cov[N*4];bool flg[N*4];
#endif
#ifdef Max
	T mx[N*4];
#endif
#ifdef Min
	T mn[N*4];
#endif
#ifdef Sum
	T s[N*4],len[N*4];
#endif
	int z,y;
	T dt;
private:
	void pushup(int x)
	{
		int c=x<<1;
	#ifdef Max
		mx[x]=max(mx[c],mx[c|1]);
	#endif
	#ifdef Min
		mn[x]=min(mn[c],mn[c|1]);
	#endif
	#ifdef Sum
		s[x]=s[c]+s[c|1];
	#endif
	}
#ifdef Plus
	void plus(int x,T y)
	{
	#ifdef Cover
		if (flg[x]) {cov[x]+=y;goto cv;}
	#endif
	plz[x]+=y;
	cv:;
	#ifdef Max
		mx[x]+=y;
	#endif
	#ifdef Min
		mn[x]+=y;
	#endif
	#ifdef Sum
		s[x]+=y*len[x];
	#endif
	}
#endif
#ifdef Times
	void times(int x,T y)
	{
	#ifdef Cover
		if (flg[x]) {cov[x]*=y;goto cv;}
	#endif
	#ifdef Plus
		plz[x]*=y;
	#endif
		clz[x]*=y;
	cv:;
	#ifdef Max
		mx[x]*=y;
	#endif
	#ifdef Min
		mn[x]*=y;
	#endif
	#ifdef Sum
		s[x]*=y;
	#endif
	#if defined(Max)&&defined(Min)
		if (y<0) swap(mx[x],mn[x]);
	#endif
	}
#endif
#ifdef Cover
	void cov(int x,T y)
	{
		flg[x]=1;
		cov[x]=y;
	#ifdef Plus
		plz[x]=0;
	#endif
	#ifdef Times
		clz[x]=1;
	#endif
	#ifdef Max
		mx[x]=y;
	#endif
	#ifdef Min
		mn[x]=y;
	#endif
	#ifdef Sum
		s[x]=y*len[x];
	#endif
	}
#endif
	void pushdown(int x)
	{
		int c=x<<1;
	#ifdef Cover
		if (flg[x])
		{
			cov(c,cover[x]);cov(c|1,cover[x]);
			flg[x]=0;
			return;
		}
	#endif
	#ifdef Times
		if (clz[x]!=1)
		{
			times(c,clz[x]);times(c|1,clz[x]);
			clz[x]=1;
		}
	#endif
	#ifdef Plus
		if (plz[x])
		{
			plus(c,plz[x]);plus(c|1,plz[x]);
			plz[x]=0;
		}
	#endif
	}
	void build(int x)
	{
	#ifdef Plus
		plz[x]=0;
	#endif
	#ifdef Times
		clz[x]=1;
	#endif
	#ifdef Cover
		flg[x]=0; 
	#endif
	#ifdef Sum
		len[x]=r[x]-l[x]+1;
	#endif
		if (l[x]==r[x])
		{
			ys[l[x]]=x;
		#ifdef Max
			mx[x]=a[l[x]];
		#endif
		#ifdef Min
			mn[x]=a[l[x]];
		#endif
		#ifdef Sum
			s[x]=a[l[x]];
		#endif
			return;
		}
		int c=x<<1;
		l[c]=l[x];r[c]=l[x]+r[x]>>1;
		l[c|1]=r[c]+1;r[c|1]=r[x];
		build(c);build(c|1);
		pushup(x); 
	}
public: void init(int n)
	{
		assert(n>0&&n<N);
		memset(a+1,0,n*sizeof a[0]);
		r[l[1]=1]=n;build(1);
	}
	template<typename TT> void init(int n,TT *b)
	{
		assert(n>0&&n<N);
		for (int i=1;i<=n;i++) a[i]=b[i];
		r[l[1]=1]=n;build(1);
	}
#ifdef Plus
private: void modify_plus(int x)
	{
		if (z<=l[x]&&r[x]<=y)
		{
			plus(x,dt);
			return;
		}
		int c=x<<1;
		pushdown(x);
		if (z<=r[c]) modify_plus(c);
		if (y>r[c]) modify_plus(c|1);
		pushup(x);
	}
public: void modify_plus(int l,int r,T x)
	{
		dt=x;z=l;y=r;
		modify_plus(1);
	}
#endif
#ifdef Times
private: void modify_times(int x)
	{
		if (z<=l[x]&&r[x]<=y)
		{
			times(x,dt);
			return;
		}
		int c=x<<1;
		pushdown(x);
		if (z<=r[c]) modify_times(c);
		if (y>r[c]) modify_times(c|1);
		pushup(x);
	}
public: void modify_times(int l,int r,T x)
	{
		dt=x;z=l;y=r;
	#if defined(Max)^defined(Min)
		assert(x>=0);
	#endif
		modify_times(1);
	}
#endif
#ifdef Cover
private: void modify_cover(int x)
	{
		if (z<=l[x]&&r[x]<=y)
		{
			cov(x,dt);
			return;
		}
		int c=x<<1;
		pushdown(x);
		if (z<=r[c]) modify_cover(c);
		if (y>r[c]) modify_cover(c|1);
		pushup(x);
	}
public: void modify_cover(int l,int r,T x)
	{
		dt=x;z=l;y=r;
		modify_cover(1);
	}
#endif
#ifdef Max
private: void ask_max(int x)
	{
		if (z<=l[x]&&r[x]<=y)
		{
			dt=max(dt,mx[x]);
			return;
		}
		pushdown(x);
		int c=x<<1;
		if (z<=r[c]) ask_max(c);
		if (y>r[c]) ask_max(c|1);
	}
public: T ask_max(int l,int r)
	{
		z=l;y=r;dt=numeric_limits<T>::min();
		ask_max(1);return dt;
	}
#endif
#ifdef Min
private: void ask_min(int x)
	{
		if (z<=l[x]&&r[x]<=y)
		{
			dt=min(dt,mn[x]);
			return;
		}
		pushdown(x);
		int c=x<<1;
		if (z<=r[c]) ask_min(c);
		if (y>r[c]) ask_min(c|1);
	}
public: T ask_min(int l,int r)
	{
		z=l;y=r;dt=numeric_limits<T>::max();
		ask_min(1);return dt;
	}
#endif
#ifdef Sum
private: void ask_sum(int x)
	{
		if (z<=l[x]&&r[x]<=y)
		{
			dt+=s[x];
			return;
		}
		pushdown(x);
		int c=x<<1;
		if (z<=r[c]) ask_sum(c);
		if (y>r[c]) ask_sum(c|1);
	}
public: T ask_sum(int l,int r)
	{
		z=l;y=r;dt=0;
		ask_sum(1);return dt;
	}
#endif
	void allpd(int x)
	{
		if (l[x]==r[x]) return;
		pushdown(x);
		allpd(x<<1);allpd(x<<1|1);
	}
};
namespace HLD
{
	const int N=2e5+2;
	struct Q
	{
		int v,w;
		Q(int a,int b):v(a),w(b){}
	};
	vector<Q> e[N];
	int dfn[N],dep[N],f[N],lf[N],siz[N],hc[N],top[N],nfd[N];
	int id;
	void dfs1(int u)
	{
		siz[u]=1;
		for (auto [v,w]:e[u]) if (v!=f[u])
		{
			dep[v]=dep[f[v]=u]+1;
			lf[v]=w;
			dfs1(v);
			siz[u]+=siz[v];
			if (siz[v]>siz[hc[u]]) hc[u]=v;
		}
	}
	void dfs2(int u)
	{
		dfn[u]=++id;nfd[id]=u;
		if (hc[u])
		{
			top[hc[u]]=top[u];
			dfs2(hc[u]);
			for (auto [v,w]:e[u]) if (v!=hc[u]&&v!=f[u]) dfs2(top[v]=v);
		}
	}
	int lca(int u,int v)
	{
		while (top[u]!=top[v])
		{
			if (dep[top[u]]<dep[top[v]]) swap(u,v);
			u=f[top[u]];
		}
		if (dep[u]>dep[v]) swap(u,v);
		return u;
	}
	int dis(int u,int v)
	{
		return dep[u]+dep[v]-(dep[lca(u,v)]<<1);
	}
	void init(int n)
	{
		for (int i=1;i<=n;i++)
		{
			e[i].clear();
			f[i]=hc[i]=0;
		}
		id=0;
	}
	void fun(int root)
	{
		dep[root]=1;dfs1(root);dfs2(top[root]=root);
	}
}
using HLD::e;
using HLD::f;
using HLD::top;
using HLD::fun;
using HLD::lca;
using HLD::dis;
using HLD::init;
using HLD::dep;
using HLD::dfn;
using HLD::nfd;
using HLD::lf;
const int N=2e5+2,inf=1e9;
sgt<int,N> s1,s2;
sgt_2<ll,N> t;
int main()
{
	int cnt=1;
	ios::sync_with_stdio(0);cin.tie(0);
	int n,i;
	cin>>n;init(n);
	ll tot=(ll)n*(n-1)>>1;
	//static int sf[N];mt19937 rnd(time(0));
	//for (i=1;i<=n;i++) sf[i]=i;shuffle(sf+2,sf+n+1,rnd);
	for (i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		//u=sf[u];v=sf[v];
		e[u].emplace_back(v,i);
		e[v].emplace_back(u,i);
	}
	fun(1);
	static int a[N],b[N];
	static int c[N];
	for (i=2;i<=n;i++) c[i]=lf[nfd[i]];
	//for (i=1;i<=n;i++) cerr<<dfn[i]<<" \n"[i==n];
	a[1]=1;
	for (i=1;i<=n;i++)
	{
		if (dep[nfd[i]]&1) b[i]=inf; else a[i]=inf;
	}
	int la=0;
	s1.init(n,a);s2.init(n,b);t.init(n,c);
	while (1)
	{
		int op,u;
		cin>>op;
		if (op==3) return 0;
		if (op==0) return 0;
		if (op==2)
		{
			if (la==0) {cout<<0<<endl;continue;}
			s1.allpd(1);
			s2.allpd(1);
			vector<int> ans;ans.reserve(n);
			for (i=1;i<=n;i++) if (s1.mn[s1.ys[i]]==1) ans.push_back(lf[nfd[i]]);
			for (i=1;i<=n;i++) if (s2.mn[s2.ys[i]]==1) ans.push_back(lf[nfd[i]]);
			sort(all(ans));cout<<ans.size();
			for (int x:ans) cout<<' '<<x;cout<<endl;
		}
		if (op==1)
		{
			++cnt;
			cin>>u;
		//u=sf[u];
			int jo=dep[u]&1;
			if (dep[u]&1)
			{
				while (u)
				{
					int v=top[u],x,y;
					x=dfn[v];y=dfn[u];
					s1.modify_plus(x,y,1);s2.modify_plus(x,y,-1);
					t.modify_times(x,y,-1);
					u=f[v];
				}
			}
			else
			{
				while (u)
				{
					int v=top[u],x,y;
					x=dfn[v];y=dfn[u];
					s1.modify_plus(x,y,-1);s2.modify_plus(x,y,1);
					t.modify_times(x,y,-1);
					u=f[v];
				}
			}
			if (min(s1.ask_min(1,n),s2.ask_min(1,n))<0||(cnt&1)) cout<<0,la=0; else
			{
				ll sum=t.ask_sum(1,n);
				assert(tot>=sum);
				cout<<(tot-sum>>1);
				assert(1^tot+sum&1);
				la=1;
			}
			cout<<endl;
		}
	}
}