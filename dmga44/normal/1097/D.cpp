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
#define MAXN (ll)(1e4+5)

ll cant[60];
vector<pii> g[60];
ll dp[60][MAXN];
ll inv[MAXN];
int k;

ll qp(ll b,ll e)
{
    if(!e)
        return 1;
    ll x=qp(b,e/2);
    x=(x*x)%mod;
    if(e&1)
        x=(x*b)%mod;
    return x;
}

ll solve(pii p)
{
    vector<ll> divs;

    for(int i=0;i<60;i++)
    {
        cant[i]=0;
        g[i].clear();
        for(int j=0;j<MAXN;j++)
            dp[i][j]=0;
    }

    ll d=1;
    divs.push_back(d);
    for(int i=0;i<p.s;i++)
    {
        d=(d*p.f);
        divs.push_back(d);
    }

    for(int i=0;i<divs.size();i++)
        for(int j=0;j<=i;j++)
            if(divs[i]%divs[j]==0)
                cant[i]++;

    for(int i=0;i<divs.size();i++)
        for(int j=0;j<=i;j++)
            if(divs[i]%divs[j]==0)
                g[i].push_back(pii(j,inv[cant[i]]));

    dp[divs.size()-1][0]=1;
    for(int i=0;i<k;i++)
        for(int j=0;j<divs.size();j++)
            for(auto y: g[j])
                dp[y.f][i+1]=(dp[y.f][i+1]+dp[j][i]*y.s)%mod;

    ll res=0;
    for(int i=0;i<divs.size();i++)
        res=(res+((divs[i])%mod)*dp[i][k])%mod;
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=1;i<MAXN;i++)
        inv[i]=qp(i,mod-2);

    ll n;
    cin >> n >> k;
    vector<pii> fac;
    for(ll i=2;i<4e7;i++)
    {
        int e=0;
        while(n%i==0)
        {
            e++;
            n/=i;
        }
        if(e)
            fac.push_back(pii(i,e));
    }
    if(n!=1)
        fac.push_back(pii(n,1));

    ll res=1;
    for(auto y : fac)
        res=(res*solve(y))%mod;
    db(res)


    return 0;
}