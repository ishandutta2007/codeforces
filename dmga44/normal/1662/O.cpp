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

set<pii> g[22][360];
bool mk[22][360];

int32_t main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i=0;i<22;i++)
            for(int j=0;j<360;j++)
            {
                if(i<21)
                    g[i][j].insert(pii(i+1,j));
                if(i)
                    g[i][j].insert(pii(i-1,j));
                g[i][j].insert(pii(i,(j+1)%360));
                g[i][j].insert(pii(i,(j+359)%360));
                mk[i][j]=0;
            }
        // cerr << "xxx\n";

        for(int i=0;i<n;i++)
        {
            char ty;
            cin >> ty;
            if(ty=='C')
            {
                int r,a1,a2;
                cin >> r >> a1 >> a2;
                for(int j=a1;j!=a2;j=(j+1)%360)
                {
                    if(g[r-1][j].count(pii(r,j)))
                        g[r-1][j].erase(pii(r,j));
                    if(g[r][j].count(pii(r-1,j)))
                        g[r][j].erase(pii(r-1,j));
                }
            }
            else
            {
                int r1,r2,a;
                cin >> r1 >> r2 >> a;
                for(int j=r1;j<r2;j=j+1)
                {
                    if(g[j][a].count(pii(j,(a+359)%360)))
                        g[j][a].erase(pii(j,(a+359)%360));
                    if(g[j][(a+359)%360].count(pii(j,a)))
                        g[j][(a+359)%360].erase(pii(j,a));
                }
            }
        }
        // cerr << "xxx\n";

        queue<pii> q;
        q.push(pii(0,0));
        mk[0][0]=1;
        while(!q.empty())
        {
            pii x=q.front();
            q.pop();

            // cerr << x.first << ' ' << x.second << '\n';
            for(auto e : g[x.first][x.second])
            {
                int r=e.first;
                int a=e.second;
                if(!mk[r][a])
                {
                    mk[r][a]=1;
                    q.push(pii(r,a));
                }
            }
        }

        if(mk[21][0])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}