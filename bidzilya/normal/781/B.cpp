#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class TKuhnSolver {
public:
    void Init(int n_, int m_) {
        n = n_;
        m = m_;
        g.clear();
        g.resize(n);
    }

    void AddEdge(int from, int to) {
        g[from].push_back(to);
    }

    bool Solve(vector<int>& solution) {
        revSolution.assign(m, -1);
        for (int i = 0; i < n; ++i) {
            used.assign(n, false);
            if (!Try(i)) {
                return false;
            }
        }
        solution.resize(n);
        for (int i = 0; i < m; ++i) {
            if (revSolution[i] != -1) {
                solution[revSolution[i]] = i;
            }
        }
        return true;
    }

private:
    int n, m;
    vector<vector<int>> g;

    vector<bool> used;

    vector<int> revSolution;

    bool Try(int v) {
        if (used[v]) {
            return false;
        }
        used[v] = true;
        for (int u : g[v]) {
            if (revSolution[u] == -1 || Try(revSolution[u])) {
                revSolution[u] = v;
                return true;
            }
        }
        return false;
    }

};

int n;
vector<string> ss[2];
vector<int> ids[2];

map<string, int> indexes;
map<int, string> revIndexes;

int GetIndex(const string& s) {
    auto itr = indexes.find(s);
    if (itr == indexes.end()) {
        int result = indexes.size();
        indexes[s] = result;
        revIndexes[result] = s;
        return result;
    }
    return itr->second;
}

void Solve() {
    map<string, int> usedCount;
    for (int i = 0; i < n; ++i) {
        ++usedCount[ss[0][i]];
    }
    indexes.clear();
    revIndexes.clear();
    ids[0].resize(n);
    ids[1].resize(n);
    for (int i = 0; i < n; ++i) {
        ids[0][i] = GetIndex(ss[0][i]);
        ids[1][i] = GetIndex(ss[1][i]);
    }
    TKuhnSolver solver;
    solver.Init(n, indexes.size());
    for (int i = 0; i < n; ++i) {
        if (usedCount[ss[0][i]] == 1) {
            solver.AddEdge(i, ids[0][i]);
        }
        solver.AddEdge(i, ids[1][i]);
    }
    vector<int> solution;
    if (!solver.Solve(solution)) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        cout << revIndexes[solution[i]] << '\n';
    }
    cout.flush();
}

bool Read() {
    if (!(cin >> n)) {
        return false;
    }
    ss[0].resize(n);
    ss[1].resize(n);
    for (int i = 0; i < n; ++i) {
        string a, b;
        cin >> a >> b;
        ss[0][i] = a.substr(0, 3);
        ss[1][i] = a.substr(0, 2) + b.substr(0, 1);
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}