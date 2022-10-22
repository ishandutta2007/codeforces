#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define mod (ll)(998244353)
#define MAXN 200005

ll res[MAXN];

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
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int sz=n-i+1;
        if(sz==1)
            cout << "10\n";
        else
        {
            ll res=0;
            ll men=sz-2;
            ll b1=qp(10,n-i);
            b1=(b1*9ll)%mod;
            res=(res+2*b1)%mod;

            ll b2=qp(10,n-i-1);
            b2=(b2*81)%mod;
            res=(res+(b2*men))%mod;
            cout << res << ' ';
        }
    }

    return 0;
}