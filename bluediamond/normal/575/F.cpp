#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N=5000+7;

ll n;
ll l[N];
ll r[N];

vector<ll>keks;

vector<ll>dp;
vector<ll>new_dp;

ll gt(ll l,ll r,ll x)
{
        if(l<=x && x<=r)
        {
                return 0;
        }
        else
        {
                if(x<l)
                {
                        return (l-x);
                }
                else
                {
                        return (x-r);
                }
        }
}

int32_t main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        //freopen("aaaaa","r",stdin);
        //freopen("bbbbb","w",stdout);
        ll x;
        cin>>n>>x;
        keks.push_back(x);
        for(ll i=1;i<=n;i++)
        {
                cin>>l[i]>>r[i];
                keks.push_back(l[i]);
                keks.push_back(r[i]);
        }
        sort(keks.begin(),keks.end());
        dp.resize(keks.size(),(1LL<<60));
        for(ll i=0;i<dp.size();i++)
        {
                if(keks[i]==x)
                {
                        dp[i]=0;
                }
        }
        for(ll i=1;i<=n;i++)
        {
                vector<ll>new_dp=dp;
                ll mi=(1LL<<60);
                for(ll j=0;j<keks.size();j++)
                {
                        mi=min(mi,dp[j]-keks[j]);
                        new_dp[j]=min(new_dp[j],mi+keks[j]);
                }
                mi=(1LL<<60);
                for(ll j=keks.size()-1;j>=0;j--)
                {
                        mi=min(mi,dp[j]+keks[j]);
                        new_dp[j]=min(new_dp[j],mi-keks[j]);
                }
                for(ll j=0;j<keks.size();j++)
                {
                        new_dp[j]+=gt(l[i],r[i],keks[j]);
                }
                swap(dp,new_dp);
        }
        ll res=(1LL<<60);
        for(auto &it:dp)
        {
                res=min(res,it);
        }
        cout<<res<<"\n";
        return 0;
}
/**
**/