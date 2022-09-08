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

const int max_n = 200111, mod = 1000000007, inf = 1000111222;

int power(int a, int b, int mod) {
    if (b == 0) {
        return 1 % mod;
    }
    if (b % 2 == 0) {
        return power((1LL * a * a) % mod, b / 2, mod);
    }
    return (1LL * a * power(a, b - 1, mod)) % mod;
}

int f[max_n], rf[max_n];

void get_all_f() {
    f[0] = rf[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        f[i] = (1LL * i * f[i - 1]) % mod;
        rf[i] = power(f[i], mod - 2, mod);
    }
}

int get_c(int n, int k) {
    if (n < k) {
        return 0;
    }
    int res = (1LL * f[n] * rf[k]) % mod;
    return (1LL * res * rf[n - k]) % mod;
}

int n, ans = 1, pw[max_n];
vector<pair<int, int> > v;

vector<pair<int, int> > proc(vector<pair<int, int> > v) {
    vector<pair<int, int> > res;
    sort(v.begin(), v.end());
    map<int, int> q;
    for (int i = 0; i < v.size(); ++i) {
        ++q[v[i].second];
    }
    for (int i = 0; i < v.size(); ) {
        int f = 1;
        int pos = i;
        while (pos < v.size() && v[i].first == v[pos].first) {
            if (q[v[pos].second] > 1) {
                f = 0;
            }
            ++pos;
        }
        if (f == 0) {
            for (int j = i; j < pos; ++j) {
                res.push_back(v[j]);
            }
        } else {
            int x = (pw[pos - i + 1] + mod - 1) % mod;
            ans = (1LL * ans * x) % mod;
        }
        i = pos;
    }
    return res;
}

set<int> x, y;
set<pair<int, int> > xp, yp;

int dfs(pair<int, int> p) {
    x.insert(p.first);
    y.insert(p.second);
    int res = 1;
    pair<int, int> pr = p;
    swap(pr.first, pr.second);
    xp.erase(p);
    yp.erase(pr);
    while (xp.size()) {
        auto it = xp.lower_bound({p.first, -inf});
        if (it != xp.end() && it->first == p.first) {
            res += dfs(*it);
        } else {
            break;
        }
    }
    while (yp.size()) {
        auto it = yp.lower_bound({pr.first, -inf});
        if (it != yp.end() && it->first == pr.first) {
            auto to = *it;
            swap(to.first, to.second);
            res += dfs(to);
        } else {
            break;
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_f();
    pw[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        pw[i] = (1LL * pw[i - 1] * 2) % mod;
    }
    scanf("%d", &n);
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &v[i].first, &v[i].second);
    }
    v = proc(v);
    for (int i = 0; i < v.size(); ++i) {
        swap(v[i].first, v[i].second);
    }
    v = proc(v);
    for (int i = 0; i < v.size(); ++i) {
        xp.insert({v[i].first, v[i].second});
        yp.insert({v[i].second, v[i].first});
    }
    while (!xp.empty()) {
        x.clear();
        y.clear();
        int cnt = dfs(*xp.begin());
        int d = x.size() + y.size();
        d -= cnt;
        d = max(d, 0);
        if (d > 1) {
            exit(228);
        }
        cnt = 0;
        if (d) {
            cnt = 1;
        }
        int k = (pw[x.size() + y.size()] + mod - cnt) % mod;
        ans = (1LL * ans * k) % mod;
    }
    printf("%d\n", ans);
    return 0;
}