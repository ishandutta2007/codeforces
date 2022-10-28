#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define fi first
#define se second
#define N 200005
#define P 1000000007
#define debug(x) cout<<#x<<"="<<x<<endl
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int n,k,rt,sz[N],dp[N],f[N],fa[N],a[N],mx1[N],mx2[N],lim,flag;
vector<int> G[N];

void dfs(int x)
{
    int i,v;
    mx1[x]=0,mx2[x]=0;
    dp[x]=1;
    sz[x]=1;
    for(i=0;i<G[x].size();i++)
    {
        v=G[x][i];
        if(v!=fa[x]&&a[v]>=lim)
        {
            fa[v]=x;
            dfs(v);
            sz[x]+=sz[v];
            if(!f[v])
                dp[x]+=dp[v];
            else
            {
                f[x]+=f[v];
                if(dp[v]>mx1[x])
                {
                    mx2[x]=mx1[x];
                    mx1[x]=dp[v];
                }
                else mx2[x]=max(mx2[x],dp[v]);
            }
        }
        else if(v!=fa[x]&&a[v]<lim) f[x]++;
    }
    dp[x]+=mx1[x];
    //debug(x);
    //debug(dp[x]);
    if(dp[x]+mx2[x]>=k)
        flag=1;
}

void dfs2(int x)
{
    int i,v;
    //dp[x]=1;
    for(i=0;i<G[x].size();i++)
    {
        v=G[x][i];
        if(v!=fa[x]&&a[v]>=lim)
            dfs2(v);
    }
    if(f[x]==f[rt])
        dp[x]+=sz[rt]-sz[x];
    if(dp[x]+mx2[x]>=k)
        flag=1;
}

int main()
{
    int i,u,v,l,r,mid;
    cin>>n>>k;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    l=1,r=1000000;
    while(l<r)
    {
        mid=(l+r+1)>>1;
        //debug(l);
        //debug(r);
        lim=mid;
        flag=0;
        //memset(vis,0,sizeof(vis));
        memset(f,0,sizeof(f));
        memset(fa,0,sizeof(fa));
        memset(dp,0,sizeof(dp));
        memset(sz,0,sizeof(sz));
        for(i=1;i<=n;i++)
            if(a[i]>=mid&&!dp[i])
            {
                rt=i;
                dfs(i);
                dfs2(i);
            }
        //debug(flag);
        if(flag==1)
            l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
/*
6 4
2 2 2 2 1 1
1 2
2 3
2 4
3 5
4 6
*/