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
#define oo (ll)(1e18)
#define pi acos(-1)
#define MAXN (ll)(6e1+5)

string s[MAXN];
int r,c;

ll solve()
{
    bool hay=0;
    bool full=1;
    bool sides=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            hay|=(s[i][j]=='A');
            full&=(s[i][j]=='A');
            if(i==0 || i==r-1 || j==0 || j==c-1)
                sides|=(s[i][j]=='A');
        }
    }

    if(!hay)
        return oo;
    if(full)
        return 0;
    if(!sides)
        return 4;

    ///1
    bool ok=1;
    for(int i=0;i<r;i++)
        ok&=(s[i][0]=='A');
    if(ok)
        return 1;

    ok=1;
    for(int i=0;i<r;i++)
        ok&=(s[i][c-1]=='A');
    if(ok)
        return 1;

    ok=1;
    for(int i=0;i<c;i++)
        ok&=(s[0][i]=='A');
    if(ok)
        return 1;

    ok=1;
    for(int i=0;i<c;i++)
        ok&=(s[r-1][i]=='A');
    if(ok)
        return 1;

    ///2
    ok=0;
    ok|=(s[0][0]=='A');
    ok|=(s[0][c-1]=='A');
    ok|=(s[r-1][0]=='A');
    ok|=(s[r-1][c-1]=='A');
    for(int i=0;i<r;i++)
    {
        bool kk=1;
        for(int j=0;j<c;j++)
            kk&=(s[i][j]=='A');
        ok|=kk;
    }
    for(int i=0;i<c;i++)
    {
        bool kk=1;
        for(int j=0;j<r;j++)
            kk&=(s[j][i]=='A');
        ok|=kk;
    }
    if(ok)
        return 2;
    return 3;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        cin >> r >> c;
        for(int i=0;i<r;i++)
            cin >> s[i];

        ll x=solve();
        if(x==oo)
            db("MORTAL")
        else
            db(x)
    }

    return 0;
}