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
const ld eps=(1e-8);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

int p[MAXN];

void criba()
{
    for(int i=2;i<MAXN;i++)
        if(!p[i])
            for(int j=i;j<MAXN;j+=i)
                p[j]=i;
}

int trans(int x)
{
    if(x==1)
        return 1;
    map<int,int> mp;
    while(x!=1)
    {
        mp[p[x]]++;
        x/=p[x];
    }
    int res=1;
    for(auto y : mp)
        for(int i=0;i<(y.s&1);i++)
            res*=y.f;
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    criba();

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            a[i]=trans(a[i]);
        }
//        for(int i=0;i<n;i++)
//            cout << a[i] << ' ';
//        cout << '\n';
        map<int,int> fx;
        map<int,int> f2;
        for(int i=0;i<n;i++)
            fx[a[i]]++;
        for(auto y : fx)
        {
            if(y.s&1)
                f2[y.f]+=y.s;
            else
                f2[1]+=y.s;
        }
        int r0=0,r1=0;
        for(auto y : fx)
            r0=max(r0,y.s);
        for(auto y : f2)
            r1=max(r1,y.s);
        int q;
        cin >> q;
        while(q--)
        {
            ll w;
            cin >> w;
            if(w==0)
                db(r0)
            else
                db(r1)
        }
    }

    return 0;
}