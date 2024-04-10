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
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(998244353);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

ll qp(ll k)
{
    if(!k)
        return 1;
    ll x=qp(k>>1);
    x=(x*x)%mod;
    if(k&1)
        x=(x+x)%mod;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m;
    cin >> m;
    vector<ll>f(MAXN),ans(MAXN);
    for(int i=0;i<m;i++)
    {
        int a;
        cin >> a;
        cin >> f[a];
    }

    for(int i=MAXN-1;i>0;i--)
    {
        ll k=0,sum1=0,sum2=0;
        for(int j=i;j<MAXN;j+=i)
        {
            ans[i]=(ans[i]-ans[j]+mod)%mod;
            k+=f[j];
            sum1=(sum1+f[j]*j)%mod;
            sum2=(sum2+((f[j]*j)%mod)*j)%mod;
        }

        sum1=(sum1*sum1-sum2+mod)%mod;
        if(k>=2)
        {
            ans[i]=(ans[i]+((sum2*((k-1)%mod))%mod)*qp(k-2))%mod;
            ans[i]=(ans[i]+sum1*qp(k-2))%mod;
            if(k>=3)
                ans[i]=(ans[i]+((sum1*((k-2)%mod))%mod)*qp(k-3))%mod;
        }
    }
    cout << ans[1] << '\n';

    return 0;
}