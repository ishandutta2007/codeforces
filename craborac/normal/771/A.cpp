#include <bits/stdc++.h>

using namespace std;

vector<int> mas[(int)2e5 + 10];
int used[(int)2e5 + 10];
long long s1, s2;

void dfs(int v)
{
    used[v] = 0;
    s1++;
    s2 += mas[v].size();
    for (int u: mas[v])
    {
        if (used[u])
            dfs(u);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        mas[a - 1].push_back(b - 1);
        mas[b - 1].push_back(a - 1);
    }
    fill(used, used + n, 1);
    for (int i = 0; i < n; i++)
    {
        if (used[i])
        {
            s1 = 0;
            s2 = 0;
            dfs(i);
            if (s2 != s1 * (s1 - 1))
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}