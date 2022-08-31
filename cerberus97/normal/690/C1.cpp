#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <int> g[1005];
queue <int> q;
bool visited[1005] = {0};

void bfs(int startNode)
{
    visited[startNode] = true;
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

    if (m != n-1)
    {
        cout << "no";
        return 0;
    }

    bfs(1);

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            cout << "no";
            return 0;
        }
    }

    cout << "yes";
    return 0;
}