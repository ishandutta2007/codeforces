#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    const int lim=50;
    vector<array<int,lim+1>> in(n+1);
    vector<array<int,lim+1>> out(n+1);
    int id=n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=lim;j++)
        {
            in[i][j]=++id;
            out[i][j]=++id;
        }
    }
    vector<array<int,2>> v[id+1];
    vector<int> deg(id+1,0);
    auto add=[&](int a,int b,int c)
    {
        v[a].push_back({b,c});
        deg[a]++;
        deg[b]++;
    };
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        add(a,in[b][c],c*c);
        add(out[b][c],a,c*c);
        add(b,in[a][c],c*c);
        add(out[a][c],b,c*c);
    }
    for(int i=1;i<=n;i++)
    {
        vector<int> one,two;
        for(int j=1;j<=lim;j++)
        {
            if(deg[in[i][j]]>0) one.push_back(j);
            if(deg[out[i][j]]>0) two.push_back(j);
        }
        for(int a:one) for(int b:two) add(in[i][a],out[i][b],2*a*b);
    }
    const ll inf=(1ll<<60);
    vector<ll> d(id+1,inf);
    priority_queue<array<ll,2>,vector<array<ll,2>>,greater<array<ll,2>>> q;
    q.push({0,1});
    d[1]=0;
    while(!q.empty())
    {
        auto [da,a]=q.top();
        q.pop();
        if(d[a]<da) continue;
        for(auto [to,c]:v[a])
        {
            if(d[a]+c<d[to])
            {
                d[to]=d[a]+c;
                q.push({d[to],to});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(d[i]==inf) d[i]=-1;
        cout << d[i] << " \n"[i==n];
    }
    return 0;
}