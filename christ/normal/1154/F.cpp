#include <bits/stdc++.h>

using namespace std;

long long dp[100005];

int main()
{
    int n, m, k;
    scanf("%i%i%i", &n, &m, &k);
    vector<int> arr(n), psa(n);
    for (auto &x : arr)
        scanf("%i", &x);
    sort(arr.begin(), arr.end());
    psa[0] = arr[0];
    for (int x = 1; x < n; x++)
        psa[x] = psa[x-1] + arr[x];
    vector<pair<int,int>> off(m);
    for (auto &x : off)
        scanf("%i%i", &x.first, &x.second);
    for (int x = 0; x < k; x++)
    {
        dp[x] = (x ? dp[x-1] : 0) + arr[x];
        for (auto &y : off)
        {
            if (x - y.first + 1 >= 0)
            {
                long long cur = x - y.first + 1 > 0 ? dp[x - y.first] : 0;
                cur += psa[x] - psa[x - y.first + y.second];
                dp[x] = min(dp[x], cur);
            }
        }
    }
    printf("%lli\n", dp[k-1]);
}