#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int,2>> v[2*n+1];
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back({b,i});
        v[b].push_back({a,i});
    }
    vector<int> id(2*n+1,0);
    vector<bool> vis(n+1,0);
    bool ok=1;
    vector res(2,vector<int>());
    vector x(2,string());
    vector y(2,string());
    for(int o=1;o<=2*n;o++)
    {
        vector<int> e;
        function<void(int)> dfs=[&](int a)
        {
            while(id[a]<(int)v[a].size())
            {
                auto [to,edge]=v[a][id[a]++];
                if(vis[edge]) continue;
                vis[edge]=1;
                e.push_back(to);
                dfs(to);
                e.push_back(a);
            }
        };
        dfs(o);
        int m=e.size()/2;
        ok&=(m!=1);
        if(m==0) continue;
        for(int i=0;i<m;i++) res[0].push_back(e[i]);
        for(int i=2*m-1;i>=m;i--) res[1].push_back(e[i]);
        string tmp;
        for(int i=0;i<m/2;i++) tmp+="LR";
        if(m&1)
        {
            x[0]+=("U"+tmp);
            x[1]+=("D"+tmp);
            y[0]+=(tmp+"U");
            y[1]+=(tmp+"D");
        }
        else
        {
            x[0]+=tmp;
            x[1]+=tmp;
            y[0]+=("U"+tmp.substr(0,m-2)+"U");
            y[1]+=("D"+tmp.substr(0,m-2)+"D");
        }
    }
    if(ok)
    {
        cout << 2 << " " << n << "\n";
        for(int i=0;i<2;i++) for(int j=0;j<n;j++) cout << res[i][j] << " \n"[j==n-1];
        for(int i=0;i<2;i++) cout << x[i] << "\n";
        for(int i=0;i<2;i++) cout << y[i] << "\n";
    }
    else cout << "-1\n";
    return 0;
}