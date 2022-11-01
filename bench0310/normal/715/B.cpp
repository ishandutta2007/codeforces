#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,goal,s,t;
    cin >> n >> m >> goal >> s >> t;
    vector<array<int,2>> v[n];
    vector<array<int,4>> edges;
    vector<array<int,3>> ini;
    const int inf=goal+1;
    for(int i=1;i<=m;i++)
    {
        int a,b,w;
        cin >> a >> b >> w;
        if(w==0) edges.push_back({a,b,(int)v[a].size(),(int)v[b].size()});
        else ini.push_back({a,b,w});
        v[a].push_back({b,w});
        v[b].push_back({a,w});
    }
    int e=edges.size();
    auto set_edge=[&](int i,int w)
    {
        auto [a,b,x,y]=edges[i];
        v[a][x][1]=v[b][y][1]=w;
    };
    auto setup=[&](int one)
    {
        for(int i=0;i<=one;i++) set_edge(i,1);
        for(int i=one+1;i<e;i++) set_edge(i,inf);
    };
    auto go=[&](int one)->int
    {
        setup(one);
        vector<int> d(n,inf);
        d[s]=0;
        priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> q;
        q.push({0,s});
        while(!q.empty())
        {
            auto [da,a]=q.top();
            q.pop();
            if(d[a]<da) continue;
            for(auto [to,w]:v[a])
            {
                if(d[a]+w<d[to])
                {
                    d[to]=d[a]+w;
                    q.push({d[to],to});
                }
            }
        }
        return (d[t]!=-1?d[t]:inf);
    };
    if(go(-1)<goal||go(e-1)>goal) cout << "NO\n";
    else
    {
        int l=-1,r=e;
        while(l<r-1)
        {
            int one=(l+r)/2;
            if(go(one)>=goal) l=one;
            else r=one;
        }
        cout << "YES\n";
        for(int i=0;i<e;i++)
        {
            int a=edges[i][0];
            int b=edges[i][1];
            int w=(i<r?1:(i==r?(1+goal-go(r)):inf));
            cout << a << " " << b << " " << w << "\n";
        }
        for(auto [a,b,w]:ini) cout << a << " " << b << " " << w << "\n";
    }
    return 0;
}