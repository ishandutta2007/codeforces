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

const int max_n = 111, inf = 1111111111;

struct state {
    long long w, h, border, spacing;
    bool vb, hb;
    string name;
    vector<string> v;
    state() {
        v.clear();
    }
    state(long long w, long long h, long long border, long long spacing, bool hb, bool vb, string name) : w(w), h(h), border(border), spacing(spacing), hb(hb), vb(vb), name(name) {
        v.clear();
    }
    bool operator < (const state &q) const {
        return name < q.name;
    }
};

long long n;
map<string, state> m;
set<string> qq;
map<state, pair<long long, long long> > res;

pair<long long, long long> dfs(state q) {
    if (res.count(q)) {
        return res[q];
    }
    if (q.vb) {
        long long w = 0, h = (q.v.size() - 1) * q.spacing;
        //cout << "----------------------------------------Vbox" << endl;
        for (int i = 0; i < q.v.size(); ++i) {
            pair<long long, long long> p = dfs(m[q.v[i]]);
            //cout << p.first << " " << p.second << endl;
            w = max(w, p.first);
            h += p.second;
        }
        //cout << q.v.size() << endl;
        //cout << "----------------------------------------Vbox" << endl;
        w += 2 * q.border;
        h += 2 * q.border;
        //cout << w << " " << h << " " << q.v.size() << endl;
        if (q.v.size() == 0) {
            w = h = 0;
        }
        return res[q] = make_pair(w, h);
    } else if (q.hb) {
        long long w = (q.v.size() - 1) * q.spacing, h = 0;
        //cout << "----------------------------------------HBox" << endl;
        for (int i = 0; i < q.v.size(); ++i) {
            pair<long long, long long> p = dfs(m[q.v[i]]);
            //cout << p.first << " " << p.second << endl;
            w += p.first;
            h = max(h, p.second);
        }
        //cout << "----------------------------------------Hbox" << endl;
        w += 2 * q.border;
        h += 2 * q.border;
        //cout << "                    " << w << " " << h << " " << q.v.size() << endl;
        if (q.v.size() == 0) {
            w = h = 0;
        }
        return res[q] = make_pair(w, h);
    } else {
        return make_pair(q.w, q.h);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s, name = "";
        cin >> s;
        if (s == "Widget") {
            char c = '!';
            long long f = 0, w = 0, h = 0;
            while (c != ')') {
                cin >> c;
                if (c == '(') {
                    f = 1;
                } else if (c == ',') {
                    f = 2;
                } else if (c != ')') {
                    if (f == 0) {
                        name += c;
                    }
                    if (f == 2) {
                        h = h * 10 + c - '0';
                    }
                    if (f == 1) {
                        w = w * 10 + c - '0';
                    }
                }
            }
            qq.insert(name);
            m[name] = state(w, h, 0, 0, false, false, name);
        } else if (s == "VBox") {
            cin >> name;
            m[name] = state(0, 0, 0, 0, false, true, name);
            qq.insert(name);
        } else if (s == "HBox") {
            cin >> name;
            m[name] = state(0, 0, 0, 0, true, false, name);
            qq.insert(name);
        } else {
            char c = '!';
            long long f = 0, x = 0;
            string tp = "", name2 = "";
            for (int i = 0; i + 1 < s.length(); ++i) {
                char c = s[i];
                if (c == '.') {
                    f = 1;
                } else if (c == '(') {
                    f = 2;
                } else {
                    if (f == 0) {
                        name += c;
                    }
                    if (f == 1) {
                        tp += c;
                    }
                    if (f == 2) {
                        if (c >= '0' && c <= '9') {
                            x = x * 10 + c - '0';
                        } else {
                            name2 += c;
                        }
                    }
                }
            }
            //cout << "                             " << tp << endl;
            if (tp == "set_border") {
                m[name].border = x;
            }
            if (tp == "set_spacing") {
                m[name].spacing = x;
            }
            if (tp == "pack") {
                //cout << name << " -> " << name2 << endl;
                m[name].v.push_back(name2);
            }
        }
    }
    while (!qq.empty()) {
        string name = *qq.begin();
        qq.erase(name);
        pair<long long, long long> ans = dfs(m[name]);
        cout << name << " " << ans.first << " " << ans.second << endl;
    }
    return 0;
}