#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 55;

int n, m;

struct state {
    string s[max_n];
    void read() {
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
    }
    void write(string q = "") {
        for (int i = 0; i < n; ++i) {
            cout << s[i] << endl;
        }
        cout << q;
    }
};

state st, fin;

void proc(state &a, int x, int y) {
    if (a.s[x][y] == 'U') {
        a.s[x][y] = 'L';
        a.s[x][y + 1] = 'R';
        a.s[x + 1][y] = 'L';
        a.s[x + 1][y + 1] = 'R';
    } else {
        a.s[x][y] = 'U';
        a.s[x][y + 1] = 'U';
        a.s[x + 1][y] = 'D';
        a.s[x + 1][y + 1] = 'D';
    }
}

void rec(state &a, vector<pair<int, int> > &v, int x, int y, char c) {
    if (a.s[x][y] == c) {
        return;
    }
    if (c == 'L') {
        rec(a, v, x, y + 1, 'U');
    } else {
        rec(a, v, x + 1, y, 'L');
    }
    proc(a, x, y);
    v.push_back(make_pair(x + 1, y + 1));
}

vector<pair<int, int> > solve(state a) {
    vector<pair<int, int> > res;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (m % 2 == 0) {
                if (a.s[i][j] == 'U') {
                    //cout << "#" << i << " " << j << endl;
                    rec(a, res, i, j, 'L');
                    //a.write("\n");
                }
            } else {
                if (a.s[i][j] == 'L') {
                    //cout << "#" << i << " " << j << endl;
                    rec(a, res, i, j, 'U');
                    //a.write("\n");
                }
            }
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    st.read();
    fin.read();
    vector<pair<int, int> > ans1 = solve(st), ans2 = solve(fin);
    reverse(ans2.begin(), ans2.end());
    cout << ans1.size() + ans2.size() << endl;
    for (int i = 0; i < ans1.size(); ++i) {
        cout << ans1[i].first << " " << ans1[i].second << endl;
    }
    for (int i = 0; i < ans2.size(); ++i) {
        cout << ans2[i].first << " " << ans2[i].second << endl;
    }
    return 0;
}