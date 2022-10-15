#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e5 + 7;
int n;
int k;
int cb[N]; /// come back
int dont[N]; /// dont come back
vector<pair<int, int>> g[N];

void dfs(int a, int p)
{
    cb[a] = 0;
    vector<pair<int, int>> lol;
    for (auto &it : g[a])
    {
        int b = it.first;
        int c = it.second;
        if (b != p)
        {
            dfs(b, a);
            lol.push_back({c + cb[b], c + dont[b]});
        }
    }
    if (lol.empty())
    {
        return;
    }
    sort(lol.rbegin(), lol.rend());
    for (int i = 0; i < min((int) lol.size(), k - 1); i++)
    {
        cb[a] += lol[i].first;
    }
    vector<int> pre((int) lol.size());
    pre[0] = lol[0].first;
    for (int i = 1; i < (int) lol.size(); i++)
    {
        pre[i] = pre[i - 1] + lol[i].first;
    }
    function<int(int, int)> firstk = [&] (int del, int k)
    {
        k = min(k, (int) lol.size() - 1);
        if (k == 0)
        {
            return 0;
        }
        if (del <= k - 1)
        {
            return pre[k] - lol[del].first;
        }
        else
        {
            return pre[k - 1];
        }
    };
    for (int i = 0; i < (int) lol.size(); i++)
    {
        dont[a] = max(dont[a], lol[i].second + firstk(i, k - 1));
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }
    dfs(0, -1);
    cout << max(cb[0], dont[0]) << "\n";
    return 0;
}