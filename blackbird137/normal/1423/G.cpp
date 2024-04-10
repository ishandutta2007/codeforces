#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define int long long
#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define INF 0x3f3f3f3f

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=2e5+5;
int n,m,a[N],b[N],k;

struct Node
{
	int l,r,v;
	bool operator < (const Node &x)const
	{
		return l<x.l;
	}
};

set<Node> seg,s[N];

struct BIT
{
	int c[N];
	inline void add(int x,int v)
	{
		for(;x<=n;x+=lowbit(x))
			c[x]+=v;
	}
	inline int query(int x)
	{
		int res=0;
		for(;x;x-=lowbit(x))
			res+=c[x];
		return res;
	}
	inline int query(int l,int r)
	{
		return query(r)-query(l-1);
	}
	inline void clear()
	{
		for(int i=1;i<=n;++i)
			c[i]=0;
	}
}s1,s2;

void upd(int p,Node v)
{
	int L=s[v.v].upper_bound(v)->l;
	int R=prev(s[v.v].lower_bound(v))->r;
	if(p==1)
	{
		s1.add(L-R-1,-1);
		s2.add(L-R-1,-L+R+1);
		if(R+1!=v.l)
		{
			s1.add(v.l-R-1,1);
			s2.add(v.l-R-1,v.l-R-1);
		}
		if(L-1!=v.r)
		{
			s1.add(L-v.r-1,1);
			s2.add(L-v.r-1,L-v.r-1);
		}
		s[v.v].insert(v);	
	}
	else
	{
		s1.add(L-R-1,1);
		s2.add(L-R-1,L-R-1);
		if(R+1!=v.l)
		{
			s1.add(v.l-R-1,-1);
			s2.add(v.l-R-1,-v.l+R+1);
		}
		if(L-1!=v.r)
		{
			s1.add(L-v.r-1,-1);
			s2.add(L-v.r-1,-L+v.r+1);
		}
		s[v.v].erase(v);
	}
}

set<Node>::iterator split(int x)
{
    auto it=--seg.upper_bound((Node){x,0,0});
    if(it->l==x) return it;
    int l=it->l,r=it->r,v=it->v;
    s[v].erase(*it);
	s[v].insert((Node){l,x-1,v});
	s[v].insert((Node){x,r,v});
    seg.erase(it);seg.insert((Node){l,x-1,v});
    return seg.insert((Node){x,r,v}).fi;
}

void assign(int l,int r,int v)
{
	auto itr=split(r+1),itl=split(l);
	for(auto i=itl;i!=itr;++i)
		upd(-1,*i);
	seg.erase(itl,itr);
	seg.insert((Node){l,r,v});
	upd(1,(Node){l,r,v});
}

struct Qus
{
	int opt,l,r,v;
}c[N];

signed main()
{
	n=read();m=read();k=n;
	for(int i=1;i<=n;++i)
		a[i]=b[i]=read();
	for(int i=1;i<=m;++i)
	{
		c[i].opt=read();
		if(c[i].opt==1)
		{
			c[i].l=read();
			c[i].r=read();
			c[i].v=read();
			b[++k]=c[i].v;
		}
		else c[i].v=read();
	}
	sort(b+1,b+1+k);
	k=unique(b+1,b+1+k)-b-1;
	for(int i=1;i<=n;++i)
		a[i]=lower_bound(b+1,b+1+k,a[i])-b;
	for(int i=1;i<=k;++i)
	{
		s[i].insert((Node){-1,0,0});
		s[i].insert((Node){n+1,n+2,0});
	}
	seg.insert((Node){-1,0,0});
	seg.insert((Node){n+1,n+2,0}),
	s1.add(n,n);s2.add(n,n*n);
	for(int i=1;i<=n;++i)
	{
		upd(1,(Node){i,i,a[i]});
		seg.insert((Node){i,i,a[i]});
	}
	for(int i=1;i<=m;++i)
	{
		int opt=c[i].opt;
		if(opt==1)
		{
			int l=c[i].l,r=c[i].r;
			int x=lower_bound(b+1,b+1+k,c[i].v)-b;
			assign(l,r,x);
		}
		else
		{
			int x=c[i].v;
			int ans=n*(n-x+1);
			ans+=s1.query(x,n)*(x-1);
			ans-=s2.query(x,n);
			write(ans);puts("");
		}
	}
	return 0;
}