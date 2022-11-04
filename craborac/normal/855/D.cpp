#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > mas[(int)1e5 + 10];
int t11[(int)1e5 + 10];
int t12[(int)1e5 + 10];
int t21[(int)1e5 + 10];
int t22[(int)1e5 + 10];
int type[(int)1e5 + 10];
int used[(int)1e5 + 10];
int up[(int)1e5 + 10][20];
int h[(int)1e5 + 10];
int t;

void dfs(int v)
{
    used[v] = 1;
    for (auto p: mas[v])
    {
        h[p.first] = h[v] + 1;
        dfs(p.first);
    }
}

void dfs1(int v)
{
    used[v] = 1;
    t11[v] = t;
    t++;
    for (auto p: mas[v])
    {
        if (p.second == 0)
            dfs1(p.first);
    }
    t12[v] = t;
    t++;
}

void dfs2(int v)
{
    used[v] = 1;
    t21[v] = t;
    t++;
    for (auto p: mas[v])
    {
        if (p.second == 1)
            dfs2(p.first);
    }
    t22[v] = t;
    t++;
}

int lca(int a, int b)
{
    if (h[a] > h[b])
        swap(a, b);
    for (int i = 19; i >= 0; i--)
        if ((1 << i) <= h[b] - h[a])
            b = up[b][i];
    if (a == b)
        return a;
    for (int i = 19; i >= 0; i--)
        if (up[a][i] != up[b][i])
        {
            a = up[a][i];
            b = up[b][i];
        }
    return up[a][0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        type[i] = b;
        if (a != -1)
        {
            a--;
            up[i][0] = a;
            mas[a].push_back({i, b});
        }
        else
        {
            v.push_back(i);
            up[i][0] = i;
        }
    }
    for (int i = 1; i < 20; i++)
    {
        for (int j = 0; j < n; j++)
        {
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }
    t = 0;
    fill(used, used + n, 0);
    for (int i = 0; i < n; i++)
        if (used[i] == 0)
        {
            h[i] = 0;
            dfs(i);
        }
    fill(used, used + n, 0);
    for (int i = 0; i < n; i++)
        if (used[i] == 0)
            dfs1(i);
    fill(used, used + n, 0);
    for (int i = 0; i < n; i++)
        if (used[i] == 0)
            dfs2(i);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int q, w, e;
        cin >> q >> w >> e;
        w--;
        e--;
        if (q == 1)
        {
            if (t11[w] <= t11[e] && t12[e] <= t12[w] && w != e)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
        {
            int c = lca(w, e);
            if (t11[c] <= t11[w] && t12[w] <= t12[c] && t21[c] <= t21[e] && t22[e] <= t22[c] && c != e)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}