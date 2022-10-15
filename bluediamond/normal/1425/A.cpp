#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1000;
ll dp[N + 7];
ll rem[N + 7];

ll f(ll n)
{
    if (n <= 10)
    {
        return dp[n];
    }
    if (n % 4 == 2)
    {
        return n / 2 - f(n / 2) + n / 2;
    }
    else
    {
        return n - 1 - f(n - 1) + 1;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    dp[1] = 1;
    rem[1] = 0;
    for (int i = 2; i <= N; i++)
    {
        dp[i] = rem[i - 1] + 1;
        if (i % 2 == 0)
        {
            dp[i] = max(dp[i], rem[i / 2] + i / 2);
        }
        rem[i] = i - dp[i];
    }
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << f(n) << "\n";
    }
}