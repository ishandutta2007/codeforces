#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

const int INF = 1e9 + 1;

class TDsu {
public:
    void Init(int n) {
        Rank.assign(n, 0);
        Parent.resize(n);
        Left.resize(n);
        Right.resize(n);
        for (int i = 0; i < n; ++i) {
            Parent[i] = i;
            Left[i] = i;
            Right[i] = i;
        }
    }

    int GetParent(int v) {
        if (Parent[v] != v) {
            Parent[v] = GetParent(Parent[v]);
        }
        return Parent[v];
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

        Left[v1] = min(Left[v1], Left[v2]);
        Right[v1] = max(Right[v1], Right[v2]);

        return true;
    }

    int GetLeft(int v) const {
        return Left[v];
    }

    int GetRight(int v) const {
        return Right[v];
    }

private:
    vector<int> Rank;
    vector<int> Parent;

    vector<int> Left;
    vector<int> Right;
};

const int BASE = 300;

int n;
vector<int> a;

int m;
vector<pair<int, int>> qs;

struct TQuery {
    int Left;
    int Right;
    int Index;
};

int bc;
vector<vector<TQuery>> qids;

vector<int> result;

vector<vector<int>> smallResult;

vector<vector<int>> poses;

TDsu dsu;

vector<int> allValues;

inline int GetDist(int i, int j) {
    return abs(allValues[i] - allValues[j]);
}

vector<int> valueCount;
vector<int> dp;

void Solve(const vector<TQuery>& qs, int l, int r) {
    poses.clear();
    poses.resize(n);
    for (int i = 0; i < (int) qs.size(); ++i) {
        const TQuery& q = qs[i];
        if (q.Right < r) {
            result[q.Index] = min(result[q.Index], smallResult[q.Left][q.Right - q.Left + 1]);
        } else {
            result[q.Index] = min(result[q.Index], smallResult[q.Left][(r - 1) - q.Left + 1]);
            poses[q.Right].push_back(i);
        }
    }

    dsu.Init(allValues.size());

    valueCount.assign(allValues.size(), 0);
    for (int i = r; i < n; ++i) {
        ++valueCount[a[i]];
    }

    for (int i = 1; i < (int) allValues.size(); ++i) {
        if (valueCount[i] == 0 && valueCount[i - 1] == 0) {
            dsu.Unite(i - 1, i);
        }
    }

    dp.assign(n, INF);
    for (int i = n - 1; i >= r; --i) {
        for (auto x : poses[i]) {
            const int id = qs[x].Index;
            for (int j = qs[x].Left; j < r; ++j) {
                const int cur = a[j];

                if (valueCount[cur] > 0) {
                    result[id] = 0;
                } else {
                    int par = dsu.GetParent(cur);

                    int l = dsu.GetLeft(par);
                    int r = dsu.GetRight(par);

                    if (l - 1 >= 0) {
                        result[id] = min(result[id], GetDist(l - 1, cur));
                    }
                    if (r + 1 < (int) allValues.size()) {
                        result[id] = min(result[id], GetDist(r + 1, cur));
                    }
                }
            }
        }

        const int cur = a[i];

        --valueCount[cur];
        if (valueCount[cur] > 0) {
            dp[i] = 0;
        } else {
            if (cur + 1 < (int) allValues.size() && valueCount[cur + 1] == 0) {
                dsu.Unite(cur, cur + 1);
            }
            if (cur - 1 >= 0 && valueCount[cur - 1] == 0) {
                dsu.Unite(cur, cur - 1);
            }
            int par = dsu.GetParent(cur);

            int l = dsu.GetLeft(par);
            int r = dsu.GetRight(par);

            if (l - 1 >= 0) {
                dp[i] = min(dp[i], GetDist(l - 1, cur));
            }
            if (r + 1 < (int) allValues.size()) {
                dp[i] = min(dp[i], GetDist(r + 1, cur));
            }
        }
    }

    for (int i = r + 1; i < n; ++i) {
        dp[i] = min(dp[i], dp[i - 1]);
    }

    for (int i = r; i < n; ++i) {
        for (auto x : poses[i]) {
            const int id = qs[x].Index;
            result[id] = min(result[id], dp[i]);
        }
    }
}

void Solve() {
    {
        allValues.clear();
        for (int i = 0; i < n; ++i) {
            allValues.push_back(a[i]);
        }
        sort(allValues.begin(), allValues.end());
        allValues.resize(unique(allValues.begin(), allValues.end()) - allValues.begin());
        unordered_map<int, int> mp;
        for (int i = 0; i < (int) allValues.size(); ++i) {
            mp[allValues[i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            a[i] = mp[a[i]];
        }
    }

    bc = (n / BASE) + (n % BASE != 0);
    qids.clear();
    qids.resize(bc);
    for (int i = 0; i < m; ++i) {
        int bid = qs[i].first / BASE;
        qids[bid].push_back(TQuery{qs[i].first, qs[i].second, i});
    }

    smallResult.assign(n, vector<int>(BASE + 1, INF));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 2; j <= BASE; ++j) {
            smallResult[i][j] = smallResult[i][j - 1];
            if (i + 1 < n) {
                smallResult[i][j] = min(smallResult[i][j], smallResult[i + 1][j - 1]);
            }
            if (i + j - 1 < n) {
                smallResult[i][j] = min(smallResult[i][j], GetDist(a[i + j - 1], a[i]));
            }
        }
    }

    result.assign(m, INF);

    for (int bid = 0; bid < bc; ++bid) {
        Solve(qids[bid], bid * BASE, min((bid + 1) * BASE, n));
    }

    for (int i = 0; i < m; ++i) {
        printf("%d\n", result[i]);
    }
}

bool Read() {
    if (scanf("%d", &n) == EOF) {
        return false;
    }
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    qs.resize(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &qs[i].first, &qs[i].second);
        --qs[i].first;
        --qs[i].second;
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