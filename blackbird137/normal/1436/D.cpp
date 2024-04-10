#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define int long long

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

void write(int x)
{
    if(x<0){putchar('-');x=-x;}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}

const int N=2e5+5;
int n,tag[N],a[N],vis[N],flag,ans;

struct Edge
{
	int v,ne;
}e[N*2];
int head[N],tot;

inline void add(int u,int v);
inline bool check(int x);
void dfs1(int u,int fa);
__int128 dfs2(int u,int fa,int ss);

signed main()
{
	//freopen("yangli.in","r",stdin);
	n=read();
	for(int i=2;i<=n;++i)
	{
		int u=read();
		add(u,i);add(i,u); 
	}
	for(int i=1;i<=n;++i)
		a[i]=read();
	dfs1(1,0);
	register int l=0,r=1e15;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			r=mid-1;
			ans=mid;
		}
		else l=mid+1;
	}
	write(ans);
	return 0;
}

inline void add(int u,int v)
{
	e[++tot]=(Edge){v,head[u]};
	head[u]=tot;
}

inline bool check(int x)
{
	memset(vis,0,sizeof(vis));
	flag=1;
	dfs2(1,0,x);
	return flag;
}

void dfs1(int u,int fa)
{
	if(vis[u]) return;
	vis[u]=1;
	int flag=0;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs1(v,u);flag=1;
	}
	if(!flag) tag[u]=1;
}

__int128 dfs2(int u,int fa,int ss)
{
	if(vis[u]) return 0;
	vis[u]=1;
	__int128 sum=0;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		if(tag[v])
		{
			sum+=ss-a[v];
			if(ss-a[v]<0)
				flag=0;
		}
		else sum+=dfs2(v,u,ss);
	}
	if(sum-a[u]<0) flag=0;
	return sum-a[u];
}