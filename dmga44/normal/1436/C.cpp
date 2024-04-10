#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,x,pos;
    cin >> n >> x >> pos;
    vector<int> tc;
    int l=0;
    int r=n;
    while(l<r)
    {
        int mid=(l+r)>>1;
        tc.push_back(mid);
        if(mid<=pos)
            l=mid+1;
        else
            r=mid;
    }

    int pu=0;
    int pd=0;
    for(auto y : tc)
    {
        if(y<pos)
            pd++;
        if(y>pos)
            pu++;
    }
    if(pd>x-1 || pu>n-x)
        db(0)
    else
    {
        ll res=1;
        for(ll i=0;i<pd;i++)
            res=(res*(x-1-i))%mod;
        for(ll i=0;i<pu;i++)
            res=(res*(n-x-i))%mod;
        for(ll i=1;i<=n-pd-pu-1;i++)
            res=(res*i)%mod;
        db(res)
    }

    return 0;
}