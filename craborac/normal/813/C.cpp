#include <bits/stdc++.h>
#define android ios

using namespace std;

int used[(int)2e5 + 10];
int d[(int)2e5 + 10];
int up[(int)2e5 + 10];
int h[(int)2e5 + 10];
vector<int> mas[(int)2e5 + 10];

void dfs(int v)
{
    used[v] = 1;
    h[v] = 0;
    for (int u: mas[v])
    {
        if (used[u] == 0)
        {
            d[u] = d[v] + 1;
            up[u] = v;
            dfs(u);
            h[v] = max(h[v], h[u] + 1);
        }
    }
}

int main()
{
    android::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n >> x;
    x--;
    fill(d, d + n, 0);
    fill(used, used + n, 0);
    fill(up, up + n, 0);
    fill(h, h + n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int a, b;
        cin >> a >> b;
        mas[a - 1].push_back(b - 1);
        mas[b - 1].push_back(a - 1);
    }
    dfs(0);
    int a = x;
    for (int i = 0; i < (d[x] - 1) / 2; i++)
        a = up[a];
    cout << 2 * (d[a] + h[a]) << endl;
    return 0;
}