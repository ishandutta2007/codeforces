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
        for(int i=1;i<=m;i++)
        {
            int a,b;
            string c;
            cin >> a >> b >> c;
            v[a].push_back({b,(c=="imposter")});
            v[b].push_back({a,(c=="imposter")});
        }
        vector<int> col(n+1,-1);
        int res=0;
        bool ok=1;
        for(int i=1;i<=n;i++)
        {
            if(col[i]!=-1) continue;
            array<int,2> now={0,0};
            function<void(int)> dfs=[&](int a)
            {
                now[col[a]]++;
                for(auto [to,x]:v[a])
                {
                    if(col[to]==-1)
                    {
                        col[to]=col[a]^x;
                        dfs(to);
                    }
                    ok&=((col[a]^x)==col[to]);
                }
            };
            col[i]=0;
            dfs(i);
            res+=max(now[0],now[1]);
        }
        if(ok) cout << res << "\n";
        else cout << "-1\n";
    }
    return 0;
}