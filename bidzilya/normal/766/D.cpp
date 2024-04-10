#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

const string YES = "YES";
const string NO = "NO";

class TDsu {
public:
    void Init(int n) {
        Rank.assign(n, 0);
        Parent.resize(n);
        for (int i = 0; i < n; ++i) {
            Parent[i] = i;
        }
        Op.assign(n, -1);
    }

    int GetParent(int x) {
        if (Parent[x] != x) {
            Parent[x] = GetParent(Parent[x]);
        }
        return Parent[x];
    }

    bool TryUniteSyn(int x, int y) {
        x = GetParent(x);
        y = GetParent(y);

        if (x == y) {
            return true;
        }

        int a1 = Op[x];
        int a2 = Op[y];

        if (a1 == y || a2 == x) {
            return false;
        }

        x = Unite(x, y);
        a1 = Unite(a1, a2);

        if (x != -1) {
            Op[x] = a1;
        }
        if (a1 != -1) {
            Op[a1] = x;
        }

        return true;
    }

    bool TryUniteAnt(int x, int y) {
        x = GetParent(x);
        y = GetParent(y);

        if (x == y) {
            return false;
        }

        int a1 = Op[x];
        int a2 = Op[y];

        x = Unite(x, a2);
        a1 = Unite(a1, y);

        if (x != -1) {
            Op[x] = a1;
        }
        if (a1 != -1) {
            Op[a1] = x;
        }

        return true;
    }

    int Unite(int x, int y) {
        if (x == -1 && y == -1) {
            return x;
        }
        if (x == -1) {
            return GetParent(y);
        }
        if (y == -1) {
            return GetParent(x);
        }

        x = GetParent(x);
        y = GetParent(y);

        if (x == y) {
            return x;
        }

        if (Rank[x] < Rank[y]) {
            swap(x, y);
        }

        Parent[y] = x;
        if (Rank[x] == Rank[y]) {
            ++Rank[x];
        }

        return x;
    }

    bool IsSyn(int x, int y) {
        x = GetParent(x);
        y = GetParent(y);

        return x == y;
    }

    bool IsAnt(int x, int y) {
        x = GetParent(x);
        y = GetParent(y);

        return x == Op[y];
    }

private:
    vector<int> Rank;
    vector<int> Parent;
    vector<int> Op;
};

int n, m, q;
vector<string> words;

map<string, int> wordsMap;

struct TFirstQuery {
    int Type;
    string First;
    string Second;
};

vector<TFirstQuery> fqs;

vector<pair<string, string>> sqs;

TDsu dsu;

void Solve() {
    wordsMap.clear();
    for (int i = 0; i < n; ++i) {
        auto itr = wordsMap.find(words[i]);
        if (itr == wordsMap.end()) {
            const int id = wordsMap.size();
            wordsMap[words[i]] = id;
        }
    }
    n = wordsMap.size();
    dsu.Init(n);

    for (const auto& q : fqs) {
        const int id1 = wordsMap[q.First];
        const int id2 = wordsMap[q.Second];

        if (q.Type == 1) {
            if (dsu.TryUniteSyn(id1, id2)) {
                cout << YES << '\n';
            } else {
                cout << NO << '\n';
            }
        } else {
            if (dsu.TryUniteAnt(id1, id2)) {
                cout << YES << '\n';
            } else {
                cout << NO << '\n';
            }
        }
    }

    for (const auto& q : sqs) {
        const int id1 = wordsMap[q.first];
        const int id2 = wordsMap[q.second];

        if (dsu.IsSyn(id1, id2)) {
            cout << 1 << '\n';
        } else if (dsu.IsAnt(id1, id2)) {
            cout << 2 << '\n';
        } else {
            cout << 3 << '\n';
        }
    }
}

bool Read() {
    if (!(cin >> n >> m >> q)) {
        return false;
    }
    words.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }
    fqs.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> fqs[i].Type >> fqs[i].First >> fqs[i].Second;
    }
    sqs.resize(q);
    for (int i = 0; i < q; ++i) {
        cin >> sqs[i].first >> sqs[i].second;
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
    cout.flush();

    return 0;
}