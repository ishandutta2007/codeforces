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
    vector<array<int,3>> edges;
    for(int i=0;i<m;i++)
    {
        int a,b,t;
        cin >> a >> b >> t;
        v[a].push_back({b,1});
        v[b].push_back({a,(t==0?1:-1)});
        edges.push_back({a,b,1});
        edges.push_back({b,a,(t==0?1:-1)});
    }
    vector<int> col(n+1,0);
    bool ok=1;
    function<void(int)> dfs=[&](int a)
    {
        for(auto [to,c]:v[a])
        {
            if(col[to]==0)
            {
                col[to]=3-col[a];
                dfs(to);
            }
            else if(col[to]==col[a]) ok=0;
        }
    };
    col[1]=1;
    dfs(1);
    const int inf=(1<<30);
    vector<vector<int>> d(n+1,vector<int>(n+1,inf));
    d[0][0]=-inf;
    int x=0,y=0;
    for(int i=1;i<=n;i++)
    {
        d[i][i]=0;
        for(int z=0;z<=n;z++)
        {
            bool relax=0;
            for(auto [a,b,c]:edges)
            {
                if(d[i][a]+c<d[i][b])
                {
                    d[i][b]=d[i][a]+c;
                    relax=1;
                }
            }
            if(relax==1&&z==n) ok=0;
        }
        for(int j=1;j<=n;j++) if(d[i][j]>d[x][y]) tie(x,y)={i,j};
    }
    if(ok==1)
    {
        cout << "YES\n";
        cout << d[x][y] << "\n";
        for(int i=1;i<=n;i++) cout << d[x][i] << " \n"[i==n];
    }
    else cout << "NO\n";
    return 0;
}