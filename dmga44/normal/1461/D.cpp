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
#define MAXN (ll)(5e2+5)

set<ll> solve(vector<int>& a)
{
    set<ll> res;
    if(a.empty())
        return res;
    ll sum=0;
    int ma=0,mi=1e6;
    bool eq=1;
    int ini=a[0];
    for(auto y : a)
    {
        eq&=(y==ini);
        ma=max(ma,y);
        mi=min(mi,y);
        sum+=y;
    }
    res.insert(sum);
    if(eq)
        return res;
    int mid=(ma+mi)/2;
    vector<int> m1;
    vector<int> m2;
    for(auto y : a)
    {
        if(y<=mid)
            m1.push_back(y);
        else
            m2.push_back(y);
    }
    set<ll> s1=solve(m1);
    set<ll> s2=solve(m2);
    for(auto y : s1)
        res.insert(y);
    for(auto y : s2)
        res.insert(y);
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
        int n,m;
        cin >> n >> m;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin >> a[i];
        set<ll> mk=solve(a);
        for(int i=0;i<m;i++)
        {
            int x;
            cin >> x;
            if(mk.count(x))
                db("Yes")
            else
                db("No")
        }
    }

    return 0;
}