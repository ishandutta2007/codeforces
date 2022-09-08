#include <bits/stdc++.h>

using namespace std;

const int max_n = 55, inf = 1000111222;
const int mod = 998244353;

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int power(int x, int y) {
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        return power(mul(x, x), y / 2);
    }
    return mul(x, power(x, y - 1));
}

int inv(int x) {
    return power(x, mod - 2);
}

int n, t, x[max_n], y[max_n];
vector<int> xs, ys;
multiset<int> q;

int add(int x, int len) {
    auto it = q.insert(x);
    int l = x;
    if (it != q.begin()) {
        --it;
        l = max(*it + len, x);
        ++it;
    }
    ++it;
    int r = x + len;
    if (it != q.end()) {
        r = min(r, *it);
    }
    return max(0, r - l);
}

int del(int x, int len) {
    q.erase(q.find(x));
    int res = add(x, len);
    q.erase(q.find(x));
    return res;
}

int f(int t) {
    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < n; ++i) {
        v.push_back({x[i] - t, {0, y[i]}});
        v.push_back({x[i] + t + 1, {1, y[i]}});
    }
    sort(v.begin(), v.end());
    int res = 0, cur = 0;
    for (int i = 0; i < v.size(); ) {
        int pos = i;
        while (i < v.size() && v[pos].first == v[i].first) {
            if (v[i].second.first == 0) {
                cur += add(v[i].second.second, 2 * t + 1);
            } else {
                cur -= del(v[i].second.second, 2 * t + 1);
            }
            ++i;
        }
        if (i < v.size()) {
            //cout << "[" << v[pos].first << " " << v[i].first << "): " << cur << endl;
            res += mul(cur, v[i].first - v[pos].first);
            res %= mod;
        }
    }
    //cout << t << ": " << res << endl;
    return res;
}

int triv(int t) {
    int res = mul(t, f(t));
    for (int i = 0; i < t; ++i) {
        res += mod - f(i);
        res %= mod;
    }
    return res;
}

const int max_p = 4;

struct interpolation {
    int x[max_p], y[max_p];
    int rev[max_p];

    interpolation() {
        for (int i = 1; i < max_p; ++i) {
            rev[i] = inv(i);
        }
    }

    int interpolate(int X) const {
        int res = 0;
        for (int i = 0; i < max_p; ++i) {
            int add = y[i];
            for (int j = 0; j < max_p; ++j) {
                if (i != j) {
                    add = mul(add, X - x[j]);
                    add = mul(add, rev[abs(x[i] - x[j])]);
                    if (x[i] < x[j]) {
                        add = mod - add;
                    }
                }
            }
            res += add;
            res %= mod;
        }
        return res;
    }
};

int solve(int t) {
    vector<int> all;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int d = max(abs(x[i] - x[j]), abs(y[i] - y[j]));
            all.push_back((d + 1) / 2);
        }
    }
    all.push_back(0);
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    while (!all.empty() && all.back() >= t) {
        all.pop_back();
    }
    all.push_back(t);
    int res = 0;
    interpolation inter;
    for (int i = 0; i + 1 < all.size(); ++i) {
        int l = all[i], r = all[i + 1];
        if (r - l < max_p + 1) {
            for (int j = l; j < r; ++j) {
                res += f(j);
                res %= mod;
            }
        } else {
            int cur = 0;
            for (int j = l; j < l + max_p; ++j) {
                cur += f(j);
                cur %= mod;
                inter.x[j - l] = j;
                inter.y[j - l] = cur;
            }
            res += inter.interpolate(r - 1);
            res %= mod;
        }
    }
    res = (mul(t, f(t)) + mod - res) % mod;
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    cout << solve(t) << endl;
    return 0;
}