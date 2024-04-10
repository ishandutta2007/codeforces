#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 998244353;

int add(int a, int b)
{
    a += b;
    if (a >= M)
    {
        return a - M;
    }
    if (a < 0)
    {
        return a + M;
    }
    return a;
}

int mul(int a, int b)
{
    return a * (ll) b % M;
}

int pw(int a, int b)
{
    int r = 1;
    while (b)
    {
        if (b & 1)
        {
            r = mul(r, a);
        }
        a = mul(a, a);
        b /= 2;
    }
    return r;
}

int dv(int a, int b)
{
    return mul(a, pw(b, M - 2));
}

const int N = 3600 + 7;
int n;
int m;
int cnt;
int row[N];
int col[N];
int dp_row[N][N];
int dp_col[N][N];
int fact[N];
int ifact[N];

int comb(int n, int k)
{
    return mul(fact[n], mul(ifact[k], ifact[n - k]));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = mul(fact[i - 1], i);
    }
    ifact[N - 1] = dv(1, fact[N - 1]);
    for (int i = N - 2; i >= 0; i--)
    {
        ifact[i] = mul(ifact[i + 1], i + 1);
    }
    cin >> n >> m >> cnt;
    for (int i = 1; i <= cnt; i++)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        row[r1] = 1;
        row[r2] = 1;
        col[c1] = 1;
        col[c2] = 1;
    }
    dp_row[0][0] = dp_col[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp_row[i][j] = dp_row[i - 1][j];
            if (i >= 2 && row[i] == 0 && row[i - 1] == 0 && j >= 1)
            {
                dp_row[i][j] = add(dp_row[i][j], dp_row[i - 2][j - 1]);
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp_col[i][j] = dp_col[i - 1][j];
            if (i >= 2 && col[i] == 0 && col[i - 1] == 0 && j >= 1)
            {
                dp_col[i][j] = add(dp_col[i][j], dp_col[i - 2][j - 1]);
            }
        }
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt1 += (row[i] == 0);
    }
    for (int i = 1; i <= m; i++)
    {
        cnt2 += (col[i] == 0);
    }
    int sol = 0;
    for (int c1 = 0; c1 <= n; c1++)
    {
        for (int c2 = 0; c2 <= m; c2++)
        {
            if (c1 + 2 * c2 > cnt1 || c2 + 2 * c1 > cnt2)
            {
                continue;
            }
            int x = mul(dp_row[n][c2], comb(cnt1 - 2 * c2, c1));
            int y = mul(dp_col[m][c1], comb(cnt2 - 2 * c1, c2));
            x = mul(x, y);
            x = mul(x, fact[c1]);
            x = mul(x, fact[c2]);
            sol = add(sol, x);
        }
    }
    cout << sol << "\n";
}