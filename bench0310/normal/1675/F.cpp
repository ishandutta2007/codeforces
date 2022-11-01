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
        int x,y;
        cin >> x >> y;
        vector<bool> vis(n+1,0);
        vis[x]=vis[y]=1;
        for(int i=1;i<=k;i++)
        {
            int a;
            cin >> a;
            vis[a]=1;
        }
        vector<int> v[n+1];
        for(int i=1;i<=n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int res=0;
        function<bool(int,int,int)> dfs=[&](int a,int p,int depth)->bool
        {
            if(a==y) res-=depth;
            bool req=vis[a];
            for(int to:v[a])
            {
                if(to==p) continue;
                req|=dfs(to,a,depth+1);
            }
            if(a!=x&&req) res+=2;
            return req;
        };
        dfs(x,0,0);
        cout << res << "\n";
    }
    return 0;
}