#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222;

bool is_prime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int next_prime(int number) {
    for (int i = number + 1; ; ++i) {
        if (is_prime(i)) {
            return i;
        }
    }
}

const int seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 generator(0 * seed);

int rnd() {
    return generator() >> 1;
}

int rnd(int r) {
    return rnd() % r;
}

int rnd(int l, int r) {
    return l + rnd(r - l + 1);
}

const int p1 = next_prime(300 + rnd(5000));
const int p2 = next_prime(300 + rnd(5000));
const int mod = next_prime(1000000000 + rnd(100000));

long long pw1[max_n];
int pw2[max_n];

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

const int max_k = 10;

int n, m, k;
vector<int> all[max_k];
vector<pair<int, int>> g[max_n];
long long need1, need2;

void init() {
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        pw1[i] = pw1[i - 1] * p1;
        pw2[i] = mul(pw2[i - 1], p2);
    }
    for (int i = 0; i < n; ++i) {
        need1 += pw1[i];
        need2 += pw2[i];
    }
    need2 %= mod;
}

int c[max_k], used[max_n];
vector<pair<long long, int>> all1, all2;
int ans;

void proc(int pos, int to, long long h1, int h2, vector<pair<long long, int>> &v) {
    if (pos == to) {
        v.push_back({h1, h2});
        return;
    }
    for (int i = 0; i < pos; ++i) {
        c[pos] = i;
        bool ok = true;
        long long nh1 = h1, nh2 = h2;
        for (int v : all[pos]) {
            nh1 += pw1[g[v][c[pos]].second];
            nh2 += pw2[g[v][c[pos]].second];
            ++used[g[v][c[pos]].second];
            ok &= used[g[v][c[pos]].second] == 1;
        }
        if (ok) {
            nh2 %= mod;
            proc(pos + 1, to, nh1, nh2, v);
        }
        for (int v : all[pos]) {
            --used[g[v][c[pos]].second];
        }
    }
}

const int magic = 6;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    while (m--) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        --u;
        --v;
        g[u].push_back({w, v});
    }
    for (int i = 0; i < n; ++i) {
        sort(g[i].begin(), g[i].end());
        all[g[i].size()].push_back(i);
    }
    init();

    proc(1, min(magic, k) + 1, 0, 0, all1);
    proc(magic + 1, max(magic, k) + 1, 0, 0, all2);
    for (const auto &p1 : all1) {
        for (const auto &p2 : all2) {
            long long h1 = p1.first + p2.first;
            int h2 = (p1.second + p2.second) % mod;
            if (h1 == need1) {//} && h2 == need2) {
                ++ans;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}