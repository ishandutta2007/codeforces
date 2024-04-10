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

const int max_n = 111111, inf = 1111111111;

struct event {
    int l, r, num, t;
    void read() {
        cin >> l >> r;
    }
    void write() {
        cout << l << " " << r << " " << t << endl;
    }
    bool operator < (const event &e) const {
        return l < e.l || l == e.l && t < e.t || l == e.l && t == e.t && r < e.r || l == e.l && t == e.t && r == e.r && num < e.num;
    }
};

int n, m, k[max_n], ans[max_n];
event a[max_n], b[max_n];
vector<event> v;
set<pair<int, int> > s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        a[i].read();
        a[i].num = i;
        a[i].t = 2;
        v.push_back(a[i]);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        b[i].read();
        cin >> k[i];
        b[i].num = i;
        b[i].t = 1;
        v.push_back(b[i]);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
        //v[i].write();
        if (v[i].t == 1) {
            s.insert(make_pair(v[i].r, v[i].num));
        } else {
            if (s.size()) {
                pair<int, int> p = *s.rbegin();
                if (p.first >= v[i].r) {
                    p = *s.lower_bound(make_pair(v[i].r, -inf));
                    --k[p.second];
                    //cout << "+ " << b[p.second].k << endl;
                    //cout << v[i].num << endl;
                    ans[v[i].num] = p.second + 1;
                    if (k[p.second] == 0) {
                        s.erase(p);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (ans[i] == 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}