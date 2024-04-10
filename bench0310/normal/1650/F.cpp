#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n,m;
        cin >> n >> m;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<array<int,3>> v[n+1];
        for(int i=1;i<=m;i++)        
        {
            int e,t,p;
            cin >> e >> t >> p;
            v[e].push_back({t,p,i});
        }
        bool ok=1;
        vector<int> res;
        const ll inf=(1ll<<60);
        auto chmin=[&](array<ll,3> &x,array<ll,3> y){x=min(x,y);};
        ll now=0;
        vector<int> pos(m+1,0);
        for(int i=1;i<=n;i++)
        {
            int sz=v[i].size();
            vector dp(sz+1,vector(101,array<ll,3>{inf,0,0}));
            dp[0][0]={0,0,0};
            for(int x=0;x<sz;x++)
            {
                dp[x+1]=dp[x];
                auto [t,p,id]=v[i][x];
                pos[id]=x;
                for(int j=100;j>=0;j--) chmin(dp[x+1][min(100,j+p)],{dp[x][j][0]+t,j,id});
            }
            if(dp[sz][100][2]!=0)
            {
                now+=dp[sz][100][0];
                int x=100;
                int p=sz;
                while(x>0)
                {
                    res.push_back(dp[p][x][2]);
                    x=dp[p][x][1];
                    p=pos[res.back()];
                }
                ok&=(now<=a[i]);
            }
            else ok=0;
        }
        if(ok)
        {
            cout << res.size() << "\n";
            for(int id:res) cout << id << " ";
            cout << "\n";
        }
        else cout << "-1\n";
    }
    return 0;
}