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

    int n,k;
    cin >> n >> k;
    vector<pii> res;
    vector<pii> ev;
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin >> l >> r;
        ev.push_back(pii(l,0));
        ev.push_back(pii(r,1));
    }

    sort(all(ev));

    int ini=-1,sum=0;
    for(auto y : ev)
    {
        if(y.s==0)
        {
            sum++;
            if(sum==k)
                ini=y.f;
        }
        else
        {
            if(sum==k)
                res.push_back(pii(ini,y.f));
            sum--;
        }
    }

    db(res.size())
    for(auto y : res)
        cout << y.f << ' ' << y.s << '\n';

    return 0;
}