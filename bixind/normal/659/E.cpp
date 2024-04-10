#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<vector<int> > tr;

vector<bool> used;

pair<int, int> dfs(int v)
{
    used[v] = true;
    int cnt = tr[v].size(), p = 1;
    for (int i = 0; i < tr[v].size(); i++)
    if (!used[tr[v][i]])
    {
        auto u = dfs(tr[v][i]);
        cnt += u.first;
        p += u.second;
    }
    return {cnt, p};
}


int main()
{
    int n, m, i;
    cin >> n >> m;
    tr.resize(n);
    used.resize(n);
    for (i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        tr[a].push_back(b);
        tr[b].push_back(a);
    }
    int ans = 0;
    for (i = 0; i < n; i++)
    {
        if (!used[i])
        {
            auto cnt = dfs(i);
            if (cnt.first / 2 <= cnt.second - 1)
                ans++;
        }
    }
    cout << ans;
    return 0;
}