#include <bits/stdc++.h>

using namespace std;

const int N = 4000 + 7, M = (int) 2e4 + 7;
int n, m, p;
int dp[N], sufdp[N][N], left[N], ans[M];
vector <pair <int, int> > w[M];
vector <pair <int, int> > q[M];

void solve (int t)
{
    int s = max (1, t - p), e = min (t + p - 1, M - 6);
    vector <int> cur;
    cur.push_back (-1);
    memset (dp, 0, sizeof dp);
    for (int i = t - 1; i >= s; i--)
    {
        for (int j = 0; j < (int) w[i].size(); j++)
        {
            cur.push_back (i);
            int ind = (int) cur.size() - 1;
            for (int p = 1; p < N; p++)
            {
                sufdp[ind][p] = max (sufdp[ind][p - 1], sufdp[ind - 1][p]);
                if (p - w[i][j].first >= 0)
                {
                    sufdp[ind][p] = max (sufdp[ind][p], sufdp[ind - 1][p - w[i][j].first] + w[i][j].second);
                }
            }
        }
    }
    int last = (int) cur.size() - 1;
    for (int i = t; i <= e; i++)
    {
        for (int j = 0; j < (int) w[i].size(); j++)
        {
            for (int p = N - 1; p - w[i][j].first >= 0; p--)
            {
                dp[p] = max (dp[p], dp[p - w[i][j].first] + w[i][j].second);
            }
        }
        while (last > 0 && i - p >= cur[last])
        {
            last--;
        }
        for (int j = 0; j < (int) q[i].size(); j++)
        {
            for (int p = 0; p <= q[i][j].first; p++)
            {
                ans[q[i][j].second] = max (ans[q[i][j].second], sufdp[last][p] + dp[q[i][j].first - p]);
            }
        }
    }
}


int main()
{
    int x, y, z;
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y >> z;
        w[z].push_back ({x, y});
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        q[x].push_back ({y, i});
    }
    for (int i = 1; i <= M - 6; i += p)
    {
        solve (i);
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}