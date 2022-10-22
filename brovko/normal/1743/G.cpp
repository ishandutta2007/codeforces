#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;

const int N = 3e6 + 5;
const int LOGN = 40;
const int M = 1'111'111'111'111'111'111ll;
const int MOD = 998244353;
const int p = 53;
const int B = 10000;
const int K = B + 2;

int hs[LOGN], hf[LOGN], sp[LOGN], f[LOGN], dp[K];

int sum(int x, int y)
{
    x += y;

    return (x >= M ? x - M : x);
}

int mul(int x, int y)
{
    int q = (ld)x * y / M;
    int r = x * y - q * M;

    while(r < 0)
        r += M;

    while(r >= M)
        r -= M;

    return r;
}

int sum2(int x, int y)
{
    x += y;

    return (x >= MOD ? x - MOD : x);
}

int mul2(int x, int y)
{
    return x * 1ll * y % MOD;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    bitset <N> b;
    vector <int> sz;

    string S;
    int k = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> S;

        sz.pb(S.size());

        for(auto x:S)
            b[k++] = x - '0';
    }

    f[0] = f[1] = 1;
    hf[0] = 1;
    hf[1] = 2;

    sp[0] = sp[1] = 1;

    for(int i = 2; i < LOGN; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
        hf[i] = sum(mul(hf[i - 1], mul(p, sp[i - 2])), hf[i - 2]);
        sp[i] = mul(p, mul(sp[i - 1], sp[i - 2]));
    }

    int big = 0;

    while(f[big] < B)
        big++;

    vector <pair <int, int> > v;

    for(int i = 0; i < k; i++)
    {
        for(int j = big; j < LOGN; j++)
        {
            if(i >= f[j])
                hs[j] = sum(hs[j], M - mul((b[i - f[j]] + 1), sp[j]));

            hs[j] = mul(hs[j], p);

            hs[j] = sum(hs[j], b[i] + 1);

            if(i + 1 >= f[j] && hs[j] == hf[j])
            {
                v.pb({i + 1 - f[j], i + 1});
//                cout << i << ' ' << j << endl;
            }
        }
    }

    sort(v.begin(), v.end());
    map <int, int> mp;

    int vi = 0;

    while(vi < v.size() && v[vi].f == 0)
    {
        mp[v[vi].s] = sum2(mp[v[vi].s], MOD - 1);
        vi++;
    }

    int s = 1;
    dp[0] = 1;

    int c = 0, nb = 0;

    for(int i = 0; i < k; i++)
    {
        dp[(i + 1) % K] = 0;

        for(int j = 0; j < big; j++)
        {
            if(i >= f[j])
                hs[j] = sum(hs[j], M - mul((b[i - f[j]] + 1), sp[j]));

            hs[j] = mul(hs[j], p);

            hs[j] = sum(hs[j], b[i] + 1);

            if(i + 1 >= f[j] && hs[j] == hf[j])
            {
                dp[(i + 1) % K] = sum2(dp[(i + 1) % K], MOD - dp[(i + 1 - f[j]) % K]);
//                cout << i << ' ' << j << endl;
            }
        }

        dp[(i + 1) % K] = sum2(dp[(i + 1) % K], s);

//        cout << "dp0 " << dp[(i + 1) % K] << endl;

        if(mp.count(i + 1))
            dp[(i + 1) % K] = sum2(dp[(i + 1) % K], mp[i + 1]);

        s = sum2(s, dp[(i + 1) % K]);

        while(vi < v.size() && v[vi].f == i + 1)
        {
            mp[v[vi].s] = sum2(mp[v[vi].s], MOD - dp[(i + 1) % K]);
            vi++;
        }

//        cout << "dp " << dp[(i + 1) % K] << endl;

        c++;

        if(c == sz[nb])
        {
            nb++;
            c = 0;
            cout << dp[(i + 1) % K] << "\n";
        }
    }
}