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

bool operator<(vector<int> &a, vector<int> &b)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < b[i])
            return 1;
        if (a[i] > b[i])
            return 0;
    }
    return 0;
}

int val(vector<int> &a)
{
    int p = 1;
    int ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        ans += p * a[i];
        p *= a.size();
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // int n=3;
    // vector<int> p(2*n);
    // for(int i=0;i<2*n;i++)
    //     p[i]=i;
    // queue<vector<int>> q;
    // map<int,int> s;
    // q.push(p);
    // s[val(p)]++;
    // vector<vector<int>>passed;
    // while(!q.empty())
    // {
    //     vector<int> u=q.front();
    //     passed.push_back(u);
    //     // cout << val(u) << '\n';
    //     q.pop();

    //     for(int i=1;i<=n;i++)
    //     {
    //         vector<int> cpy=u;
    //         for(int j=0;j<i;j++)
    //             swap(cpy[n-i+j],cpy[n+j]);
    //         if(s[val(cpy)])
    //             continue;
    //         q.push(cpy);
    //         s[val(cpy)]++;
    //     }
    // }

    // for(auto v : passed)
    // {
    //     for(auto x : v)
    //         cout << x << ' ';
    //     cout << '\n';
    // }
    // cout << passed.size() << '\n';

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        map<pii, int> f;
        vector<int> fc(26);
        for (int i = 0; i < n; i++)
        {
            int c1 = a[i] - 'a';
            int c2 = b[n - i - 1] - 'a';
            fc[c1]++;
            fc[c2]++;
            if (c1 > c2)
                swap(c1, c2);
            f[pii(c1, c2)]++;
        }
        bool ok = 1;
        for (int i = 0; i < 26; i++)
            ok &= (fc[i] % 2 == 0);
        int cant = 0;
        for (auto y : f)
            cant += (y.second & 1);
        if (cant > 1 || !ok)
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}