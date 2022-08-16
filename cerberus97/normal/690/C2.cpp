#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = (int)1e5 + 5;

vector <int> g[N];
queue <int> q;
bool visited[N] = {0};
int dist[N];

void bfs(int startNode)
{
    visited[startNode] = true;
    dist[startNode] = 0;
    q.push(startNode);

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        for (vector <int>::iterator i = g[temp].begin(); i != g[temp].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                dist[*i] = dist[temp]+1;
                q.push(*i);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n, m, u, v;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bfs(1);

    int furthest = -1, maxDist = -1;

    for (int i = 1; i <= n; ++i)
    {
        if (dist[i] > maxDist)
        {
            maxDist = dist[i];
            furthest = i;
        }
    }

    for (int i = 1; i <= n; ++i)
        visited[i] = false;

    bfs(furthest);

    int ans = -1;

    for (int i = 1; i <= n; ++i)
    {
        if (dist[i] > ans)
            ans = dist[i];
    }

    cout << ans;
    return 0;
}