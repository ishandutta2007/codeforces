#include <iostream>

using namespace std;
typedef long long ll;

ll dp[20000000];

int main()
{
    ll n, x, y, i;
    cin >> n >> x >> y;
    dp[0] = 0;
    for (i = 1; i<15000000; i++) {
        if ((i%2) == 0) dp[i] = min(dp[i-1]+x, dp[i/2]+y);
        if ((i%2) == 1) dp[i] = min(dp[i-1]+x, min(dp[i/2+1], dp[i/2])+x+y);
    }
    cout << dp[n];
    return 0;
}