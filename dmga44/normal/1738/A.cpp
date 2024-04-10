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
        vector<ll> a0,a1;
        vector<int> ty(n);
        for(int i=0;i<n;i++)
            cin >> ty[i];
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;
            sum+=2*x;
            if(ty[i])
                a1.push_back(x);
            else
                a0.push_back(x);
        }

        sort(all(a0));
        sort(all(a1));

        if(a0.size()==a1.size())
            sum-=min(a0[0],a1[0]);
        else
        {
            if(a0.size()>a1.size())
                swap(a0,a1);
            for(int i=0;i<a1.size()-a0.size();i++)
                sum-=a1[i];
        }
        cout << sum << '\n';
    }   

    return 0;
}