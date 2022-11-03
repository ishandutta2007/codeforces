#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

const int BASE = 1002;
const int INF = 1e9;

int n;
vector<int> a;

void Solve() {
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    vector<int> d;
    queue<int> qs;
    d.assign(2 * BASE, INF);
    d[BASE] = 0;
    qs.push(BASE);
    int result = -1;
    while (!qs.empty()) {
        int v = qs.front();
        qs.pop();

        int value = v - BASE;

        for (int u : a) {
            if (value + u == 0) {
                result = d[v] + 1;
                break;
            }
        }

        if (result != -1) {
            break;
        }

        for (int u : a) {
            int nv = value + u + BASE;
            if (nv >= 0 && nv < d.size() && d[nv] == INF) {
                d[nv] = d[v] + 1;
                qs.push(nv);
            }
        }
    }
    cout << result << endl;
}

bool Read() {
    int m;
    if (!(cin >> m >> n)) {
        return false;
    }
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] -= m;
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