/**
 *  created: 21/12/2020, 16:06:41
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;
const int max_m = 100111;

char buf[max_m];

string read() {
    scanf("%s", buf);
    return buf;
}

int t, n, m;
int cnt[222];

vector<int> inv(const vector<int> &v) {
    vector<int> res(v.size());
    for (int i = 0; i < v.size(); ++i) {
        res[v[i]] = i;
    }
    return res;
}

vector<vector<int>> op(vector<vector<int>> v, char c) {
    if (c == 'I') {
        for (int i = 0; i < v.size(); ++i) {
            v[i] = inv(v[i]);
        }
    } else if (c == 'C') {
        for (int i = 0; i < v.size(); ++i) {
            vector<int> a;
            for (int j = 0; j < v.size(); ++j) {
                a.push_back(v[j][i]);
            }
            a = inv(a);
            for (int j = 0; j < v.size(); ++j) {
                v[j][i] = a[j];
            }
        }
    } else if (c == 'T') {
        auto res = v;
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < v.size(); ++j) {
                res[i][j] = v[j][i];
            }
        }
        v = res;
    }
    return v;
}

void norm(int &x) {
    x %= n;
    x += n;
    x %= n;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        vector<vector<int>> a(n, vector<int> (n));
        for (auto &v : a) {
            for (int &x : v) {
                scanf("%d", &x);
                --x;
            }
        }
        string s = read(), ops;
        memset(cnt, 0, sizeof(cnt));
        int num = 0;
        for (char c : s) {
            if (c == 'I' || c == 'C') {
                if (ops.empty() || ops.back() != c) {
                    ops += c;
                } else {
                    ops.pop_back();
                }
            }
            if (c == 'I') {
                swap(cnt['L'], cnt['-']);
                swap(cnt['R'], cnt['+']);
            } else if (c == 'C') {
                swap(cnt['U'], cnt['-']);
                swap(cnt['D'], cnt['+']);
            } else {
                ++cnt[c];
            }
        }
        int t = (ops.length() / 3);
        if (t % 2) {
            a = op(a, 'T');
        }
        ops = ops.substr(t * 3);
        for (char c : ops) {
            a = op(a, c);
        }
        int add = cnt['+'] - cnt['-'], dx = cnt['U'] - cnt['D'], dy = cnt['L'] - cnt['R'];
        norm(add);
        norm(dx);
        norm(dy);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = a[(i + dx) % n][(j + dy) % n];
                x += add;
                x %= n;
                printf("%d ", x + 1);
            }
            puts("");
        }
    }
    return 0;
}