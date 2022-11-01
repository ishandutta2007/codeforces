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
        vector<array<int,2>> v[n+1];
        vector<array<int,3>> res;
        vector<array<int,2>> vary;
        for(int i=1;i<=n-1;i++)
        {
            int a,b,x;
            cin >> a >> b >> x;
            if(x!=-1)
            {
                int c=(popcount(uint32_t(x))&1);
                v[a].push_back({b,c});
                v[b].push_back({a,c});
                res.push_back({a,b,x});
            }
            else vary.push_back({a,b});
        }
        for(int i=1;i<=m;i++)
        {
            int a,b,c;
            cin >> a >> b >> c;
            v[a].push_back({b,c});
            v[b].push_back({a,c});
        }
        vector<int> c(n+1,-1);
        bool ok=1;
        function<void(int)> dfs=[&](int a)
        {
            for(auto [to,x]:v[a])
            {
                if(c[to]==-1)
                {
                    c[to]=(c[a]^x);
                    dfs(to);
                }
                ok&=((c[a]^x)==c[to]);
            }
        };
        for(int i=1;i<=n;i++)
        {
            if(c[i]==-1)
            {
                c[i]=0;
                dfs(i);
            }
        }
        if(ok)
        {
            cout << "YES\n";
            for(auto [a,b]:vary) res.push_back({a,b,(c[a]!=c[b])});
            for(auto [a,b,x]:res) cout << a << " " << b << " " << x << "\n";
        }
        else cout << "NO\n";
    }
    return 0;
}