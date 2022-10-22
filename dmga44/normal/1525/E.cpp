#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
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
const ll mod=(998244353 );
const ld eps=(1e-9);
const ll oo=(ll)((1e18)+5);
#define pi acos(-1)
#define MAXN (ll)(5e3+5)

ll qp(ll b,ll e)
{
    ll ans=1;
    while(e)
    {
        if(e&1)
            ans=(ans*b)%mod;
        b=(b*b)%mod;
        e>>=1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<vector<ll>> a(n,vector<ll>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> a[i][j];
    
    ll fac=1;
    for(int i=2;i<=n;i++)
        fac=(fac*i)%mod;

    ll ans=0;
    for(int i=0;i<m;i++)
    {
        vector<int> f(n);
        for(int j=0;j<n;j++)
        {
            int x=a[j][i];
            for(int k=n-(x-1);k<n;k++)
                f[k]++;
        }
        ll mul=1;
        for(int i=0;i<n;i++)
            mul=(mul*(f[i]-i))%mod;
        ll add=(fac-mul+mod)%mod;
        add=(add*qp(fac,mod-2))%mod;
        ans=(ans+add)%mod;
    }
    db(ans)

    return 0;
}