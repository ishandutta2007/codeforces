#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 7;
int n, m;
vector<int> g[N];
bool u[N];
int mn, mx;

void dfs(int a)
{
    mn = min(mn, a);
    mx = max(mx, a);
    u[a] = 1;
    for (auto &b : g[a])
    {
        if (u[b] == 0)
        {
            dfs(b);
        }
    }
}

struct seg
{
    int l;
    int r;
};

bool operator < (seg a, seg b)
{
    return a.l < b.l;
}

vector<seg> s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int a = 1; a <= n; a++)
    {
        if (u[a] == 0)
        {
            mn = mx = a;
            dfs(a);
            s.push_back({mn, mx});
        }
    }
    sort(s.begin(), s.end());
    int cnt = 0, i = 0;
    while (i < (int) s.size())
    {
        int j = i, dr = s[i].r;
        while (j + 1 < (int) s.size() && s[j + 1].l < dr)
        {
            j++;
            dr = max(dr, s[j].r);
        }
        cnt++;
        i = j + 1;
    }
    cout << (int) s.size() - cnt << "\n";
}