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
int n,m,k,b[N],l[N],r[N],fa[N],tg[N],up[N];
char a[N];

inline void print(int x)
{
	if(!x) return;
	print(l[x]);
	putchar(a[x]);
	if(up[x]) putchar(a[x]);
	print(r[x]);
}

void dfs(int u)
{
	if(l[u]) dfs(l[u]);
	b[++m]=u;
	if(r[u]) dfs(r[u]);
}

int dfs2(int u,int s)
{
	if(l[u]) up[u]|=dfs2(l[u],s+1);
	if(!up[u]&&tg[u]&&s<=k) k-=s,up[u]=1;
	if(up[u]&&r[u]) dfs2(r[u],1);
	return up[u];
}

signed main()
{
	n=read();k=read();
	scanf("%s",a+1);
	for(int i=1;i<=n;++i)
	{
		l[i]=read();fa[l[i]]=i;
		r[i]=read();fa[r[i]]=i;
	}
	dfs(1);int ls=n+1;
	for(int i=n;i>=1;--i)
		if(a[b[i]]!=a[b[i+1]])
			ls=i,tg[b[i]]=(a[b[i]]<a[b[i+1]]);
		else tg[b[i]]=(a[b[i]]<a[b[ls+1]]);
	dfs2(1,1);
	print(1);
	return 0;
}