#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct TValue {
    int Cost;
    int Index;
};

bool operator < (const TValue& lhs, const TValue& rhs) {
    return lhs.Cost < rhs.Cost;
}

int n;
vector<int> p, a, b;
int m;
vector<int> c;

set<TValue> s[4];
set<int> ri;

void Solve() {
    for (int i = 1; i <= 3; ++i) {
        s[i].clear();
    }
    ri.clear();
    for (int i = 0; i < n; ++i) {
        TValue cur;
        cur.Cost = p[i];
        cur.Index = i;
        s[a[i]].insert(cur);
        s[b[i]].insert(cur);
    }
    for (int i = 0; i < m; ++i) {
        int cur = -1;
        while (!s[c[i]].empty()) {
            TValue value = *s[c[i]].begin();
            s[c[i]].erase(s[c[i]].begin());
            if (ri.find(value.Index) == ri.end()) {
                cur = value.Cost;
                ri.insert(value.Index);
                break;
            }
        }
        cout << cur << " ";
    }
    cout << endl;
}

bool Read() {
    if (!(cin >> n)) {
        return false;
    }
    p.resize(n);
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    cin >> m;
    c.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
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