#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, dp[105][105][30];
vector <pair <int, int> > g[105];

int dfs(int x, int y, int c)
{
    if(dp[x][y][c]!=-1)
        return dp[x][y][c];

    int Min=1;

    for(auto to:g[x])
        if(to.second>=c)
            {
                Min=min(Min, dfs(y, to.first, to.second));
            }
    dp[x][y][c]=1-Min;
    return 1-Min;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u, v;
        char y;
        cin >> u >> v >> y;
        y-='a';
        u--;
        v--;
        g[u].push_back({v, y});
    }

    for(int i=0;i<105;i++)
        for(int j=0;j<105;j++)
            for(int k=0;k<30;k++)
                dp[i][j][k]=-1;

    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dfs(i, j, 0))
                    cout << "A";
                else cout << "B";
            }

            cout << "\n";
        }
}