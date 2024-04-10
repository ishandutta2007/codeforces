#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    ll inf=(1ll<<60);
    auto chmax=[&](ll &x,ll y){x=max(x,y);};
    auto go=[&](auto &&_go,int l,int r)->vector<ll>
    {
        if(l>r) return {0};
        int mn=l;
        for(int i=l;i<=r;i++) if(a[i]<a[mn]) mn=i;
        vector<ll> dp(min(r-l+1,m)+1,-inf);
        dp[0]=0;
        dp[1]=(m-1)*a[mn];
        int sz=1;
        vector<ll> one=_go(_go,l,mn-1);
        vector<ll> two=_go(_go,mn+1,r);
        for(vector<ll> t:{one,two})
        {
            int s=(int)t.size()-1;
            for(int i=min(m,sz);i>=0;i--)
            {
                for(int j=0;j<=s&&i+j<=m;j++)
                {
                    chmax(dp[i+j],dp[i]+t[j]-2*i*j*a[mn]);
                }
            }
            sz+=s;
        }
        return dp;
    };
    cout << go(go,1,n)[m] << "\n";
    return 0;
}