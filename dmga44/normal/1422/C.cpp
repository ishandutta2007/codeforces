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

ll p10[MAXN];
ll beg[MAXN][2];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    p10[0]=1;
    for(int i=1;i<MAXN;i++)
        p10[i]=(p10[i-1]*10)%mod;

    string t;
    cin >> t;
    ll fins=0;
    int n=t.size();
    ll s=0;
    for(int i=n-1;i>=0;i--)
    {
        beg[i][0]=n-1-i;
        beg[i][1]=s;
        s=(s+p10[n-1-i]*((ll)(t[i]-'0')))%mod;
    }
    s=0;
    ll sum=0;
    ll res=0;
    for(ll i=0;i<n;i++)
    {
        res=(res+sum*p10[beg[i][0]]+(i+1)*beg[i][1])%mod;
        s=(s*10+t[i]-'0')%mod;
        sum=(sum+s)%mod;
    }
    db(res)

    return 0;
}