#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, m, d[3005][3005];
vector <int> g[3005];
vector <pair <int, int> > v[3005], u[3005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        g[u].push_back(v);
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            d[i][j] = -1e9;

    for(int i = 0; i < n; i++)
    {
        queue <int> q;

        q.push(i);
        d[i][i] = 0;

        while(!q.empty())
        {
            int v = q.front();

            for(auto to:g[v])
            {
                if(d[i][to] == -1e9)
                {
                    q.push(to);
                    d[i][to] = d[i][v] + 1;
                }
            }

            q.pop();
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            v[i].push_back({-d[i][j], j});
            u[i].push_back({-d[j][i], j});
        }

        sort(v[i].begin(), v[i].end());
        sort(u[i].begin(), u[i].end());
    }

    int ans = -1e9;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i != j)
            {
                int x = 0;
                int y = 0;

                while(u[i][x].second == i || u[i][x].second == j)
                    x++;

                while(v[j][y].second == i || v[j][y].second == j || v[j][y].second == u[i][x].second)
                    y++;

                ans = max(ans, d[u[i][x].second][i] + d[j][v[j][y].second] + d[i][j]);
            }
            
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i != j)
            {
                int x = 0;
                int y = 0;

                while(v[j][y].second == i || v[j][y].second == j)
                    y++;
                    
                while(u[i][x].second == i || u[i][x].second == j || u[i][x].second == v[j][y].second)
                    x++;

                ans = max(ans, d[u[i][x].second][i] + d[j][v[j][y].second] + d[i][j]);
            }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i != j)
            {
                int x = 0;
                int y = 0;

                while(u[i][x].second == i || u[i][x].second == j)
                    x++;

                while(v[j][y].second == i || v[j][y].second == j || v[j][y].second == u[i][x].second)
                    y++;

                if(ans == d[u[i][x].second][i] + d[j][v[j][y].second] + d[i][j])
                {
                    cout << u[i][x].second + 1 << ' ' << i + 1 << ' ' << j + 1 << ' ' << v[j][y].second + 1;
                    return 0;
                }
            }
            
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i != j)
            {
                int x = 0;
                int y = 0;

                while(v[j][y].second == i || v[j][y].second == j)
                    y++;
                    
                while(u[i][x].second == i || u[i][x].second == j || u[i][x].second == v[j][y].second)
                    x++;

                ans = max(ans, d[u[i][x].second][i] + d[j][v[j][y].second] + d[i][j]);
                
                if(ans == d[u[i][x].second][i] + d[j][v[j][y].second] + d[i][j])
                {
                    cout << u[i][x].second + 1 << ' ' << i + 1 << ' ' << j + 1 << ' ' << v[j][y].second + 1;
                    return 0;
                }
            }
}