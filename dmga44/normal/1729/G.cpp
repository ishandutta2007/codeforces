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
    while (t--)
    {
        string s;
        cin >> s;
        string t;
        cin >> t;
        int n = s.size();
        vector<bool> ok(n);
        for (int i = 0; i + t.size() <= n; i++)
        {
            ok[i] = 1;
            for (int j = 0; j < t.size(); j++)
                ok[i] = ok[i] & (s[i + j] == t[j]);
        }

        vector<int> in(n + 1);
        vector<vector<int>> g(n + 1);
        for (int i = 0; i < n; i++)
            if (ok[i])
            {
                for (int j = i; j < i + t.size(); j++)
                    if (ok[j])
                    {
                        // cout << 0 << ' ' << j + 1 << '\n';
                        g[0].push_back(j + 1);
                        in[j + 1]++;
                    }
                break;
            }
        for (int i = 0; i < n; i++)
        {
            if (ok[i])
            {
                for (int ini = i + t.size(); ini < n; ini++)
                    if (ok[ini])
                    {
                        for (int j = ini; j < ini + t.size(); j++)
                            if (ok[j])
                            {
                                // cout << i + 1 << ' ' << j + 1 << '\n';
                                g[i + 1].push_back(j + 1);
                                in[j + 1]++;
                            }
                        break;
                    }
            }
        }

        vector<pii> dp(n + 1, pii(1e9, 0));
        dp[0] = pii(0, 1);
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            pii val = pii(dp[u].first + 1, dp[u].second);
            for (auto v : g[u])
            {
                in[v]--;
                if (dp[v].first > val.first)
                    dp[v] = val;
                else if (dp[v].first == val.first)
                    dp[v] = pii(val.first, (val.second + dp[v].second) % mod);
                if (!in[v])
                    q.push(v);
            }
        }
        pii ans = pii(1e9, 0);
        for (int i = 0; i <= n; i++)
            if (g[i].empty())
            {
                if (ans.first > dp[i].first)
                    ans = dp[i];
                else if (ans.first == dp[i].first)
                    ans = pii(ans.first, (ans.second + dp[i].second) % mod);
            }
        cout << ans.first << ' ' << ans.second << '\n';
    }

    return 0;
}