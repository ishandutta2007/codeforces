#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TDsu {
    void Init(int n) {
        Rank.assign(n, 0);
        Parent.resize(n);
        for (int i = 0; i < n; ++i) {
            Parent[i] = i;
        }
    }

    int GetParent(int v) {
        if (Parent[v] == v) {
            return v;
        }
        return Parent[v] = GetParent(Parent[v]);
    }

    bool Unite(int v1, int v2) {
        v1 = GetParent(v1);
        v2 = GetParent(v2);

        if (v1 == v2) {
            return false;
        }

        if (Rank[v1] < Rank[v2]) {
            swap(v1, v2);
        }

        Parent[v2] = v1;

        if (Rank[v1] == Rank[v2]) {
            ++Rank[v1];
        }

        return true;
    }

    vector<int> Parent;
    vector<int> Rank;
};

int n;
vector<int> p;

void Solve() {
    TDsu dsu;
    dsu.Init(n);
    int result = n;
    for (int i = 0; i < n; ++i) {
        result -= dsu.Unite(i, p[i]);
    }
    cout << result << endl;
}

bool Read() {
    if (!(cin >> n)) {
        return false;
    }
    p.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
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