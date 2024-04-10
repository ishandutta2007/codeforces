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
typedef double ld;
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
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

ll a[MAXN];
ll rr[MAXN];
ll n;

ll solve(ll y)
{
    ll res=0;
    ll ty=0;
    ll prevs=0;
    ll ac=0;
    ll mean=-1;
    for(ll i=0;i<n;i++)
    {
//        cout << i << ' ' << res << '\n';
        ll extra=max(0ll,ac+rr[i]-y);
        ac+=rr[i];
        if(ac>=y)
            ac=y;
        if(!ty && ac*2>=y)
        {
            prevs+=(rr[i]-extra)*i;
            res+=ac*i-prevs;
            mean=i;
            ty=1;
        }
        else if(!ty)
            prevs+=rr[i]*i;
        else
            res+=(rr[i]-extra)*(i-mean);

        if(ac==y)
        {
            ty=0;
            ac=extra;
            prevs=extra*i;
            if(ac*2>=y)
            {
                mean=i;
                ty=1;
            }
        }
    }
//    cout << y << ' ' << res << '\n';
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        sum+=a[i];
    }
    vector<int> ps;
    for(ll i=2;i<=MAXN;i++)
    {
        if(sum%i==0)
        {
            ps.push_back(i);
            while(sum%i==0)
                sum/=i;
        }
    }
    if(sum!=1)
        ps.push_back(sum);

    ll res=1e18;
    if(ps.empty())
        res=-1;
    for(auto y : ps)
    {
        for(int i=0;i<n;i++)
            rr[i]=a[i]%y;
        res=min(res,solve(y));
    }
    db(res)

    return 0;
}