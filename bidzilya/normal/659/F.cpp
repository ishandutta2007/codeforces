#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>
using namespace std;

const int DX[4] = {-1, 0, 0, 1};
const int DY[4] = {0, -1, 1, 0};

class TDsu {
public:
    void Init(int n) {
        Rank.assign(n, 0);
        Pred.resize(n);
        Size.assign(n, 1);
        for (int i = 0; i < n; ++i) {
            Pred[i] = i;
        }
        MaxSize = 1;
    }

    int GetParent(int v) {
        if (Pred[v] == v) {
            return v;
        }
        return Pred[v] = GetParent(Pred[v]);
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
        Size[v1] += Size[v2];
        Pred[v2] = v1;
        if (Rank[v1] == Rank[v2]) {
            ++Rank[v1];
        }
        MaxSize = max(MaxSize, Size[v1]);
        return true;
    }

    int GetSize(int v) {
        return Size[GetParent(v)];
    }

    int GetMaxSize() const {
        return MaxSize;
    }
private:
    vector<int> Rank;
    vector<int> Pred;
    vector<int> Size;
    int MaxSize;
};

long long k;
int n, m;
vector<vector<int>> a;
vector<vector<int>> result;

void Dfs(int x, int y, int& count) {
    result[x][y] = a[x][y];
    --count;
    for (int dir = 0; dir < 4; ++dir) {
        int nx = x + DX[dir];
        int ny = y + DY[dir];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] > 0 && count > 0 && result[nx][ny] == 0) {
            Dfs(nx, ny, count);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    a.resize(n, vector<int>(m));
    vector<pair<int, int>> b;
    b.reserve(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            b.push_back(make_pair(a[i][j], i * m + j));
        }
    }

    sort(b.begin(), b.end(), greater<pair<int, int>>());

    TDsu dsu;
    dsu.Init(n * m);
    vector<bool> used(n * m, false);
    for (int i = 0; i < n * m; ++i) {
        int x = b[i].second / m;
        int y = b[i].second % m;
        used[b[i].second] = true;
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + DX[dir];
            int ny = y + DY[dir];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && used[nx * m + ny]) {
                dsu.Unite(b[i].second, nx * m + ny);
            }
        }

        if (k % b[i].first == 0 && 1LL * dsu.GetMaxSize() * b[i].first >= k) {
            int root = dsu.GetParent(b[i].second);
            for (int v = 0; v < n * m; ++v) {
                if (dsu.GetParent(v) == root) {
                    a[v / m][v % m] = b[i].first;
                } else {
                    a[v / m][v % m] = 0;
                }
            }
            result.assign(n, vector<int>(m, 0));
            {
                int count = k / b[i].first;
                Dfs(b[i].second / m, b[i].second % m, count);
            }
            cout << "YES" << endl;
            for (int x = 0; x < n; ++x) {
                for (int y = 0; y < m; ++y) {
                    cout << result[x][y] << " ";
                }
                cout << '\n';
            }
            cout.flush();
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}