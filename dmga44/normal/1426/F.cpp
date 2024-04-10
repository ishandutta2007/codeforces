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
#define MAXN (ll)(2e5+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    ll ca=0;
    ll cb=0;
    ll res=0;
    string s;
    cin >> s;
    ll kk=1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='a')
            ca=(ca+kk)%mod;
        if(s[i]=='b')
            cb=(ca+cb)%mod;
        if(s[i]=='c')
            res=(cb+res)%mod;
        if(s[i]=='?')
        {
            res=(cb+3*res)%mod;
            cb=(ca+3*cb)%mod;
            ca=(3*ca+kk)%mod;
            kk=(kk*3)%mod;
        }
    }
    db(res)

    return 0;
}