/**
 *  created: 25/05/2022, 21:55:58
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

template<typename T>
ostream& operator << (ostream &os, const vector<T> &v) {
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        if (i) {
            os << " ";
        }
        os << v[i];
    }
    os << "]";
    return os;
}

int func(vector<int> p, vector<int> q) {
    int tot = 0;
    for (int i = 0; i < p.size(); ++i) {
        tot += abs(q[i] - p[q[(i + 1) % p.size()]]);
    }
    return tot;
}

vector<int> one(vector<int> a, const vector<int> &pos) {
    vector<int> res;
    int cur = a[0];
    while (res.size() != a.size()) {
        res.push_back(cur);
        cur = pos[cur];
    }
    return res;
}

vector<int> combine(vector<int> a, vector<int> b, int X, vector<int> POS) {
    vector<int> res;
    int pos = find(a.begin(), a.end(), X) - a.begin();
    for (int i = 0; i <= pos; ++i) {
        res.push_back(a[i]);
    }
    rotate(b.begin(), find(b.begin(), b.end(), POS[X + 1]), b.end());
    res.insert(res.end(), b.begin(), b.end());
    for (int i = pos + 1; i < a.size(); ++i) {
        res.push_back(a[i]);
    }
    return res;
}

vector<int> ok(vector<int> p) {
    vector<int> used(p.size()), POS(p.size());
    vector<vector<int>> cycles;
    for (int i = 0; i < p.size(); ++i) {
        POS[p[i]] = i;
    }
    for (int i = 0; i < p.size(); ++i) {
        if (!used[i]) {
            vector<int> cycle;
            int x = i;
            while (!used[x]) {
                cycle.push_back(x);
                used[x] = 1;
                x = p[x];
            }
            cycles.push_back(one(cycle, POS));
        }
    }
    while (cycles.size() > 1) {
        vector<int> a = cycles.back(), b;
        cycles.pop_back();
        vector<int> our(p.size());
        for (int x : a) {
            our[x] = 1;
        }
        int X = -1;
        for (int i = 0; i < cycles.size(); ++i) {
            int xx = -1, yy;
            for (int x : cycles[i]) {
                if (x && our[x - 1]) {
                    xx = x;
                    yy = x - 1;
                    break;
                }
                if (x + 1 < p.size() && our[x + 1]) {
                    xx = x;
                    yy = x + 1;
                    break;
                }
            }
            if (xx != -1) {
                swap(cycles[i], cycles.back());
                b = cycles.back();
                cycles.pop_back();
                if (xx < yy) {
                    swap(a, b);
                    swap(xx, yy);
                }
                X = yy;
                break;
            }
        }
        cycles.push_back(combine(a, b, X, POS));
        //cout << a << " " << b << ", X = " << X << ": " << cycles.back() << endl;
    }
    return cycles.back();
}

void solve(vector<int> p) {
    vector<int> q(p.size());
    iota(q.begin(), q.end(), 0);
    pair<int, vector<int>> res(inf, {});
    do {
        res = min(res, {func(p, q), q});
    } while (next_permutation(q.begin(), q.end()));
    vector<int> used(p.size());
    int c = 0;
    for (int i = 0; i < p.size(); ++i) {
        if (!used[i]) {
            int x = i;
            while (!used[x]) {
                used[x] = 1;
                x = p[x];
            }
            ++c;
        }
    }
    c = 2 * (c - 1);

    auto my = ok(p);
    cout << p << " -> " << res.second << ", score = " << res.first << "     " << c << "   " << my << endl;
    assert(res.first == c);
    assert(func(p, my) == c);
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (1) {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            vector<int> v(n);
            for (int &x : v) {
                cin >> x;
                --x;
            }
            auto ans = ok(v);
            for (int x : ans) {
                cout << x + 1 << " ";
            }
            cout << "\n";

        }
        return 0;
    }
    //cout << ok({0, 2, 1});
    //cout << ok({1, 2, 0, 3});
    for (int n = 2; n <= 7; ++n) {
        vector<int> v(n);
        iota(v.begin(), v.end(), 0);
        do {
            solve(v);
        } while (next_permutation(v.begin(), v.end()));
    }
    return 0;
}