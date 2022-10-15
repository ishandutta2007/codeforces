#include <bits/stdc++.h>

using namespace std;

const int N = 80 + 7;
const int M = 200000 + 7;
const int INF = (int) 1e9;

int n;
int m;
int l[N];
int r[N];
int dp[M];
int aib[M];

void upd(int i, int x)
{
    i = m + 1 - i;
    while (i <= m + 1)
    {
        aib[i] = min(aib[i], x);
        i += i & (-i);
    }
}

int get(int i)
{
    i = m + 1 - i;
    int ans = INF;
    while (i >= 1)
    {
        ans = min(ans, aib[i]);
        i -= i & (-i);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    m = 2 * m + 4;
    for (int i = 1; i <= n; i++)
    {
        int x, s;
        cin >> x >> s;
        l[i] = x - s;
        r[i] = x + s;
    }
    for (int i = 1; i <= m; i++)
    {
        dp[i] = INF;
        aib[i] = INF;
    }
    upd(0, 0);
    for (int p = 1; p <= m; p++)
    {
        for (int i = 1; i <= n; i++)
        {
            int cost = max(0, p - r[i]);
            int down = l[i] - cost - 1;
            if (down < 0)
            {
                down = 0;
            }
            dp[p] = min(dp[p], get(down) + cost);
            upd(p, dp[p]);
        }
    }
    int ans = INF;
    m -= 4;
    m /= 2;
    for (int i = m; i <= 2 * m + 4; i++)
    {
        ans = min(ans, dp[i]);
    }
    cout << ans << "\n";
}