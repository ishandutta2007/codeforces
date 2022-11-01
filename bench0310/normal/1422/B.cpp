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
        vector<vector<ll>> a(n+1,vector<ll>(m+1,0));
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> a[i][j];
        vector<vector<bool>> vis(n+1,vector<bool>(m+1,0));
        ll res=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(vis[i][j]==1) continue;
                vector<ll> v;
                vector<array<int,2>> opt={{i,j},{n+1-i,j},{i,m+1-j},{n+1-i,m+1-j}};
                for(auto [r,c]:opt)
                {
                    if(vis[r][c]==0)
                    {
                        v.push_back(a[r][c]);
                        vis[r][c]=1;
                    }
                }
                sort(v.begin(),v.end());
                for(ll x:v) res+=abs(x-v[v.size()/2]);
            }
        }
        cout << res << "\n";
    }
    return 0;
}