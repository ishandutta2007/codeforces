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

    int t,k;
    cin >> t >> k;
    vector<ll> c(MAXN);
    c[0]=1;
    for(int i=1;i<MAXN;i++)
    {
        c[i]=c[i-1];
        if(i>=k)
            c[i]=(c[i]+c[i-k])%mod;
    }

    vector<ll> ac(MAXN+1);
    ac[0]=0;
    for(int i=1;i<MAXN;i++)
    {
        ac[i]=(ac[i-1]+c[i-1])%mod;
    }

    while(t--)
    {
        int a,b;
        cin >> a >> b;
        cout << (ac[b+1]-ac[a]+mod)%mod << '\n';
    }

    return 0;
}