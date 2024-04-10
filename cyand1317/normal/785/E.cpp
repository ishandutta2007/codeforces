#include <cstdio>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>
typedef long long int64;
static const int MAXN = 200004;
static const int MAXQ = 50004;
static const int N_BLK = 418;
static const int Q_BLK = 221;

struct sqrt_summer {
    int a[MAXN], b[MAXN / N_BLK + 1];
    sqrt_summer() { std::fill(a, a + MAXN, 0); std::fill(b, b + (sizeof b / sizeof b[0]), 0); }
    inline void add(int pos, int inc) { a[pos] += inc; b[pos / N_BLK] += inc; }
    inline int sum(int lf, int rg) {
        if (lf > rg) return 0;
        int lf_blk = lf / N_BLK, rg_blk = rg / N_BLK;
        int ans = 0;
        if (lf_blk == rg_blk) {
            for (int i = lf; i <= rg; ++i) ans += a[i];
        } else {
            for (int i = lf; i < (lf_blk + 1) * N_BLK; ++i) ans += a[i];
            for (int i = rg_blk * N_BLK; i <= rg; ++i) ans += a[i];
            for (int i = lf_blk + 1; i < rg_blk; ++i) ans += b[i];
        }
        return ans;
    }
};

int n, q;
int a[MAXN];
int u[MAXN], v[MAXN];
int64 ans[MAXN];

inline void solve(int l, int r)
{
    std::vector<int> changed;
    for (int i = l; i <= r; ++i) {
        changed.push_back(u[i]);
        changed.push_back(v[i]);
    }
    std::sort(changed.begin(), changed.end());
    changed.resize(std::unique(changed.begin(), changed.end()) - changed.begin());
    static bool is_changed[MAXN] = { false };
    for (int i = 0; i < (int)changed.size(); ++i) is_changed[changed[i]] = true;
    //for (int i = 0; i < n; ++i) printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');

    // Preparations
    static sqrt_summer natsu;

    // (1) Immobile - Immobile
    int64 a1 = (l == 0 ? 0 : ans[l - 1]);
    // (2) Mobile - Mobile
    int64 a2 = 0;
    for (int i = 0; i < (int)changed.size(); ++i)
        for (int j = i + 1; j < (int)changed.size(); ++j)
            if (a[changed[i]] > a[changed[j]]) ++a2;
    a1 -= a2;
    // (3) Mobile - Immobile
    int64 a3 = 0;
    std::map<std::pair<int, int>, int> queries; // map<pair<pos, val>, ans>
    for (int i = 0; i < (int)changed.size(); ++i)
        queries[std::make_pair(changed[i], a[changed[i]])] = -114514;
    for (int i = l; i <= r; ++i) {
        std::swap(a[u[i]], a[v[i]]);
        queries[std::make_pair(u[i], a[u[i]])] = -114514;
        queries[std::make_pair(v[i], a[v[i]])] = -114514;
    }
    // (3) prep. a. How many element to the left are greater
    int p = 0;
    for (std::map<std::pair<int, int>, int>::iterator i = queries.begin(); i != queries.end(); ++i) {
        for (; p <= i->first.first; ++p) if (!is_changed[p]) natsu.add(a[p], +1);
        i->second = natsu.sum(i->first.second + 1, n - 1);
    }
    for (int i = 0; i < p; ++i)
        if (!is_changed[i]) natsu.add(a[i], -1);
    // (3) prep. b. How many element to the right are smaller
    p = n - 1;
    for (std::map<std::pair<int, int>, int>::reverse_iterator i = queries.rbegin(); i != queries.rend(); ++i) {
        for (; p >= i->first.first; --p) if (!is_changed[p]) natsu.add(a[p], +1);
        i->second += natsu.sum(0, i->first.second - 1);
    }
    for (int i = n - 1; i > p; --i)
        if (!is_changed[i]) natsu.add(a[i], -1);
    // (3) main. Calculate the initial value
    for (int i = r; i >= l; --i) std::swap(a[u[i]], a[v[i]]);
    for (int i = 0; i < (int)changed.size(); ++i)
        a3 += queries[std::make_pair(changed[i], a[changed[i]])];
    a1 -= a3;

    // Let's rock!
    //printf("> %I64d %I64d %I64d\n", a1, a2, a3);
    for (int i = l; i <= r; ++i) {
        // (2) Mobile - Mobile
        // (3) Mobile - Immobile
        for (int j = 0; j < (int)changed.size(); ++j) if (changed[j] != u[i] && changed[j] != v[i]) {
            if ((u[i] < changed[j]) ^ (a[u[i]] < a[changed[j]])) --a2;
            if ((v[i] < changed[j]) ^ (a[v[i]] < a[changed[j]])) --a2;
        }
        a2 -= ((u[i] < v[i]) ^ (a[u[i]] < a[v[i]]));
        a3 -= queries[std::make_pair(u[i], a[u[i]])];
        a3 -= queries[std::make_pair(v[i], a[v[i]])];
        std::swap(a[u[i]], a[v[i]]);
        for (int j = 0; j < (int)changed.size(); ++j) if (changed[j] != u[i] && changed[j] != v[i]) {
            if ((u[i] < changed[j]) ^ (a[u[i]] < a[changed[j]])) ++a2;
            if ((v[i] < changed[j]) ^ (a[v[i]] < a[changed[j]])) ++a2;
        }
        a2 += ((u[i] < v[i]) ^ (a[u[i]] < a[v[i]]));
        a3 += queries[std::make_pair(u[i], a[u[i]])];
        a3 += queries[std::make_pair(v[i], a[v[i]])];
        ans[i] = a1 + a2 + a3;
        //printf("> [%d] %I64d %I64d %I64d\n", i, a1, a2, a3);
    }

    //printf("** %d\n", natsu.sum(0, n - 1));
    for (int i = 0; i < (int)changed.size(); ++i) is_changed[changed[i]] = false;
}

int main()
{
    scanf("%d%d", &n, &q);

    for (int i = 0; i < q; ++i) {
        scanf("%d%d", &u[i], &v[i]);
        --u[i], --v[i];
        //u[i] = rand() % n, v[i] = rand() % n;
        if (u[i] > v[i]) std::swap(u[i], v[i]);
    }

    for (int i = 0; i < n; ++i) a[i] = i;
    for (int i = 0; i < q; i += Q_BLK) solve(i, std::min(q, i + Q_BLK) - 1);
    for (int i = 0; i < q; ++i) printf("%I64d\n", ans[i]);
    return 0;
}