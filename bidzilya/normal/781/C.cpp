#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m, k;
vector<vector<int>> g;
vector<bool> used;

vector<int> seq;

void BuildSeq(int v) {
    used[v] = true;
    seq.push_back(v);
    for (int u : g[v]) {
        if (!used[u]) {
            BuildSeq(u);
            seq.push_back(v);
        }
    }
}

void Solve() {
    seq.clear();
    used.assign(n, false);
    BuildSeq(0);

    vector<vector<int>> result;
    result.resize(k);
    const int smallSz = seq.size() / k;
    const int bigSz = smallSz + 1;
    int bigCount = seq.size() % k;
    int smallCount = k - bigCount;
    for (int i = 0, j = 0; j < k; ++j) {
        int rg;
        if (bigCount > 0) {
            --bigCount;
            rg = i + bigSz;
        } else {
            --smallCount;
            rg = i + smallSz;
        }

        result[j].assign(seq.begin() + i, seq.begin() + rg);

        i = rg;
    }

    for (int i = 0; i < k; ++i) {
        cout << result[i].size();
        for (int x : result[i]) {
            cout << " " << x + 1;
        }
        cout << '\n';
    }
    cout.flush();
}

bool Read() {
    if (!(cin >> n >> m >> k)) {
        return false;
    }
    g.clear();
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1;
        --v2;
        g[v1].push_back(v2);
        if (v1 != v2) {
            g[v2].push_back(v1);
        }
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