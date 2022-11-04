#include <bits/stdc++.h>

using namespace std;

int answer;
vector<int> mas[(int)1e5 + 10];
int used[(int)1e5 + 10];

void dfs(int v, int q)
{
    used[v] = q;
    for (int i = 0; i < mas[v].size(); i++)
    {
        int w = mas[v][i];
        if (used[w] == q)
            answer = -1;
        else if (used[w] == 0)
            dfs(w, 3 - q);
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        mas[a].push_back(b);
        mas[b].push_back(a);
    }
    answer = 0;
    for (int i = 0; i < n; i++)
    {
        used[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (used[i] == 0)
            dfs(i, 1);
    }
    if (answer == -1)
        cout << -1 << endl;
    else
    {
        int c1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (used[i] == 1)
                c1++;
        }
        cout << c1 << endl;
        for (int i = 0; i < n; i++)
            if (used[i] == 1)
                cout << i + 1 << " ";
        cout << endl;
        cout << n - c1 << endl;
        for (int i = 0; i < n; i++)
            if (used[i] == 2)
                cout << i + 1 << " ";
        cout << endl;
    }
    return 0;
}