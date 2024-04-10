#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N=(ll)3e5+7;

ll n,m;
ll v[N];
ll df[N];

int32_t main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n>>m;
        for(ll i=1;i<=n;i++)
        {
                cin>>v[i];
        }
        sort(v+1,v+n+1);
        ll g=0;
        for(ll i=1;i<n;i++)
        {
                df[i]=v[i+1]-v[i];
                g=__gcd(g,df[i]);
        }
        for(ll i=1;i<=m;i++)
        {
                ll x;
                cin>>x;
                if(g%x==0)
                {
                        cout<<"YES\n";
                        cout<<v[1]<<" "<<i<<"\n";
                        return 0;
                }
        }
        cout<<"NO\n";
        return 0;
}
/**


**/