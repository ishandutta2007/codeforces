#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    const ll inf=(1ll<<60);
    vector<vector<ll>> d(n+1,vector<ll>(n+1,inf));
    for(int i=1;i<=n;i++) d[i][i]=0;
    vector<array<int,3>> edges(m+1,{0,0,0});
    auto chmin=[&](ll &a,ll b){a=min(a,b);};
    auto chmax=[&](ll &a,ll b){a=max(a,b);};
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        chmin(d[a][b],c);
        chmin(d[b][a],c);
        edges[i]={a,b,c};
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                chmin(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    int q;
    cin >> q;
    vector<array<int,2>> opt[n+1];
    for(int i=1;i<=q;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        opt[a].push_back({b,c});
        opt[b].push_back({a,c});
    }
    vector<bool> res(m+1,0);
    vector<ll> best(n+1,-inf);
    auto set_goal=[&](int goal)
    {
        best.assign(n+1,-inf);
        for(int i=1;i<=n;i++) for(auto [b,c]:opt[i]) chmax(best[i],c-d[b][goal]);
    };
    vector<array<int,3>> queries[n+1]; //a,c,id
    for(int i=1;i<=m;i++) queries[edges[i][1]].push_back({edges[i][0],edges[i][2],i});
    for(int i=1;i<=n;i++)
    {
        set_goal(i);
        for(auto [a,c,id]:queries[i])
        {
            for(int j=1;j<=n;j++) if(d[a][j]+c<=best[j]) res[id]=1;
        }
    }
    int cnt=0;
    for(int i=1;i<=m;i++) cnt+=res[i];
    cout << cnt << "\n";
    return 0;
}