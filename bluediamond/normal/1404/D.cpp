#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6 + 7;
vector<int> g[N];
int val[N];
int col[N];

void dfs(int a)
{
    for (auto &b : g[a])
    {
        if (col[b] == 0)
        {
            col[b] = 3 - col[a];
            dfs(b);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << "First\n";
        for (int i = 1; i <= 2 * n; i++)
        {
            cout << i % n + 1 << " ";
        }
        cout << endl;
        return 0;
    }
    cout << "Second\n";
    for (int i = 1; i <= 2 * n; i++)
    {
        int team;
        cin >> team;
        if (val[team])
        {
            int j = val[team];
            g[i].push_back(j);
            g[j].push_back(i);
        }
        else
        {
            val[team] = i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        g[i].push_back(i + n);
        g[i + n].push_back(i);
    }
    /// no odd cycles => the graph is bip :)))))
    for (int i = 1; i <= 2 * n; i++)
    {
        if (col[i] == 0)
        {
            col[i] = 1;
            dfs(i);
        }
    }
    int sum = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        if (col[i] == 1)
        {
            sum = (sum + i) % (2 * n);
        }
    }
    if (sum == 0)
    {
        sum = 1;
    }
    else
    {
        sum = 2;
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        if (col[i] == sum)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}