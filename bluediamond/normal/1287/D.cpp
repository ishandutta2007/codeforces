#include <bits/stdc++.h>

using namespace std;

const int N = 2000 + 7;
int n;
int sol[N];
int c[N];
vector<int> g[N];
vector<int> sub_arb[N];
int cur_node;

void build(int a)
{
    sub_arb[cur_node].push_back(a);
    for (auto &b : g[a])
    {
        build(b);
    }
}

void print(bool ok)
{
    if (ok)
    {
        cout << "YES\n";
        for (int i = 1; i <= n; i++)
        {
            cout << sol[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << "NO\n";
    }
    exit(0);
}

void dfs(int a, int l, int r)
{
    if (g[a].empty())
    {
        if (c[a] > 0)
        {
            print(0);
        }
        sol[a] = l;
    }
    else
    {
        if (c[a] > (int) sub_arb[a].size() - 1)
        {
            print(0);
        }
        int cur = l;
        for (auto &b : g[a])
        {
            dfs(b, cur, cur + (int) sub_arb[b].size() - 1);
            cur += (int) sub_arb[b].size();
        }
        for (auto &i : sub_arb[a])
        {
            sol[i] += (sol[i] >= l + c[a]);
        }
        sol[a] = l + c[a];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> p >> c[i];
        g[p].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cur_node = i;
        build(i);
    }
    dfs(g[0][0], 1, n);
    print(1);
}