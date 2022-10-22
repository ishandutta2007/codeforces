#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

vector<vector<int>> adj(MAXN);
vector<int> a(MAXN), dp(MAXN, INT_MAX);

int main()
{
    int n;
    scanf("%i", &n);
    for (int x = 0; x < n; x++)
    {
        scanf("%i", &a[x]);
        int y = x - a[x], z = x + a[x];
        if (y >= 0)
            adj[y].push_back(x);
        if (z < n)
            adj[z].push_back(x);
    }
    for (int k = 0; k < 2; k++)
    {
        queue<int> q;
        for (int x = 0; x < n; x++)
        {
            if ((a[x] & 1) == k)
            {
                for (int y : adj[x])
                {
                    if ((a[y] & 1) != k)
                    {
                        q.push(y);
                        dp[y] = 1;
                    }
                }
            }
        }
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int y : adj[x])
            {
                if ((a[y] & 1) != k && dp[x] + 1 < dp[y])
                {
                    dp[y] = dp[x] + 1;
                    q.push(y);
                }
            }
        }
    }
    for (int x = 0; x < n; x++)
        printf("%i ", dp[x] == INT_MAX ? -1 : dp[x]);
    printf("\n");
}