#include <bits/stdc++.h>

using namespace std;

#define x first
#define cost second

typedef long long ll;

const int N=3000;
int n;
pair<int,int>v[N+5];
ll dp[N+5][N+5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i].x>>v[i].cost;
    }
    sort(v+1,v+n+1);
    dp[1][1]=v[1].cost;
    for(int pre=2;pre<=n;pre++)
    {
        ll mi=(1LL<<60);
        for(int i=1;i<pre;i++)
        {
            dp[pre][i]=dp[pre-1][i]+v[pre].x-v[i].x;
            mi=min(mi,dp[pre-1][i]);
        }
        dp[pre][pre]=mi+v[pre].cost;
    }
    ll sol=(1LL<<60);
    for(int i=1;i<=n;i++)
    {
        sol=min(sol,dp[n][i]);
    }
    cout<<sol<<"\n";
    return 0;
}