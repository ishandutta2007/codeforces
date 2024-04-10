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
        int n,m,k;
        cin >> n >> m >> k;
        vector<ll> x(n+1,0);
        for(int i=1;i<=n;i++) cin >> x[i];
        vector<array<int,5>> ladder(k+2);
        vector<array<int,3>> e[n+1]; //c,id,tp
        for(int i=1;i<=k;i++)
        {
            auto &[a,b,c,d,h]=ladder[i];
            cin >> a >> b >> c >> d >> h;
            e[a].push_back({b,i,0});
            e[c].push_back({d,i,1});
        }
        ladder[k+1]={0,0,0,0,0};
        const ll inf=(1ll<<60);
        vector<ll> dp(k+2,-inf);
        dp[0]=0;
        e[1].push_back({1,0,1});
        e[n].push_back({m,k+1,0});
        auto chmax=[&](ll &a,ll b){a=max(a,b);};
        for(int i=1;i<=n;i++)
        {
            ranges::sort(e[i]);
            auto go=[&]()
            {
                ll mx=-inf;
                int pc=0;
                for(auto [c,id,tp]:e[i])
                {
                    if(mx!=-inf) mx-=(abs(c-pc)*x[i]);
                    pc=c;
                    if(tp==0)
                    {
                        if(mx!=-inf) chmax(dp[id],mx+ladder[id][4]);
                    }
                    else mx=max(mx,dp[id]);
                }
            };
            go();
            ranges::reverse(e[i]);
            go();
        }
        if(dp[k+1]!=-inf) cout << -dp[k+1] << "\n";
        else cout << "NO ESCAPE\n";
    }
    return 0;
}