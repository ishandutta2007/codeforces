#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define inf 1000000007
#define N 200005
using namespace std;
int gh[N];
long long f[2][N];
long long a[N];
int dfn[N];
int n,ans,cnt,tot;
struct EDGE {int adj,next;}edge[N<<1];
void addedge(int x,int y)
{
	++tot;
	edge[tot].adj=y;
	edge[tot].next=gh[x];
	gh[x]=tot;
}
void dfs(int x,int pre)
{
	dfn[x]=++cnt;
    for(int p=gh[x];p;p=edge[p].next)
        if(edge[p].adj!=pre)
        {
        	dfs(edge[p].adj,x);
        	f[0][x]+=f[1][edge[p].adj];
        	f[1][x]+=f[0][edge[p].adj];
    	}
    f[0][x]++;
}
void fuck(int x,int pre,long long s0,long long s1)
{
    for(int p=gh[x];p;p=edge[p].next)
        if(edge[p].adj!=pre)
       	{
       		long long tmp1=1ll*a[x]*(f[1][edge[p].adj]-f[0][edge[p].adj]+inf);
       		long long tmp2=n-f[1][edge[p].adj]-f[0][edge[p].adj]+inf;
       		tmp1=(tmp1%inf+inf)%inf;
       		tmp2=(tmp2%inf+inf)%inf;
       		tmp1=tmp1*tmp2%inf;
       		ans=(ans+tmp1)%inf;
       	}
        else 
        {
        	ans=(ans+1ll*a[x]*(s1-s0+inf)%inf*(f[1][x]+f[0][x])%inf)%inf;
        }
    ans=(ans+1ll*a[x]*n%inf)%inf;
    for(int p=gh[x];p;p=edge[p].next)
    	if(edge[p].adj!=pre)
    	{
    		long long now1=f[0][x]-f[1][edge[p].adj]+s1;
    		long long now2=f[1][x]-f[0][edge[p].adj]+s0;
        	fuck(edge[p].adj,x,now1,now2);
    	}
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
   	for(int i=1;i<=n;i++)a[i]=(a[i]+inf)%inf;
   	for(int i=1;i<=n;i++)gh[i]=0; tot=0;
   	for(int i=2;i<=n;i++)
   	{
   		int x,y;
   		scanf("%d%d",&x,&y);
   		addedge(x,y);
   		addedge(y,x);
   	}
    ans=0;
    dfs(1,0);
    fuck(1,0,0,0);
  	cout<<ans<<endl;
    return 0;
}