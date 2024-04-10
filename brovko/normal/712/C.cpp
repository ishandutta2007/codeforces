#include <bits/stdc++.h>
#define int long long
#define ld lond double
#define y1 eohfweoifhew

using namespace std;

int x, y, dp[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> y;

    dp[3] = y + 1;
    dp[4] = 2 * y;

    for(int i = 5; i < 100005; i++)
        dp[i] = dp[i - 1] + dp[i - 2] - 2;

    int z = 3;

    while(x >= dp[z])
        z++;

    z--;
    cout << z;
}