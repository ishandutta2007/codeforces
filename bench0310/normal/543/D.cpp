#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod=1000000007;
const int N=200005;
vector<int> v[N];
vector<ll> dp(N,0);
vector<array<ll,2>> tmp(N,{-1,-1});
vector<ll> z[N];
vector<int> pos(N,0);
vector<ll> up(N,1);
vector<ll> res(N,0);

void dfs(int a)
{
    dp[a]=1;
    vector<ll> x;
    vector<ll> one;
    vector<ll> two;
    for(int to:v[a])
    {
        dfs(to);
        x.push_back(dp[to]+1);
        pos[to]=(int)x.size()-1;
        dp[a]=(dp[a]*(dp[to]+1))%mod;
    }
    if(!x.empty())
    {
        int m=x.size();
        one.resize(m);
        one[0]=x[0];
        for(int i=1;i<m;i++) one[i]=(one[i-1]*x[i])%mod;
        two.resize(m);
        two[m-1]=x[m-1];
        for(int i=m-2;i>=0;i--) two[i]=(two[i+1]*x[i])%mod;
        z[a].resize(m);
        if(x.size()==1) z[a][0]=1;
        else
        {
            z[a][0]=two[1];
            for(int i=1;i<m-1;i++) z[a][i]=(one[i-1]*two[i+1])%mod;
            z[a][m-1]=one[m-2];
        }
    }
}

void solve(int a,int p=-1)
{
    res[a]=dp[a];
    for(int to:v[a])
    {
        tmp[a]={dp[a],dp[to]};
        dp[a]=(z[a][pos[to]]*up[a])%mod;
        dp[to]=(dp[to]*(dp[a]+1))%mod;
        up[to]=(dp[a]+1);
        solve(to,a);
    }
    if(p!=-1)
    {
        dp[p]=tmp[p][0];
        dp[a]=tmp[p][1];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=2;i<=n;i++)
    {
        int p;
        cin >> p;
        v[p].push_back(i);
    }
    dfs(1);
    solve(1);
    for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    return 0;
}