#include <bits/stdc++.h>

using namespace std;

vector<int> mas[(int)2e5 + 10];
int used[(int)2e5 + 10];
long long d1[(int)2e5 + 10][5], d2[(int)2e5 + 10][5];
long long ans;
int p[(int)2e5 + 10];
int n, m;

void update(int u, int qq)
{
    for (int q = 0; q < m - 1; q++)
    {
        d1[p[u]][q + 1] += d1[u][q] * qq;
        d2[p[u]][q + 1] += (d2[u][q] + d1[u][q]) * qq;
    }
    d1[p[u]][0] += d1[u][m - 1] * qq;
    d2[p[u]][0] += (d2[u][m - 1] + d1[u][m - 1]) * qq;
}

void dfs(int v)
{
    fill(d1[v], d1[v] + 5, 0);
    fill(d2[v], d2[v] + 5, 0);
    used[v] = 0;
    for (int u: mas[v])
    {
        if (used[u])
        {
            p[u] = v;
            dfs(u);
            update(u, 1);
        }
    }
    for (int u: mas[v])
    {
        if (p[u] == v)
        {
            update(u, -1);
            for (int q = 0; q < m; q++)
            {
                long long a = d1[u][q];
                long long b = d1[u][q] + d2[u][q];
                for (int w = 0; w < m; w++)
                {
                    int t = (m - ((q + w + 1) % m)) % m;
                    ans += (b * d1[v][w] + a * d2[v][w] + t * d1[v][w] * a) / m;
                }
            }
            update(u, 1);
        }
    }
    for (int i = 0; i < m; i++)
    {
        int t = (m - i) % m;
        ans += 2 * ((d2[v][i] + d1[v][i] * t) / m);
    }
    d1[v][0]++;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        mas[a - 1].push_back(b - 1);
        mas[b - 1].push_back(a - 1);
    }
    fill(used, used + n, 1);
    p[0] = -1;
    ans = 0;
    dfs(0);
    cout << ans / 2 << endl;
    return 0;
}