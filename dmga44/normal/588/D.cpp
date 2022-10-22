#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

map<int,int> t;
int a[MAXN];

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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,l,k;
    cin >> n >> l >> k;
    set<int> s;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }

    int cont=0;
    for(auto y : s)
    {
        t[y]=cont;
        cont++;
    }

    for(int i=0;i<n;i++)
        a[i]=t[a[i]];

    vector< vector<ll> > dp;
    vector< vector<ll> > ac;
    for(int i=0;i<=k;i++)
    {
        dp.push_back(vector<ll>(n+1));
        ac.push_back(vector<ll>(n+1));
    }

    for(int i=0;i<=n;i++)
        ac[0][i]=1;

    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i+1][j]=ac[i][a[j]];
            ac[i+1][a[j]]=(ac[i+1][a[j]]+dp[i+1][j])%mod;
        }
        for(int j=1;j<=n;j++)
            ac[i+1][j]=(ac[i+1][j-1]+ac[i+1][j])%mod;
    }

    vector<ll> c0;
    c0.push_back(1);
    ll x=(l-1)/n+1;
    for(ll i=0;i<min(k,x);i++)
    {
        ll den=qp(i+1,mod-2);
        ll num=(x-i)%mod;
        ll f1=c0.back();
        f1=(f1*num)%mod;
        f1=(f1*den)%mod;
        c0.push_back(f1);
    }
    while(c0.size()<=k)
        c0.push_back(0);

    vector<ll> c1;
    c1.push_back(1);
    x--;
    for(ll i=0;i<min(k,x);i++)
    {
        ll den=qp(i+1,mod-2);
        ll num=(x-i)%mod;
        ll f1=c1.back();
        f1=(f1*num)%mod;
        f1=(f1*den)%mod;
        c1.push_back(f1);
    }
    while(c1.size()<=k)
        c1.push_back(0);

//    for(int i=0;i<=k;i++)
//        cout << c0[i] << ' ' << c1[i] << '\n';
//    for(int i=0;i<=k;i++)
//    {
//        for(int j=0;j<n;j++)
//            cout << dp[i][j] << ' ';
//        cout << '\n';
//    }

    ll res=0;
    ll lim=l%n;
    if(!lim)
        lim=n;
    for(int i=0;i<n;i++)
    {
        if(i<lim)
        {
            ll cant=x+1;
            for(int j=1;j<=k;j++)
                if(cant>=j)
                    res=(res+((cant-j+1)%mod)*dp[j][i])%mod;
        }
        else
        {
            ll cant=x;
            cant%=mod;
            for(int j=1;j<=k;j++)
                if(cant>=j)
                    res=(res+((cant-j+1)%mod)*dp[j][i])%mod;
        }
    }
    db(res)

    return 0;
}
/**
6 5 6
5 9 1 2 3 4
**/