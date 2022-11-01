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
        vector<bool> f(n+1,0);
        for(int i=1;i<=k;i++)
        {
            int a;
            cin >> a;
            f[a]=1;
        }
        vector<int> v[n+1];
        for(int i=1;i<=n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        vector<int> c(n+1,0);
        function<int(int,int,int)> dfs=[&](int a,int p,int d)->int
        {
            int o=2*n;
            if(f[a]) o=d;
            for(int to:v[a])
            {
                if(to==p) continue;
                o=min(o,dfs(to,a,d+1));
            }
            if(o-d<=d) c[a]=1;
            return o;
        };
        dfs(1,0,0);
        bool win=0;
        function<void(int,int,int)> go=[&](int a,int p,int x)
        {
            win|=(a!=1&&v[a].size()==1&&x==0);
            for(int to:v[a]) if(to!=p) go(to,a,x|c[to]);
        };
        go(1,0,0);
        if(win) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}