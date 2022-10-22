#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,pii> ppp;
#define MAXN 100005
#define mod (ll(998244353))

ll a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    ll res=0,nn=n,p=1;
    while(p<(1e9+7))
    {
        ll cont=0;
        for(int i=0;i<n;i++)
        {
            if(!a[i])
                continue;
            ll v=(a[i]%10)*11;
            ll add=(nn*v)%mod;
            ll mul=(p*p)%mod;
            add=(add*mul)%mod;
            res=(res+add)%mod;
            a[i]/=10;
            if(!a[i])
                cont++;
        }

        for(int i=0;i<n;i++)
        {
            ll add=(2*cont*a[i])%mod;
            ll po=(p*p)%mod;
            po=(po*100ll)%mod;
            add=(add*po)%mod;
            res=(res+add)%mod;
        }

        nn-=cont;
        p*=10;
    }
    db(res)

    return 0;
}