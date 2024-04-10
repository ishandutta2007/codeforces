    #pragma GCC optimize("Ofast")
    #include <iostream>
    #include <map>
    #include <vector>
    #include <deque>
    #include <algorithm>
    #include <bitset>
    #include <cstring>
    #include <math.h>
    #include <string>
    #include <set>
    #include <iomanip>
    #include <bitset>
    #include <random>
    #include <complex>
    #include <random>
    #include <cassert>
    #include <unordered_map>
    #include <unordered_set>
    using namespace std;
    #define pb push_back
    #define ll long long
    #define mp make_pair
    #define fdeg firdeg
    #define snd second
    #define ins insert
    #define ld long double
    #define mt make_tuple
    #define fst first
    const double PI = acos(-1);
    // = 5e5 + 17;
    ll MOD = 1e9 + 7;
    const int INF = 1e9;
    const int MaXN = 150;
    const int N = 2e5 + 1000;
    const int LOG = 64;
    const int FACT = 120;
    ld ecr = 1e-8;
    random_device rd;
    mt19937 rnd(rd());
    uniform_int_distribution<ll> nextRand(0,(ll)1e9);
    template<class A, class B>
    void sum(A &a, B b)
    {
        a += b;
        if (a < 0LL) a += MOD;
        if (a >= MOD) a -= MOD;
    }
    ll add(ll a, ll b)
    {
        a += b;
        if (a < 0) a += MOD;
        if (a >= MOD) a -= MOD;
        return a;
        
    }
    int to_i(char c)
    {
        return c - 'a';
    }
    ll mult(ll a, ll b) {
        ll val = a * b - (ll) ((ld) a * b / MOD) * MOD;
        if (val < 0) {
            val += MOD;
        }
        if (val >= MOD) {
            val -= MOD;
        }
        return val;
    }
    ll gcd (ll a, ll b)
    {
        if (b == 0)
            return a;
        else
            return gcd (b, a % b);
    }
    ll gcd_eu (ll a, ll b, ll & x, ll & y)
    {
        if (a == 0)
        {
            x = 0LL; y = 1LL;
            return b;
        }
        ll x1, y1;
        ll d = gcd_eu (b%a, a, x1, y1);
        x = y1 - (b / a) * x1;
        y = x1;
        return d;
    }
    long long poww(long long a, long long b)
    {
        long long val = 1;
        a %= MOD;
        while (b > 0)
        {
            if (b % 2) val = mult(a, val);
            a = mult(a, a);
            b >>= 1;
        }
        return val % MOD;
    }
    ll inv(ll a)
    {
        return poww(a , MOD - 2);
    }
    int logP(int a, int p)
    {
        int logg = 0;
        while (a % p == 0)
        {
            a /= p;
            logg++;
        }
        return logg;
    }

    int calc(vector<int>& a, vector<int>& b, int p) {
        int n = a.size(), m = b.size();
        vector<int> logA(n), logB(m);
        for (int i = 0; i < n; i++)
            logA[i] = logP(a[i], p);
        for (int i = 0; i < m; i++)
            logB[i] = logP(b[i], p);
        ll mna = 1e18, mnb = 1e18;
        for(int i = 0; i < n; i++)
            mna = min(mna, (ll)logA[i]);
        for(int i = 0; i < m; i++)
            mnb = min(mnb, (ll)logB[i]);
        ll mnx = max(mna, mnb);
        int aa = 0, bb = 0;
        for (int i = 0; i < n; i++)
            if (logA[i] < mnx + 1)
                aa++;
        for (int i = 0; i < m; i++)
            if (logB[i] < mnx + 1)
                bb++;
        return add(poww(mnx + 1, aa),poww(mnx + 1, bb) - 1);
    }
    vector<int> pr;
    void add_to_pr(ll x)
    {
        for (int i = 2; i * i <= x; i++)
        {
            //cout << x << " ";
            if (x % i == 0)
            {
                while (x % i == 0) x /= i;
                pr.pb(i);
            }
        }
        if (x > 1)
        {
            pr.pb(x);
        }
    }

const int dx[6] = {-1, -2, -1, 1, 2, 1};
const int dy[6] = {2, 0, -2, -2, 0, 2};
int cnt[200005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++)
    {
        cin >> p[i];
        cnt[p[i]]++;
    }
    ll ans = 1, x = 1;
    sort(p.begin(), p.end());
    p.resize(unique(p.begin(), p.end()) - p.begin());
    n = p.size();
    for(int i = 0; i < n; i++)
    {
        ll z = 1LL * (cnt[p[i]] + 1) * cnt[p[i]] / 2;
        ans = mult(poww(poww(p[i], z), x), poww(ans, cnt[p[i]] + 1));
        x = (cnt[p[i]] + 1) * x % (MOD - 1);
        //cout << ans << " ";
    }
    cout << ans << "\n";
}