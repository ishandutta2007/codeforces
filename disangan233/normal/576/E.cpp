#pragma GCC optimize(2,3,"Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0,ny;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in int read()
	{
		int x=0;ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)ny=-1;Bi=1;if(nc<0)return nc;
		x=nc-48;while(nc=gc(),47<nc&&nc<58&&nc!=EOF)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*ny;
	}
	in db gf() {int a=read(),y=ny,b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi)*y:a);}
	in int gs(char *s) {char c,*t=s;while(c=gc(),c<32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
	in void ot() {fwrite(sr,1,C+1,stdout);C=-1;}
	in void flush() {if(C>1<<22) ot();}
	template <typename T>
	in void write(T x,char t)
	{
		int y=0;if(x<0)y=1,x=-x;while(z[++Z]=x%10+48,x/=10);
		if(y)z[++Z]='-';while(sr[++C]=z[Z],--Z);sr[++C]=t;flush();
	}
	in void write(char *s) {int l=strlen(s);for(int i=0;i<l;i++)sr[++C]=*s++;sr[++C]='\n';flush();}
};
using namespace fast_io;
#define pb push_back
const int N=5e5+5;
int n,m,k,q;
struct E{int u,v,c;}e[N];
struct P{int e,c;}p[N];
vector<int>v[N];vector<int>::iterator pos[N];
struct dsu
{
	int fa[N];short h[N];bool wi[N];
	in bool check(int i)
	{
		int u=e[i].u,v=e[i].v;bool w=0;
		while(fa[u]) w^=wi[u],u=fa[u]; while(fa[v]) w^=wi[v],v=fa[v];
		return u^v||w;
	}
	in E merge(int u, int v)
	{
		bool w=1;while(fa[u]) w^=wi[u],u=fa[u]; while(fa[v]) w^=wi[v],v=fa[v];
		if(u==v) return {0,0,0};h[u]>h[v]?swap(u,v):void(),fa[u]=v,wi[u]=w;
        return {u,v,h[v]+=(h[u]==h[v])};
    }
}dsu[51];
struct sgt
{
	#define ls(x) (x<<1)
	#define rs(x) (x<<1|1)
	#define mid ((l+r)>>1)
	vector<E>t[N<<2],rec[205];
	in void ins(int k,int d)
	{
		rec[d].clear();
		for(auto x:t[k]) rec[d].pb(dsu[x.c].merge(x.u,x.v));
	}
	in void del(int k,int d)
	{
		for(int i=t[k].size()-1;~i;i--) if(rec[d][i].u)
		{
			int u=rec[d][i].u,v=rec[d][i].v,c=t[k][i].c;
			dsu[c].fa[u]=dsu[c].wi[u]=0,dsu[c].h[v]=rec[d][i].c;
		}
	}
	void add(int p,int l,int r,int L,int R,E v)
	{
		if(R<l||r<L) return; if(L<=l&&r<=R) return t[p].pb(v);
		add(ls(p),l,mid,L,R,v);add(rs(p),mid+1,r,L,R,v);
	}
	void work(int x,int l,int r,int d)
	{
		ins(x,d);
		if(l==r)
		{
			int id=p[l].e;pos[id]++;
			if(dsu[p[l].c].check(id)) write("YES"),e[id].c=p[l].c; else write("NO");
			return add(1,1,q,l+1,(*pos[id])-1,e[id]),del(x,d);
		}
		work(ls(x),l,mid,d+1),work(rs(x),mid+1,r,d+1),del(x,d);
	}
}t;
int main()
{
	n=read(),m=read(),k=read(),q=read();
	for(int i=1;i<=m;i++) e[i]={read(),read()};
	for(int i=1;i<=q;i++) p[i]={read(),read()},v[p[i].e].pb(i);
	for(int i=1;i<=m;i++) v[i].pb(q+1),pos[i]=v[i].begin();
	t.work(1,1,q,0);
	return ot(),0;
}
//Author: disangan233