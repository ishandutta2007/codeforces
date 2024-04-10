#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

#include <cassert>
using namespace std;

const long long INF = 1e18;

struct TFirstEdge {
    int From;
    int To;
    int Weight;
};

struct TSecondEdge {
    int From;
    int ToLeft;
    int ToRight;
    int Weight;
};

struct TThirdEdge {
    int FromLeft;
    int FromRight;
    int To;
    int Weight;
};

int n, s;

vector<TFirstEdge> firstEdges;
vector<TSecondEdge> secondEdges;
vector<TThirdEdge> thirdEdges;

int GetId(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        return v;
    } else {
        int tm = (tl + tr) >> 1;
        if (pos <= tm) {
            return GetId(2 * v, tl, tm, pos);
        } else {
            return GetId(2 * v + 1, tm + 1, tr, pos);
        }
    }
}

int GetId(int pos) {
    return GetId(1, 0, n - 1, pos) - 1;
}

template <typename TFunc>
void Invoke(int v, int tl, int tr, int l, int r, TFunc func) {
    if (tl == l && tr == r) {
        func(v - 1);
    } else {
        int tm = (tl + tr) >> 1;
        if (r <= tm) {
            Invoke(2 * v, tl, tm, l, r, func);
        } else if (l > tm) {
            Invoke(2 * v + 1, tm + 1, tr, l, r, func);
        } else {
            Invoke(2 * v, tl, tm, l, tm, func);
            Invoke(2 * v + 1, tm + 1, tr, tm + 1, r, func);
        }
    }
}

template <typename TFunc>
void Invoke(int l, int r, TFunc func) {
    Invoke(1, 0, n - 1, l, r, func);
}

template <typename TFunc>
void Traverse(int v, int tl, int tr, TFunc func) {
    if (tl != tr) {
        int tm = (tl + tr) >> 1;
        func(v - 1, 2 * v - 1);
        Traverse(2 * v, tl, tm, func);
        func(v - 1, 2 * v);
        Traverse(2 * v + 1, tm + 1, tr, func);
    }
}

template <typename TFunc>
void Traverse(TFunc func) {
    Traverse(1, 0, n - 1, func);
}

vector<long long> FindDijkstra(int n, int s, const vector<vector<pair<int, int>>>& g) {
    vector<long long> result(n, INF);
    priority_queue<pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>> q;
    result[s] = 0;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        auto dist = q.top().first;
        auto v = q.top().second;
        q.pop();

        if (result[v] < dist) {
            continue;
        }

        for (const auto& edge : g[v]) {
            auto newDist = dist + edge.first;
            if (newDist < result[edge.second]) {
                result[edge.second] = newDist;
                q.push(make_pair(newDist, edge.second));
            }
        }
    }
    return result;
}

int GetTreeVertexCount() {
    int result = 1;
    Traverse([&result] (int from, int to) {
        result = max(result, from + 1);
        result = max(result, to + 1);
    });
    return result;
}

void Solve() {
    const int nn = GetTreeVertexCount();

    vector<vector<pair<int, int>>> g(nn + n + nn);

    for (int i = 0; i < (int) firstEdges.size(); ++i) {
        const auto& edge = firstEdges[i];
        g[nn + edge.From].push_back(make_pair(edge.Weight, nn + edge.To));
    }

    for (int i = 0; i < (int) secondEdges.size(); ++i) {
        const auto& edge = secondEdges[i];
        Invoke(edge.ToLeft, edge.ToRight, [&] (int v) {
            g[nn + edge.From].push_back(make_pair(edge.Weight, v));
        });
    }

    for (int i = 0; i < (int) thirdEdges.size(); ++i) {
        const auto& edge = thirdEdges[i];
        Invoke(edge.FromLeft, edge.FromRight, [&] (int v) {
            g[nn + n + v].push_back(make_pair(edge.Weight, nn + edge.To));
        });
    }

    for (int i = 0; i < n; ++i) {
        const auto id = GetId(i);
        g[id].push_back(make_pair(0, nn + i));
        g[nn + i].push_back(make_pair(0, nn + n + id));
    }

    Traverse([&] (int from, int to) {
        g[from].push_back(make_pair(0, to));
        g[nn + n + to].push_back(make_pair(0, nn + n + from));
    });

    vector<long long> result = FindDijkstra(nn + n + nn, nn + s, g);
    for (int i = 0; i < n; ++i) {
        if (result[nn + i] == INF) {
            cout << -1 << " ";
        } else {
            cout << result[nn + i] << " ";
        }
    }
    cout << endl;
}

bool Read() {
    int q;
    if (!(cin >> n >> q >> s)) {
        return false;
    }
    --s;
    firstEdges.clear();
    secondEdges.clear();
    thirdEdges.clear();
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            firstEdges.emplace_back();
            auto& edge = firstEdges.back();

            cin >> edge.From >> edge.To >> edge.Weight;
            --edge.From;
            --edge.To;
        } else if (t == 2) {
            secondEdges.emplace_back();
            auto& edge = secondEdges.back();

            cin >> edge.From >> edge.ToLeft >> edge.ToRight >> edge.Weight;
            --edge.From;
            --edge.ToLeft;
            --edge.ToRight;
        } else {
            assert(t == 3);

            thirdEdges.emplace_back();
            auto& edge = thirdEdges.back();

            cin >> edge.To >> edge.FromLeft >> edge.FromRight >> edge.Weight;
            --edge.FromLeft;
            --edge.FromRight;
            --edge.To;
        }
    }
    return true;
}

int main() {
    // freopen("input2.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}