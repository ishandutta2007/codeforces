#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N=(ll)3e5+7;

ll n;
ll k;
ll v[N];
ll s[N];
ll dp1[N];
ll dp2[N];
ll dp3[N];
ll dp4[N];

int32_t main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n>>k;
        for(ll i=1;i<=n;i++)
        {
                cin>>v[i];
                s[i]=s[i-1]+v[i];
        }
        k--;
        ll rs=0;
        for(ll i=1;i<=n;i++)
        {
                dp1[i]=max(dp1[i-1],-s[i-1]);
                dp2[i]=max(dp2[i-1],dp1[i]-k*s[i-1]);
                dp3[i]=max(dp3[i-1],dp2[i]+k*s[i]);
                dp4[i]=max(dp4[i-1],dp3[i]+s[i]);
                rs=max(rs,dp4[i]);
        }
        cout<<rs<<"\n";
        return 0;
}
/**

**/