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
#define MAXN (ll)(1e2 + 5)

bool dp[MAXN][MAXN][2];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    dp[0][0][0] = 1;
    dp[0][1][1] = 1;
    dp[1][0][0] = 1;
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
        {
            if(i+j<=1)
                continue;
            int c[2];
            c[0] = i;
            c[1] = j;
            
            if((c[0] && (!c[1] || dp[c[0]-1][c[1]-1][0]) && (c[0]<=1 || dp[c[0]-2][c[1]][0])) || (c[1] && (!c[0] || dp[c[0]-1][c[1]-1][1]) && (c[1]<=1 || dp[c[0]][c[1]-2][1])))
                dp[i][j][0]=1;
            // if(i==0 && j==2)
            //     cout << (c[1] && (!c[0] || dp[c[0]-1][c[1]-1][1]) && (c[1]<=1 || dp[c[0]][c[1]-2][1])) << '\n';
            
            if((c[0] && (!c[1] || dp[c[0]-1][c[1]-1][1]) && (c[0]<=1 || dp[c[0]-2][c[1]][1])) || (c[1] && (!c[0] || dp[c[0]-1][c[1]-1][0]) && (c[1]<=1 || dp[c[0]][c[1]-2][0])))
                dp[i][j][1]=1;
        }
    // cout << dp[2][0][1] << '\n';
    // cout << dp[0][2][0] << '\n';
    // cout << (2<=1 && dp[0][0][1]) << '\n';

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int c0 = 0, c1 = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            x = abs(x);
            a[i] = x & 1;
            if (a[i])
                c1++;
            else
                c0++;
        }

        if (dp[c0][c1][0])
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }

    return 0;
}