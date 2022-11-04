#include <bits/stdc++.h>

using namespace std;

vector<int> mas[(int)2e5 + 10], v;
int used[(int)2e5 + 10];

void dfs(int a)
{
    used[a] = 1;
    v.push_back(a);
    for (int b: mas[a])
    {
        if (used[b] == 0)
        {
            dfs(b);
            v.push_back(a);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int c = (2 * n + k - 1) / k;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        mas[a].push_back(b);
        mas[b].push_back(a);
    }
    dfs(1);
    fill(used, used + n + 1, 0);
    int q = 0;
    for (int i = 0; i < k; i++)
    {
        while (q < v.size() && used[v[q]])
            q++;
        if (q < v.size())
        {
            int t = min((int)v.size(), q + c);
            cout << t - q << " ";
            for (int j = q; j < t; j++)
            {
                used[v[j]] = 1;
                cout << v[j] << " ";
            }
            cout << "\n";
            q = t;
        }
        else
            cout << "1 1 \n";
    }
    return 0;
}