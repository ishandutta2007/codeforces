#include <bits/stdc++.h>

using namespace std;

long long dp[5005][505];

int main()
{
    int n, k;
    scanf("%i%i", &n, &k);
    vector<int> cnt(100005), ask(100005);
    for (int x = 0; x < n * k; x++)
    {
        int a;
        scanf("%i", &a);
        cnt[a]++;
    }
    vector<int> f(n);
    for (auto &x : f)
        scanf("%i", &x), ask[x]++;
    vector<int> h(k);
    for (auto &x : h)
        scanf("%i", &x);
    h.insert(h.begin(), 0);

    for (int x = 1; x <= 5000; x++)
    {
        for (int y = 1; y <= 500; y++)
        {
            for (int z = 0; z <= k; z++)
                if (x-z >= 0)
                    dp[x][y] = max(dp[x][y], dp[x-z][y-1] + h[z]);
        }
    }

    long long ans = 0;
    for (int x = 0; x < ask.size(); x++)
    {
        if (cnt[x] >= ask[x] * k)
            ans += h[k] * ask[x];
        else
            ans += dp[cnt[x]][ask[x]];
    }
    printf("%lli\n", ans);
}