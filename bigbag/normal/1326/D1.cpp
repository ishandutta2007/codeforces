#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;
const int max_c = 26;

struct palindrom_tree {
    int nxt[max_n][max_c];
    int suffix_link[max_n], len[max_n];
    int cur, first;
    vector<int> v;

    palindrom_tree() {
        first = max_n;
        init();
    }

    void init() {
        for (int i = 0; i < first; ++i) {
            len[i] = suffix_link[i] = 0;
            memset(nxt[i], 0, sizeof(nxt[i]));
        }
        len[0] = 0;
        len[1] = -1;
        suffix_link[0] = 1;
        suffix_link[1] = 1;
        cur = 0;
        first = 2;
        //v = {-1};
        v.clear();
        v.push_back(-1);
    }

    int get_link(int pos) const {
        while (v[v.size() - len[pos] - 2] != v.back()) {
            pos = suffix_link[pos];
        }
        return pos;
    }

    void add(int c) {
        v.push_back(c);
        cur = get_link(cur);
        if (!nxt[cur][c]) {
            nxt[cur][c] = first;
            len[first] = len[cur] + 2;
            if (len[first] == 1) {
                suffix_link[first] = 0;
            } else {
                suffix_link[first] = nxt[get_link(suffix_link[cur])][c];
            }
            ++first;
        }
        cur = nxt[cur][c];
    }
};

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

int t, n, len[2][max_n];
palindrom_tree pt;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        string s = read();
        n = s.length();
        int l = 0, r = n - 1;
        while (l <= r) {
            if (l == r || s[l] != s[r]) {
                break;
            }
            ++l;
            --r;
        }
        int len_pr = l;
        int len_suf = l;
        int add_pr = 0, add_suf = 0;
        if (l <= r) {
            const int mx = r - l + 1;

            pt.init();
            for (int i = 0; i <= r; ++i) {
                pt.add(s[i] - 'a');
            }
            int cur = pt.cur;
            while (pt.len[cur] > mx) {
                cur = pt.suffix_link[cur];
            }
            add_suf = pt.len[cur];

            pt.init();
            for (int i = n - 1; i >= l; --i) {
                pt.add(s[i] - 'a');
            }
            cur = pt.cur;
            while (pt.len[cur] > mx) {
                cur = pt.suffix_link[cur];
            }
            add_pr = pt.len[cur];
        }

        if (add_pr > add_suf) {
            len_pr += add_pr;
        } else {
            len_suf += add_suf;
        }
        string res = s.substr(0, len_pr) + s.substr(n - len_suf);
        puts(res.c_str());
    }
    return 0;
}