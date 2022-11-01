#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod=998244353;
const int N=1505;
vector<int> p(N,0);
vector<int> sz(N,1);
vector<int> cnt(N,0);
vector<vector<int>> dp(N,{0,1});

int find_set(int a)
{
    if(a==p[a]) return a;
    else return p[a]=find_set(p[a]);
}

void merge_sets(int a,int b)
{
    a=find_set(a);
    b=find_set(b);
    cnt[a]++;
    if(a==b)
    {
        if(cnt[a]==sz[a]*(sz[a]-1)/2) dp[a][1]=(dp[a][1]+1)%mod;
        return;
    }
    if(sz[a]<sz[b]) swap(a,b);
    p[b]=a;
    cnt[a]+=cnt[b];
    vector<int> tmp(sz[a]+sz[b]+1,0);
    for(int i=0;i<=sz[a];i++) for(int j=0;j<=sz[b];j++) tmp[i+j]=(tmp[i+j]+(ll)dp[a][i]*dp[b][j])%mod;
    dp[a]=tmp;
    sz[a]+=sz[b];
    if(sz[a]==2) dp[a][1]=(dp[a][1]+1)%mod;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) p[i]=i;
    vector<array<int,3>> edges;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int a;
            cin >> a;
            if(i<j) edges.push_back({a,i,j});
        }
    }
    sort(edges.begin(),edges.end());
    for(auto [c,a,b]:edges) merge_sets(a,b);
    vector<int> res=dp[find_set(1)];
    for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    return 0;
}