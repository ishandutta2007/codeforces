#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 5;

int n, m;
vector <int> g[N];

int diam[N];
vector <int> center[N];
vector <int> comp[N];
int d[N][N];

int cnt = 0;
bool viz[N];

void clr()
{
    for (int i = 0; i < N; i++)
    {
        viz[i] = 0;
    }
}

void bc(int nod)
{
    comp[cnt].push_back(nod);
    viz[nod] = 1;
    for (auto &nou : g[nod])
    {
        if (viz[nou] == 0)
        {
            bc(nou);
        }
    }
}

void build_comp(int nod)
{
    cnt++;
    bc(nod);
    int mi = (1 << 30);
    for (auto &it : comp[cnt])
    {
        int ma_dist = 0;
        for (auto &kek : comp[cnt])
        {
            ma_dist = max(ma_dist, d[it][kek]);
        }
        mi = min(mi, ma_dist);
    }
    for (auto &it : comp[cnt])
    {
        int ma_dist = 0;
        for (auto &kek : comp[cnt])
        {
            ma_dist = max(ma_dist, d[it][kek]);
        }
        if (ma_dist == mi)
        {
            center[cnt].push_back(it);
        }
    }

}

void build_d(int lol)
{
    for (int i = 1; i <= n; i++)
    {
        d[lol][i] = -1;
    }
    queue <int> q;
    q.push(lol);
    d[lol][lol] = 0;
    while (!q.empty())
    {
        int nod = q.front();
        q.pop();
        for (auto &nou : g[nod])
        {
            if (d[lol][nou] == -1)
            {
                d[lol][nou] = d[lol][nod] + 1;
                q.push(nou);
            }
        }
    }
}

void build_diam(int id)
{
    for (auto &a : comp[id])
    {
        for (auto &b : comp[id])
        {
            diam[id] = max(diam[id], d[a][b]);
        }
    }
}

vector <pair <int, int>> add;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        build_d(i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (viz[i] == 0)
        {
            build_comp(i);
        }
    }
    clr();
    for (int i = 1; i <= cnt; i++)
    {
        build_diam(i);
    }
    clr();

    int max_diam = 0;
    for (int i = 1; i <= cnt; i++)
    {
        max_diam = max(max_diam, diam[i]);
    }
    int go = 0;
    for (int i = 1; i <= cnt; i++)
    {
        if (max_diam == diam[i])
        {
            go = i;
        }
    }
    for (int i = 1; i <= cnt; i++)
    {
        if (i == go)
        {
            continue;
        }
        add.push_back({center[i][0], center[go][0]});
        g[center[i][0]].push_back(center[go][0]);
        g[center[go][0]].push_back(center[i][0]);
    }

    for (int i = 1; i <= n; i++)
    {
        build_d(i);
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ans = max(ans, d[i][j]);
        }
    }

    cout << ans << "\n";

    for (auto &it : add)
    {
        cout << it.first << " " << it.second << "\n";
    }
}