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
        string s;
        cin >> s;
        vector<ll> ac(n+1);
        ac[0]=0;
        map<pii,ll> fs;
        // fs[0]=1; 
        for(int i=0;i<n;i++)
        {
            if(s[i]=='D')
                ac[i+1]=ac[i]+1;
            else
                ac[i+1]=ac[i]-1;
            ll x=(((i+1)+ac[i+1])/2)/__gcd((((i+1)+ac[i+1])/2),(ll)i+1);
            ll y=(((i+1)-ac[i+1])/2)/__gcd((((i+1)-ac[i+1])/2),(ll)i+1);
            // cout << i << ' ' << x << '\n';
            fs[pii(x,y)]++;
            cout << fs[pii(x,y)] << " \n"[i==n-1];
        }

        // vector<int> ans(n+1);
        // for(int i=1;i<=n;i++)
        //     for(int j=i;j<=n;j+=i)
        //         if(ac[i]*(j/i)==ac[j])
        //             ans[j]++;
        
        // for(int i=1;i<=n;i++)
        //     cout << ans[i] << " \n"[i==n];
    }

    return 0;
}