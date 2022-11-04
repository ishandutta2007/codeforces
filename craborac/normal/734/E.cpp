#include <bits/stdc++.h>

using namespace std;

vector<int> mas[(int)2e5 + 10], arr[(int)2e5 + 10];
int used[(int)2e5 + 10], c[(int)2e5 + 10], a[(int)2e5 + 10], d[(int)2e5 + 10];

void dfs(int v, int q)
{
    used[v] = q;
    for (int i: mas[v])
    {
        if (used[i] == 0 && c[i] == c[v])
            dfs(i, q);
    }
}

void dfs2(int v)
{
    used[v] = 1;
    for (int i : arr[v])
    {
        if (used[i] == 0)
        {
            d[i] = d[v] + 1;
            dfs2(i);
        }
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    fill(used, used + n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i + 1 < n; i++)
    {
        int a, b;
        cin >> a >> b;
        mas[a - 1].push_back(b - 1);
        mas[b - 1].push_back(a - 1);
    }
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        if (used[i] == 0)
        {
            m++;
            dfs(i, m);
        }
    }
    set<int> s[m];
    for (int i = 0; i < n; i++)
        used[i]--;
    for (int i = 0; i < n; i++)
    {
        a[used[i]] = c[i];
        for (int j : mas[i])
        {
            if (used[i] != used[j])
            {
                if (s[used[i]].find(used[j]) == s[used[i]].end())
                {
                    s[used[i]].insert(used[j]);
                    arr[used[i]].push_back(used[j]);
                }
            }
        }
    }
    fill(used, used + m, 0);
    d[0] = 0;
    dfs2(0);
    int v = 0;
    for (int i = 1; i < n; i++)
    {
        if (d[i] > d[v])
            v = i;
    }
    fill(used, used + m, 0);
    d[v] = 0;
    dfs2(v);
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, d[i]);
    cout << (ans + 1) / 2 << endl;
    return 0;
}