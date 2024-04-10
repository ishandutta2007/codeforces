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
        vector<array<int,3>> p(n);
        vector<int> lim(n,0);
        for(int i=0;i<n;i++)
        {
            auto &[x,y,id]=p[i];
            cin >> x >> y >> lim[i];
            id=i;
        }
        vector<int> v[n];
        auto go=[&]()
        {
            ranges::sort(p);
            for(int i=0;i+1<n;i++)
            {
                if(p[i][0]==p[i+1][0]&&p[i+1][1]-p[i][1]<=k)
                {
                    int a=p[i][2];
                    int b=p[i+1][2];
                    v[a].push_back(b);
                    v[b].push_back(a);
                }
            }
        };
        go();
        for(auto &[x,y,id]:p) swap(x,y);
        go();
        vector<int> u;
        vector<bool> vis(n,0);
        function<int(int)> dfs=[&](int a)->int
        {
            int m=lim[a];
            vis[a]=1;
            for(int to:v[a]) if(!vis[to]) m=min(dfs(to),m);
            return m;
        };
        for(int i=0;i<n;i++) if(!vis[i]) u.push_back(dfs(i));
        ranges::sort(u,greater<>());
        int res=0;
        int sz=u.size();
        for(int i=0;i<sz;i++) res=max(res,min(u[i],i));
        cout << res << "\n";
    }
    return 0;
}