#include <bits/stdc++.h>

using namespace std;

const int N=1000005;
int d;
vector<int> v[N];
vector<bool> x(N,0);
vector<int> dp(N,-(1<<30));
int res=0;

void dfs(int a,int p=-1)
{
    if(x[a]==1) dp[a]=0;
    for(int to:v[a])
    {
        if(to==p) continue;
        dfs(to,a);
        dp[a]=max(dp[a],dp[to]+1);
    }
}

void solve(int a,int val,int p=-1)
{
    res+=(max(val,dp[a])<=d);
    if(x[a]==1) val=max(val,0);
    vector<array<int,2>> c;
    c.push_back({-(1<<30),0});
    for(int to:v[a])
    {
        if(to==p) continue;
        c.push_back({dp[to]+1,to});
    }
    sort(c.begin(),c.end(),greater<array<int,2>>());
    for(int to:v[a])
    {
        if(to==p) continue;
        int t=val;
        if(c[0][1]!=to) t=max(t,c[0][0]);
        else t=max(t,c[1][0]);
        solve(to,t+1,a);
    }
}

int main()
{
    int n,m;
    scanf("%d%d%d",&n,&m,&d);
    while(m--)
    {
        int a;
        scanf("%d",&a);
        x[a]=1;
    }
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    solve(1,-(1<<30));
    printf("%d\n",res);
    return 0;
}