#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
int n, a[N], id[N];
int dp[N], par[N], ans[N];

bool cmp(int i, int j)
{
    return a[i] < a[j];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        id[i] = i;
    }

    sort(id + 1, id + n + 1, cmp);

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = (int) 1e9 + 7;
        for (int j = i - 2; j >= i - 6 && j >= 1; j--)
        {
            if (dp[j - 1] + a[id[i]] - a[id[j]] < dp[i])
            {
                dp[i] = dp[j - 1] + a[id[i]] - a[id[j]];
                par[i] = j;
            }
        }
    }

    int teams = 0, p = n;

    while (p >= 1)
    {
        teams++;
        for (int j = p; j >= par[p]; j--)
        {
            ans[id[j]] = teams;
        }
        p = par[p] - 1;
    }

    cout << dp[n] << " " << teams << "\n";
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
}