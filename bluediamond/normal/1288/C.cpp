#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 10 + 7;
const int N = 1000 + 7;
const int MOD = (int) 1e9 + 7;

int add(int a, int b)
{
    a += b;
    if (a >= MOD)
    {
        return a - MOD;
    }
    if (a < 0)
    {
        return a + MOD;
    }
    return a;
}

int mul(int a, int b)
{
    return a * (ll) b % MOD;
}

int inc[M][N];
int de[M][N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
    {
        inc[1][i] = de[1][i] = 1;
    }
    for (int i = 2; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = j; k <= n; k++)
            {
                inc[i][k] = add(inc[i][k], inc[i - 1][j]);
                de[i][j] = add(de[i][j], de[i - 1][k]);
            }
        }
    }
    int sol = 0;
    for (int x = 1; x <= n; x++)
    {
        for (int y = x + 1; y <= n; y++)
        {
            sol = add(sol, mul(inc[m][x], de[m][y]));
        }
    }
    for (int p = 1; p <= m; p++)
    {
        for (int x = 1; x <= n; x++)
        {
            sol = add(sol, add(mul(inc[p][x], de[p][x]), -mul(inc[p - 1][x], de[p - 1][x])));
        }
    }
    cout << sol << "\n";
}