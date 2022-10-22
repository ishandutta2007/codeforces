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
const ll mod=(ll)(998244353);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(3e5+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pii> vp(n);
    for(int i=0;i<n;i++)
        cin >> vp[i].f >> vp[i].s;

    int res=0;
    for(int i=0;i<n;i++)
    {
        vector<bool> ok(4);
        for(int j=0;j<n;j++)
        {
            if(vp[i].f==vp[j].f && vp[i].s>vp[j].s)
                ok[0]=1;
            if(vp[i].f==vp[j].f && vp[i].s<vp[j].s)
                ok[1]=1;
            if(vp[i].f>vp[j].f && vp[i].s==vp[j].s)
                ok[2]=1;
            if(vp[i].f<vp[j].f && vp[i].s==vp[j].s)
                ok[3]=1;
        }
        ll add=1;
        for(int i=0;i<4;i++)
            if(!ok[i])
                add=0;
        res+=add;
    }
    db(res)

    return 0;
}