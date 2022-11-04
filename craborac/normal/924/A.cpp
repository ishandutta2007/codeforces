#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > a[100];
int used[100];
string s[100];

void dfs(int v, int q)
{
    used[v] = q;
    for (auto p: a[v])
    {
        int u = p.first;
        if (used[u] == 0)
        {
            if (p.second == 1)
                dfs(u, q);
        }
        else if (used[u] == q && p.second == 0)
        {
            //cout << v << " " << u << endl;
            cout << "No" << endl;
            exit(0);
        }
        else if (used[u] != q && p.second == 1)
        {
            //cout << v << " " << u << endl;
            cout << "No" << endl;
            exit(0);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        for (int j = 0; j < m; j++)
        {
            for (int q = j + 1; q < m; q++)
            {
                if (s[i][j] != s[i][q])
                {
                    a[j].push_back({q, 0});
                    a[q].push_back({j, 0});
                }
                if (s[i][j] == s[i][q] && s[i][j] == '#')
                {
                    a[j].push_back({q, 1});
                    a[q].push_back({j, 1});
                }
            }
        }
    }
    int cnt = 0;
    for (int j = 0; j < m; j++)
    {
        if (used[j] == 0)
        {
            cnt++;
            dfs(j, cnt);
        }
    }
    cout << "Yes" << endl;
    return 0;
}