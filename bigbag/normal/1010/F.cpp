#include <bits/stdc++.h>

using namespace std;

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

const int max_pw = 18;
const int max_n = 133333, mod = 998244353;

int bases[max_pw], rbases[max_pw], pws[max_n], rn[max_pw];
int rev_bits[max_pw][max_n];

int mul(int a, int b) {
    return (1LL * a * b) % mod;
}

int power(int a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b % 2 == 0) {
        return power(mul(a, a), b / 2);
    }
    return mul(a, power(a, b - 1));
}

int rev(int x) {
    return power(x, mod - 2);
}

int get_rev_bits(int len, int x) {
    int res = 0;
    while (len--) {
        res = res * 2 + x % 2;
        x /= 2;
    }
    return res;
}

void prec() {
    int n = 1 << (max_pw - 1), b;
    for (int i = 2; ; ++i) {
        if (power(i, n) == 1) {
            b = i;
            break;
        }
    }
    for (int i = max_pw - 1; i >= 0; --i) {
        bases[i] = b;
        rbases[i] = rev(b);
        b = mul(b, b);
        rn[i] = rev(n);
        n /= 2;
    }
    pws[1] = 0;
    for (int i = 1; i < max_pw; ++i) {
        for (int j = (1 << (i - 1)) + 1; j <= (1 << i) && j < max_n; ++j) {
            pws[j] = i;
        }
    }
    for (int len = 1; len < max_pw; ++len) {
        for (int i = 0; i < max_n; ++i) {
            rev_bits[len][i] = get_rev_bits(len, i);
        }
    }
}

vector<int> fft(const vector<int> &v, int steps, int bases[]) {
    vector<int> res(v.size());
    for (int i = 0; i < v.size(); ++i) {
        res[rev_bits[steps][i]] = v[i];
    }
    for (int i = 0; i < steps; ++i) {
        int step = 1 << i;
        int base = bases[i + 1];
        for (int i = 0; i < res.size(); i += 2 * step) {
            int b = 1;
            for (int j = i; j < i + step; ++j) {
                int x = (res[j] + mul(b, res[j + step])) % mod;
                int y = (res[j] + mod - mul(b, res[j + step])) % mod;
                res[j] = x;
                res[j + step] = y;
                b = mul(b, base);
            }
        }
    }
    return res;
}

vector<int> fast_multiply(vector<int> a, vector<int> b) {
    int len = a.size() + b.size() - 1;
    int pw = pws[len];
    int n = 1 << pw;
    while (a.size() < n) {
        a.push_back(0);
    }
    while (b.size() < n) {
        b.push_back(0);
    }
    a = fft(a, pw, bases);
    b = fft(b, pw, bases);
    for (int i = 0; i < n; ++i) {
        a[i] = mul(a[i], b[i]);
    }
    a = fft(a, pw, rbases);
    for (int i = 0; i < len; ++i) {
        a[i] = mul(a[i], rn[pw]);
    }
    a.erase(a.begin() + len, a.end());
    return a;
}

int n, where[max_n], sz[max_n];
long long x;
vector<vector<int>> res[max_n];
vector<int> g[max_n];

vector<int> add(const vector<int> &a, const vector<int> &b) {
    vector<int> res(max(a.size(), b.size()));
    for (int i = 0; i < res.size(); ++i) {
        if (i < a.size()) {
            res[i] += a[i];
        }
        if (i < b.size()) {
            res[i] += b[i];
        }
        res[i] %= mod;
    }
    return res;
}

vector<int> multiply(const vector<int> &a, const vector<int> &b) {
    if (min(a.size(), b.size()) > 10) {
        return fast_multiply(a, b);
    }
    vector<int> res(a.size() + b.size() - 1);
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            res[i + j] += mul(a[i], b[j]);
            res[i + j] %= mod;
        }
    }
    return res;
}

pair<vector<int>, vector<int>> calc(const vector<vector<int>> &v) {
    pair<vector<int>, vector<int>> res;
    if (v.size() == 1) {
        res.first = v[0];
        res.second = v[0];
        ++res.first[0];
        res.first[0] %= mod;
        return res;
    }
    int mid = v.size() / 2;
    vector<vector<int>> l(v.begin(), v.begin() + mid), r(v.begin() + mid, v.end());
    pair<vector<int>, vector<int>> a = calc(l);
    pair<vector<int>, vector<int>> b = calc(r);
    res.second = multiply(a.second, b.second);
    a.first[0] += mod - 1;
    a.first[0] %= mod;
    res.first = add(multiply(a.first, b.second), b.first);
    return res;
}

void dfs(int v, int p) {
    sz[v] = 1;
    vector<int> real_g;
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v);
            real_g.push_back(to);
            sz[v] += sz[to];
        }
    }
    g[v] = real_g;
}

void rec(int v) {
    for (int to : g[v]) {
        rec(to);
    }
    if (g[v].size() == 0) {
        where[v] = v;
        res[v].push_back({0, 1});
    } else if (g[v].size() == 1) {
        where[v] = where[g[v][0]];
        res[where[v]].push_back({0, 1});
    } else {
        if (sz[g[v][0]] < sz[g[v][1]]) {
            swap(g[v][0], g[v][1]);
        }
        where[v] = where[g[v][0]];
        vector<int> second = calc(res[where[g[v][1]]]).first;
        second.push_back(0);
        for (int i = second.size() - 1; i > 0; --i) {
            second[i] = second[i - 1];
        }
        second[0] = 0;
        res[where[v]].push_back(second);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    prec();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    rec(1);
    vector<int> cnt = calc(res[where[1]]).first;
    int c_n_k = 1, ans = 0;
    for (int i = 1; i < cnt.size(); ++i) {
        ans += mul(c_n_k, cnt[i]);
        ans %= mod;
        c_n_k = mul(c_n_k, (x + i) % mod);
        c_n_k = mul(c_n_k, rev(i));
    }
    cout << ans << "\n";
    return 0;
}