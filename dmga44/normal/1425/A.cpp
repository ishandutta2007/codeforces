#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")
#pragma GCC target ("sse4")

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
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

ll solve(ll n)
{
    ll res=0;
    while(n)
    {
        if(n==4)
        {
            res+=3;
            break;
        }
        if(n==1)
        {
            res++;
            break;
        }
        if((n/2)&1)
        {
            res+=n/2;
            n/=2;
            n--;
        }
        else
        {
            res++;
            n-=2;
        }
    }
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll res=0;
        if(n&1)
        {
            res++;
            n--;
            res+=n-solve(n);
        }
        else
            res=solve(n);
        db(res)
    }

    return 0;
}
/**
10
1
2
3
4
5
6
7
8
9
10
**/