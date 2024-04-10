#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>

using namespace std;

long long mas[(int)1e6 + 10], dp[(int)1e6 + 10];

int main()
{
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 2; i < (1 << (n + 1)); i++)
    {
        cin >> mas[i];
        dp[i] = 0;
    }
    for (int i = (1 << n) - 1; i > 0; i--)
    {
        dp[i] = max(dp[2 * i] + mas[2 * i], dp[2 * i + 1] + mas[2 * i + 1]);
        ans += 2 * dp[i] - dp[2 * i] - mas[2 * i] - dp[2 * i + 1] - mas[2 * i + 1];
    }
    cout << ans << endl;
    return 0;
}