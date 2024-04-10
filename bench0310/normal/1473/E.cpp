#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<array<int,2>> v[n+1];
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    priority_queue<array<ll,3>,vector<array<ll,3>>,greater<array<ll,3>>> q;
    const ll inf=(1ll<<60);
    vector<array<ll,4>> d(n+1,{inf,inf,inf,inf});
    auto upd=[&](int a,int t,ll x)
    {
        if(x<d[a][t])
        {
            d[a][t]=x;
            q.push({x,a,t});
        }
    };
    upd(1,0,0);
    while(!q.empty())
    {
        auto [da,a,t]=q.top();
        q.pop();
        if(d[a][t]<da) continue;
        for(auto [to,c]:v[a])
        {
            for(int x=(t&2)/2;x<=1;x++)
            {
                for(int y=(t&1);y<=1;y++)
                {
                    upd(to,t^((1-x)*2)^(1-y),da+(1-(1-x)+(1-y))*c);
                }
            }
        }
    }
    for(int i=2;i<=n;i++) cout << d[i][3] << " \n"[i==n];
    return 0;
}