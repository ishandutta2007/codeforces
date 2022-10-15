#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N=(ll)1e3+7;

ll n;
ll h;
ll a[N];

ll v[N];

bool ok(ll k)
{
        for(ll i=1;i<=k;i++)
        {
                v[i]=a[i];
        }
        sort(v+1,v+k+1);
        reverse(v+1,v+k+1);
        ll kek=0;
        for(ll i=1;i<=k;i+=2)
        {
                kek+=max(v[i],v[i+1]);
        }
        return (kek<=h);
}

int32_t main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n>>h;
        for(ll i=1;i<=n;i++)
        {
                cin>>a[i];
        }
        ll last=0;
        for(ll i=1;i<=n;i++)
        {
                if(ok(i))
                {
                        last=i;
                }
        }
        cout<<last<<"\n";
        return 0;
}
/**

**/