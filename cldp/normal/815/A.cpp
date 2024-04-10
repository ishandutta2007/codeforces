#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int x[MAXN][MAXN];
bool row[MAXN], col[MAXN];

void print(int N, int M) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) cout << x[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) cin >> x[i][j];
    }

    vector<string> ans;
    int minv = INF;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) minv = min(minv, x[i][j]);
    }

    if (minv > 0) {
        if (N > M) {
            for (int k = 0; k < minv; ++k) {
                for (int j = 0; j < M; ++j) ans.push_back("col " + to_string(j + 1));
            }
        } else {
            for (int k = 0; k < minv; ++k) {
                for (int i = 0; i < N; ++i) ans.push_back("row " + to_string(i + 1));
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) x[i][j] -= minv;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (x[i][j] == 0) row[i] = col[j] = true;
        }
    }
    bool invalid = false;
    while (true) {
        bool update = false;
        for (int i = 0; i < N; ++i) {
            if (invalid) break;
            for (int j = 0; j < M; ++j) {
                if (invalid) break;
                if (x[i][j] > 0 && (row[i] || col[j])) {
                    update = true;
                    if (row[i] && col[j]) {
                        invalid = true;
                        break;
                    }
                    if (row[i]) {
                        int temp = x[i][j];
                        for (int k = 0; k < temp; ++k) ans.push_back("col " + to_string(j + 1));
                        for (int k = 0; k < N; ++k) {
                            x[k][j] -= temp;
                            if (x[k][j] < 0) {
                                invalid = true;
                                break;
                            }
                        }
                    } else {
                        int temp = x[i][j];
                        for (int k = 0; k < temp; ++k) ans.push_back("row " + to_string(i + 1));
                        for (int k = 0; k < M; ++k) {
                            x[i][k] -= temp;
                            if (x[i][k] < 0) {
                                invalid = true;
                                break;
                            }
                        }
                    }
                    row[i] = col[j] = true;
                }
            }
        }
        if (invalid) break;
        if (!update) break;
    }

    if (!invalid) {
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}