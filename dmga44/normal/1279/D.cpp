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
typedef pair<ll,ll> pii;
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
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

vector<int> c[MAXN];
int f[MAXN];

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

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int cant,x;
        cin >> cant;
        for(int j=0;j<cant;j++)
        {
            cin >> x;
            f[x]++;
            c[i].push_back(x);
        }
    }

    ll res=0;
    for(int i=0;i<n;i++)
    {
        for(auto j : c[i])
        {
            ll p1=qp(n,mod-2);
            ll p2=qp(n,mod-2);
            ll p3=qp(c[i].size(),mod-2);
            ll p4=f[j];
            ll m1=(p1*p2)%mod;
            ll m2=(p3*p4)%mod;
            res=(res+(m1*m2))%mod;
        }
    }
    db(res)
    return 0;
}