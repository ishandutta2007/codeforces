#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = (int) 1e9 + 7;

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

#define matrix vector<vector<int>>

matrix create(int n, int m)
{
    matrix a(n, vector<int> (m, 0));
    return a;
}

matrix operator * (matrix a, matrix b)
{
    int n = (int) a.size();
    int m = (int) a[0].size();
    matrix c = create(n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < m; k++)
            {
                c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
            }
        }
    }
    return c;
}

matrix operator ^ (matrix a, ll b)
{
    int n = (int) a.size();
    if ((int) a[0].size() != n)
    {
        cout << "error when rising to the power\n";
        exit(0);
    }
    matrix r = create(n, n);
    for (int i = 0; i < n; i++)
    {
        r[i][i] = 1;
    }
    while (b)
    {
        if (b & 1)
        {
            r = r * a;
        }
        a = a * a;
        b /= 2;
    }
    return r;
}

const int N = (int) 1e6 + 7;
int n;
int l;
int m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l >> m;
    matrix dp = create(1, m);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        dp[0][x % m]++;
    }
    vector<int> f(m, 0), val(n);
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
        val[i] %= m;
        f[val[i]]++;
    }
    matrix mul = create(m, m);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mul[i][(i + j) % m] = f[j];
        }
    }
    mul = mul ^ (l - 2);
    dp = dp * mul;
    for (int i = 0; i < n; i++)
    {
        int sc;
        cin >> sc;
        val[i] = (val[i] + sc) % m;
    }
    int sol = 0;
    for (int i = 0; i < n; i++)
    {
        sol = add(sol, dp[0][(m - val[i]) % m]);
    }
    cout << sol << "\n";
}