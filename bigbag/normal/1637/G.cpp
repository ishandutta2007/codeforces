/**
 *  created: 12/02/2022, 18:21:10
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

vector<int> step(const vector<int> &v, int need) {
    for (int val = 0; val < 30; ++val) {
        for (int i = v.size() - 1; i >= 0; --i) {
            for (int j = v.size() - 1; j > i; --j) {
                //if (v[i] && v[j] && val == __builtin_ctz(v[i]) && __builtin_ctz(v[i]) == __builtin_ctz(v[j]) && v[i] + v[j] <= need) {
                if (v[i] && v[j] && val == __builtin_ctz(v[i]) && __builtin_ctz(v[i]) == __builtin_ctz(v[j]) && v[i] + v[j] <= need) {
                    assert(v[i] && v[j]);
                    vector<int> to = v;
                    to.erase(to.begin() + j);
                    to.erase(to.begin() + i);
                    to.push_back(v[i] + v[j]);
                    to.push_back(abs(v[i] - v[j]));
                    sort(to.begin(), to.end());
                    return to;
                }
            }
        }
    }
    if (v[0] == 0 && 1) {
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] && need % v[i] == 0 && v[i] < need) {
                vector<int> to = v;
                to[i] *= 2;
                sort(to.begin(), to.end());
                return to;
            }
        }
        assert(v[0] == 0 && v.back() == need);
        auto to = v;
        to[0] = need;
        sort(to.begin(), to.end());
        return to;
    }
    assert(false);
    /*assert(v[0] == 0 && v.back() == need);
    auto to = v;
    to[0] = need;
    sort(to.begin(), to.end());
    return to;*/
    return {};
}

vector<pair<int, int>> ops;
multiset<int> q, all[30];

void clr() {
    ops.clear();
    q.clear();
    for (int i = 0; i < 30; ++i) {
        all[i].clear();
    }
}

void del(int x) {
    q.erase(q.find(x));
    if (x) {
        all[__builtin_ctz(x)].erase(all[__builtin_ctz(x)].find(x));
    }
}

void add(int x) {
    q.insert(x);
    if (x) {
        all[__builtin_ctz(x)].insert(x);
    }
}

void proc(int x, int y) {
    ops.push_back({x, y});
    del(x);
    del(y);
    add(x + y);
    add(abs(x - y));
}

void ok(int n) {
    int ans = 1;
    while (ans < n) {
        ans *= 2;
    }
    clr();
    for (int i = 1; i <= n; ++i) {
        add(i);
    }
    while (true) {
        if (0) {
            for (int x : q) {
                cout << x << " ";
            }
            cout << endl;
        }
        if (*q.begin() == *q.rbegin()) {
            assert(*q.begin() == ans);
            return;
        }
        int x = -1, y = -1;
        for (int val = 0; val < 30; ++val) {
            if (all[val].size() >= 2 && *all[val].begin() + *next(all[val].begin()) <= ans) {
                //cout << "!! " << val << endl;
                auto it = all[val].upper_bound(ans / 2);
                --it;
                if (next(it) != all[val].end() && *it + *next(it) <= ans) {
                    x = *it;
                    it = all[val].upper_bound(ans - x);
                    --it;
                    y = *it;
                    break;
                } else {
                    assert(it != all[val].begin());
                    --it;
                    x = *it;
                    it = all[val].upper_bound(ans - x);
                    --it;
                    y = *it;
                    break;
                }
            }
        }
        if (x == -1) {
            assert(*q.begin() == 0);
            for (int val = 1; val < ans; val *= 2) {
                if (q.find(val) != q.end()) {
                    x = val;
                    break;
                }
            }
            if (x != -1) {
                proc(0, x);
                proc(x, x);
            } else {
                x = *q.rbegin();
                assert(x == ans);
                proc(0, x);
            }
        } else {
            proc(x, y);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    /*for (int n = 3; n <= 32; ++n) {
        cout << n << endl;
        solve(n);
        cout << endl;
        cout << endl;
    }*/
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n == 2) {
            cout << -1 << "\n";
            continue;
        }
        ok(n);
        cout << ops.size() << "\n";
        for (auto [x, y] : ops) {
            cout << x << " " << y << "\n";
        }
    }
    return 0;
}