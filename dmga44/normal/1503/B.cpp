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
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;
    vector<pii> p1;
    vector<pii> p2;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if((i+j)&1)
                p1.push_back(pii(i,j));
            else
                p2.push_back(pii(i,j));
        }
    int c1=0;
    int c2=0;
    for(int i=0;i<n*n;i++)
    {
        int x;
        cin >> x;
        if(x!=1)
        {
            if(c1<p1.size())
            {
                cout << 1 << ' ' << p1[c1].f << ' ' << p1[c1].s << '\n';
                cout.flush();
                c1++;
            }
            else
            {
                if(x==2)
                {
                    cout << 3 << ' ' << p2[c2].f << ' ' << p2[c2].s << '\n';
                    cout.flush();
                    c2++;
                }
                else
                {
                    cout << 2 << ' ' << p2[c2].f << ' ' << p2[c2].s << '\n';
                    cout.flush();
                    c2++;
                }
            }
        }
        else
        {
            if(c2<p2.size())
            {
                cout << 2 << ' ' << p2[c2].f << ' ' << p2[c2].s << '\n';
                cout.flush();
                c2++;
            }
            else
            {
                cout << 3 << ' ' << p1[c1].f << ' ' << p1[c1].s << '\n';
                cout.flush();
                c1++;
            }
        }
    }

    return 0;
}