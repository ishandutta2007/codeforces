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
    vector<array<int,2>> vr[n+1];
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        vr[b].push_back({a,c});
    }
    const ll inf=(1ll<<60);
    vector<array<ll,2>> d(n+1,{inf,inf});
    priority_queue<array<ll,3>,vector<array<ll,3>>,greater<>> q;
    auto add=[&](int a,int x,ll nd)
    {
        if(nd<d[a][x])
        {
            d[a][x]=nd;
            q.push({nd,a,x});
        }
    };
    add(1,0,0);
    while(!q.empty())
    {
        auto [td,a,x]=q.top();
        q.pop();
        if(d[a][x]<td) continue;
        if(x==0)
        {
            add(a,1,d[a][x]);
            for(auto [to,c]:v[a]) add(to,0,d[a][x]+c);
        }
        else
        {
            for(auto [to,c]:vr[a]) add(to,1,d[a][x]+c);
        }
    }
    for(int i=2;i<=n;i++) cout << (d[i][1]<inf?d[i][1]:-1) << " \n"[i==n];
    return 0;
}