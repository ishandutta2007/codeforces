#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v[n+1];
    for(int i=1;i<=n;i++)
    {
        int c;
        cin >> c;
        for(int j=0;j<c;j++)
        {
            int a;
            cin >> a;
            v[i].push_back(a);
        }
    }
    vector<int> vis(n+1,0);
    vector<array<int,2>> p(n+1,{0,0});
    bool cycle=0;
    function<void(int)> dfs=[&](int a)
    {
        vis[a]=1;
        if(v[a].empty()) p[a][0]=-1;
        for(int to:v[a])
        {
            if(vis[to]==0) dfs(to);
            else if(vis[to]==1) cycle=1;
            for(int i=0;i<=1;i++) if(p[a][i^1]==0&&p[to][i]!=0) p[a][i^1]=to;
        }
        vis[a]=2;
    };
    int src;
    cin >> src;
    dfs(src);
    vis.assign(n+1,0);
    dfs(src);
    if(p[src][1]!=0)
    {
        cout << "Win\n";
        int x=1;
        while(src!=-1)
        {
            cout << src << " ";
            src=p[src][x];
            x^=1;
        }
        cout << "\n";
    }
    else if(cycle==1) cout << "Draw\n";
    else cout << "Lose\n";
    return 0;
}