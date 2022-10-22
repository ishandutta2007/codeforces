#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native", "no-zero-upper") // Enable AVX

/// UH Top
#include <bits/stdc++.h>
#define db(x) cerr << #x << ':' << (x) << '\n';
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
// #define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t int128;
typedef pair<ll, ll> pii;
typedef pair<ld, ll> pdi;
typedef pair<ld, ld> pdd;
typedef pair<ld, pdd> pdp;
typedef pair<string, ll> psi;
typedef pair<ll, string> pls;
typedef pair<string, string> pss;
typedef pair<ll, pii> pip;
typedef pair<pii, pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef vector<ll> vi;
typedef pair<point, int> ppi;
#define prec(n)        \
    cout.precision(n); \
    cout << fixed
const ll mod = (1e9 + 7);
const ld eps = (1e-9);
const ll oo = (ll)(1e18 + 5);
#define pi acos(-1)
#define MAXN (ll)(1e6 + 5)

bool split(vector<int> a,vector<int> b,int bit,vector<int>& a0,vector<int>& a1,vector<int>& b0,vector<int>& b1)
{
    int n=a.size();
    int ca1=0,cb1=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]&(1<<bit))
        {
            a1.push_back(a[i]);
            ca1++;
        }
        else
            a0.push_back(a[i]);

        if(b[i]&(1<<bit))
        {
            b1.push_back(b[i]);
            cb1++;
        }
        else
            b0.push_back(b[i]);
    }

    return (ca1+cb1)==n;
}

int solve(vector<vector<int>> a,vector<vector<int>> b,int last)
{
    if(last==0)
        return 0;
    
    last--;
    int n=a.size();
    vector<vector<int>> na,nb;
    bool ok=1;
    for(int i=0;i<n && ok;i++)
    {
        vector<int> a0,a1,b0,b1;
        ok&=split(a[i],b[i],last,a0,a1,b0,b1);
        if(a0.size())
        {
            na.push_back(a0);
            nb.push_back(b1);
        }
        if(a1.size())
        {
            na.push_back(a1);
            nb.push_back(b0);
        }
    }

    if(ok)
        return (1<<last)+solve(na,nb,last);
    return solve(a,b,last);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin >> a[i];
        vector<int> b(n);
        for(int i=0;i<n;i++)
            cin >> b[i];

        cout << solve({a},{b},30) << '\n';
    }

    return 0;
}