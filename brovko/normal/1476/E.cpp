#include <bits/stdc++.h>
//#define int long long

using namespace std;

int n, m, k, y, a[100005], used[100005];
string s[100005], t[100005];
map <string, int> q;
vector <int> g[100005], ans;

void dfs(int v)
{
    used[v] = 1;

    for(auto to:g[v])
    {
        if(used[to] == 0)
        {
            dfs(to);
        }

        if(used[to] == 1)
        {
            cout << "NO";
            exit(0);
        }
    }

    used[v] = 2;
    ans.push_back(v + 1);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++)
    {
        y++;
        cin >> s[i];
        q[s[i]] = y;
    }

    for(int i = 0; i < m; i++)
    {
        cin >> t[i] >> a[i];

        int f = 0;

        for(int mask = 0; mask < (1 << k); mask++)
        {
            int w = mask;
            string p = t[i];

            for(int j = 0; j < k; j++)
            {
                if(w % 2)
                    p[j] = '_';

                w /= 2;
            }

            int z = q[p];

            if(z > 0 && z != a[i])
                g[z - 1].push_back(a[i] - 1);

            if(z == a[i])
                f = 1;
        }

        if(f == 0)
        {
            cout << "NO";
            return 0;
        }
    }

    for(int i = 0; i < n; i++)
        if(used[i] == 0)
            dfs(i);

    cout << "YES\n";

    for(auto to:ans)
        cout << to << ' ';
}