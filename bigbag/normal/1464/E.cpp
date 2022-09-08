#include<bits/stdc++.h>

using namespace std;

const int mod = 998244353;

inline void dec(int &x, int y) {
    x -= y;
    if (x < 0) {
        x += mod;
    }
}

int mul(int x, int y) {
    return (1LL * x * y) % mod;
}

int power(int a, int b) {
    int res = 1 % mod;
    while (b) {
        if (b % 2) {
            res = mul(res, a);
        }
        b /= 2;
        a = mul(a, a);
    }
    return res;
}

int inv(int x) {
    return power(x, mod - 2);
}

vector<vector<int>> solve_equations_system(vector<vector<int>> a, vector<vector<int>> b) {
    const int n = a.size(), m = b[0].size();
    for (int i = 0; i < n; ++i) {
        int row = i;
        for (int j = i; j < n; ++j) {
            if (a[j][i]) {
                row = j;
            }
        }
        swap(a[i], a[row]);
        swap(b[i], b[row]);
        for (int j = i + 1; j < n; ++j) {
            int coef = mul(a[j][i], inv(a[i][i]));
            for (int k = 0; k < n; ++k) {
                dec(a[j][k], mul(a[i][k], coef));
            }
            for (int k = 0; k < m; ++k) {
                dec(b[j][k], mul(b[i][k], coef));
            }
        }
    }
    vector<vector<int>> ans(n, vector<int> (m));
    for (int i = n - 1; i >= 0; --i) {
        const int coef = inv(a[i][i]);
        for (int j = 0; j < m; ++j) {
            for (int k = i + 1; k < n; ++k) {
                dec(b[i][j], mul(ans[k][j], a[i][k]));
            }
            ans[i][j] = mul(b[i][j], coef);
        }
    }
    return ans;
}

vector<vector<double>> solve_equations_system(vector<vector<double>> a, vector<vector<double>> b) {
    const int n = a.size(), m = b[0].size();
    for (int i = 0; i < n; ++i) {
        int row = i;
        for (int j = i; j < n; ++j) {
            if (abs(a[j][i]) > abs(a[row][i])) {
                row = j;
            }
        }
        swap(a[i], a[row]);
        swap(b[i], b[row]);
        for (int j = i + 1; j < n; ++j) {
            auto coef = a[j][i] / a[i][i];
            for (int k = 0; k < n; ++k) {
                a[j][k] -= a[i][k] * coef;
            }
            for (int k = 0; k < m; ++k) {
                b[j][k] -= b[i][k] * coef;
            }
        }
    }
    auto ans = b;
    for (int i = n - 1; i >= 0; --i) {
        auto coef = 1 / a[i][i];
        for (int j = 0; j < m; ++j) {
            for (int k = i + 1; k < n; ++k) {
                b[i][j] -= ans[k][j] * a[i][k];
            }
            ans[i][j] = b[i][j], coef;
        }
    }
    return ans;
}

template<typename T>
vector<vector<T>> get_inverse_matrix(const vector<vector<T>> &a) {
    assert(!a.empty() && a.size() == a[0].size());
    vector<vector<T>> b(a.size(), vector<T> (a.size()));
    for (int i = 0; i < b.size(); ++i) {
        b[i][i] = 1;
    }
    return solve_equations_system(a, b);
}

string str_fraq(int x, int n = 200) {
    stringstream res;
    pair<int, int> best(x, 1);
    for (int j = 1; j < n; ++j) {
        best = min(best, {mul(x, j), j});
    }
    res << best.first << "/" << best.second;
    return res.str();
}

const int max_n = 100111;

int n, m, dp[max_n], cnt[max_n], last[max_n], curt;
vector<int> g[max_n];

void calc_dp(int v) {
    for (int to : g[v]) {
        if (dp[to] == -1) {
            calc_dp(to);
        }
    }
    ++curt;
    for (int to : g[v]) {
        last[dp[to]] = curt;
    }
    for (int i = 0; ; ++i) {
        if (last[i] != curt) {
            dp[v] = i;
            return;
        }
    }
}

int main() {
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
    }
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        calc_dp(i);
        ++cnt[dp[i]];
    }
    int mx = *max_element(dp, dp + n);
    int pw = 1;
    while (mx >= pw) {
        pw *= 2;
    }
    vector<vector<int>> a(pw, vector<int> (pw)), b(pw, vector<int> (1));
    b[0][0] = inv(n + 1);
    for (int i = 0; i < pw; ++i) {
        a[i][i] = 1;
        for (int j = 0; j < pw; ++j) {
            dec(a[i][j], mul(cnt[i ^ j], b[0][0]));
        }
    }
    auto ans = solve_equations_system(a, b);
    cout << (1 + mod - ans[0][0]) % mod << endl;
    return 0;
}