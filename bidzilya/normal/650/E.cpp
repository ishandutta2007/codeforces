#include <iostream>
#include <vector>
#include <set>
#include <list>
using namespace std;

struct TEdge {
    int From;
    int To;
};

struct TLists {
public:
    using TListIterator = list<TEdge>::iterator;

    void Init(int n) {
        Data.resize(n);
    }

    TListIterator GetHead(int vert) {
        return Data[vert].begin();
    }

    bool IsEnd(int vert, const TListIterator& itr) {
        return Data[vert].end() == itr;
    }

    const TEdge& GetEdge(const TListIterator& itr) {
        return *itr;
    }

    void AddUndirEdge(int from, int to) {
        Data[from].push_back(TEdge{from, to});
        Data[to].push_back(TEdge{to, from});
    }

    void Splice(int to, int from) {
        Data[to].splice(Data[to].end(), Data[from]);
    }

    TEdge GetEdgeAndPopFront(int vert) {
        TEdge result;
        while (true) {
            result = Data[vert].front();
            Data[vert].pop_front();
            if (Deleted.find(make_pair(result.From, result.To)) == Deleted.end()) {
                break;
            }
        }
        Deleted.insert(make_pair(result.From, result.To));
        Deleted.insert(make_pair(result.To, result.From));
        return result;
    }
private:
    vector<list<TEdge>> Data;
    set<pair<int, int>> Deleted;
};

struct TDsu {
public:
    void Init(int n) {
        Rank.assign(n, 0);
        Pred.resize(n);
        for (int i = 0; i < n; ++i) {
            Pred[i] = i;
        }
    }

    int GetParent(int vert) {
        if (Pred[vert] != vert) {
            Pred[vert] = GetParent(Pred[vert]);
        }
        return Pred[vert];
    }

    bool Unite(int v1, int v2) {
        v1 = GetParent(v1);
        v2 = GetParent(v2);

        if (v1 == v2) {
            return false;
        }

        if (Rank[v2] > Rank[v1]) {
            swap(v1, v2);
        }

        Pred[v2] = v1;
        if (Rank[v1] == Rank[v2]) {
            ++Rank[v1];
        }

        return true;
    }
private:
    vector<int> Rank;
    vector<int> Pred;
};

int n;
TLists g[2];

TDsu dsu;

void CreateOrder(int v, int pred, vector<pair<int, int>>& order) {
    for (auto i = g[0].GetHead(dsu.GetParent(v)); !g[0].IsEnd(dsu.GetParent(v), i); ++i) {
        int from = g[0].GetEdge(i).From;
        int to = g[0].GetEdge(i).To;
        if (pred == -1 || dsu.GetParent(to) != dsu.GetParent(pred)) {
            CreateOrder(to, from, order);
        }
    }
    order.push_back(make_pair(v, pred));
}

void MergeVertexes(int v1, int v2) {
    v1 = dsu.GetParent(v1);
    v2 = dsu.GetParent(v2);
    dsu.Unite(v1, v2);
    int u = dsu.GetParent(v1);
    if (v1 == u) {
        g[0].Splice(u, v2);
        g[1].Splice(u, v2);
    } else {
        g[0].Splice(u, v1);
        g[1].Splice(u, v1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    set<pair<int, int>> has[2];
    vector<pair<int, int>> edges[2];
    for (int i = 0; i < 2; ++i) {
        edges[i].resize(n - 1);
        for (int j = 0; j + 1 < n; ++j) {
            int v1, v2;
            cin >> v1 >> v2;
            --v1;
            --v2;
            edges[i][j].first = v1;
            edges[i][j].second = v2;
            has[i].insert(make_pair(v1, v2));
            has[i].insert(make_pair(v2, v1));
        }
    }

    dsu.Init(n);
    g[0].Init(n);
    g[1].Init(n);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j + 1 < n; ++j) {
            int ni = 1 - i;
            if (has[ni].find(make_pair(edges[i][j].first, edges[i][j].second)) == has[ni].end()) {
                g[i].AddUndirEdge(edges[i][j].first, edges[i][j].second);
            }
        }
    }
    for (int i = 0; i + 1 < n; ++i) {
        if (has[1].find(make_pair(edges[0][i].first, edges[0][i].second)) != has[1].end()) {
            MergeVertexes(edges[0][i].first, edges[0][i].second);
        }
    }

    vector<pair<int, int>> order;
    CreateOrder(0, -1, order);

    vector<pair<pair<int, int>, pair<int, int>>> result;
    result.reserve(n);
    for (const auto& x : order) {
        int vert = x.first;
        int pred = x.second;
        if (pred == -1) {
            break;
        }
        const TEdge& edge = g[1].GetEdgeAndPopFront(dsu.GetParent(vert));
        result.push_back(make_pair(make_pair(vert, pred), make_pair(edge.From, edge.To)));
        MergeVertexes(
            vert,
            dsu.GetParent(edge.From) == dsu.GetParent(vert) ? edge.To : edge.From
        );
    }

    cout << result.size() << endl;
    for (const auto& x : result) {
        cout << x.first.first + 1 << " " << x.first.second + 1 << " ";
        cout << x.second.first + 1 << " " << x.second.second + 1 << '\n';
    }
    cout.flush();

    return 0;
}