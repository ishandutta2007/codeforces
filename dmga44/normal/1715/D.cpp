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

    int n,m;
    cin >> n >> m;
    vector<pip> edges;
    for(int i=0;i<m;i++)
    {
        int l,r,v;
        cin >> l >> r >> v;
        l--,r--;
        edges.push_back(pip(v,pii(l,r)));
    }

    vector<int> ans(n);
    for(int b=0;b<30;b++)
    {
        vector<bool> is0(n);
        vector<bool> is1(n);
        vector<vector<int>> g(n);
        for(int i=0;i<m;i++)
        {
            if(edges[i].first&(1<<b))
            {
                if(edges[i].second.first!=edges[i].second.second)
                {
                    g[edges[i].second.first].push_back(edges[i].second.second);
                    g[edges[i].second.second].push_back(edges[i].second.first);
                }
                else
                {
                    ans[edges[i].second.first]|=(1<<b);
                    is1[edges[i].second.first]=1;
                }
            }
            else
            {
                is0[edges[i].second.first]=1;
                is0[edges[i].second.second]=1;
            }
        }

        for(int i=0;i<n;i++)
        {
            if(is0[i] || is1[i])
                continue;
            is0[i]=1;
            for(auto e : g[i])
                is0[i]=is0[i]&(!is0[e]);
        }

        for(int i=0;i<n;i++)
            ans[i]|=(((int)!is0[i])<<b);
    }

    for(int i=0;i<n;i++)
        cout << ans[i] << ' ';
    cout << '\n'; 

    return 0;
}