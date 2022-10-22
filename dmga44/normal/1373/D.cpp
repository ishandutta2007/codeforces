#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

ll ma(vector<ll> &a)
{
    ll mi=0,sum=0,res=0;
    for(int i=0;i<a.size();i++)
    {
        sum+=a[i];
        mi=min(mi,sum);
        res=max(res,sum-mi);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> b(n);
        vector<ll> c(n);
        ll base=0;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            if(!(i&1))
                base+=a[i];
        }
        for(int i=0;i+1<n;i+=2)
            b[i>>1]=a[i+1]-a[i];
        for(int i=1;i+1<n;i+=2)
            c[i>>1]=a[i]-a[i+1];
        db(base+max(ma(b),ma(c)))
    }

    return 0;
}