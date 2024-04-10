#include <bits/stdc++.h>

using namespace std;

const long long inf = 1000111222000111222LL;
const int infI = 1000111222;

bool sort_by_k = true;

struct line {
    long long k;
    long long b;
    mutable long long x;
    line(long long k, long long b, long long x = 0): k(k), b(b), x(x) {
    }
    long long value(long long x) const {
        return k * x + b;
    }
    bool operator < (const line &l) const {
        return sort_by_k ? (k > l.k || k == l.k && b > l.b) : (x < l.x);
    }
};

long long intersection(const line &l1, const line &l2) {
    long long a = l2.b - l1.b;
    long long b = l1.k - l2.k;
    return a / b - ((a ^ b) < 0 && a % b);
}

struct line_container : set<line> {
    line_container() {
    }
    bool bad(iterator it, iterator nxt) {
        if (nxt == end()) {
            it->x = infI;
            return false;
        }
        it->x = intersection(*it, *nxt);
        return it->x >= nxt->x;
    }
    void add(const line &l) {
        auto ins = insert(l);
        if (!ins.second) {
            return;
        }
        iterator it = ins.first;
        iterator nxt = it;
        nxt++;
        if (nxt != end()) {
            if (it->k == nxt->k) {
                erase(it);
                return;
            }
            if (it != begin()) {
                iterator prev = it;
                --prev;
                if (prev->k != it->k && intersection(*prev, *it) >= intersection(*prev, *nxt)) {
                    erase(it);
                    return;
                }
            }
            while (bad(it, nxt)) {
                nxt = erase(nxt);
            }
        } else {
            it->x = infI;
        }
        if (it == begin()) {
            return;
        }
        iterator prev = it;
        --prev;
        while (it != begin()) {
            prev = it;
            --prev;
            if (prev->k == it->k) {
                erase(prev);
                continue;
            }
            bad(prev, it);
            if (prev == begin()) {
                break;
            }
            iterator prev2 = prev;
            --prev2;
            if (bad(prev2, prev)) {
                erase(prev);
            } else {
                break;
            }
        }
    }
    long long get_min(long long x) {
        if (empty()) {
            return infI;
        }
        sort_by_k = false;
        line best = *lower_bound(line(0, 0, x));
        sort_by_k = true;
        return best.value(x);
    }
};

const int max_n = 500555;

int n, sz[max_n];
long long best[max_n];
vector<int> g[max_n];
long long mn = inf;

long long f(int x) {
    return 1LL * x * (x + 1) / 2;
}

void dfs(int v, int p) {
    sz[v] = 1;
    best[v] = 0;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v);
        sz[v] += sz[to];
    }
    best[v] = f(sz[v] - 1);
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        best[v] = min(best[v], f(sz[v] - 1 - sz[to]) + best[to]);
        mn = min(mn, f(n - 1 - sz[to]) + best[to]);
    }
    //cout << v << ": " << best[v] + f(n - sz[v]) << endl;
    line_container lc;
    bool ok = false;
    int S = n - 1;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        if (ok) {
            long long res = 2LL * best[to] + 1LL * sz[to] * sz[to] - 2LL * sz[to] * S;
            res += S - sz[to];
            res += 1LL * S * S;
            res += lc.get_min(sz[to]);
            assert(res % 2 == 0);
            res /= 2;
            mn = min(mn, res);
        }
        ok = true;
        int k = 2LL * sz[to];
        long long b = 1LL * sz[to] * sz[to] + 2LL * best[to] - 2LL * sz[to] * S - sz[to];
        lc.add({k, b});
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    long long ans = 1LL * n * (n - 1);
    //cout << mn << endl;
    ans -= mn;
    printf("%I64d\n", ans);
    return 0;
}