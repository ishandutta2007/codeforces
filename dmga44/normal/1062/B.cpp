#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")
#pragma GCC target ("sse4")

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
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    ll nn=n;
    vector<pii> fac;
    int ma=0;
    ll r1=1;
    for(int i=2;i<=1e6;i++)
    {
        int e=0;
        while(n%i==0)
        {
            e++;
            n/=i;
        }
        ma=max(ma,e);
        if(e)
            r1*=i;
    }
    if(ma==0)
    {
        cout << "1 0\n";
        return 0;
    }

    int res=0;
    while(ma!=(ma&-ma))
    {
        ma+=(ma&-ma);
        res=1;
    }

    if(!res)
    {
        ll kk=nn;
        int mm=ma;
        while(mm!=1)
        {
            mm/=2;
            kk=sqrt(kk);
        }

        while(mm!=ma)
        {
            mm*=2;
            kk*=kk;
        }
        if(kk!=nn)
            res++;
    }

    while(ma!=1)
    {
        res++;
        ma/=2;
    }
    cout << r1 << ' ';
    db(res)

    return 0;
}