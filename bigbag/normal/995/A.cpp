#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

struct state {
    int num, x, y;
    state(int num, int x, int y): num(num), x(x), y(y) {
    }
    void write() const {
        cout << num << " " << x + 1 << " " << y + 1 << "\n";
    }
};

int n, k, a[4][max_n], pos[max_n], lev[max_n];
vector<state> ans;

void add(const state &s) {
    ans.push_back(s);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (i == 0) {
                pos[a[i][j]] = j;
                lev[a[i][j]] = 1;
            } else if (i == 3) {
                pos[a[i][j]] = j;
                lev[a[i][j]] = 2;
            }
        }
    }
    int TO[3] = {-1, 0, 3};
    for (int it = 0; it < 2 * n; ++it) {
        for (int i = 1; i < 3; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] && pos[a[i][j]] == j && lev[a[i][j]] == i) {
                    add(state(a[i][j], TO[i], j));
                    a[i][j] = 0;
                }
            }
        }
        int x = -1, y = -1;
        for (int i = 1; i < 3; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] == 0) {
                    x = i;
                    y = j;
                }
            }
        }
        if (x == -1) {
            cout << -1 << endl;
            return 0;
        }
        for (int i = 0; i + 1 < 2 * n; ++i) {
            int px, py;
            if (x == 2) {
                px = 2;
                py = y - 1;
                if (y == 0) {
                    px = 1;
                    py = 0;
                }
            } else {
                px = 1;
                py = y + 1;
                if (py == n) {
                    px = 2;
                    py = n - 1;
                }
            }
            if (a[px][py]) {
                add(state(a[px][py], x, y));
            }
            swap(a[x][y], a[px][py]);
            x = px;
            y = py;
        }
    }
    cout << ans.size() << "\n";
    for (const state &s : ans) {
        s.write();
    }
    return 0;
}