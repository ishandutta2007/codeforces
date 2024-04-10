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

const int N=1e7+5;
int n,m,k,a[N],b[N],mx,ps,A,B;

map<int,int> vis,tag,fr;

struct Edge
{
	int v,ne;
}e[N*2];
int head[N],tot;

inline int query(int x)
{
	for(int i=0;;++i)
		if((1<<i)>=x)
			return (1<<i)-x;
}

inline void add(int u,int v);
void dfs(int u,int fa,int s);

signed main()
{
	n=read();
	vis[0]=1;a[++m]=0;
	for(int i=1;i<=n;++i)
	{
		int x=read();
		tag[x]=1;fr[x]=i;
		while(x)
		{
			if(!vis[x])
			{
				vis[x]=1;
				a[++m]=x;
			}
			x=query(x);
		}
	}
	sort(a+1,a+1+m);
	for(int i=1;i<=m;++i)
		b[i]=tag[a[i]];
	for(int i=1;i<=m;++i)
		if(a[i]!=0)
		{
			int fa=lower_bound(a+1,a+1+m,query(a[i]))-a;
			add(fa,i);add(i,fa);
		}
	mx=ps=-1;
	dfs(1,0,0);
	A=ps;mx=ps=-1;
	dfs(A,0,0);B=ps;
	printf("%d %d %d\n",fr[a[A]],fr[a[B]],mx);
	return 0; 
}

inline void add(int u,int v)
{
	e[++tot]=(Edge){v,head[u]};
	head[u]=tot;
}

void dfs(int u,int fa,int s)
{
	if(b[u]&&s>mx)
		mx=s,ps=u;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u,s+1);
	}
}