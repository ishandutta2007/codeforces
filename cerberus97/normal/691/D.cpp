#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int maxN = (int)1e6 + 5, maxM = (int)1e6 + 5;

vector <int> g[maxN];
queue <int> q;
int conn[maxN], val[maxN], a[maxN], ctr;
bool seen[maxN] = {0};

void bfs(int st)
{
    seen[st] = true;
    q.push(st);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (vector <int>::iterator i = g[cur].begin(); i != g[cur].end(); ++i)
        {
            if (!seen[*i])
            {
                seen[*i] = true;
                conn[ctr] = *i;
                val[ctr] = a[*i];
                ++ctr;

                q.push(*i);
            }
        }
    }
}

void update(int i)
{
    ctr = 1;

    conn[0] = i;
    val[0] = a[i];

    bfs(i);

    sort(conn, conn + ctr);
    sort(val, val + ctr, greater <int>());

    for (int i = 0; i < ctr; ++i)
        a[conn[i]] = val[i];
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n, m, u, v;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!seen[i])
            update(i);

        cout << a[i] << ' ';
    }

    return 0;
}