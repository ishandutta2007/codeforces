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

const int max_n = 1111, inf = 1111111111;

int get_type_orj(string s) {
    if (s == "weapon") return 0;
    if (s == "armor") return 1;
    if (s == "orb") return 2;
}

int get_type_res(string s) {
    if (s == "gladiator") return 0;
    if (s == "sentry") return 1;
    if (s == "physician") return 2;
}

int get_x(int tp, int a, int b, int c) {
    if (tp == 0) return a;
    if (tp == 1) return b;
    if (tp == 2) return c;
}

map<string, int> pl, TP;
map<string, vector<string> > A;

struct orj {
    string name;
    int tp, x, sz;
    void read() {
        string cl;
        int a, b, c;
        cin >> name >> cl >> a >> b >> c >> sz;
        tp = get_type_orj(cl);
        x = get_x(tp, a, b, c);
        TP[name] = tp;
    }
};

struct res {
    string name, home;
    int tp, x;
    void read() {
        string cl;
        cin >> name >> cl >> x >> home;
        tp = get_type_res(cl);
        if (tp == TP[home]) {
            pl[home] += x;
        }
        A[home].push_back(name);
    }
    bool operator < (const res &r) const {
        return x > r.x;
    }
};

int n, k, sumsz, sum[3][max_n], ans[3];
set<string> all;
vector<string> Q;
vector<orj> a[3];
vector<res> b[3];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        orj o;
        o.read();
        a[o.tp].push_back(o);
        sumsz += o.sz;
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        res r;
        r.read();
        b[r.tp].push_back(r);
    }
    if (k == sumsz) {
        string ans[3];
        for (int tp = 0; tp < 3; ++tp) {
            int mx = -1;
            for (int i = 0; i < a[tp].size(); ++i) {
                if (mx < a[tp][i].x + pl[a[tp][i].name]) {
                    mx = a[tp][i].x + pl[a[tp][i].name];
                    ans[tp] = a[tp][i].name;
                }
            }
            vector<string> v = A[ans[tp]];
            cout << ans[tp] << " " << v.size() << " ";
            for (int i = 0; i < v.size(); ++i) {
                cout << v[i] << " ";
            }
            cout << endl;
        }
        return 0;
    }
    sort(b[0].begin(), b[0].end());
    sort(b[1].begin(), b[1].end());
    sort(b[2].begin(), b[2].end());
    for (int tp = 0; tp < 3; ++tp) {
        if (b[tp].size() == 0) {
            continue;
        }
        sum[tp][0] = b[tp][0].x;
        for (int i = 1; i < b[tp].size(); ++i) {
            sum[tp][i] = b[tp][i].x + sum[tp][i - 1];
        }
        for (int i = b[tp].size(); i < max_n; ++i) {
            sum[tp][i] = sum[tp][i - 1];
        }
    }
    for (int tp = 0; tp < 3; ++tp) {
        int mx = -1;
        for (int i = 0; i < a[tp].size(); ++i) {
            int Res = a[tp][i].x + sum[tp][a[tp][i].sz - 1];
            if (mx < Res) {
                mx = Res;
                ans[tp] = i;
            }
        }
        for (int i = 0; i < a[tp][ans[tp]].sz && i < b[tp].size(); ++i) {
            all.insert(b[tp][i].name);
        }
    }
    for (int tp = 0; tp < 3; ++tp) {
        vector<string> v, q;
        for (int i = 0; i < a[tp][ans[tp]].sz && i < b[tp].size(); ++i) {
            v.push_back(b[tp][i].name);
        }
        q = A[a[tp][ans[tp]].name];
        for (int i = 0; i < q.size(); ++i) {
            if (!all.count(q[i])) {
                if (a[tp][ans[tp]].sz == v.size()) {
                    Q.push_back(q[i]);
                } else {
                    v.push_back(q[i]);
                }
            }
        }
        while (Q.size() && v.size() < a[tp][ans[tp]].sz) {
            v.push_back(Q.back());
            Q.pop_back();
        }
        cout << a[tp][ans[tp]].name << " " << v.size() << " ";
        for (int i = 0; i < v.size(); ++i) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}