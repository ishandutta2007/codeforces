#include<bits/stdc++.h>
using namespace std;
const int N=200005;
typedef pair<int,int> pii;
typedef long long ll;
#define mk make_pair
int dep[N],n,dp[N][2],up[N][2],down[N],antidown[N];
ll cross[N];
vector<pii> v[N];

void init()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        v[x].push_back(mk(y,z));
        v[y].push_back(mk(x,z)); 
    }
    dep[1]=0;
}

void dfs(int u,int f,int edg)
{
    if(u!=1)
    {
        if(edg==0) 
        {
            up[u][0]=up[f][0]+1;
            up[u][1]=0;
        }
        else 
        {
            up[u][1]=up[f][1]+1;
            up[u][0]=up[u][1];
        }
    }
    dp[u][1]=0; dp[u][0]=0; down[u]=0; antidown[u]=0;
    int sum0=0,sum1=0,sum01=0,sum10=0;
    for(int i=0;i<(int)v[u].size();i++)
    {
        int to=v[u][i].first;
        int w=v[u][i].second;
        if(to==f) continue;
        dep[to]=dep[u]+1;
        dfs(to,u,w);
        if(w==0) sum0+=dp[to][0]+1, sum01+=down[to]+1;
        else sum1+=dp[to][1]+1,sum10+=antidown[to]+1;
        if(w==1) 
        {
            dp[u][1]+=dp[to][1]+1;
            down[u]+=dp[to][1]+1;
            antidown[u]+=antidown[to]+1;
        }
        if(w==0) 
        {
            dp[u][0]+=dp[to][0]+1;
            down[u]+=down[to]+1;
            antidown[u]+=dp[to][0]+1;
        }
    }
    cross[u]=0;
    sum01+=sum1; sum10+=sum0;
    //if(u==1) cout<<sum0<<" "<<sum1<<" "<<sum01<<" "<<antidown[u]<<endl;
    for(int i=0;i<(int)v[u].size();i++)
    {
        int to=v[u][i].first;
        int w=v[u][i].second;
        if(to==f) continue;
        if(w==1)
        {
            int rest1=sum1-dp[to][1]-1;
            if(rest1<0) rest1=0; 
            cross[u]+=1ll*rest1*(antidown[to]+1);
        }
        else
        {
            int rest0=sum0-dp[to][0]-1,rest01=sum01-down[to]-1;
            if(rest0<0) rest0=0; if(rest01<0) rest01=0;
            cross[u]+=1ll*(dp[to][0]+1)*rest01;
        }
        //if(u==1)cout<<to<<" "<<cross[u]<<endl;
    }
}

void solve()
{
    long long ans=0;
    for(int i=1;i<=n;i++) 
    {
        //cout<<i<<":"<<up[i][0]<<" "<<down[i]<<" "<<antidown[i]<<" "<<dp[i][0]<<" "<<dp[i][1]<<" "<<cross[i]<<endl;
        ans+=up[i][0]+down[i]+cross[i];
    }
    cout<<ans<<endl; 
}

int main()
{
    init();
    dfs(1,-1,-1);
    solve();
    return 0;
}