#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

inline int GetBit(int mask, int num) {
    return (mask >> num) & 1;
}

const int BITS_COUNT = 20;

int n;
vector<vector<int>> g;
vector<int> aa;
vector<int> a;

vector<vector<int>> downCount;
vector<vector<int>> upCount;

void BuildDownCount(int v, int pr) {
    downCount[v][0] = downCount[v][1] = 0;
    ++downCount[v][a[v]];
    for (int u : g[v]) {
        if (u != pr) {
            BuildDownCount(u, v);
            for (int b = 0; b < 2; ++b) {
                const int nb = (b ^ a[v]);

                downCount[v][nb] += downCount[u][b];
            }
        }
    }
}

void BuildUpCount(int v, int pr, int zeroCount, int oneCount) {
    if (a[v]) {
        swap(zeroCount, oneCount);
    }
    upCount[v][0] = zeroCount;
    upCount[v][1] = oneCount;
    if (a[v]) {
        ++oneCount;
    } else {
        ++zeroCount;
    }
    for (int u : g[v]) {
        if (u != pr) {
            if (a[v]) {
                zeroCount += downCount[u][1];
                oneCount += downCount[u][0];
            } else {
                zeroCount += downCount[u][0];
                oneCount += downCount[u][1];
            }
        }
    }
    for (int u : g[v]) {
        if (u != pr) {
            int curZeroCount = zeroCount;
            int curOneCount = oneCount;
            if (a[v]) {
                curZeroCount -= downCount[u][1];
                curOneCount -= downCount[u][0];
            } else {
                curZeroCount -= downCount[u][0];
                curOneCount -= downCount[u][1];
            }
            BuildUpCount(u, v, curZeroCount, curOneCount);
        }
    }
}

long long GetCount() {
    downCount.assign(n, vector<int>(2));
    upCount.assign(n, vector<int>(2));

    BuildDownCount(0, -1);
    BuildUpCount(0, -1, 0, 0);

    long long result = 0;
    for (int i = 0; i < n; ++i) {
        result += downCount[i][1];
        result += upCount[i][1];
    }
    return result;
}

void Solve() {
    long long result = 0;
    a.resize(n);
    for (int b = 0; b < BITS_COUNT; ++b) {
        for (int i = 0; i < n; ++i) {
            a[i] = GetBit(aa[i], b);
        }

        result += GetCount() * (1 << b);
    }
    for (int i = 0; i < n; ++i) {
        result -= aa[i];
    }
    result >>= 1;
    for (int i = 0; i < n; ++i) {
        result += aa[i];
    }
    cout << result << endl;
}

bool Read() {
    if (!(cin >> n)) {
        return false;
    }
    aa.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> aa[i];
    }
    g.clear();
    g.resize(n);
    for (int i = 0; i + 1 < n; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1;
        --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
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