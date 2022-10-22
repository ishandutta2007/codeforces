//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

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
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

bool solve(ll x,ll l,ll r,ll t,ll dif)
{
    if(x<l)
        return 0;
    if(!dif)
        return 1;
    if((x-l)/dif<t)
        return 0;
    return 1;
}

bool solve2(ll k,ll r,ll t,ll x,ll y)
{
    ll add=y%x;
    ll act=k%x;
    ll ma=k/x;
    ll top=r-y;
    vector<bool> mk(x);
    while(!mk[act])
    {
        if(act>top)
            break;
        mk[act]=1;
        act+=y;
        ma+=act/x;
        act%=x;
    }

    if(mk[act])
        ma=-1;

    return ma==-1 || ma>=t;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll k,l,r,t,x,y;
    cin >> k >> l >> r >> t >> x >> y;
    bool res;
    if(x>=y)
    {
        if(k+y>r)
            res=solve(k-x,l,r,t-1,x-y);
        else
            res=solve(k,l,r,t,x-y);
    }
    else
    {
        if(r-l>=x+y)
            res=1;
        else if(r-l<y)
            res=((k-l)/x>=t);
        else
        {
            k-=l;
            r-=l;
            res=solve2(k,r,t,x,y);
        }
    }

    if(res)
        db("Yes")
    else
        db("No")

    return 0;
}
/**
9 1 10 8 2 9
**/