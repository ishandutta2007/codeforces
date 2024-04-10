#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

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
//#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

struct matrix{
    vector< vector<ll> > m;
    ll mod,sz;
    ll mod2;

    matrix (ll n,ll modc) : sz(n),m(n),mod(modc) {
        for(int i=0;i<n;i++)
            m[i].resize(n);
        mod2=mod*mod;
    }

    matrix operator*(matrix b)
    {
        matrix ans(sz,mod);
        for(int i=0;i<sz;i++)
            for(int j=0;j<sz;j++)
                for(int u=0;u<sz;u++)
                {
                    ans.m[i][u]+=m[i][j]*b.m[j][u];
                    if(ans.m[i][u]>=mod2)
                        ans.m[i][u]-=mod2;
                }
        for(int i=0;i<sz;i++)
            for(int j=0;j<sz;j++)
                ans.m[i][j]%=mod;
        return ans;
    }

    matrix qp(ll e)
    {
        if(e==1)
            return *this;
        matrix x=qp(e/2);
        x=(x*x);
        if(e&1)
            x=(x*(*this));
        return x;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll m,l,r,k;
    cin >> m >> l >> r >> k;
    if(m==1)
    {
        db(0)
        return 0;
    }
    ll p=1;
    for(ll sz=1;sz<=1e6;sz++)
        if((r/(sz))-((l-1)/sz)>=k)
            p=sz;
    for(ll sz=1e6;sz>=2;sz--)
    {
        if(sz>r)
            continue;
        ll x=r/sz;
        if((r/x)-((l-1)/(x))>=k)
            p=max(p,x);
    }

    if(p==1 || p==2)
        db(1)
    else
    {
        matrix fib(2,m);
        fib.m[0][0]=1;
        fib.m[0][1]=1;
        fib.m[1][0]=1;
        cout << fib.qp(p-1).m[0][0] << '\n';
    }

    return 0;
}
/**
10 1 8 2
10 1 8 3
10 1 6 2
**/