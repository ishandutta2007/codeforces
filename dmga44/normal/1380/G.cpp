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
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e3+5)

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
    vector<ll> a(n);
    vector<ll> ac(n+1);
    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(all(a));

    for(int i=0;i<n;i++)
    {
        ac[i+1]=ac[i]+a[i];
        ac[i+1]%=mod;
    }

    for(int i=1;i<=n;i++)
    {
        ll res=0;
        int pos=n-i;
        ll mul=1;
        while(pos)
        {
            if(pos-i>=0)
            {
                res=(res+(mul)*(ac[pos]-ac[pos-i]))%mod;
                mul++;
                pos-=i;
            }
            else
            {
                res=(res+(mul)*(ac[pos]-ac[0]))%mod;
                mul++;
                pos=0;
            }
        }

        cout << (res*qp(n,mod-2))%mod << ' ';
    }
    cout << '\n';
    return 0;
}
/**
8
10 4 3 6 5 10 7 5
**/