#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <cassert>
#include <iostream>
#include <map>

using namespace std;

map<pair<int, int>, int> Set;
vector<pair<int, int>> Edges[500000];

struct DSU {
    
    vector<int> Link, Rank, XXX;
    vector<int> ops;

    DSU(int n) : Link(n, -1), Rank(n, 0), XXX(n, 0) {}

    pair<int, int> Find(int node) {
        int xxx = 0;
        while (Link[node] != -1) { 
            xxx ^= XXX[node];
            node = Link[node];
        }
        xxx ^= XXX[node];
        return make_pair(node, xxx);
    }
    
    vector<int> commits;
    void Commit() {
        commits.push_back(ops.size());
    }
    void Rollback() {
        int last = commits.back(); commits.pop_back();
        while (ops.size() > last)
            Undo();
    }

    void Union(int a, int b) {
        auto p = Find(a), q = Find(b);
        assert(p.first != q.first);

        if (Rank[p.first] > Rank[q.first]) {
            swap(p, q);
        }

        if (Rank[p.first] == Rank[q.first]) ++Rank[q.first];
        ops.push_back(p.first);
        Link[p.first] = q.first;
        XXX[p.first] ^= XXX[q.first];
        if (p.second == q.second)
            XXX[p.first] ^= 1;

        assert(Find(a).second != Find(b).second);
    }

    void Undo() {
        int last = ops.back(); ops.pop_back();
        Link[last] = -1;
    }
};

void AddRange(int node, int b, int e, int l, int r, pair<int, int> p) {
    if (l > r) return;

    if (l == b && e == r) {
        //cerr << "Adding edge: " << p.first << " " << p.second << " to " << l << " " << r << endl;
        Edges[node].push_back(p);
    }
    else {
        int m = (b + e) / 2;
        AddRange(node * 2, b, m, l, min(r, m), p);
        AddRange(node * 2 + 1, m + 1, e, max(l, m + 1), r, p);
    }
}


void DFS(int node, int b, int e, DSU &dsu, vector<int> &ans) {
    //cerr << "At: " << b << " " << e << endl;
    //cerr << "Commiting..." << endl;
    dsu.Commit();

    bool bad = false;
    for (auto p : Edges[node]) {
        //cerr << "Adding edge: " << p.first << " " << p.second << endl;

        pair<int, int> a = dsu.Find(p.first), b = dsu.Find(p.second);
        if (a.first != b.first) dsu.Union(p.first, p.second);
        else {
            if (a.second == b.second) {
                //cerr << "BAD" << endl;
                bad = true;
                break;
            }
        }
    }

    if (!bad) {
        //cerr << "GOOD" << endl;
        //for (int i = 0; i < dsu.Link.size(); ++i) {
        //    cerr << dsu.Find(i).second;
        //}
        //cerr << endl;

        if (b == e) {
            ans[b] = true;
        } else {
            int m = (b + e) / 2;
            DFS(node * 2, b, m, dsu, ans);
            DFS(node * 2 + 1, m + 1, e, dsu, ans);
        }
    }
    
    //cerr << "Rolling back..." << endl;

    dsu.Rollback();

    //cerr << "Done " << b << " " << e << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        if (a > b) swap(a, b);
        --a; --b;

        auto p = make_pair(a, b);
        if (Set.find(p) == Set.end()) {
            Set[p] = i;
        } else {
            AddRange(1, 0, m - 1, Set[p], i - 1, p);
            Set.erase(p);
        }
    }

    for (auto p : Set) {
        AddRange(1, 0, m - 1, p.second, m - 1, p.first);
    }
    
    vector<int> ans(m);
    DSU dsu(n);

    DFS(1, 0, m - 1, dsu, ans);
    
    for (int i = 0; i < m; ++i) {
        if (ans[i] == true) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}