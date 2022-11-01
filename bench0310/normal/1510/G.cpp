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
        int n,k;
        cin >> n >> k;
        vector<int> p(n+1,0);
        vector<int> v[n+1];
        for(int i=2;i<=n;i++)
        {
            cin >> p[i];
            v[p[i]].push_back(i);
        }
        vector<int> depth(n+1,0);
        array<int,2> mx={0,1};
        function<void(int)> dfs=[&](int a)
        {
            depth[a]=depth[p[a]]+1;
            if(depth[a]<=k) mx=max(mx,{depth[a],a});
            for(int to:v[a]) dfs(to);
        };
        dfs(1);
        vector<int> c(n+1,0);
        int tmp=mx[1];
        while(tmp!=0)
        {
            c[tmp]=1;
            tmp=p[tmp];
        }
        k-=mx[0];
        vector<int> res;
        function<void(int)> solve=[&](int a)
        {
            res.push_back(a);
            for(int to:v[a])
            {
                if(c[to]==0&&k>0)
                {
                    k--;
                    solve(to);
                    res.push_back(a);
                }
            }
            for(int to:v[a]) if(c[to]==1) solve(to);
        };
        solve(1);
        cout << res.size()-1 << "\n";
        for(int a:res) cout << a << " ";
        cout << "\n";
    }
    return 0;
}