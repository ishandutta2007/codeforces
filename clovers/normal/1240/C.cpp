#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pii;
#define mk make_pair
const int N=500005;
const int inf=(int)1e9+1;
const ll INF=(ll)5e18;
int n,k,bl[N];
vector<pii> v[N];
ll dp[N][2];

bool cmp(pair<ll,int> x,pair<ll,int> y){
    return x.first>y.first;
}
void dfs(int u,int f)
{
    vector<pair<ll,int> > V; V.clear();
    for(int i=0;i<(int)v[u].size();i++)
    {
        int to=v[u][i].first,w=v[u][i].second; if(to==f) continue;
        dfs(to,u);
        if(dp[to][1]+w>dp[to][0]) 
            V.push_back(mk(w+dp[to][1]-dp[to][0],to));
    }
    sort(V.begin(),V.end(),cmp);
    for(int i=0;i<min((int)V.size(),k);i++) 
    {
        int to=V[i].second;
        if(i==k-1) 
        {
            dp[u][0]+=V[i].first+dp[to][0];
            dp[u][1]+=dp[to][0];
        }
        else
        {
            dp[u][0]+=V[i].first+dp[to][0];
            dp[u][1]+=V[i].first+dp[to][0];
        }
        bl[to]=1;
    }
    for(int i=0;i<(int)v[u].size();i++)
    {
        int to=v[u][i].first,w=v[u][i].second; if(to==f) continue;
        if(bl[to]) continue;
        dp[u][1]+=max(dp[to][0],dp[to][1]);
        dp[u][0]+=max(dp[to][0],dp[to][1]);
    }
}

void init()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) dp[i][0]=dp[i][1]=0,bl[i]=0,v[i].clear();
    for(int i=1;i<n;i++)
    {
        int x,y; ll z;
        scanf("%d%d%lld",&x,&y,&z);
        v[x].push_back(mk(y,z));
        v[y].push_back(mk(x,z));
    }
    dfs(1,-1);
    printf("%lld\n",max(dp[1][0],dp[1][1]));
}

void solve()
{
    
}

int main()
{
    int TTT=1; scanf("%d",&TTT);
    while(TTT--){init(); solve();}
    return 0;
}