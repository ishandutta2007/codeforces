#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#include <cassert>
using namespace std;

int n;
vector<vector<int>> g;

int start;
int finish;

vector<int> path;
vector<bool> onPath;

vector<int> dist;
vector<int> pred;

void BuildDist(int v, int pr) {
    pred[v] = pr;
    if (pr == -1) {
        dist[v] = 0;
    }
    for (int u : g[v]) {
        if (u != pr) {
            dist[u] = dist[v] + 1;
            BuildDist(u, v);
        }
    }
}

int GetMaxDistVertex() {
    int v = 0;
    for (int i = 1; i < n; ++i) {
        if (dist[i] > dist[v]) {
            v = i;
        }
    }
    return v;
}

void BuildPath() {
    path.clear();
    for (int v = finish; v != -1; v = pred[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    onPath.assign(n, false);
    for (int v : path) {
        onPath[v] = true;
    }
}

int Compress(int v, int pr) {
    int x = -1;
    for (int u : g[v]) {
        if (u != pr) {
            int y = Compress(u, v);

            if (y == -1) {
                return -1;
            }

            if (x == -1) {
                x = y;
            } else if (x != y) {
                return -1;
            }
        }
    }

    if (x == -1) {
        x = 0;
    } else {
        ++x;
    }

    return x;
}

void ShowResult(int x) {
    while ((x & 1) == 0) {
        x >>= 1;
    }
    cout << x << endl;
}

void Solve() {
    dist.resize(n);
    pred.resize(n);

    BuildDist(0, -1);

    start = GetMaxDistVertex();

    BuildDist(start, -1);

    finish = GetMaxDistVertex();

    BuildPath();

    const int k = path.size();
    const bool evenPath = (((k - 1) & 1) == 0);
    const int halfDist = ((k - 1) >> 1);
    int center = -1;
    for (int i = 1; i + 1 < k; ++i) {
        const int v = path[i];
        const int leftDist = i;
        const int rightDist = k - i - 1;
        const int curDist = min(leftDist, rightDist);

        if (evenPath && leftDist == rightDist && leftDist == halfDist) {
            center = v;
            continue;
        }

        int x = -1;
        for (int u : g[v]) {
            if (!onPath[u]) {
                int y = Compress(u, v);

                if (y == -1) {
                    cout << -1 << endl;
                    return;
                }

                ++y;

                if (x == -1) {
                    x = y;
                } else if (x != y) {
                    cout << -1 << endl;
                    return;
                }
            }
        }

        if (x != -1 && x != curDist) {
            cout << -1 << endl;
            return;
        }
    }

    if (center != -1) {
        set<int> finalDists;
        finalDists.insert(halfDist);
        for (int u : g[center]) {
            if (!onPath[u]) {
                int y = Compress(u, center);

                if (y == -1) {
                    cout << -1 << endl;
                    return;
                }

                ++y;

                finalDists.insert(y);
            }
        }
        if (finalDists.size() > 2) {
            cout << -1 << endl;
            return;
        }
        int sum = 0;
        for (int x : finalDists) {
            sum += x;
        }
        ShowResult(sum);
    } else {
        ShowResult(k - 1);
    }
}

bool Read() {
    if (!(cin >> n)) {
        return false;
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