#include<bits/stdc++.h>
#define N 200000
#define mod 998244353
using namespace std;
inline int quick_pow(int x,int b)
{
    int ret=1;
    while(b)
    {
        if(b&1) ret=1ll*ret*x%mod;
        x=1ll*x*x%mod,b>>=1;
    }
    return ret;
}
int T,n,p[N+5],cnt,inv[N+5],now[N+5],one[N+5],ans;
bool vis[N+5];
vector<pair<int,int> > v[N+5];
vector<pair<int,pair<int,int> > > e[N+5];
#define y edge.first
#define w edge.second
inline void dfs1(int x,int fa)
{
    for(pair<int,pair<int,int> > edge:e[x]) if(y!=fa)
    {
        for(pair<int,int> val:v[w.second]) now[val.first]+=val.second;
        for(pair<int,int> val:v[w.first])
        {
            now[val.first]-=val.second;if(now[val.first]<0)
                one[val.first]+=-now[val.first],now[val.first]=0; 
        }
        dfs1(y,x);
        for(pair<int,int> val:v[w.second]) now[val.first]-=val.second;
        for(pair<int,int> val:v[w.first]) now[val.first]+=val.second;
    }
}
inline void dfs2(int x,int fa,int now)
{
    ans=(ans+now)%mod;
    for(pair<int,pair<int,int> > edge:e[x]) if(y!=fa)
        dfs2(y,x,1ll*now*w.second%mod*inv[w.first]%mod);
}
#undef y
#undef w
int main()
{
    inv[1]=1;
    for(int i=2;i<=N;++i)
    {
        inv[i]=mod-1ll*(mod/i)*inv[mod%i]%mod;
        if(!vis[i])
        {
            p[++cnt]=i;
            for(int j=i;j<=N;j+=i)
            {
                vis[j]=1,v[j].push_back({cnt,0});
                for(int x=j;!(x%i);x/=i) ++v[j].back().second;
            }
        }
    }
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n),ans=0;
        for(int i=1;i<=n;++i) e[i].clear();
        for(int i=1;i<=cnt && p[i]<=n;++i) now[i]=one[i]=0;
        for(int i=1,u,v,x,y;i<n;++i)
        {
            scanf("%d %d %d %d",&u,&v,&x,&y);
            int d=__gcd(x,y);x/=d,y/=d;
            e[u].push_back({v,{x,y}});
            e[v].push_back({u,{y,x}});
        }
        dfs1(1,0);
        int temp=1;
        for(int i=1;i<=cnt && p[i]<=n;++i)
            temp=1ll*temp*quick_pow(p[i],one[i])%mod;
        dfs2(1,0,temp);
        printf("%d\n",ans);
    }
    return 0;
}