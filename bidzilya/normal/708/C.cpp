#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

class TBox {
public:
    void Init(int sz) {
        Result.clear();
        Size = sz;
    }

    void Add(const pair<int, int>& value) {
        Result.push_back(value);
        sort(Result.begin(), Result.end(), greater<pair<int, int>>());

        if (Result.size() > Size) {
            Result.pop_back();
        }
    }

    pair<int, int> GetExcept(int except) {
        for (int i = 0; i < Result.size(); ++i) {
            if (Result[i].second != except) {
                return Result[i];
            }
        }
        return make_pair(-1, -1);
    }
private:
    vector<pair<int, int>> Result;
    int Size;
};

int n;
vector<vector<int>> g;

vector<bool> result;

vector<int> size;
vector<int> partSize;

void BuildAddInfo(int v, int pr) {
    size[v] = 1;
    partSize[v] = 0;
    for (int u : g[v]) {
        if (u == pr) {
            continue;
        }

        BuildAddInfo(u, v);

        size[v] += size[u];

        partSize[v] = max(partSize[v], partSize[u]);
    }

    if (size[v] * 2 <= n) {
        partSize[v] = max(partSize[v], size[v]);
    }
}

void BuildResult(int v, int upPartSize, int pr) {
    int upSize = n - size[v];
    bool centroid = (upSize * 2 <= n);
    for (int u : g[v]) {
        if (u == pr) {
            continue;
        }

        if (size[u] * 2 > n) {
            centroid = false;
        }
    }

    result[v] = false;
    if (centroid) {
        result[v] = true;
    } else {
        if (upSize * 2 > n) {
            if ((upSize - upPartSize) * 2 <= n) {
                result[v] = true;
            }
        } else {
            for (int u : g[v]) {
                if (u == pr) {
                    continue;
                }

                if (size[u] * 2 > n) {
                    if ((size[u] - partSize[u]) * 2 <= n) {
                        result[v] = true;
                    }
                    break;
                }
            }
        }
    }

    TBox box;
    box.Init(2);
    for (int u : g[v]) {
        if (u == pr) {
            continue;
        }

        box.Add(make_pair(partSize[u], u));
    }

    for (int u : g[v]) {
        if (u == pr) {
            continue;
        }

        int newUpPartSize;
        if ((n - size[u]) * 2 <= n) {
            newUpPartSize = n - size[u];
        } else {
            newUpPartSize = upPartSize;

            pair<int, int> temp = box.GetExcept(u);

            if (temp.second != -1) {
                newUpPartSize = max(newUpPartSize, temp.first);
            }
        }

        BuildResult(u, newUpPartSize, v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    g.resize(n);
    for (int i = 0; i + 1 < n; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1;
        --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    size.resize(n);
    partSize.resize(n);
    BuildAddInfo(0, -1);

    result.assign(n, false);
    BuildResult(0, 0, -1);

    for (int i = 0; i < n; ++i) {
        if (result[i]) {
            cout << 1 << " ";
        } else {
            cout << 0 << " ";
        }
    }
    cout << endl;

    return 0;
}