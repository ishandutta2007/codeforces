#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, n;

vector<pair<int, int>> factorize(int n) {
    vector<pair<int, int>> res;
    for (int x = 2; x * x <= n; ++x) {
        int cnt = 0;
        while (n % x == 0) {
            n /= x;
            ++cnt;
        }
        if (cnt) {
            res.push_back({x, cnt});
        }
    }
    if (n > 1) {
        res.push_back({n, 1});
    }
    return res;
}

void write(const vector<int> &v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << "\n";
}

void solve(const vector<int> &v, const vector<pair<int, int>> &f, int x) {
    vector<int> used(v.size()), ans;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == x) {
            used[i] = 1;
        }
    }
    ans.push_back(x);
    for (int i = 0; i < f.size(); ++i) {
        int y = f[i].first;
        if (i + 1 < f.size()) {
            y *= f[i + 1].first;
        }
        for (int j = 0; j < v.size(); ++j) {
            if (v[j] == y) {
                used[j] = 1;
            }
        }
        for (int j = 0; j < v.size(); ++j) {
            if (!used[j] && v[j] % f[i].first == 0) {
                ans.push_back(v[j]);
                used[j] = 1;
            }
        }
        ans.push_back(y);
    }
    write(ans);
    puts("0");
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> v;
        for (int x = 1; x * x <= n; ++x) {
            if (n % x == 0) {
                if (x != 1) {
                    v.push_back(x);
                }
                if (x * x != n) {
                    v.push_back(n / x);
                }
            }
        }
        vector<pair<int, int>> f = factorize(n);
        if (f.size() == 1) {
            write(v);
            puts("0");
        } else if (f.size() == 2) {
            if (f[0].second * f[1].second == 1) {
                write(v);
                puts("1");
            } else {
                if (f[0].second == 1) {
                    swap(f[0], f[1]);
                }
                int x = f[0].first * f[0].first * f[1].first;
                solve(v, f, x);
            }
        } else {
            int x = f[0].first * f.back().first;
            solve(v, f, x);
        }
    }
    return 0;
}