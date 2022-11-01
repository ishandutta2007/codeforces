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
        const ll inf=(1ll<<60);
        vector<ll> a(n+2,0);
        a[0]=-inf;
        a[n+1]=inf;
        for(int i=1;i<=n;i++) cin >> a[i];
        sort(a.begin(),a.end());
        vector<array<ll,2>> b;
        for(int i=1;i<=m;i++)
        {
            ll l,r;
            cin >> l >> r;
            if((*lower_bound(a.begin(),a.end(),l))>r) b.push_back({l,r});
        }
        vector<array<ll,3>> v;
        for(ll x:a) v.push_back({x,0,1});
        for(auto [l,r]:b) v.push_back({l,r,2});
        sort(v.begin(),v.end());
        int sz=v.size();
        vector<ll> dp(sz,inf);
        dp[0]=0;
        auto chmin=[&](ll &x,ll y){x=min(x,y);};
        for(int i=0;i<sz;i++)
        {
            if(v[i][2]==2) continue;
            ll x=v[i][0];
            ll one=inf,two=inf;
            if(i>0)
            {
                one=two=dp[i-1];
                ll mn=x;
                for(int j=i-1;v[j][2]==2;j--)
                {
                    mn=min(mn,v[j][1]);
                    chmin(one,dp[j-1]+x-mn);
                    chmin(two,dp[j-1]+2*(x-mn));
                }
            }
            for(int j=i;j==i||(j<sz&&v[j][2]==2);j++)
            {
                chmin(dp[j],min(one+2*(v[j][0]-x),two+v[j][0]-x));
            }
        }
        cout << dp[sz-1] << "\n";
    }
    return 0;
}