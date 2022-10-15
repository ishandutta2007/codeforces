#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 7;
int n;
int k;
int a[N];
ll dp[N];
ll sum;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        if (i <= k)
        {
            dp[i] = sum;
        }
        else
        {
            dp[i] = sum + dp[i - k];
        }
        cout << dp[i] << " ";
    }
    cout << "\n";

}