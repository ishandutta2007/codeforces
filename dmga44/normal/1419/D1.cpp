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
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int a[MAXN],res[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    map<int,int> fs;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        fs[a[i]]++;
    }

    pii ma=pii(0,0);
    for(auto y : fs)
        ma=max(ma,pii(y.s,y.f));

    bool kk=0;
    if((n&1)==0)
    {
        res[n-1]=ma.s;
        n--;
        fs[ma.s]--;
        kk=1;
    }

    vector<int> ss;
    for(auto y : fs)
        for(int i=0;i<y.s;i++)
            ss.push_back(y.f);
//    for(int i=0;i<n;i++)
//        cout << ss[i] << ' ';
//    cout << '\n';

    for(int i=1;i<n;i+=2)
        res[i]=ss[i/2];
    for(int i=0;i<n;i+=2)
        res[i]=ss[(i+n)/2];

    if(kk)
        n++;

    int cant=0;
    for(int i=1;i<n-1;i++)
        if(res[i]<res[i-1] && res[i]<res[i+1])
            cant++;

    db(cant)
    for(int i=0;i<n;i++)
        cout << res[i] << ' ';
    cout << '\n';


    return 0;
}