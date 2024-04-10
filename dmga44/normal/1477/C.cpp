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
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> res;
    vector<pii> ts;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        ts.push_back(pii(x,y));
    }

    vector<bool> mk(n);
    res.push_back(0);
    int act=0;
    mk[0]=1;
    for(int i=1;i<n;i++)
    {
        pdi kk=pdi(0,0);
        for(int j=0;j<n;j++)
        {
            if(mk[j])
                continue;
            ld dx=abs(ts[act].f-ts[j].f);
            ld dy=abs(ts[act].s-ts[j].s);
            kk=max(kk,pdi(sqrt(dx*dx+dy*dy),j));
        }
        mk[kk.s]=1;
        res.push_back(kk.s);
        act=kk.s;
    }

    for(int i=0;i<n;i++)
        cout << res[i]+1 << ' ';
    cout << '\n';

    return 0;
}