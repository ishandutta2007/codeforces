#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;
const int MOD = 1e9 + 7;

int n, b, k, x, a[50005], c[105];
map <int, int> dp[105];

int add(int x, int y)
{
    return (x + y) % MOD;
}

int mul(int x, int y)
{
    return x * y % MOD;
}

int binpow(int a, int b)
{
    if(b == 0)
        return 1;

    if(b % 2)
        return a * binpow(a, b - 1) % x;

    int c = binpow(a, b / 2);
    return c * c % x;
}

void calc(int N)
{

    if(N == 0)
    {
        dp[0][0] = 1;
        return;
    }

    if(N % 2)
    {
        calc(N - 1);

        for(int i = 0; i < x; i++)
        {
            for(int j = 0; j < x; j++)
            {
                dp[i][N] = add(dp[i][N], mul(dp[j][N - 1], c[(i - j * 10 + 100000 * x) % x]));
            }
        }
    }
    else
    {
        calc(N / 2);

        for(int i = 0; i < x; i++)
            for(int j = 0; j < x; j++)
        {
            dp[i][N] = add(dp[i][N], mul(dp[j][N / 2], dp[(i - j * binpow(10, N / 2) + 100000 * x) % x][N / 2]));
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> b >> k >> x;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        c[a[i] % x]++;
    }

    calc(b);

    cout << dp[k][b];
}