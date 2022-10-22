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
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

ll a,b;
ll res,n;

void solve(ll l,ll r)
{
    if(n/l==n/r)
    {
        ll g=n/l;
        if(g>min(a,b))
            return ;
        if(a%g>a/g || b%g>b/g)
            return ;
        ll inf=max(l,(a-1)/(g+1)+1+(b-1)/(g+1)+1);
        ll sup=min(r,a/g+b/g);
        if(inf<=sup)
            res+=(sup-inf+1);
        return ;
    }
    ll mid=(l+r)/2;
    solve(l,mid);
    solve(mid+1,r);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    n=a+b;
    solve(1,n);

    db(res)

    return 0;
}