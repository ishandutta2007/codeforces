#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef long double ld;
typedef pair<pii,string> pps;
typedef pair<char,int> pci;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define mod (ll(998244353))
#define MAXN 200005

ll a[MAXN],f[MAXN],d[MAXN],t[MAXN][2];

ll qp(ll b,ll e)
{
    if(!e)
        return 1;
    ll x=qp(b,e/2);
    x=(x*x)%mod;
    if(e&1)
        x=(x*b)%mod;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,k;
    cin >> n >> k;
    for(ll i=0;i<n;i++)
    {
        cin >> a[i];
        if(i<2)
        {
            if(a[i]==-1)
            {
                f[i]=k;
                d[i]=-1;
                t[i][0]=1;
            }
            else
            {
                f[i]=1;
                d[i]=a[i];
                t[i][0]=1;
            }
            continue;
        }

        if(a[i]!=-1)
        {
            if(a[i-2]==-1)
            {
                if(d[i-2]==a[i])
                {
                    f[i]=(f[i-2]-t[i-2][1]+mod)%mod;
                    d[i]=a[i];
                    t[i][0]=f[i];
                }
                else
                {
                    f[i]=(f[i-2]-t[i-2][0]+mod)%mod;
                    d[i]=a[i];
                    t[i][0]=f[i];
                }
            }
            else
            {
                if(a[i-2]==a[i])
                {
                    f[i]=0;
                    t[i][0]=0;
                    t[i][1]=0;
                }
                else
                {
                    f[i]=f[i-2];
                    d[i]=a[i];
                    t[i][0]=f[i];
                }
            }
        }
        else
        {
            if(a[i-2]==-1)
            {
                if(d[i-2]!=-1)
                {
                    t[i][0]=(t[i-2][1]+((k-2)*t[i-2][0]))%mod;
                    t[i][1]=((k-1)*t[i-2][0])%mod;
                    f[i]=((t[i][0]*(k-1))+t[i][1])%mod;
                }
                else
                {
                    t[i][0]=((k-1)*t[i-2][0])%mod;
                    f[i]=((t[i][0]*k))%mod;
                }
                d[i]=d[i-2];
            }
            else
            {
                f[i]=(f[i-2]*(k-1))%mod;
                d[i]=a[i-2];
                t[i][0]=f[i-2];
                t[i][1]=0;
            }
        }
    }
    db((f[n-1]*f[n-2])%mod)

    return 0;
}