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
#define MAXN (ll)(2e3+5)

ll pascal[MAXN][MAXN];
ll vb[MAXN][40];
ll v[MAXN];
ll xy[MAXN][2];
ll cant[MAXN];

ll comb(int n,int m)
{
    if(n<0)
        return 0;
    return pascal[n][m+1];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pascal[0][1]=1;
    for(int i=1;i<MAXN-1;i++)
        for(int j=1;j<=i+1;j++)
            pascal[i][j]=(pascal[i-1][j]+pascal[i-1][j-1])%mod;

    ll n,m,r;
    cin >> n >> m >> r;
    ll res=0;
    for(int i=0;i<n;i++)
        cin >> xy[i][0] >> xy[i][1] >> v[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            bool kk=max(abs(xy[i][0]-xy[j][0]),abs(xy[i][1]-xy[j][1]))<=r;
            if(kk)
                vb[i][j/60]|=(1ll<<(j%60));
        }
        ll vv=0;
        for(int j=0;j<40;j++)
            vv+=__builtin_popcountll(vb[i][j]);
        cant[i]=vv;
//        ll base=(comb(n,m)-comb(n-vv,m)+mod)%mod;
//        res=(res+base*(v[i]*v[i])%mod)%mod;
//        cout << comb(n,m) << ' ' << comb(n-vv,m) << '\n';
//        cout << i << ' ' << base << '\n';
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            vector<ll> v1(40);
            for(int k=0;k<40;k++)
                v1[k]=vb[i][k]&vb[j][k];
            ll c2=0;
            for(auto y : v1)
                c2+=__builtin_popcountll(y);
            ll f1=(comb(n,m)-comb(n-c2,m)+mod)%mod;
            res=(res+f1*((v[i]*v[j])%mod))%mod;
            ll p1=cant[i]-c2;
            ll p2=cant[j]-c2;
            ll f2=(comb(n-c2,m)-comb(n-c2-p1,m)+mod)%mod;
            f2=(f2-comb(n-c2-p2,m)+mod)%mod;
            f2=(f2+comb(n-c2-p1-p2,m))%mod;
            res=(res+f2*((v[i]*v[j])%mod))%mod;
//            db("")
//            cout << i << ' ' << j << '\n';
//            cout << f1 << ' ' << f2 << ' ' << v[i]*v[j] << '\n';
        }
    }
    db(res)

    return 0;
}