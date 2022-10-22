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
#define MAXN (ll)(1e6 + 30)

int trans[MAXN][26];

void prefix_function(const string &p, vector<int> &pref, int start)
{
    int n = p.length();

    int i = 0, j = pref[0] = -1;
    if (start)
    {
        i = start, j = pref[start];
    }
    for (; i < n; pref[++i] = ++j)
    {
        int x = 0;
        if (j >= 0)
            x = trans[j][p[i] - 'a'];
        if (j < start && x)
        {
            j = x - 1e6;
            continue;
        }
        int act = j;
        while (j >= 0 && p[i] != p[j])
        {
            j = pref[j];
            if (j >= 0 && trans[j][p[i] - 'a'])
                j = trans[j][p[i] - 'a'] - 1e6;
        }
        if (act >= 0 && (start==0 || act<start))
            trans[act][p[i] - 'a'] = j + 1e6;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<string> qs(q);
    vector<int> pref(s.size() + 1);
    prefix_function(s, pref, 0);
    for (int i = 0; i < 10; i++)
        pref.push_back(0);

    for (int i = 0; i < q; i++)
    {
        cin >> qs[i];
        for (auto c : qs[i])
            s.push_back(c);

        prefix_function(s, pref, s.size() - qs[i].size());

        for (auto c : qs[i])
            s.pop_back();

        for (int j = s.size() + 1; j <= s.size() + qs[i].size(); j++)
            cout << pref[j] << ' ';
        cout << '\n';
    }

    return 0;
}