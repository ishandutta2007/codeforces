#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 22, inf = 111111111;

const char dost[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
const char mast[4] = {'C', 'D', 'H', 'S'};

struct state {
    char c1, c2;
    void read() {
        cin >> c1 >> c2;
    }
    void write() {
        cout << c1 << c2;
    }
    state() {
        c1 = c2 = '!';
    }
    state(char c1, char c2) : c1(c1), c2(c2) {
    }
    bool operator < (const state &a) const {
        return c1 < a.c1 || c1 == a.c1 && c2 < a.c2;
    }
};

struct point {
    int x, y;
    point() {
        x = y = 0;
    }
    point(int xx, int yy) {
        x = xx;
        y = yy;
    }
    void read() {
        cin >> x >> y;
    }
    void write() {
        cout << "(" << x << ", " << y << ")." << endl;
    }
    bool operator < (const point &a) const {
        return x < a.x || x == a.x && y < a.y;
    }
};

int n, m, x1, x2, y1, y2;
state q[max_n][max_n];
map<state, int> f;
vector<state> v;

bool good(int x, int y) {
    if (x + 2 > n || y + 2 > m) {
        return false;
    }
    int f1 = 0;
    for (int i = x; i <= x + 2; ++i) {
        for (int j = y; j <= y + 2; ++j) {
            if (q[i][j].c2 != q[x][y].c2) {
                f1 = 1;
                break;
            }
        }
    }
    if (f1 == 0) {
        return true;
    }
    f1 = 0;
    set<char> sss;
    for (int i = x; i <= x + 2; ++i) {
        for (int j = y; j <= y + 2; ++j) {
            sss.insert(q[i][j].c1);
        }
    }
    return sss.size() == 9;
}

bool is_intersect(int x1, int y1, int x2, int y2) {
    return !(min(x1, x2) + 2 < max(x1, x2) || min(y1, y2) + 2 < max(y1, y2));
}

pair<point, point> good() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int i1 = 1; i1 <= n; ++i1) {
                for (int j1 = 1; j1 <= m; ++j1) {
                    if (!is_intersect(i, j, i1, j1) && good(i, j) && good(i1, j1)) {
                        return make_pair(point(i, j), point(i1, j1));
                    }
                }
            }
        }
    }
    return make_pair(point(inf, inf), point(inf, inf));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    x1 = x2 = y1 = y2 = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            q[i][j].read();
            f[q[i][j]] = 1;
            if (q[i][j].c1 == 'J') {
                if (q[i][j].c2 == '1') {
                    x1 = i;
                    y1 = j;
                }
                if (q[i][j].c2 == '2') {
                    x2 = i;
                    y2 = j;
                }
            }
        }
    }
    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 4; ++j) {
            state s(dost[i], mast[j]);
            if (!f.count(s)) {
                v.push_back(s);
            }
        }
    }
    if (x1 != 0 && x2 != 0) {
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < v.size(); ++j) {
                if (i != j) {
                    q[x1][y1] = v[i];
                    q[x2][y2] = v[j];
                    pair<point, point> ans = good();
                    if (ans.first.x != inf) {
                        cout << "Solution exists." << endl;
                        cout << "Replace J1 with ";
                        v[i].write();
                        cout << " and J2 with ";
                        v[j].write();
                        cout << "." << endl;
                        cout << "Put the first square to ";
                        ans.first.write();
                        cout << "Put the second square to ";
                        ans.second.write();
                        return 0;
                    }
                }
            }
        }
        cout << "No solution." << endl;
        return 0;
    }
    if (x1 != 0) {
        for (int i = 0; i < v.size(); ++i) {
            q[x1][y1] = v[i];
            pair<point, point> ans = good();
            if (ans.first.x != inf) {
                cout << "Solution exists." << endl;
                cout << "Replace J1 with ";
                v[i].write();
                cout << "." << endl;
                cout << "Put the first square to ";
                ans.first.write();
                cout << "Put the second square to ";
                ans.second.write();
                return 0;
            }
        }
        cout << "No solution." << endl;
        return 0;
    }
    if (x2 != 0) {
        for (int i = 0; i < v.size(); ++i) {
            q[x2][y2] = v[i];
            pair<point, point> ans = good();
            if (ans.first.x != inf) {
                cout << "Solution exists." << endl;
                cout << "Replace J2 with ";
                v[i].write();
                cout << "." << endl;
                cout << "Put the first square to ";
                ans.first.write();
                cout << "Put the second square to ";
                ans.second.write();
                return 0;
            }
        }
        cout << "No solution." << endl;
        return 0;
    }
    pair<point, point> ans = good();
    if (ans.first.x != inf) {
        cout << "Solution exists." << endl;
        cout << "There are no jokers." << endl;
        cout << "Put the first square to ";
        ans.first.write();
        cout << "Put the second square to ";
        ans.second.write();
        return 0;
    }
    cout << "No solution." << endl;
    return 0;
}