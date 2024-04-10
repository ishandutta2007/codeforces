#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, k, used[200005], dp[200005], v[200005], u[200005];
vector <int> g[200005], e[200005];
vector <vector <int> > ans;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < m; i++)
    {
        cin >> u[i] >> v[i];

        u[i]--;
        v[i]--;

        g[u[i]].pb(v[i]);
        g[v[i]].pb(u[i]);
    }

    queue <int> q;

    q.push(0);
    used[0] = 1;
    dp[0] = 0;

    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        for(auto to:g[v])
            if(used[to] == 0)
            {
                used[to] = 1;
                dp[to] = dp[v] + 1;
                q.push(to);
            }
    }

    for(int i = 0; i < m; i++)
    {
        if(dp[u[i]] < dp[v[i]])
            swap(u[i], v[i]);

        if(dp[u[i]] == dp[v[i]] + 1)
            e[u[i]].pb(i);
    }

    vector <int> v;

    for(int i = 1; i < n; i++)
        v.pb(0);

//    cout << 1 << endl;

    int f = 1;
    ans.pb(v);

    for(int i = 0; (i < k - 1 && f == 1); i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(v[j - 1] + 1 < e[j].size())
            {
                for(int z = 0; z < j - 1; z++)
                    v[z] = 0;

                v[j - 1]++;
                ans.pb(v);

                break;
            }

            if(j == n - 1)
                f = 0;
        }
    }

    cout << ans.size() << "\n";

    for(auto to:ans)
    {
        string s = "";

        for(int i = 0; i < m; i++)
            s += "0";

        for(int x = 0; x < n - 1; x++)
            s[e[x + 1][to[x]]] = '1';

        cout << s << "\n";
    }
}