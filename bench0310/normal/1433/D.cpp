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
        int n;
        cin >> n;
        vector<int> v(n+1,0);
        for(int i=1;i<=n;i++) cin >> v[i];
        vector<bool> vis(n+1,0);
        vector<array<int,2>> res;
        function<void(int)> dfs=[&](int a)
        {
            for(int to=1;to<=n;to++)
            {
                if(vis[to]==0&&v[to]!=v[a])
                {
                    res.push_back({a,to});
                    vis[to]=1;
                    dfs(to);
                }
            }
        };
        vis[1]=1;
        dfs(1);
        if((int)res.size()==n-1)
        {
            cout << "YES\n";
            for(auto [a,b]:res) cout << a << " " << b << "\n";
        }
        else cout << "NO\n";
    }
    return 0;
}