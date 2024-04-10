#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,sz;
    cin >> sz >> n;
    vector<array<int,2>> v[n+2];
    auto add=[&](int a,int b,int c)
    {
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    };
    int sx,sy,fx,fy;
    cin >> sx >> sy >> fx >> fy;
    add(0,n+1,abs(sx-fx)+abs(sy-fy));
    vector<array<int,3>> z;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin >> x >> y;
        z.push_back({x,y,i});
        add(0,i,min(abs(sx-x),abs(sy-y)));
        add(i,n+1,abs(fx-x)+abs(fy-y));
    }
    sort(z.begin(),z.end());
    for(int i=0;i<n-1;i++) add(z[i][2],z[i+1][2],abs(z[i][0]-z[i+1][0]));
    sort(z.begin(),z.end(),[](const array<int,3> &a,const array<int,3> &b){return (a[1]<b[1]);});
    for(int i=0;i<n-1;i++) add(z[i][2],z[i+1][2],abs(z[i][1]-z[i+1][1]));
    priority_queue<array<ll,2>,vector<array<ll,2>>,greater<array<ll,2>>> q;
    vector<ll> d(n+2,(1ll<<60));
    q.push({0,0});
    d[0]=0;
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
    cout << d[n+1] << "\n";
    return 0;
}