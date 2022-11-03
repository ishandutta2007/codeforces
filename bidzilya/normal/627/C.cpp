#include <iostream>
#include <vector>
#include <algorithm>

#include <cstdio>
using namespace std;

const int MAX_N = 2e5 + 100;
const int MAX_LOG = 20;

vector<int> logs;

void BuildLogs() {
    logs.resize(MAX_N);
    logs[1] = 0;
    for (int i = 2; i < MAX_N; ++i) {
        logs[i] = logs[i - 1];
        if ((1 << (logs[i] + 1)) <= i) {
            ++logs[i];
        }
    }
}

struct TTable {
    void Build(const vector<int>& a) {
        int n = a.size();
        A = a;
        T.resize(n, vector<int>(MAX_LOG));
        for (int i = 0; i < n; ++i) {
            T[i][0] = i;
        }
        for (int i = 1; i < MAX_LOG; ++i) {
            for (int j = 0; j < n; ++j) {
                T[j][i] = T[j][i - 1];
                int nxt = j + (1 << (i - 1));
                if (nxt < n) {
                    int index = T[nxt][i - 1];

                    if (A[index] < A[T[j][i]]) {
                        T[j][i] = index;
                    }
                }
            }
        }
    }

    int Get(int l, int r) {
        int logLen = logs[r - l + 1];

        int i1 = T[l][logLen];
        int i2 = T[r - (1 << logLen) + 1][logLen];

        if (A[i1] < A[i2]) {
            return i1;
        } else {
            return i2;
        }
    }

    vector<int> A;
    vector<vector<int>> T;
};

const long long LONG_INF = 1e18;

TTable minTable;
vector<pair<int, int>> a;
int n;

pair<long long, int> Solve(int l, int r) {
    if (l == r) {
        return make_pair(0, n);
    }
    if (l + 1 == r) {
        int dist = a[r].first - a[l].first;
        if (dist <= n) {
            return make_pair(0, n - dist);
        } else {
            return make_pair(LONG_INF, n);
        }
    }

    int minPos = minTable.Get(l + 1, r - 1);

    pair<long long, int> leftResult = Solve(l, minPos);

    if (leftResult.first == LONG_INF) {
        return leftResult;
    }

    int rightDist = a[r].first - a[minPos].first;

    if (rightDist <= n) {
        if (rightDist <= leftResult.second) {
            return make_pair(leftResult.first, leftResult.second - rightDist);
        } else {
            return make_pair(leftResult.first + 1LL * (rightDist - leftResult.second) * a[minPos].second, 0);
        }
    }

    long long cost = leftResult.first + 1LL * (n - leftResult.second) * a[minPos].second;

    pair<long long, int> rightResult = Solve(minPos, r);

    if (rightResult.first == LONG_INF) {
        return rightResult;
    }

    return make_pair(cost + rightResult.first, rightResult.second);
}

int main() {
    // freopen("input.txt", "r", stdin);

    BuildLogs();

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int d;
    int m;
    cin >> d >> n >> m;

    a.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    a.push_back(make_pair(0, 0));
    a.push_back(make_pair(d, 0));
    sort(a.begin(), a.end());

    m = a.size();

    vector<int> ps(m);
    for (int i = 0; i < m; ++i) {
        ps[i] = a[i].second;
    }

    minTable.Build(ps);

    pair<long long, int> result = Solve(0, m - 1);

    if (result.first >= LONG_INF) {
        cout << -1 << endl;
    } else {
        cout << result.first << endl;
    }

    return 0;
}