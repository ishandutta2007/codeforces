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

const int N=1e6+5;
int n,m;
char opt[15];

struct BIT
{
	int c[N];
	inline void add(int x,int v)
	{
		for(;x<=n;x+=lowbit(x))
			c[x]+=v;
	}
	inline void update(int l,int r,int v)
	{
		add(l,v);add(r+1,-v);
	}
	inline int query(int x)
	{
		int res=0;
		for(;x;x-=lowbit(x))
			res+=c[x];
		return res;
	}
	inline void clear()
	{
		for(int i=1;i<=n;++i)
			c[i]=0;
	}
}sum;

struct Seg
{
	int val[N<<2],tg[N<<2];
	void build(int x,int l,int r,int v)
	{
		val[x]=v;tg[x]=0;
		if(l==r) return;
		build(lc,l,mid,v);
		build(rc,mid+1,r,v);
	}
	void upd(int x,int v)
	{
		val[x]=v;tg[x]=v;
	}
	void pushdown(int x)
	{
		if(tg[x])
		{
			upd(lc,tg[x]);
			upd(rc,tg[x]);
			tg[x]=0;
		}
	}
	void update(int x,int l,int r,int L,int R,int v)
	{
		if(L<=l&&r<=R)
			return upd(x,v);
		pushdown(x);
		if(L<=mid) update(lc,l,mid,L,R,v);
		if(mid+1<=R) update(rc,mid+1,r,L,R,v);
	}
	int query(int x,int l,int r,int p)
	{
		if(l==r) return val[x];
		pushdown(x);
		if(p<=mid) return query(lc,l,mid,p);
		else return query(rc,mid+1,r,p);
	}
}tag,Col;

struct Node
{
	int l,r,w1,w2;
	//w1 
	//w2 
	bool operator < (const Node &x)const
	{
		return l<x.l;
	}
};

set<Node> seg;
vector<pair<int,int> > col[N];

inline int query(int x,int y)
{
	int tot=col[x].size()-1;
	int l=0,r=tot,ps=-1;
	while(l<=r)
	{
		if(col[x][mid].fi>y)
			ps=mid,r=mid-1;
		else l=mid+1;
	}
	if(ps==-1) return 0;
	if(ps==0) return col[x][tot].se;
	return col[x][tot].se-col[x][ps-1].se;
}

set<Node>::iterator split(int x)
{
	if(x>n) return seg.end();
	auto it=--seg.upper_bound((Node){x,0,0,0});
	if(it->l==x) return it;
	int l=it->l,r=it->r,w1=it->w1,w2=it->w2;
	seg.erase(it);seg.insert((Node){l,x-1,w1,w2});
	return seg.insert((Node){x,r,w1,w2}).first;
}

void assign(int l,int r,int w1,int w2)
{
	auto itr=split(r+1),itl=split(l);
	for(;itr!=itl;)
	{
		Node tmp=*itl;
		sum.update(tmp.l,tmp.r,query(tmp.w1,tmp.w2));
		auto qwq=itl;++itl;
		seg.erase(qwq);
	}
	tag.update(1,1,n,l,r,w2);
	Col.update(1,1,n,l,r,w1);
	seg.insert((Node){l,r,w1,w2});
}

signed main()
{
	n=read();m=read();
	tag.build(1,1,n,0);
	Col.build(1,1,n,1);
	seg.insert((Node){1,n,1,0});
	for(int i=1;i<=m;++i)
	{
		scanf("%s",opt+1);
		if(opt[1]=='C')
		{
			int l=read(),r=read(),c=read();
			assign(l,r,c,i);
		}
		else if(opt[1]=='A')
		{
			int c=read(),x=read();
			int pre=0;
			if(col[c].size()!=0)
				pre=col[c][col[c].size()-1].se;
			col[c].push_back(mp(i,pre+x));
		}
		else
		{
			int x=read();
			int ans=sum.query(x);
			int w1=Col.query(1,1,n,x);
			int w2=tag.query(1,1,n,x);
			ans+=query(w1,w2);
			write(ans);puts("");
		}
	}
	return 0;
}