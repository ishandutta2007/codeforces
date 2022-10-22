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
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

bool ok(int x,vector<ll> &d,int m)
{
    bool res=1;
    for(int i=0;i<x;i++)
        if(d[i]+(x-1-i)>m)
            res=0;
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll n,m,a,b;
        cin >> n >> m >> a >> b;
        if(b<a)
        {
            a=n+1-a;
            b=n+1-b;
        }
        int ma=b-a-1;
        int ml=b-2;
        vector<ll> d(m);
        for(int i=0;i<m;i++)
            cin >> d[i];
        sort(all(d));
        int res=0;
        int p=0;
        for(int po=(1<<17);po;po>>=1)
            if(p+po<=m && ok(p+po,d,ml))
                p+=po;

        db(min(p,ma))
    }

    return 0;
}