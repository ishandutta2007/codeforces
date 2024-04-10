#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <functional>

#include <cmath>
using namespace std;

const long long INF = 1e18;

const long long SMALL_INF = 1e9;

const string NO = "NO";
const string YES = "YES";

struct TEdge {
    int From;
    int To;
    long long Cost;
    int Next;
};

int n;
vector<TEdge> edges;
vector<int> head;

void AddEdge(int from, int to, long long cost) {
    edges.push_back(TEdge{from, to, cost, head[from]});
    head[from] = edges.size() - 1;
    edges.push_back(TEdge{to, from, cost, head[to]});
    head[to] = edges.size() - 1;
}

vector<long long> dist;
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;

long long GetDist(int s, int t) {
    dist.assign(n, INF);
    dist[s] = 0;
    q.push(make_pair(dist[s], s));
    while (!q.empty()) {
        long long d = q.top().first;
        int v = q.top().second;
        q.pop();

        if (d > dist[v]) {
            continue;
        }

        for (int i = head[v]; i != -1; i = edges[i].Next) {
            if (edges[i].Cost != 0) {
                long long newCost = d + edges[i].Cost;
                if (newCost < dist[edges[i].To]) {
                    dist[edges[i].To] = newCost;
                    q.push(make_pair(newCost, edges[i].To));
                }
            }
        }
    }
    return dist[t];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    head.assign(n, -1);

    int m;
    int len;
    int s, t;
    cin >> m >> len >> s >> t;

    vector<int> emptyEdges;
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        long long w;
        cin >> v1 >> v2 >> w;
        if (w == 0) {
            emptyEdges.push_back(edges.size());
        }
        AddEdge(v1, v2, w);
    }

    long long z0 = GetDist(s, t);
    for (int id : emptyEdges) {
        edges[id].Cost = edges[id ^ 1].Cost = 1;
    }
    long long z1 = GetDist(s, t);

    if (len < z1 || len > z0) {
        cout << NO << endl;
        return 0;
    }

    m = emptyEdges.size();

    long long bl = 0;
    long long br = m * SMALL_INF;
    while (bl <= br) {
        long long bm = (bl + br) >> 1;

        long long x = bm;
        for (int id : emptyEdges) {
            long long cur = min(SMALL_INF, x);
            x -= cur;

            edges[id].Cost = edges[id ^ 1].Cost = cur + 1;
        }

        long long curDist = GetDist(s, t);
        if (curDist == len) {
            cout << YES << '\n';
            for (int v = 0; v < n; ++v) {
                for (int i = head[v]; i != -1; i = edges[i].Next) {
                    if (edges[i].From < edges[i].To) {
                        cout << edges[i].From << " " << edges[i].To << " " << edges[i].Cost << '\n';
                    }
                }
            }
            cout.flush();
            return 0;
        } else if (curDist > len) {
            br = bm - 1;
        } else {
            bl = bm + 1;
        }
    }

    cout << NO << endl;

    return 0;
}