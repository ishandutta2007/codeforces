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
        vector<ll> d(n+1,0);
        for(int i=1;i<=n;i++)
        {
            ll a;
            cin >> a;
            d[i]-=a;
        }
        for(int i=1;i<=n;i++)
        {
            ll a;
            cin >> a;
            d[i]+=a;
        }
        vector<int> v[n+1];
        for(int i=1;i<=m;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        bool odd=0;
        vector<int> depth(n+1,0);
        function<void(int,int)> dfs=[&](int a,int p)
        {
            depth[a]=depth[p]+1;
            for(int to:v[a])
            {
                if(depth[to]==0)
                {
                    dfs(to,a);
                    d[a]-=d[to];
                    d[to]=0;
                }
                else if((depth[a]+depth[to])%2==0) odd=1;
            }
        };
        dfs(1,0);
        if(d[1]==0||((d[1]%2)==0&&odd==1)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}