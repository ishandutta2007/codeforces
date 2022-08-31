#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair <int, int> edge;
vector <edge> g[200005];
priority_queue <edge, vector <edge>, greater <edge> > q;
bool visited[200005];
int dist[200005], a[200005];

void init(int n)
{
    while (!q.empty())
        q.pop();

    for (int i = 1; i <= n; ++i)
    {
        g[i].clear();
        visited[i] = false;
        dist[i] = 1e9;
    }
}

void dijkstra(int startNode)
{
    dist[startNode] = 0;
    q.push(make_pair(0, startNode));

    while (!q.empty())
    {
        while (!q.empty() and visited[q.top().second])
            q.pop();

        if (q.empty())
            break;

        int temp = q.top().second;

        for (vector <edge>::iterator i = g[temp].begin(); i != g[temp].end(); ++i)
        {
            if (!visited[i->first])
            {
                if (dist[temp] + i->second < dist[i->first])
                {
                    dist[i->first] = dist[temp] + i->second;
                    q.push(make_pair(dist[i->first], i->first));
                }
            }
        }

        visited[temp] = true;
        q.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    init(n);

    for (int i = 1; i < n; ++i)
    {
        g[i].push_back(make_pair(i + 1, 1));
        g[i + 1].push_back(make_pair(i, 1));
    }

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        g[i].push_back(make_pair(a[i], 1));
    }

    dijkstra(1);

    for (int i = 1; i <= n; ++i)
        cout << dist[i] << ' ';

    return 0;
}