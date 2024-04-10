#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

const int INF = 1e9;

class TBox {
public:
    void Init(int maxSize) {
        MaxSize = maxSize;
    }

    void Add(const pair<int, int>& value) {
        Values.push_back(value);
        if (Values.size() > MaxSize) {
            sort(Values.begin(), Values.end(), greater<pair<int, int>>());
            Values.resize(MaxSize);
        }
    }

    pair<int, int> Get(const vector<int>& banned) {
        auto isIn = [&] (int x) {
            for (int y : banned) {
                if (y == x) {
                    return true;
                }
            }
            return false;
        };
        pair<int, int> result = make_pair(-1, -1);
        for (int i = 0; i < (int) Values.size(); ++i) {
            if (!isIn(Values[i].second)) {
                result = max(result, Values[i]);
            }
        }
        return result;
    }
private:
    int MaxSize;
    vector<pair<int, int>> Values;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1;
        --v2;
        g[v1].push_back(v2);
    }

    vector<vector<int>> dist(n, vector<int>(n, INF));
    vector<bool> used;
    for (int i = 0; i < n; ++i) {
        queue<int> q;
        dist[i][i] = 0;
        q.push(i);
        used.assign(n, false);
        used[i] = true;
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int u : g[v]) {
                if (!used[u]) {
                    used[u] = true;
                    dist[i][u] = dist[i][v] + 1;
                    q.push(u);
                }
            }
        }
    }

    vector<TBox> inMax(n);
    vector<TBox> outMax(n);

    for (int i = 0; i < n; ++i) {
        inMax[i].Init(3);
        outMax[i].Init(3);

        for (int j = 0; j < n; ++j) {
            if (j == i) {
                continue;
            }
            if (dist[i][j] != INF) {
                outMax[i].Add(make_pair(dist[i][j], j));
            }
            if (dist[j][i] != INF) {
                inMax[i].Add(make_pair(dist[j][i], j));
            }
        }
    }

    int resultDist = -1;
    vector<int> result;
    for (int m1 = 0; m1 < n; ++m1) {
        for (int m2 = 0; m2 < n; ++m2) {
            if (m1 == m2) {
                continue;
            }

            if (dist[m1][m2] == INF) {
                continue;
            }

            vector<int> banned = {m1, m2};

            {
                pair<int, int> buf = inMax[m1].Get(banned);
                if (buf.first != -1) {
                    int m0 = buf.second;

                    banned.push_back(m0);

                    pair<int, int> buf2 = outMax[m2].Get(banned);

                    if (buf2.first != -1) {
                        int m3 = buf2.second;

                        int curDist = dist[m1][m2] + buf.first + buf2.first;

                        if (resultDist == -1 || curDist > resultDist) {
                            resultDist = curDist;
                            result = {m0, m1, m2, m3};
                        }
                    }

                    banned.pop_back();
                }
            }

            {
                pair<int, int> buf = outMax[m2].Get(banned);
                if (buf.first != -1) {
                    int m3 = buf.second;

                    banned.push_back(m3);

                    pair<int, int> buf2 = inMax[m1].Get(banned);

                    if (buf2.first != -1) {
                        int m0 = buf2.second;

                        int curDist = dist[m1][m2] + buf.first + buf2.first;

                        if (resultDist == -1 || curDist > resultDist) {
                            resultDist = curDist;
                            result = {m0, m1, m2, m3};
                        }
                    }

                    banned.pop_back();
                }
            }
        }
    }

    for (int x : result) {
        cout << x + 1 << " ";
    }
    cout << endl;

    return 0;
}