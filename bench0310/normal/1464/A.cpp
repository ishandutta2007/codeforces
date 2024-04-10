#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<int> v[n+1];
        for(int i=1;i<=m;i++)
        {
            int a,b;
            cin >> a >> b;
            if(a==b) continue;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        vector<bool> vis(n+1,0);
        int res=0;
        function<void(int)> dfs=[&](int a)
        {
            res++;
            vis[a]=1;
            for(int to:v[a]) if(vis[to]==0) dfs(to);
        };
        for(int i=1;i<=n;i++)
        {
            if(v[i].size()==0||v[i].size()==2||vis[i]==1) continue;
            assert(v[i].size()==1);
            dfs(i);
            res--;
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==1||v[i].size()==0) continue;
            assert(v[i].size()==2);
            dfs(i);
            res++;
        }
        cout << res << "\n";
    }
    return 0;
}