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
typedef pair<ld,pii> pdp;
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
#define MAXN (ll)(2e2+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll cs[2][6];
        ll x,y;
        cin >> x >> y;
        for(int i=0;i<6;i++)
            cin >> cs[0][i];
        for(int i=0;i<100;i++)
            for(int j=0;j<6;j++)
                cs[1-(i&1)][j]=min(cs[i&1][j],cs[i&1][(j+1)%6]+cs[i&1][(j+5)%6]);
        if(x==0)
        {
            if(y<0)
                db(abs(y)*cs[0][4])
            else
                db(abs(y)*cs[0][1])
        }
        else if(x>0)
        {
            if(y==0)
                db(x*cs[0][5])
            else if(y>0)
            {
                if(x<=y)
                    db(x*cs[0][0]+(y-x)*cs[0][1])
                else
                    db(y*cs[0][0]+(x-y)*cs[0][5])
            }
            else
                db(abs(y)*cs[0][4]+x*cs[0][5])
        }
        else
        {
            if(y==0)
                db(abs(x)*cs[0][2])
            else if(y>0)
                db(abs(y)*cs[0][1]+abs(x)*cs[0][2])
            else
            {
                if(abs(x)<=abs(y))
                    db(abs(x)*cs[0][3]+(abs(y)-abs(x))*cs[0][4])
                else
                    db(abs(y)*cs[0][3]+(abs(x)-abs(y))*cs[0][2])
            }
        }
    }

    return 0;
}