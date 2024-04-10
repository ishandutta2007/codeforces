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
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(1e3+5)

ll ask(int t,int i,int j,int k)
{
    cout << t << ' ' << i << ' ' << j << ' ' << k << '\n';
    cout.flush();
    ll res;
    cin >> res;
    return res;
}

int32_t main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;
    ///p2
    int p1=1;
    int p2=2;
    for(int i=3;i<=n;i++)
    {
        ll x=ask(2,1,p2,i);
        if(x==-1)
            p2=i;
    }

    vector<pii> as;
    for(int i=2;i<=n;i++)
    {
        if(i==p2)
            continue;
        ll a=ask(1,1,p2,i);
        as.push_back(pii(a,i));
    }

    sort(all(as));

    vector<int> m1,m2;
    m1.push_back(as.back().s);
    for(int i=n-4;i>=0;i--)
    {
        int x=ask(2,1,m1[0],as[i].s);
        if(x==1)
            m2.push_back(as[i].s);
        else
            m1.push_back(as[i].s);
    }
    m1.push_back(p2);
    m1.push_back(p1);
    reverse(all(m1));
    for(auto y : m2)
        m1.push_back(y);

    cout << "0 ";
    for(auto y : m1)
        cout << y << ' ';
    cout << '\n';
    cout.flush();

    return 0;
}