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
        vector<ll> a(n);
        set<pii> s;
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            s.insert(pii(-a[i],i));
            sum+=a[i];
        }

        vector<ll> vals;
        vals.push_back(1);
        ll act=1;
        if(sum>1)
        {
            vals.push_back(1);
            act++;
        }
        while(act<sum)
        {
            act+=vals[vals.size()-2]+vals.back();
            vals.push_back(vals[vals.size()-2]+vals.back());
        }
        // cout << act << ' ' << sum << '\n';
        if(act>sum)
        {
            cout << "NO\n";
            continue;
        }
        int last=-1;
        bool ok=1;
        while(1)
        {
            if(vals.empty())
                break;
            pii x=(*s.begin());
            if(x.second==last)
            {
                s.erase(x);
                if(s.empty())
                {
                    cout << "NO\n";
                    ok=0;
                    break;
                }
                pii y=(*s.begin());
                s.erase(y);
                if(y.first>-vals.back())
                {
                    cout << "NO\n";
                    ok=0;
                    break;
                }
                else
                {
                    y.first+=vals.back();
                }
                last=y.second;
                s.insert(y);
                s.insert(x);
            }
            else
            {
                s.erase(x);
                if(x.first>-vals.back())
                {
                    cout << "NO\n";
                    ok=0;
                    break;
                }
                else
                {
                    x.first+=vals.back();
                }
                last=x.second;
                s.insert(x);
            }
            vals.pop_back();
        }
        if(ok)
            cout << "YES\n";
    }

    return 0;
}