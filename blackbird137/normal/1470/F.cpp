#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<random>
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
#define lowbit(x) ((x)&(-(x)))
#define fan(x) ((((x)-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define INF 0x3f3f3f3f

using namespace std;

namespace fastIO
{
    #define BUF_SIZE 100000
    bool IOerror=0;
    inline char nc()
	{
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if(p1==pend)
		{
            p1=buf;
            pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if(pend==p1)
			{
                IOerror=1;
                return -1;
            }
        }
        return *p1++;
    }
    inline bool blank(char ch)
	{
        return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';
    }
    inline int read()
	{
		int ans=0,f=1;
		char c=nc();
		while(c>'9'||c<'0'){if(c=='-')f=-1;c=nc();}
		while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=nc();}
		return ans*f;
	}
    #undef BUF_SIZE
};

using namespace fastIO;

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
int n,m,m1,m2,bb[N],kk;

struct Node
{
	int x,y;
	Node operator - (const Node &p)const
	{
		return (Node){x-p.x,y-p.y};
	}
	int operator * (const Node &p)const
	{
		return x*p.x+y*p.y;
	}
	int operator ^ (const Node &p)const
	{
		return x*p.y-y*p.x;
	}
}a[N],b[N],c[N];

struct node
{
	int mx_x,mn_x,mx_y,mn_y;
	node(){mx_x=mx_y=-INF;mn_x=mn_y=INF;};
	node(int a,int b,int c,int d){mx_x=a,mn_x=b,mx_y=c,mn_y=d;}
	node operator + (const node &x)const
	{
		node res;
		res.mx_x=max(mx_x,x.mx_x);
		res.mn_x=min(mn_x,x.mn_x);
		res.mx_y=max(mx_y,x.mx_y);
		res.mn_y=min(mn_y,x.mn_y);
		return res;
	}
	inline int query()
	{
		return (mx_x-mn_x)*(mx_y-mn_y);
	}
}pre[N],suc[N],all;

bool cmp1(Node a,Node b)
{
	return a.x<b.x;
}

bool cmp2(Node a,Node b)
{
	return a.y<b.y;
}

namespace Sub1
{
	node p1[N],p2[N];int res,A,B;
	bool cmp(node a,node b)
	{
		return a.mn_x>b.mn_x;
	}
	struct BIT
	{
		int c[N];
		inline void add(int x,int v)
		{
			for(;x<=kk;x+=lowbit(x))
				c[x]=min(c[x],v);
		}
		inline void del(int x)
		{
			for(;x<=kk;x+=lowbit(x))
				c[x]=4e18;
		}
		inline int query(int x)
		{
			int res=4e18;
			for(;x;x-=lowbit(x))
				res=min(res,c[x]);
			return res;
		}
		inline void clear()
		{
			for(int i=1;i<=kk;++i)
				c[i]=4e18;
		}
	}s1;
	struct BIT2
	{
		int c[N];
		inline void add(int x,int v)
		{
			for(;x;x-=lowbit(x))
				c[x]=min(c[x],v);
		}
		inline void del(int x)
		{
			for(;x;x-=lowbit(x))
				c[x]=4e18;
		}
		inline int query(int x)
		{
			int res=4e18;
			for(;x<=kk;x+=lowbit(x))
				res=min(res,c[x]);
			return res;
		}
		inline void clear()
		{
			for(int i=1;i<=kk;++i)
				c[i]=4e18;
		}
	}s2;
	void cdq1(int l,int r)
	{
		if(l>r) return;
		if(l==r)
		{
			node tmp=pre[l-1]+suc[r+1];
			int now=(a[r].y-a[l].y)*(bb[all.mx_x]-bb[all.mn_x]);
			tmp.mx_x=bb[tmp.mx_x];tmp.mn_x=bb[tmp.mn_x];
			res=min(res,now+tmp.query());
			return;
		}
		cdq1(l,mid);
		cdq1(mid+1,r);
		m1=0;m2=0;
		for(int i=l;i<=mid;++i)
			p1[++m1]=pre[i-1],p1[m1].mx_y=a[i].y;
		for(int i=mid+1;i<=r;++i)
			p2[++m2]=suc[i+1],p2[m2].mx_y=a[i].y;
		sort(p1+1,p1+1+m1,cmp);
		sort(p2+1,p2+1+m2,cmp);int j=0;
		for(int i=1;i<=m1;++i)
		{
			while(j+1<=m2&&p2[j+1].mn_x>=p1[i].mn_x)
			{
				++j;s1.add(p2[j].mx_x,p2[j].mx_y*B);
				s2.add(p2[j].mx_x,bb[p2[j].mx_x]*A+p2[j].mx_y*B);
			}
			res=min(res,(bb[p1[i].mx_x]-bb[p1[i].mn_x])*A-p1[i].mx_y*B+s1.query(p1[i].mx_x));
			res=min(res,-bb[p1[i].mn_x]*A-p1[i].mx_y*B+s2.query(p1[i].mx_x));
		}
		for(int i=1;i<=j;++i)
		{
			s1.del(p2[i].mx_x);
			s2.del(p2[i].mx_x);
		}
	}
	void cdq2(int l,int r)
	{
		if(l>r) return;
		if(l==r) return;
		cdq2(l,mid);
		cdq2(mid+1,r);
		m1=0;m2=0;
		for(int i=l;i<=mid;++i)
			p2[++m2]=pre[i-1],p2[m2].mx_y=a[i].y;
		for(int i=mid+1;i<=r;++i)
			p1[++m1]=suc[i+1],p1[m1].mx_y=a[i].y;
		sort(p1+1,p1+1+m1,cmp);
		sort(p2+1,p2+1+m2,cmp);int j=0;
		for(int i=1;i<=m1;++i)
		{
			while(j+1<=m2&&p2[j+1].mn_x>=p1[i].mn_x)
			{
				++j;s1.add(p2[j].mx_x,-p2[j].mx_y*B);
				s2.add(p2[j].mx_x,bb[p2[j].mx_x]*A-p2[j].mx_y*B);
			}
			res=min(res,(bb[p1[i].mx_x]-bb[p1[i].mn_x])*A+p1[i].mx_y*B+s1.query(p1[i].mx_x));
			res=min(res,-bb[p1[i].mn_x]*A+p1[i].mx_y*B+s2.query(p1[i].mx_x));
		}
		for(int i=1;i<=j;++i)
		{
			s1.del(p2[i].mx_x);
			s2.del(p2[i].mx_x);
		}
	}
	inline int query()
	// |   |
	{
		res=0;A=0;B=0;
		all=(node){};kk=0;
		for(int i=1;i<=n;++i)
			bb[++kk]=a[i].x;
		sort(bb+1,bb+1+kk);
		kk=unique(bb+1,bb+1+kk)-bb-1;
		for(int i=1;i<=n;++i)
			a[i].x=lower_bound(bb+1,bb+1+kk,a[i].x)-bb;
		for(int i=1;i<=n;++i)
			all=all+(node){a[i].x,a[i].x,a[i].y,a[i].y},b[i]=a[i];
		sort(a+1,a+1+n,cmp2);
		B=bb[all.mx_x]-bb[all.mn_x];
		A=all.mx_y-all.mn_y;
		res=4e18;pre[0]=suc[n+1]=(node){};
		for(int i=1;i<=n;++i)
			pre[i]=pre[i-1]+(node){a[i].x,a[i].x,a[i].y,a[i].y};
		for(int i=n;i>=1;--i)
			suc[i]=suc[i+1]+(node){a[i].x,a[i].x,a[i].y,a[i].y};
		s1.clear();s2.clear();cdq1(2,n-1);
		s1.clear();s2.clear();cdq2(2,n-1);
		for(int i=1;i<=n;++i)
			a[i].x=bb[a[i].x];
		return res;
	}
};


namespace Sub2
{
	struct Seg
	{
		vector<Node> tk[N<<2];int top[N<<2];
		void build(int x,int l,int r)
		{
			tk[x].clear();top[x]=0;
			tk[x].resize(r-l+2);
			for(int i=l;i<=r;++i)
			{
				Node nw=(Node){c[i].x-all.mn_x,c[i+1].y-all.mn_y};
				while(top[x]>1&&((tk[x][top[x]]-tk[x][top[x]-1])^(nw-tk[x][top[x]]))<=0) --top[x];
				tk[x][++top[x]]=nw;
			}
			if(l==r) return;
			build(lc,l,mid);
			build(rc,mid+1,r);
		}
		inline int Query(int x,Node v)
		{
			int l=1,r=top[x]-1,ps=1;
			while(l<=r)
			{
				if(tk[x][mid]*v>=tk[x][mid+1]*v)
					ps=mid+1,l=mid+1;
				else r=mid-1;
			}
			return tk[x][ps]*v;
		}
		inline int query(int x,int l,int r,int L,int R,Node v)
		{
			if(L>R) return 4e18;
			if(L<=l&&r<=R) return Query(x,v);
			int res=4e18;
			if(L<=mid) res=min(res,query(lc,l,mid,L,R,v));
			if(mid+1<=R) res=min(res,query(rc,mid+1,r,L,R,v));
			return res;
		}
	}sum;
	inline int query()
	// -----    
	// |
	{
		all=(node){};m1=m2=0;
		for(int i=1;i<=n;++i)
			all=all+(node){a[i].x,a[i].x,a[i].y,a[i].y};
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=n;++i)
		{
			if(!m1||(a[i].x>b[m1].x&&a[i].y<b[m1].y)) b[++m1]=a[i];
			else if(a[i].x==b[m1].x&&a[i].y<b[m1].y) b[m1].y=a[i].y;
		}
		for(int i=n;i>=1;--i)
		{
			if(!m2||(a[i].x<c[m2].x&&a[i].y>c[m2].y)) c[++m2]=a[i];
			else if(a[i].x==c[m2].x&&a[i].y>c[m2].y) c[m2].y=a[i].y;
		}
		if(m1==1||m2==1)
			return 4e18;
		reverse(c+1,c+1+m2);
		sum.build(1,1,m2-1);
		int res=4e18;
		for(int i=1,l=1,r=0;i<m1;++i)
		{
			while(l<m2&&c[l].x<b[i+1].x) ++l;
			while(r+1<m2&&c[r+2].y>=b[i].y) ++r;
			res=min(res,sum.query(1,1,m2-1,l,r,(Node){all.mx_y-b[i].y,all.mx_x-b[i+1].x}));
		}
		return res;
	}	
}

namespace Sub3
{
	inline int query()
	// |   |
	// -----
	{
		all=(node){};
		for(int i=1;i<=n;++i)
			all=all+(node){a[i].x,a[i].x,a[i].y,a[i].y},b[i]=a[i];
		sort(a+1,a+1+n,cmp2);
		int res=4e18;
		res=min(res,all.query());
		suc[n+1]=(node){};
		for(int i=n;i>=1;--i)
			suc[i]=suc[i+1]+(node){a[i].x,a[i].x,a[i].y,a[i].y};
		node now=(node){};
		for(int i=1;i<=n;++i)
		{
			node tmp=suc[i+1];
			now=now+(node){a[i].x,a[i].x,a[i].y,a[i].y};
			res=min(res,now.query()+tmp.query());
		}
		return res;
	}
}


signed main()
{
	int t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;++i)
			a[i].x=read(),a[i].y=read();
		int ans=4e18;
		ans=min(ans,Sub1::query());
		ans=min(ans,Sub2::query());
		sort(a+1,a+1+n,cmp2);
		for(int i=1;i<=n;++i)
			a[i].y=a[n].y-a[i].y;
		ans=min(ans,Sub2::query());
		ans=min(ans,Sub3::query());
		for(int i=1;i<=n;++i)
			swap(a[i].x,a[i].y);
		ans=min(ans,Sub3::query());
		write(ans);puts("");	
	}
	
	return 0;
}