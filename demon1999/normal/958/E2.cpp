#include <bits/stdc++.h>

using namespace std;

int t[(int)1e6 + 10];
vector<pair<int, int> > mas, arr;
long long dp[2][5010][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
    int n, m;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
    sort(t, t + n);
    for (int i = 0; i + 1 < n; i++)
    {
        mas.push_back({t[i + 1] - t[i], i});
    }
    sort(mas.begin(), mas.end());
    for (int i = 0; i < min((int)mas.size(), 3 * m); i++)
    {
        arr.push_back({mas[i].second, mas[i].first});
    }
    n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        //cout << arr[i].first << " " << arr[i].second << endl;
    }
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j][0] = (long long)1e18;
            dp[i][j][1] = (long long)1e18;
        }
    }
    dp[0][0][0] = 0;
    long long ans = (long long)1e18;
    int q = 0;
    for (int i = 0; i < n; i++)
    {
        int w = 1 - q;
        for (int j = 0; j <= m; j++)
        {
            dp[w][j][0] = min(dp[q][j][0], dp[q][j][1]);
            if (j > 0)
            {
                dp[w][j][1] = min(dp[w][j][1], dp[q][j - 1][0] + arr[i].second);
                if (i > 0 && arr[i].first > arr[i - 1].first + 1)
                    dp[w][j][1] = min(dp[w][j][1], dp[q][j - 1][1] + arr[i].second);
            }
            //cout << dp[i + 1][j][0] << " " << dp[i + 1][j][1] << "   ";
        }
        //cout << endl;
        ans = min(ans, min(dp[w][m][0], dp[w][m][1]));
        for (int j = 0; j <= m; j++)
        {
            dp[q][j][0] = (long long)1e18;
            dp[q][j][1] = (long long)1e18;
        }
        q = w;
    }
    cout << ans << endl;
    return 0;
}