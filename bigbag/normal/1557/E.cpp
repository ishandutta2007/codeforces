/**
 *  created: 09/08/2021, 18:10:13
**/

#include <bits/stdc++.h>

using namespace std;

const int n = 8, inf = 1000111222;
const bool debug = 0;
const string done = "Done";

bool is_in(int x, int y) {
    return 0 <= x && 0 <= y && x < n && y < n;
}

int t, Q, a[n][n], b[n][n], c[n][n];

string proc(int x, int y) {
    ++Q;
    cout << x + 1 << " " << y + 1 << endl;
    string s;
    if (debug) {

    } else {
        cin >> s;
    }
    if (Q == 129 && s != done) {
        exit(228);
    }
    return s;
}

vector<pair<int, int>> get_my(int x, int y) {
    vector<pair<int, int>> v, res;
    for (int i = 0; i < 8; ++i) {
        v.push_back({i, y});
        v.push_back({x, i});
        v.push_back({i, x + y - i});
        v.push_back({i, -x + y + i});
    }
    for (auto p : v) {
        if (is_in(p.first, p.second) && (p.first != x || p.second != y)) {
            res.push_back(p);
        }
    }
    return res;
}

const int seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 generator(seed);

int rnd() {
    return generator() >> 1;
}

int rnd(int r) {
    return rnd() % r;
}

int get_k(string dir) {
    if (dir == "Right") {
        return 0;
    } else if (dir == "Left") {
        return 1;
    } else if (dir == "Up") {
        return 2;
    } else if (dir == "Down") {
        return 3;
    } else if (dir == "Down-Right") {
        return 4;
    } else if (dir == "Down-Left") {
        return 5;
    } else if (dir == "Up-Left") {
        return 6;
    } else if (dir == "Up-Right") {
        return 7;
    }
    assert(0);
}

const int dx[] = {0, 0, -1, 1, 1, 1, -1, -1};
const int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

void solve() {
    Q = 0;
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = 1;
        }
    }
    while (true) {
        vector<pair<int, int>> v = get_my(x, y);
        int id = rnd(v.size());
        int nx = v[id].first, ny = v[id].second;
        string s = proc(nx, ny);
        if (s == done) {
            return;
        }
        x = nx;
        y = ny;
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        v = get_my(x, y);
        for (auto p : v) {
            c[p.first][p.second] = 1;
        }
        c[x][y] = 1;
        const int k = get_k(s);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j]) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (is_in(ni, nj) && !c[ni][nj]) {
                        b[ni][nj] = 1;
                    }
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                a[i][j] = b[i][j];
                cnt += a[i][j];
            }
        }
        //cout << "#" << cnt << endl;
        assert(cnt);
        if (cnt == 1) {
            break;
        }
    }
    int his_x, his_y;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j]) {
                his_x = i;
                his_y = j;
            }
        }
    }
    bool first = x != 7 || y != 7;
    while (true) {
        string s;
        if (first) {
            if (x != 7) {
                x = 7;
            } else if (y != 7) {
                y = 7;
            }
        } else {
            assert(x > his_x && y > his_y);
            if (x - 1 > his_x) {
                --x;
            } else {
                assert(y - 1 > his_y);
                --y;
            }
        }
        s = proc(x, y);
        if (s == done) {
            return;
        }
        if (x == 7 && y == 7) {
            first = 0;
        }
        const int k = get_k(s);
        his_x += dx[k];
        his_y += dy[k];
    }
}

int main() {

    /*for (auto p : get_my(3, 4)) {
        a[p.first][p.second] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j];
        }
        cout << endl;
    }*/
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}