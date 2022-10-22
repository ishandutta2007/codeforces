#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, m, used[100005], c[100005], ans[3], cnt1, cnt2;
vector <int> g[100005];

void dfs(int v)
{
    used[v] = 1;

    for(auto to:g[v])
    {
        if(used[to] == 0)
        {
            c[to] = 3 - c[v];

            if(c[to] == 1)
                cnt1++;
            else cnt2++;

            dfs(to);
        }
        else if(c[to] == c[v])
        {
            cout << "0 1";
            exit(0);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    if(m == 0)
    {
        cout << 3 << ' ' << n * (n - 1) * (n - 2) / 6;
        return 0;
    }

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        g[u].pb(v);
        g[v].pb(u);
    }

    for(int i = 0; i < n; i++)
    {
        if(used[i] == 0)
        {
            cnt1 = 1;
            cnt2 = 0;
            c[i] = 1;

            dfs(i);

            if(cnt1 + cnt2 > 2)
            {
                ans[1] += cnt1 * (cnt1 - 1) / 2 + cnt2 * (cnt2 - 1) / 2;
            }
            else
                if(cnt1 + cnt2 == 2)
                    ans[2] += n - 2;
        }
    }

    if(ans[1])
        cout << "1 " << ans[1];
    else
        cout << "2 " << ans[2];
}