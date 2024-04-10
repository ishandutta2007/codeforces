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

const int N=3e5+5;
int n,m,k,du[N],sm[N],tg[N];

struct edge
{
	int u,v;
}ee[N];

struct Edge
{
	int v,ne;
}e[N*2];
int head[N],tot;

inline void add(int u,int v)
{
	e[++tot]=(Edge){v,head[u]};
	head[u]=tot;du[v]++;
}

signed main()
{
	n=read();m=read();//k=read();
	for(int i=1;i<=m;++i)
	{
		ee[i].u=read();ee[i].v=read();
		add(ee[i].u,ee[i].v);
	}
	queue<int> qu;int now=n;
	for(int i=1;i<=n;++i)
		if(!du[i]) now--,qu.push(i);
	while(!qu.empty())
	{
		int u=qu.front();
		qu.pop();
		if(qu.size()==0)
			sm[u]+=now;
		else if(qu.size()==1)
		{
			int flag=0;
			for(int i=head[qu.front()];i;i=e[i].ne)
			{
				int v=e[i].v;
				if(du[v]==1)
					flag=1;
			}
			if(flag) tg[u]=1;
			else sm[u]+=now;
		}
		for(int i=head[u];i;i=e[i].ne)
		{
			int v=e[i].v;du[v]--;
			if(!du[v]) qu.push(v),now--;
		}
	}
	for(int i=1;i<=n;++i)
		head[i]=du[i]=0;
	tot=0;now=n;
	for(int i=1;i<=m;++i)
		add(ee[i].v,ee[i].u);
	for(int i=1;i<=n;++i)
		if(!du[i]) now--,qu.push(i);
	while(!qu.empty())
	{
		int u=qu.front();
		qu.pop();
		if(qu.size()==0)
			sm[u]+=now;
		else if(qu.size()==1)
		{
			int flag=0;
			for(int i=head[qu.front()];i;i=e[i].ne)
			{
				int v=e[i].v;
				if(du[v]==1)
					flag=1;
			}
			if(flag) tg[u]=1;
			else sm[u]+=now;
		}
		for(int i=head[u];i;i=e[i].ne)
		{
			int v=e[i].v;du[v]--;
			if(!du[v]) qu.push(v),now--;
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i)
		if(!tg[i]&&sm[i]>=n-2)
			ans++;
	write(ans);
	return 0;
}