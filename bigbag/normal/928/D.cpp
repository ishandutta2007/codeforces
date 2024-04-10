#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

int n, ans, total, nxt[max_n][26], cnt[max_n], parent[max_n];
bool is_root[max_n];
string s;
vector<string> v;

void add_vertex(int cur, int to) {
    ++total;
    nxt[cur][to] = total;
    parent[total] = cur;
}

void add(const string &s) {
    int cur = 0;
    for (int i = 0; i < s.length(); ) {
        if (cnt[cur] == 1) {
            int ki = i, kcur = cur;
            while (i < s.length() && nxt[cur][s[i] - 'a']) {
                cur = nxt[cur][s[i] - 'a'];
                ++i;
            }
            if (is_root[cur]) {
                ++ans;
                if (i == ki) {
                    add_vertex(cur, s[i] - 'a');
                    cur = nxt[cur][s[i] - 'a'];
                    ++i;
                }
            } else {
                cur = kcur;
                i = ki;
                while (i < s.length()) {
                    if (nxt[cur][s[i] - 'a'] == 0) {
                        add_vertex(cur, s[i] - 'a');
                    }
                    cur = nxt[cur][s[i] - 'a'];
                    ++i;
                    ++ans;
                }
                break;
            }
        } else {
            if (nxt[cur][s[i] - 'a'] == 0) {
                add_vertex(cur, s[i] - 'a');
            }
            cur = nxt[cur][s[i] - 'a'];
            ++i;
            ++ans;
        }
    }
    if (!is_root[cur]) {
        is_root[cur] = true;
        while (cur) {
            ++cnt[cur];
            cur = parent[cur];
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (getline(cin, s)) {
        s += ".";
        n = s.length();
        ans += n;
        string cur = "";
        for (int i = 0; i < n; ++i) {
            if ('a' <= s[i] && s[i] <= 'z') {
                cur += s[i];
            } else if (cur != "") {
                v.push_back(cur);
                cur = "";
            }
        }
    }
    for (int i = 0; i < v.size(); ++i) {
        ans -= v[i].length();
        add(v[i]);
    }
    cout << ans << "\n";
    return 0;
}