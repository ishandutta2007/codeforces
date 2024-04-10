#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

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
const ll mod=(ll)(998244353);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(1e4+5)

int pascal[MAXN][MAXN/2];

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

ll comb(int n,int m)
{
    return pascal[n+1][m+1];
}

ll ways(int p,int s)
{
    return comb(s+p-1,p-1);
}

ll solve(int sum,int n,int top)
{
//    cout << sum << ' ' << n << ' ' << top << '\n';
    ll res=ways(n,sum);
//    db(res)
    for(int i=1;i*top<=sum && i<=n;i++)
    {
        if(i&1)
            res=(res+mod-(ways(n,sum-i*top)*comb(n,i))%mod)%mod;
        else
            res=(res+mod+(ways(n,sum-i*top)*comb(n,i))%mod)%mod;
    }
//    db(res)
//    db("")
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pascal[0][0]=1;
    for(int i=1;i<MAXN;i++)
        for(int j=1;j<=i && j<MAXN/2;j++)
            pascal[i][j]=(pascal[i-1][j-1]+pascal[i-1][j])%mod;

    int p,s,r;
    cin >> p >> s >> r;
    ll sum=0;
    ll res=qp(ways(p,s-r),mod-2);
    for(int i=r;i<=s;i++)
        for(int cant=1;cant*i<=s && cant<=p;cant++)
        {
//            cout << i << ' ' << cant << '\n';
//            db(solve(s-i*cant,p-cant,i))
//            db("")
            sum=(sum+((solve(s-i*cant,p-cant,i)*qp(cant,mod-2))%mod)*(comb(p-1,cant-1)))%mod;
        }

    db((sum*res)%mod)
//    db(qp(p,mod-2))

    return 0;
}
/**
2 4 0
**/