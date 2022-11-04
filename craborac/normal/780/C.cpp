#include <bits/stdc++.h>

using namespace std;

vector<int> mas[(int)2e5 + 10];
int used[(int)2e5 + 10], c[(int)2e5 + 10];

void dfs(int v)
{
    used[v] = 1;
    vector<int> a;
    a.push_back(c[v]);
    for (int u: mas[v])
        if (c[u])
            a.push_back(c[u]);
    sort(a.begin(), a.end());
    int q = 1, w = 0;
    for (int u: mas[v])
    {
        if (used[u] == 0)
        {
            while (w < a.size() && a[w] == q)
            {
                q++;
                w++;
            }
            c[u] = q;
            q++;
            dfs(u);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        mas[a].push_back(b);
        mas[b].push_back(a);
    }
    c[0] = 1;
    dfs(0);
    int mx = 0;
    for (int i = 0; i < n; i++)
        mx = max(mx, c[i]);
    cout << mx << endl;
    for (int i = 0; i < n; i++)
        cout << c[i] << " ";
    cout << endl;
    return 0;
}