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
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

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

ll fac[MAXN],ifac[MAXN];

ll comb(int n,int m)
{
    ll den=(ifac[m]*ifac[n-m])%mod;
    return (fac[n]*den)%mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fac[0]=1;
    for(int i=1;i<MAXN;i++)
        fac[i]=(fac[i-1]*i)%mod;
    ifac[MAXN-1]=qp(fac[MAXN-1],mod-2);
    for(int i=MAXN-2;i>=0;i--)
        ifac[i]=(ifac[i+1]*(i+1))%mod;

    ll n,k;
    cin >> n >> k;
    int extras=0;
    vector<int> fs(n+1);
    map<int,int> f;
    fs[0]=k;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        if(x==-1)
        {
            extras++;
            continue;
        }
        fs[f[x]]--;
        f[x]++;
        fs[f[x]]++;
    }

    ///fix f(x)=m_x*f(x+1)+n_x
    vector<ll> mx(n+1),nx(n+1);
    for(int i=0;i<=n;i++)
    {
        ll inv_den=qp(((n+(k-2)*i)%mod),mod-2);
        nx[i]=(i*k)%mod;
        mx[i]=n-i;
        ll div=1,men=0;
        if(i)
        {
            ll m1=((k-1)*i)%mod;
            men=(m1*mx[i-1])%mod;
            men=(men*inv_den)%mod;
            nx[i]=(nx[i]+m1*nx[i-1])%mod;
        }
        div=(div-men+mod)%mod;
        inv_den=(inv_den*qp(div,mod-2))%mod;
        mx[i]=(mx[i]*inv_den)%mod;
        nx[i]=(nx[i]*inv_den)%mod;
    }

    vector<ll> vs(n+1);
    vs[n]=nx[n];
    for(int i=n-1;i>=0;i--)
        vs[i]=(vs[i+1]*mx[i]+nx[i])%mod;

    vector<ll> adds(n+1);
    for(int i=0;i<=extras;i++)
        adds[i]=(qp(k-1,extras-i)*comb(extras,i))%mod;

    ll tot=qp(k,extras);
    ll sum=((k-1)*vs[0]+vs[n])%mod;
    ll ans=mod-((tot*sum)%mod);
    for(int i=n;i>=0;i--)
        if(fs[i])
        {
            ll x=fs[i];
            fs[i]=0;
            for(int j=0;j<=extras;j++)
                fs[i+j]=(fs[i+j]+x*adds[j])%mod;
        }

    for(int i=0;i<=n;i++)
        ans=(ans+fs[i]*vs[i])%mod;

    ans=(ans*qp(tot,mod-2))%mod;

    db(ans)

    return 0;
}