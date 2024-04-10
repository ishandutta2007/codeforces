#include <algorithm>
#include <iostream>
using namespace std;

#define N 64
#define M 256
using ll = long long;

const ll mod = 998244353;

pair<int, int> graph[N][N];
int n, m;

struct Gauss {
    int matrix[M * 16 + 1][M + 1];
    int n_var, n_equal, row;

    void init(int m) {
        n_var = m;
        n_equal = 0;
        for (int i = 0; i < M * 16 + 1; i++) {
            fill_n(matrix[i], n_var + 1, 0);
        }
        fill_n(result, n_var, 0);
    }

    void add_row(int start, int a, int b, int v) {
        for (int i = start; i <= n_var; i++) {
            matrix[b][i] += matrix[a][i] * v;
            if (matrix[b][i] >= 3) {
                matrix[b][i] -= 3;
            } else if (matrix[b][i] < 0) {
                matrix[b][i] += 3;
            }
        }
    }

    bool calculate() {
        row = 0;
        for (int start = 0, i; start < n_var; start++) {
            if (matrix[row][start] == 0) {
                i = row;
                while (i < n_equal && !matrix[i][start]) {
                    i++;
                }
                if (i == n_equal) {
                    continue;
                }
                swap(matrix[row], matrix[i]);
            }
            for (i = row + 1; i < n_equal; i++) {
                if (matrix[i][start]) {
                    if (matrix[row][start] != matrix[i][start]) {
                        add_row(start, row, i, 1);
                    } else {
                        add_row(start, row, i, -1);
                    }
                }
            }
            row++;
        }
        for (int i = row; i < n_equal; i++) {
            if (matrix[i][n_var]) {
                return 0;
            }
        }
        return 1;
    }

    void handle_edge(pair<int, int> edge) {
        if (edge.first == -1) {
            matrix[n_equal][edge.second] = 1;
        } else {
            matrix[n_equal][n_var] += 3 - edge.first;
            result[edge.second] = edge.first;
        }
    }

    void add_equal(int a, int b, int c) {
        matrix[n_equal][n_var] = 0;
        handle_edge(graph[a][b]);
        handle_edge(graph[c][b]);
        handle_edge(graph[a][c]);
        matrix[n_equal][n_var] %= 3;
        n_equal++;
    }

    int result[M];

    bool get_answer() {
        for (int i = row - 1, tmp; i >= 0; i--) {
            tmp = matrix[i][n_var];
            for (int j = 0; j < n_var; j++) {
                if (matrix[i][j] && result[j]) {
                    tmp -= matrix[i][j] * result[j];
                }
            }
            for (int j = 0; j < n_var; j++) {
                if (matrix[i][j] && !result[j]) {
                    result[j] = tmp;
                    result[j] %= 3;
                    if (result[j] <= 0) {
                        result[j] += 3;
                    }
                    if (matrix[i][j] == 2 && result[j] < 3) {
                        result[j] = result[j] == 1 ? 2 : 1;
                    }
                    j++;
                    while (j < n_var) {
                        if (matrix[i][j] && !result[j]) {
                            result[j] = 3;
                        }
                        j++;
                    }
                }
            }
        }
        return 1;
    }
} gauss;

int c[M];

void solve() {
    int n, m;
    cin >> n >> m;
    gauss.init(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j].first = 0;
        }
    }

    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b >> c[i];
        a--, b--;
        graph[a][b] = graph[b][a] = make_pair(c[i], i);
        for (int j = 0; j < n; j++) {
            if (graph[a][j].first && graph[b][j].first) {
                gauss.add_equal(a, b, j);
            }
        }
    }
    if (gauss.calculate()) {
        gauss.get_answer();
        for (int i = 0; i < gauss.n_var; i++) {
            if (c[i] != -1) {
                cout << c[i] << ' ';
            } else {
                cout << max(1, gauss.result[i]) << ' ';
            }
        }
    } else {
        cout << -1;
    }
    cout << '\n';
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}