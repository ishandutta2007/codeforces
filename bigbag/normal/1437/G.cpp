#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

const int small = 755;

void get_z_function(const string &s, int z[]) {
    z[0] = 0;
    int l = 0, r = 0;
    for (int i = 1; i < s.length(); ++i) {
        z[i] = 0;
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (i + z[i] < s.length() && s[i + z[i]] == s[z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
}

int z[2 * max_n];

int n, m;
int tp[max_n], id[max_n], x[max_n], ans[max_n];
string a[max_n], b[max_n];

int first, nxt[max_n][26], last[max_n], cur_val[max_n], mx_val[max_n];
multiset<int> vals[max_n];

int add(const string &s) {
    int v = 0;
    for (char c : s) {
        if (nxt[v][c - 'a'] == 0) {
            nxt[v][c - 'a'] = ++first;
        }
        v = nxt[v][c - 'a'];
    }
    return v;
}

void update_val(int i, int x) {
    vals[last[i]].erase(vals[last[i]].find(cur_val[i]));
    cur_val[i] = x;
    vals[last[i]].insert(cur_val[i]);
    mx_val[last[i]] = *vals[last[i]].rbegin();
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(mx_val, -1, sizeof(mx_val));
    scanf("%d%d", &n, &m);
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        a[i] = read();
        if (a[i].length() < small) {
            last[i] = add(a[i]);
            vals[last[i]].insert(cur_val[i]);
            mx_val[last[i]] = 0;
        }
    }
    string t;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &tp[i]);
        if (tp[i] == 1) {
            scanf("%d%d", &id[i], &x[i]);
            --id[i];
            if (a[id[i]].length() < small) {
                update_val(id[i], x[i]);
            }
        } else {
            b[i] = read();
            ans[i] = -1;
            for (int j = 0; j < b[i].length(); ++j) {
                int v = 0;
                for (int k = j; k < b[i].length(); ++k) {
                    v = nxt[v][b[i][k] - 'a'];
                    if (!v) {
                        break;
                    }
                    ans[i] = max(ans[i], mx_val[v]);
                }
            }
            if (b[i].length() >= small) {
                v.push_back({i, t.length()});
                t += b[i];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i].length() >= small) {
            get_z_function(a[i] + t, z);
            int val = 0, pos = 0;
            for (auto p : v) {
                while (pos < p.first) {
                    if (tp[pos] == 1 && id[pos] == i) {
                        val = x[pos];
                    }
                    ++pos;
                }
                const int id = p.first;
                bool ok = 0;
                for (int j = 0; j + a[i].length() <= b[id].length(); ++j) {
                    if (z[a[i].length() + p.second + j] >= a[i].length()) {
                        ok = 1;
                        break;
                    }
                }
                if (ok) {
                    ans[id] = max(ans[id], val);
                }
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        if (tp[i] == 2) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}