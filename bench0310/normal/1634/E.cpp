#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> m;
    vector<int> n(m+1,0);
    vector<vector<int>> t(m+1);
    vector<array<int,3>> h;
    for(int i=1;i<=m;i++)
    {
        cin >> n[i];
        t[i].assign(n[i]+1,0);
        for(int j=1;j<=n[i];j++)
        {
            cin >> t[i][j];
            h.push_back({t[i][j],i,j});
        }
    }
    ranges::sort(h);
    int id=0;
    for(int i=0;i<(int)h.size();i++)
    {
        if(i==0||h[i][0]!=h[i-1][0]) id++;
        t[h[i][1]][h[i][2]]=id;
    }
    vector<array<int,3>> v[m+id+1];
    vector<int> d(m+id+1,0);
    auto add=[&](int a,int b,int i,int j)
    {
        v[a].push_back({b,i,j});
        v[b].push_back({a,i,j});
        d[a]++; d[b]++;
    };
    int sum=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n[i];j++) add(i,m+t[i][j],i,j);
        sum+=n[i];
    }
    bool ok=1;
    for(int i=1;i<=m+id;i++) ok&=((d[i]%2)==0);
    if(ok)
    {
        vector<string> res(m+1);
        for(int i=1;i<=m;i++) res[i].assign(n[i]+1,'$');
        vector<int> nxt(m+id+1,0);
        function<void(int)> dfs=[&](int a)
        {
            while(nxt[a]<(int)v[a].size())
            {
                auto [to,i,j]=v[a][nxt[a]++];
                if(res[i][j]!='$') continue;
                res[i][j]="LR"[a<=m];
                dfs(to);
            }
        };
        for(int i=1;i<=m;i++) if(res[i][1]=='$') dfs(i);
        cout << "YES\n";
        for(int i=1;i<=m;i++) cout << res[i].substr(1,n[i]) << "\n";
    }
    else cout << "NO\n";
    return 0;
}