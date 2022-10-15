#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6 + 7;
int n;
int m;
int val[N];
int to[N];
vector<int> g[N];
int ans1;
int ans;
bool vis2[N];
bool vis[N];
bool act[N];
vector<int> path;
bool is[N];
int mod;

int id(int i, int j)
{
    return m * i + j;
}

void flood(int a, int l)
{
    if (val[a] == 0)
    {
        is[l % mod] = 1;
    }
    vis2[a] = 1;
    for (auto &b : g[a])
    {
        if (vis2[b] == 0)
        {
            flood(b, l + 1);
        }
    }
}

void dfs(int a)
{
    path.push_back(a);
    vis[a] = act[a] = 1;
    int b = to[a];
    if (vis[b] == 0)
    {
        dfs(b);
    }
    else
    {
        if (act[b])
        {
            int p = (int) path.size() - 1;
            while (path[p] != b)
            {
                p--;
            }
            mod = (int) path.size() - p;
            ans1 += mod;
            flood(b, 0);
            for (int j = 0; j < mod; j++)
            {
                if (is[j])
                {
                    ans++;
                    is[j] = 0;
                }
            }
        }
    }
    act[a] = 0;
    path.pop_back();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ans1 = ans = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
            {
                val[id(i, j)] = s[j] - '0';
            }
        }
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
            {
                if (s[j] == 'U') to[id(i, j)] = (id(i - 1, j));
                if (s[j] == 'R') to[id(i, j)] = (id(i, j + 1));
                if (s[j] == 'D') to[id(i, j)] = (id(i + 1, j));
                if (s[j] == 'L') to[id(i, j)] = (id(i, j - 1));
            }
        }
        n *= m;
        for (int i = 0; i < n; i++)
        {
            g[to[i]].push_back(i);
        }
        ans1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (vis2[i] == 0)
            {
                dfs(i);
            }
        }

        cout << ans1 << " " << ans << "\n";
        /// final
        for (int i = 0; i < n; i++)
        {
            g[i].clear();
            vis[i] = 0;
            act[i] = 0;
            vis2[i] = 0;
        }
    }


}