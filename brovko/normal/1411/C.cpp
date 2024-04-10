#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int a[100005], used1[100005], used2[100005], used3[100005];
vector <int> g[100005];

void dfs(int v)
{
    used3[v] = 1;

    for(auto to:g[v])
        if(used3[to] == 0)
            dfs(to);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, m;
        cin >> n >> m;

        int ans = m;

        for(int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;

            if(x == y)
                ans--;
            else
            {
                used1[x] = i;
                used2[y] = i;

                if(used2[x])
                {
                    int j = used2[x];

                    g[i].push_back(j);
                    g[j].push_back(i);
                }

                if(used1[y])
                {
                    int j = used1[y];

                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }

        for(int i = 1; i <= m; i++)
            if(used3[i] == 0 && g[i].size() < 2)
                dfs(i);

        for(int i = 1; i <= m; i++)
            if(used3[i] == 0)
        {
            dfs(i);
            ans++;
        }

        cout << ans << "\n";

        for(int i = 0; i <= n; i++)
        {
            used1[i] = 0;
            used2[i] = 0;
            used3[i] = 0;
            g[i].clear();
        }
    }
}