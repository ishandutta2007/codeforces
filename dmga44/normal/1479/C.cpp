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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int l,r;
    cin >> l >> r;
    int n=23;
    int d=r-l;
    vector<pip> edges;
    int add=0;
    edges.push_back(pip(l,pii(0,n-1)));
    for(int j=1;j+1<n;j++)
        if(d&(1<<(n-j-2)))
        {
            edges.push_back(pip(add+l,pii(0,j)));
            add+=(1<<(n-j-2));
        }
    for(int i=1;i<n;i++)
        for(int j=i+1;j<n;j++)
            edges.push_back(pip(1<<max(n-j-2,0),pii(i,j)));
    cout << "YES" << '\n';
    cout << n << ' ' << edges.size() << '\n';
    for(auto y : edges)
        cout << y.s.f+1 << ' ' << y.s.s+1 << ' ' << y.f << '\n';

    return 0;
}