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
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
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

const int N=4e5+5,M=1e9;
int n,m,q,fa[N],siz[N],sum[N],num[N],now,ans[N];

pair<int,int> a[N],b[N],c[N];

inline int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

inline void merge(int x,int y)
{
	int f1=find(x),f2=find(y);
	fa[f1]=f2;siz[f2]+=siz[f1];
	now-=num[f1]+num[f2];
	num[f2]=sum[f2]-sum[f2-siz[f2]];
	now+=num[f2];
}

signed main()
{
	n=read();m=read();q=read();
	for(int i=1;i<=n;++i)
		a[i]=mp(read(),1);
	for(int i=1;i<=m;++i)
		a[n+i]=mp(read(),0);
	m+=n;
	sort(a+1,a+1+m);
	for(int i=1;i<=m-1;++i)
	{
		b[i]=mp(a[i+1].fi-a[i].fi,i);
		sum[i]=sum[i-1]+a[i].fi;
	}
	sum[m]=sum[m-1]+a[m].fi;
	sort(b+1,b+m);
	for(int i=1;i<=q;++i)
		c[i]=mp(read(),i);
	sort(c+1,c+1+q);
	for(int i=1;i<=m;++i)
	{
		fa[i]=i;siz[i]=a[i].se;
		if(a[i].se) now+=a[i].fi,num[i]=a[i].fi;
	}
	for(int i=1,j=0;i<=q;++i)
	{
		while(j+2<=m&&b[j+1].fi<=c[i].fi)
			++j,merge(b[j].se,b[j].se+1);
		ans[c[i].se]=now;
	}
	for(int i=1;i<=q;++i)
		write(ans[i]),puts("");
	return 0;
}