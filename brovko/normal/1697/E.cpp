#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;
const int MOD = 998244353;

int n, x[105], y[105], d[105][105], used[105], c[105], bad[105], Min[105], col, fact[105], siz[105], dp[105][105][105];

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

int A(int x, int y)
{
    return divide(fact[x], fact[x - y]);
}

void dfs(int v)
{
    used[v] = 1;

    for(int i = 0; i < n; i++)
        if(i != v)
        {
            if(d[v][i] == Min[v] && c[i] == 0)
            {
                c[i] = c[v];
                dfs(i);

                if(Min[i] < Min[v])
                    bad[c[v]] = 1;
            }
            else if(c[i] == c[v] && Min[v] != d[v][i])
                bad[c[v]] = 1;
            else if(c[i] != c[v] && d[v][i] == Min[v])
                bad[c[v]] = 1;
        }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0] = 1;

    for(int i = 1; i < 105; i++)
        fact[i] = mul(fact[i - 1], i);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            d[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);

    for(int i = 0; i < n; i++)
    {
        Min[i] = 1e9;

        for(int j = 0; j < n; j++)
            if(j != i)
                Min[i] = min(Min[i], d[i][j]);
    }

    for(int i = 0; i < n; i++)
        if(!used[i])
        {
            c[i] = ++col;
            dfs(i);

            if(bad[col])
                for(int j = 0; j < n; j++)
                    if(c[j] == col && j != i)
                        used[j] = 0, c[j] = 0;

//            for(int j = 0; j < n; j++)
//                cout << c[j] << ' ';
//
//            cout << endl;
        }

//    for(int i = 0; i < n; i++)
//        cout << c[i] << ' ';
//
//    cout << endl;

    for(int i = 0; i < n; i++)
        siz[c[i]]++;

    dp[0][0][0] = 1;

    for(int i = 1; i <= col; i++)
        for(int s = 0; s <= n; s++)
            for(int k = 0; k <= i; k++)
            {
                dp[i][s][k] = dp[i - 1][s][k];

                if(!bad[i] && s >= siz[i] && k >= 1)
                    dp[i][s][k] = add(dp[i][s][k], dp[i - 1][s - siz[i]][k - 1]);
            }

    int ans = 0;

    for(int s = 0; s <= n; s++)
        for(int k = 0; k <= col; k++)
            ans = add(ans, mul(dp[col][s][k], A(n, n - s + k)));

    cout << ans;
}