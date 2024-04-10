#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;

using li = long long;

const int MOD = 998244353;
const int LOGN = 20;
const int N = (1 << LOGN);

int rv[LOGN][N], w[LOGN][N];

int add(int x, int y)
{
    x += y;

    return (x >= MOD ? x - MOD : x);
}

int mul(int x, int y)
{
    return x * 1ll * y % MOD;
}

int binpow(int x, int y)
{
    if(y == 0)
        return 1;

    if(y % 2)
        return mul(x, binpow(x, y - 1));

    int p = binpow(x, y / 2);

    return mul(p, p);
}

int inv(int x)
{
    return binpow(x, MOD - 2);
}

int divide(int x, int y)
{
    return mul(x, inv(y));
}

void precalc()
{
    for(int st = 1; st < LOGN; st++)
    {
        int h = (1 << st - 1);

        for(int i = 0; i < (1 << st); i++)
            rv[st][i] = rv[st - 1][i >= h ? i - h : i] * 2 + (i >= h);
    }

    for(int st = 0; st < LOGN - 1; st++)
    {
        for(int i = 0; i < (1 << st + 1); i++)
        {
            if(i <= 1)
                w[st][i] = binpow(3, (MOD - 1) * 1ll * i / (1 << st + 1));
            else w[st][i] = mul(w[st][i - 1], w[st][1]);
        }
    }
}

void fft(int n, int ln, vector <int> &a, bool inv)
{
    for(int i = 0; i < n; i++)
    {
        int ni = rv[ln][i];

        if(i < ni)
            swap(a[i], a[ni]);
    }

    for(int st = 0; st < ln; st++)
    {
        int len = (1 << st);

        for(int pos = 0; pos < n; pos += len * 2)
            for(int i = pos; i < pos + len; i++)
            {
                int l = a[i];
                int r = mul(a[i + len], w[st][i - pos]);

                a[i] = add(l, r);
                a[i + len] = add(l, MOD - r);
            }
    }

    if(inv)
    {
        reverse(a.begin() + 1, a.end());

        for(int i = 0; i < n; i++)
            a[i] = divide(a[i], n);
    }
}

vector <int> multiply(vector <int> a, vector <int> b)
{
    int n = a.size(), m = b.size();

    int k = 1, lk = 0;

    while(k <= n + m)
    {
        k *= 2;
        lk++;
    }

    a.resize(k);
    b.resize(k);

//    cout << 1 << endl;

    fft(k, lk, a, 0);
    fft(k, lk, b, 0);

//    cout << 2 << endl;

    vector <int> c;

    for(int i = 0; i < k; i++)
        c.pb(mul(a[i], b[i]));

    fft(k, lk, c, 1);

    return c;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    precalc();

    int n, k, f;
    cin >> n >> k >> f;

    vector <int> dp[n + 1];

    for(int i = 0; i <= k; i++)
        dp[0].pb(1);

    for(int i = 1; i <= n; i++)
    {
        vector <int> v = multiply(dp[i - 1], dp[i - 1]);
//        v.resize(k + 1);

//        for(auto x:v)
//            cout << x << ' ';
//
//        cout << endl;

        dp[i] = v;


        if(i == n)
            break;

        for(int j = 0; j <= k; j++)
            dp[i][j] = mul(dp[i][j], k - j);


        int s = 0;

        for(int j = (int)v.size() - 1; j >= 0; j--)
        {
            s = add(s, v[j]);
            dp[i][j] = add(dp[i][j], s);
        }

        dp[i].resize(k + 1);

//        for(auto x:dp[i])
//            cout << x << ' ';
//
//        cout << endl;
    }

    cout << (f >= dp[n].size() ? 0 : dp[n][f]);
}